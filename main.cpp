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

/*struct strings{
    char* pointer;
    int length;
};

struct strings_in_line{
    char* text;
    struct strings* string;
};*/
void strings_in_line_ctor(struct strings_in_line *line, FILE *readfile, long long filesize);
void strings_in_line_dtor(struct strings_in_line *line);

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

    strings_in_line_ctor(&line, readfile, filesize);

    output(line);
    NEXTLINE

    //quick_sort(&line, 0, line.number_of_strings, BIGGER_BEGINNING);
    qsort(line.string, line.number_of_strings + 1, sizeof(struct strings), comparator_bigger_beginning);
    output_beginning(line);
    NEXTLINE

    //quick_sort(&line, 0, line.number_of_strings, BACK_BIGGER_BEGINNING);
    qsort(line.string, line.number_of_strings + 1, sizeof(struct strings), comparator_back_bigger_beginning);
    output_beginning(line);
    NEXTLINE

    //quick_sort(&line, 0, line.number_of_strings, POINTERS);
    qsort(line.string, line.number_of_strings + 1, sizeof(struct strings), comparator_pointers);
    output(line);
    NEXTLINE

    strings_in_line_dtor(&line);
    //fclose(/*argv[1]*/ "answer.txt", "w");
    return 0;
}

//--------------------------------------------------------------------------------------------------------------
