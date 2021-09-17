#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_comparator_test.h"

const char* errors_value[] = {
    "FILE_ERROR_OK",
    "FILE_ERROR_NO_MEMORY"
};

#define NEWLINE '\n'
#define NEXTLINE printf("\n");

//-------------------------------------------------------------------------------------------------------------------

int main(int argc, const char** argv)
{
    for (int argc_counter = 0; argc_counter < argc; argc_counter++){
        printf("argv[%d] = %s\n", argc_counter, argv[argc_counter]);
    }
    if(argv[1] == "Test!"){
        printf("%s\n", test_comparator() == 0 ? "Test passed: No" : "Test passed: Yes");
        if (test_comparator() == 0){
            return 0;
        }
    }

    FILE *readfile = fopen(/*argv[1]*/ "Gamlet.test.txt", "r");
    if (readfile == NULL){
        printf("There is no text to work with it\n");
        return 0;
    }

    long long filesize = filesizeoftext(readfile);

    char *text = 0;

    file_working_code code_error = FILE_ERROR_OK;

    code_error = text_read(&text, filesize, readfile);
    if (code_error != FILE_ERROR_OK){
        printf("%s\n", errors_value[code_error]);
        return 0;
    }

    long long stringnumber = symbol_in_string(text, NEWLINE);

    char **stringshifts = 0;

    code_error = string_shifts_filling(text, &stringshifts, stringnumber);
    if (code_error != FILE_ERROR_OK){
        printf("%s\n", errors_value[code_error]);
        return 0;
    }

    output(text, stringshifts, stringnumber);
    NEXTLINE

    bubble_sort_beginning(stringshifts, stringnumber);
    output_beginning(text, stringshifts, stringnumber);
    NEXTLINE

    reverse_text(stringshifts, stringnumber);
    bubble_sort_beginning(stringshifts, stringnumber);
    reverse_text(stringshifts, stringnumber);
    output_beginning(text, stringshifts, stringnumber);
    NEXTLINE

    quick_sort(stringshifts, 0, stringnumber);
    output(text, stringshifts, stringnumber);

    free(text);
    free(stringshifts);

    return 0;
}

//--------------------------------------------------------------------------------------------------------------
