#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nlp.h"
struct text_s {
char * text;
list_t * sentencesList;
};

struct sentence_s{
char * sentence;
list_t * wordsList;
};

struct word_s {
char * word;
};


text_t * text_new(char * text){
text_t * self = malloc(sizeof(struct text_s));
self->text = malloc(sizeof(char) * (strlen(text)+1));
self->sentencesList = list_new();
strcpy(self->text,text);
return self;
}

void text_free(text_t * self)
{
   free(self->text);
   free (self->sentencesList);
   free(self);
}




sentence_t * sentence_new(char * sentence){
sentence_t * self = malloc(sizeof(struct sentence_s));
self->sentence = malloc(sizeof(char) * (strlen(sentence) + 1 ));
strcpy(self->sentence,sentence);
self->wordsList = list_new();
return self;
}


void sentence_free(sentence_t * self)
{
    free(self->sentence);
   free(self->wordsList);
    free(self);
}

word_t * word_new(char * word){
word_t * self = malloc(sizeof(struct word_s));
self->word = malloc(sizeof(char) * (strlen(word)+1));
strcpy(self->word,word);
return self;
}


void word_free(word_t * self){
free(self->word);
free(self);
}



FILE * file_new(char * filename, char * mode){
FILE * self;
self = fopen(filename,mode);
if (self == NULL) return NULL;
return self;
}

void * file_free(FILE * self){
fclose(self);
}

void text_divide(text_t * self){
char * part = strtok(self->text,".?!");
while (part != NULL) {
		list_push_back(self->sentencesList,sentence_new(part));
		part = strtok(NULL,".?!");
	}
}

void sentence_divide(sentence_t * self){
char * part = strtok(self->sentence," ,-");
while (part!= NULL){
list_push_back(self->wordsList,word_new(part));
part = strtok(NULL," ,-");
}
}

void removeSymbols(char * buff){
for (int i = 0; i < strlen(buff); i++){
        if (buff[i] == '"' ||buff[i] == ';' ||buff[i] == ':' ) buff[i] = ' ';
      }
}


void sentence_deleteSentence(sentence_t * self){
    self->sentence = NULL;
}

int text_getSentencesCount(text_t * self){
return list_getSize(self->sentencesList);
}

word_t * sentence_getWords(sentence_t * self, int index){
    return list_get(self->wordsList,index);
}

sentence_t * text_getSentence(text_t * self, int index){
return list_get(self->sentencesList,index);
}

int sentence_getWordsCount(sentence_t * self){
return list_getSize(self->wordsList);
}

char * word_getWord(word_t * self){
return self->word;
}
