#include "FILE_working.h"

long long filesizeoftext(FILE* readfile){
    fseek(readfile, 0, SEEK_END);
    long long filesize = ftell(readfile);
    fseek(readfile, 0, SEEK_SET);
    return filesize;
}

file_working_code text_read(char** text, long long filesize, FILE* readfile){
    char *p = 0;
    if (allocate_memory(filesize + 1, &p) != FILE_ERROR_OK){
        return FILE_ERROR_NO_MEMORY;
    }
    *text = p;
    fread(*text, filesize, 1, readfile);
    (*text)[filesize] = '\0';
    return FILE_ERROR_OK;
}

file_working_code allocate_memory (long long number_of_bytes, char** buffer){
    *buffer = (char*) calloc(number_of_bytes, sizeof(char));
    if (*buffer == NULL){
        return FILE_ERROR_NO_MEMORY;
    }
    return FILE_ERROR_OK;
}

file_working_code allocate_memory_mas (long long number_of_bytes, char*** buffer){
    *buffer = (char**) calloc(number_of_bytes, sizeof(char*));
    if (*buffer == NULL){
        return FILE_ERROR_NO_MEMORY;
    }
    return FILE_ERROR_OK;
}

file_working_code string_shifts_filling(char *text, char ***string_shifts, long long strokinum){

    allocate_memory_mas(strokinum + 1, string_shifts);
    long long amount_of_strings = 1;
    (*string_shifts)[0] = &text[0];
    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\n'){
            text[i] = '\0';
            (*string_shifts)[amount_of_strings] = &text [i + 1];
            amount_of_strings++;
        }
    }
}
