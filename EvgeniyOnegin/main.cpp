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

//-------------------------------------------------------------------------------------------------------------------

int main(int argc, const char** argv)
{
    for (int argc_counter = 0; argc_counter < argc; argc_counter++){
        printf("argv[%d] = %s\n", argc_counter, argv[argc_counter]);
    }
    printf("%s\n", test_comparator() == 0 ? "Test passed: No" : "Test passed: Yes");
    /*if (test_Comparator() == 0){
        return 0;
    }*/

    FILE *readfile = fopen("Gamlet.test.txt", "r");
    if (readfile == 0){
        printf("There is no text to work with it\n");
        return 0;
    }

    long long filesize = filesizeoftext(readfile);

    char *text = 0;

    file_working_code code_error = FILE_ERROR_OK;

    code_error = text_read(&text, filesize, readfile);
    if (code_error != FILE_ERROR_OK){
        printf("%s", errors_value[code_error]);
    }

    long long stringnumber = symbol_in_string(text, '\n');

    char **stringshifts = 0;

    code_error = string_shifts_filling(text, &stringshifts, stringnumber);

    output(text, stringshifts, stringnumber);
    printf("\n");

    bubble_sort_beginning(stringshifts, stringnumber);
    output_beginning(text, stringshifts, stringnumber);
    printf("\n");

    reverse_text(stringshifts, stringnumber);
    bubble_sort_beginning(stringshifts, stringnumber);
    reverse_text(stringshifts, stringnumber);
    output_beginning(text, stringshifts, stringnumber);
    printf("\n");

    quick_sort(stringshifts, 0, stringnumber);
    output(text, stringshifts, stringnumber);

    free(text);
    free(stringshifts);

    return 0;
}

//--------------------------------------------------------------------------------------------------------------
