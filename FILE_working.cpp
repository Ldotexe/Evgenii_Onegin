#include "FILE_working.h"

const char* file_errors_value[] = {
    "FILE_ERROR_OK",
    "FILE_ERROR_NO_MEMORY"
};

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
