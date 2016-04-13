
#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include <stdio.h>
#include "parse.h"
#include "Designers.h"
#include "parse.h"

void parse(char * text, designer ** d)
{
	cJSON * jList = cJSON_Parse(text);
	if (!jList) {
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return 1;
	}

    int count = cJSON_GetArraySize(jList);
   for (int i = 0; i < count; i++) {
        cJSON * jItem = cJSON_GetArrayItem(jList, i);
        char * name = cJSON_GetObjectItem(jItem, "name")->valuestring;
        char * surname = cJSON_GetObjectItem(jItem, "surname")->valuestring;
        cJSON * jGroup = cJSON_GetObjectItem(jItem, "working");
        char * company = cJSON_GetObjectItem(jGroup, "company")->valuestring;
        char * position = cJSON_GetObjectItem(jGroup, "position")->valuestring;
        double rating = cJSON_GetObjectItem(jItem, "rating")->valuedouble;
        set_des(d[i],name,surname,company,position,rating);
        cJSON * jProjects = cJSON_GetObjectItem(jItem, "projects");
        int cnt = cJSON_GetArraySize(jProjects);
        for (int j = 0; j < cnt; j++){
           cJSON * pItem = cJSON_GetArrayItem(jProjects, j);
           char * deadline = cJSON_GetObjectItem(pItem, "deadline")->valuestring;
           char * customer = cJSON_GetObjectItem(pItem, "customer")->valuestring;
           int budget = cJSON_GetObjectItem(pItem, "budget")->valueint;
           set_proj(d[i],deadline,customer,budget,j);

        }
    }
    cJSON_Delete(jList);

}
