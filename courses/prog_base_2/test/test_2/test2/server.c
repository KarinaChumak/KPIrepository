#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>  // ptrdiff_t
#include <string.h>
#include "socket.h"
#include "server.h"
#include "cJSON.h"

http_request_t
http_request_parse(const char * const request) {
    http_request_t req;
    req.form = NULL;
    req.formLength = 0;
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';
    // parse form data
    req.form = malloc(sizeof(keyvalue_t));
    const char * bodyStartPtr = strstr(request, "\r\n\r\n") + strlen("\r\n\r\n");
    const char * cur = bodyStartPtr;
    const char * pairEndPtr = cur;
    const char * eqPtr = cur;
    while (strlen(cur) > 0) {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr) {
            pairEndPtr = cur + strlen(cur);
        }
        keyvalue_t kv;
        // get key
        eqPtr = strchr(cur, '=');
        ptrdiff_t keyLen = eqPtr - cur;
        memcpy(kv.key, cur, keyLen);
        kv.key[keyLen] = '\0';
        // get value
        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';
        // insert key-value pair into request form list
        req.formLength += 1;
        req.form = realloc(req.form, sizeof(keyvalue_t) * req.formLength);
        req.form[req.formLength - 1] = kv;
        cur = pairEndPtr + ((strlen(pairEndPtr) > 0) ? 1 : 0);
    }
    return req;
}


void server_info(socket_t * client)
{
    char buffer[1024];
    cJSON * jInfo = cJSON_CreateObject();
    cJSON_AddItemToObject(jInfo, "name", cJSON_CreateString("Karina"));
    cJSON_AddItemToObject(jInfo, "surname", cJSON_CreateString("Chumak:)"));
    cJSON_AddItemToObject(jInfo, "group", cJSON_CreateString("KP-51"));
    cJSON_AddItemToObject(jInfo, "variant", cJSON_CreateNumber(13));
    char * pageText = cJSON_Print(jInfo);

 sprintf(buffer,
            "HTTP/1.1 404 \n"
            "Content-Type: text/html/application/json\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);

    socket_write(client, buffer,sizeof(buffer));

}


void server_db(socket_t * client, db_t * db, list_t * designers)
{
        char buffer[10240];
        db_getDesignersTask(db,designers);
        cJSON * jPageText = cJSON_CreateArray();

        for(int i = 0; i < list_size(designers); i++)
        {
            designer_t * des = list_get(designers, i);

            cJSON * jText = cJSON_CreateObject();
            cJSON_AddItemToObject(jText, "Name", cJSON_CreateString(designer_getName(des)));
            cJSON_AddItemToObject(jText, "Surname", cJSON_CreateString(designer_getSurname(des)));
            cJSON_AddItemToObject(jText, "Employment date", cJSON_CreateString(designer_getEmployment_date(des)));
            cJSON_AddItemToObject(jText, "Rating", cJSON_CreateNumber(designer_getRating(des)));
            cJSON_AddItemToObject(jText, "Number of sites", cJSON_CreateNumber(designer_getNumOfCites(des)));
            cJSON_AddItemToObject(jText, "Salary", cJSON_CreateNumber(designer_getNumOfCites(des)));
            cJSON_AddItemToArray(jPageText, jText);
        }

       char * pageText = cJSON_Print(jPageText);

       sprintf(buffer,
               "HTTP/1.1 404 \n"
            "Content-Type: text/html/application/json\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);

    socket_write(client, buffer,sizeof(buffer));
}
