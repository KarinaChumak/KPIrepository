#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct text_s text_t;
typedef struct sentence_s sentence_t;
typedef struct word_s word_t;

sentence_t * sentence_new(char * sentence);
text_t * text_new(char * text);
word_t * word_new(char * word);
void word_free(word_t * self);
void sentence_free(sentence_t * self);
void text_free(text_t * self);
FILE * file_new(char * filename, char * mode);
void * file_free(FILE * self);
void text_divide(text_t * self);
void sentence_divide(sentence_t * self);
int text_getSentencesCount(text_t * self);
sentence_t * text_getSentence(text_t * self, int index);
int sentence_getWordsCount(sentence_t * self);
void sentence_deleteSentence(sentence_t * self);
word_t * sentence_getWords(sentence_t * self, int index);
char * word_getWord(word_t * self);


