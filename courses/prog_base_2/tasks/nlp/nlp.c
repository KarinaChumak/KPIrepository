
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nlp.h"


struct word_s {
char * word;
};

struct sentence_s{
int wordsCount;
char * sentence;
word_t * words[100];
};

struct text_s {
char * text;
int sentenceCount;
sentence_t * sentences[100];
};

word_t * word_new(char * word){
word_t * self = malloc(sizeof(struct word_s));
self->word = malloc(sizeof(char) * (strlen(word)+1));
strcpy(self->word,word);
return self;
}

sentence_t * sentence_new(char * sentence){
sentence_t * self = malloc(sizeof(struct sentence_s));
self->sentence = malloc(sizeof(char) * (strlen(sentence) + 1 ));
strcpy(self->sentence,sentence);
self->wordsCount = 0;
return self;
}

text_t * text_new(char * text){
text_t * self = malloc(sizeof(struct text_s));
self->text = malloc(sizeof(char) * (strlen(text)+1));
self->sentenceCount = 0;
strcpy(self->text,text);
return self;
}

void word_free(word_t * self){
free(self->word);
free(self);
}

void sentence_free(sentence_t * self)
{
    free(self->sentence);
    for (int i = 0; i < self->wordsCount; i++){
        free(self->words[i]);
    }
    free(self);
}

void text_free(text_t * self)
{
   free(self->text);
   for (int i = 0 ; i < self->sentenceCount; i++){
    free(self->sentences[i]);
   }
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
while (part!= NULL){
    self->sentences[self->sentenceCount] = sentence_new(part);
    self->sentenceCount++;
    part = strtok(NULL,".?!");
}
}

void sentence_divide(sentence_t * self){
char * part = strtok(self->sentence," ,-");
while (part!= NULL){
self->words[self->wordsCount] = word_new(part);
self->wordsCount++;
part = strtok(NULL," ,-");
}
}



void removeSymbols(char * buff){
for (int i = 0; i < strlen(buff); i++){
        if (buff[i] == '"' ||buff[i] == ';' ||buff[i] == ':' ) buff[i] = ' ';
      }
}

int text_getSentencesCount(text_t * self){
return self->sentenceCount;
}

sentence_t * text_getSentence(text_t * self, int index){
return self->sentences[index];
}

int sentence_getWordsCount(sentence_t * self){
return self->wordsCount;
}



void sentence_deleteSentence(sentence_t * self){
    self->sentence = NULL;
}


word_t * sentence_getWords(sentence_t * self, int index){
    return self->words[index];
}

char * word_getWord(word_t * self){
return self->word;
}
