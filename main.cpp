#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_comparator_test.h"

#define NEWLINE '\n'
#define NEXTLINE printf("\n");

struct strings{
    char* pointer;
    int length;
};

struct strings_in_line{
    char* text;
    struct strings* string;
};

//-------------------------------------------------------------------------------------------------------------------

int main(int argc, const char** argv)
{
    struct strings_in_line line;
    for (int argc_counter = 0; argc_counter < argc; argc_counter++){
        printf("argv[%d] = %s\n", argc_counter, argv[argc_counter]);
    }
    if(argv[1] == "Test!"){ //strcmp
        printf("%s\n", test_comparator() == 0 ? "Test passed: No" : "Test passed: Yes");
        if (test_comparator() == 0){
            return 0;
        }
    }

    FILE *readfile = fopen(/*argv[1]*/ "Gamlet.test.txt", "r");
    //FILE *answer = fopen(/*argv[1]*/ "answer.txt", "w");
    if (readfile == NULL){
        printf("There is no text to work with it\n");
        return 0;
    }

    long long filesize = filesizeoftext(readfile);

    file_working_code code_error = FILE_ERROR_OK;

    code_error = text_read(&line.text, filesize, readfile);
    if (code_error != FILE_ERROR_OK){
        printf("%s\n", file_errors_value[code_error]);
        return 0;
    }

    long long stringnumber = symbol_in_string(line.text, NEWLINE);

    char **stringshifts = 0;

    code_error = string_shifts_filling(line.text, &stringshifts, stringnumber);
    if (code_error != FILE_ERROR_OK){
        printf("%s\n", file_errors_value[code_error]);
        return 0;
    }

    output(stringshifts, stringnumber);
    NEXTLINE

    bubble_sort_beginning(stringshifts, stringnumber);
    output_beginning(stringshifts, stringnumber);
    NEXTLINE

    reverse_text(stringshifts, stringnumber);
    bubble_sort_beginning(stringshifts, stringnumber);
    reverse_text(stringshifts, stringnumber);
    output_beginning(stringshifts, stringnumber);
    NEXTLINE

    quick_sort(stringshifts, 0, stringnumber);
    output(stringshifts, stringnumber);

    free(line.text);
    free(stringshifts);
    //fclose(/*argv[1]*/ "answer.txt", "w");
    return 0;
}

//--------------------------------------------------------------------------------------------------------------
