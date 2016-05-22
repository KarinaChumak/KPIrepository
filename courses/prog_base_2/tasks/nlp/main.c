#include <stdio.h>
#include <stdlib.h>
#include "nlp.h"
#define MAX_BUFF_SIZE 100000

int main()
{
    FILE * input = file_new("input.txt","r");
    FILE * output = file_new("output.txt","w");
    char buff[MAX_BUFF_SIZE];
    sentence_t * sentence;
    word_t * word;
    fread(buff,1,MAX_BUFF_SIZE,input);
    text_t * text = text_new(buff);
    removeSymbols(buff);
    text_divide(text);
    int sentences_count = text_getSentencesCount(text);
    for (int i = 0; i < sentences_count; i++)
    {
        sentence = text_getSentence(text,i);
        sentence_divide(sentence);
        int words_count = sentence_getWordsCount(sentence);
        if (words_count < 5) sentence_deleteSentence(sentence);
        else {

                for (int j = 0; j < words_count; j++)
                {
                    word = sentence_getWords(sentence,j);
                    if (word_getWord(word) != NULL) fprintf(output,"%s,",word_getWord(word));

                }

        fprintf(output,"\n");
        }


    }
    word_free(word);
    sentence_free(sentence);
    text_free(text);
    file_free(input);
    file_free(output);
    printf("DONE");

    return 0;
}