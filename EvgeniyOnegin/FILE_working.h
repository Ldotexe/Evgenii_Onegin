#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#ifndef FILE_WORKING_H_INCLUDED
#define FILE_WORKING_H_INCLUDED

enum file_working_code{
    FILE_ERROR_OK,
    FILE_ERROR_NO_MEMORY
};

file_working_code text_read(char **text, long long filesize, FILE* readfile);

file_working_code allocate_memory(long long number_of_bytes, char** buffer);

void string_shifts_filling(char *text, char ***stringshifts, long long strokinum);

#endif// FILE_WORKING_H_INCLUDED
