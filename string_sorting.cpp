#include <stdio.h>
#include "string_sorting.h"
#include "FILE_working.h"

#define CREATE_SWAP(type) \
void swap(type * first, type * second) { \
    type tmp = *first; \
    *first = *second; \
    *second = tmp; \
    \
}

const char* sorter_errors_value[] = {
    "SORTER_ERROR_OK",
    "SORTER_ERROR_NO_MEMORY"
};

CREATE_SWAP(int)

CREATE_SWAP(char)

CREATE_SWAP(char*)

sorter_error_code output(struct strings_in_line line)
{
    if(line.string == NULL){
        return SORTER_ERROR_NO_POINTER;
    }
    for (int i = 0; i <= line.number_of_strings; i++){
        printf("%s\n", line.string[i].pointer);
    }
    return SORTER_ERROR_OK;
}



char* from_alpha_string(char *string)
{
    char *beginning_string = string;
    while( (*beginning_string <= 'A'-1 || *beginning_string >= 'z'+1) && *beginning_string != '\0'){
        beginning_string++;
    }
    return beginning_string;
}

char* from_back_alpha_string(struct strings string)
{
    char *back_string = string.pointer + string.length - 1;
    while( (*back_string <= 'A'-1 || *back_string >= 'z'+1) && *back_string != '\0' && back_string >= string.pointer){
        back_string--;
    }
    return back_string;
}

sorter_error_code output_beginning (struct strings_in_line line)
{
    if(line.string == NULL){
        return SORTER_ERROR_NO_POINTER;
    }
    for (int i = 0; i <= line.number_of_strings; i++){
        printf("%s\n", from_alpha_string(line.string[i].pointer));
    }
    return SORTER_ERROR_OK;
}

long long symbol_in_string(char *text, char sym){
    int result = 0;
    for (int i=0; text[i]!='\0'; i++){
        if (text[i] == sym){
            result++;
        }
    }
    return result;
}

sorter_error_code reverse_string(char *string)
{
    if (string == NULL){
        return SORTER_ERROR_NO_POINTER;
    }
    char *pointer = string;
    while(*pointer != '\0'){
        pointer++;
    }
    pointer--;
    while (pointer > string){
        swap(pointer, string);
        pointer--;
        string++;
    }
    return SORTER_ERROR_OK;
}

sorter_error_code reverse_text(char *strings[], int stringnumber){
    if (strings ==NULL){
        return SORTER_ERROR_NO_POINTER;
    }
    for (int i = 0; i <= stringnumber; i++){
        reverse_string(strings[i]);
    }
    return SORTER_ERROR_OK;
}

sorter_error_code quick_sort(struct strings_in_line *line, long long leftpointer, long long rightpointer, comparator_mode mode){
    if (line == NULL){
        return SORTER_ERROR_NO_POINTER;
    }
    long long left = leftpointer;
    long long right = rightpointer;
    struct strings stringcompare = {line->string[leftpointer].pointer, line->string[leftpointer].length};
    while (leftpointer < rightpointer){
        while (leftpointer < rightpointer && comparator(stringcompare, line->string[rightpointer], mode) < 0){
            rightpointer--;
        }
        if (leftpointer != rightpointer){
            line->string[leftpointer] = line->string[rightpointer];
            leftpointer++;
        }
        while (leftpointer < rightpointer && comparator(line->string[leftpointer], stringcompare, mode) < 0){
            leftpointer++;
        }
        if (leftpointer != rightpointer){
            line->string[rightpointer] = line->string[leftpointer];
            rightpointer--;
        }
    }
    line->string[leftpointer] = stringcompare;
    long long k = leftpointer;
    leftpointer = left;
    rightpointer = right;
    if (left < k){
        quick_sort(line, left, k - 1, mode);
    }
    if (right > k){
        quick_sort(line, k + 1, right, mode);
    }
    return SORTER_ERROR_OK;
}

sorter_error_code string_shifts_filling(struct strings_in_line *line){
    allocate_memory_strings(line->number_of_strings + 1, line);
    long long amount_of_strings = 1;
    line->string[0].pointer = &line->text[0];
    int i = 0;
    for (i = 0; line->text[i] != '\0'; i++){
        if (line->text[i] == '\n'){
            line->text[i] = '\0';
            line->string[amount_of_strings].pointer = &line->text[i + 1];
            line->string[amount_of_strings - 1].length = line->string[amount_of_strings].pointer - line->string[amount_of_strings - 1].pointer - 1;
            amount_of_strings++;
        }
    }
    line->string[amount_of_strings - 1].length = &line->text[i] - line->string[amount_of_strings-1].pointer;
}

sorter_error_code allocate_memory_strings (long long number_of_bytes, strings_in_line *line){
    line->string = (strings*)calloc(number_of_bytes, sizeof(strings));
    if (line->string == NULL){
        return SORTER_ERROR_NO_MEMORY;
    }
    return SORTER_ERROR_OK;
}

int comparator_bigger_beginning(const void* string1,const void* string2){
    return comparator(*(struct strings*)string1, *(struct strings*)string2, BIGGER_BEGINNING);
}

int comparator_back_bigger_beginning(const void* string1,const void* string2){
    return comparator(*(struct strings*)string1, *(struct strings*)string2, BACK_BIGGER_BEGINNING);
}

int comparator_pointers(const void* string1,const void* string2){
    return comparator(*(struct strings*)string1, *(struct strings*)string2, POINTERS);
}

int comparator(struct strings string1, struct strings string2,  comparator_mode mode) // Ќужно принимать указатели и длины, чтобы работал qsort
{
    if (mode == BIGGER_BEGINNING){
        char *beginningstring1 = from_alpha_string(string1.pointer);
        char *beginningstring2 = from_alpha_string(string2.pointer);
        while(*beginningstring1 != '\0' && *beginningstring2 != '\0')
        {
            if(*beginningstring1 != *beginningstring2){
                return *beginningstring1 - *beginningstring2;
            }
            beginningstring1++;
            beginningstring2++;
        }
        if (*beginningstring1 == '\0')
        {
            return -1;
        }
        else{
            return 1;
        }
    }
    if (mode == LESS_BEGINNING){
        char *beginningstring1 = from_alpha_string(string1.pointer);
        char *beginningstring2 = from_alpha_string(string2.pointer);
        while(*beginningstring1 != '\n' && *beginningstring2 != '\n' && *beginningstring1 != '\0' && *beginningstring2 != '\0')
        {
        if(*beginningstring1 != *beginningstring2){
            return *beginningstring2 - *beginningstring1;
        }
            beginningstring1++;
            beginningstring2++;
        }
        if (*beginningstring1 == '\0')
        {
            return 1;
        }
        else{
            return -1;
        }
    }
    if (mode == BACK_BIGGER_BEGINNING){
        char *beginningstring1 = from_back_alpha_string(string1);
        char *beginningstring2 = from_back_alpha_string(string2);
        while(beginningstring1 >= string1.pointer && beginningstring2 >= string2.pointer)
        {
            if(*beginningstring1 != *beginningstring2){
                return *beginningstring1 - *beginningstring2;
            }
            beginningstring1--;
            beginningstring2--;
        }
        if (beginningstring1 < string1.pointer)
        {
            return -1;
        }
        else{
            return 1;
        }
    }
    if (mode == POINTERS){
        return string1.pointer - string2.pointer;
    }
}

void strings_in_line_ctor(struct strings_in_line *line, FILE *readfile, long long filesize){
    text_read(&line->text, filesize, readfile);
    line->number_of_strings = symbol_in_string(line->text, '\n');
    string_shifts_filling(line);
}

void strings_in_line_dtor(struct strings_in_line *line){
    free(line->text);
    free(line->string);
}
