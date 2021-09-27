#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_comparator_test.h"

#define NEWLINE '\n'

const char* argv_test = "Gamlet.test.txt";

//-------------------------------------------------------------------------------------------------------------------

int main(int argc, const char** argv)
{
    //FILE *answer = fopen(/*argv[1]*/ "answer.txt", "w");
    char* file_name = "Gamlet.test.txt";
    //freopen("answer.txt", "w", stdout);
    for (int argc_counter = 0; argc_counter <= argc; argc_counter++){
        printf("argv[%d] = %s\n", argc_counter, argv[argc_counter]);

    }
    /*if(argv_test != NULL){
        printf("Óðà!Óðà!Äàâàé!Äàààà!\n");
        if (strcmp(argv[1], "Test!") == 0){
            printf("Testing!\n");
            printf("%s\n", test_comparator() == 0 ? "Test passed: No" : "Test passed: Yes");
            if (test_comparator() == 0){
                return 0;
            }
        }
        else{
            printf("Working!\n");
            file_name = (char*)argv[1];
            printf("%s", file_name);
        }
    }*/
    /*printf("%s\n", test_comparator() == 0 ? "Test passed: No" : "Test passed: Yes");
    if (test_comparator() == 0){
            return 0;
    }*/
    struct strings_in_line line = {};
    strings_in_line_ctor(&line, file_name);

    output(line);
    printf("\n");

    //quick_sort(&line, 0, line.number_of_strings, BIGGER_BEGINNING);
    qsort(line, comparator_bigger_beginning);
    output_beginning(line);
    printf("\n");

    //quick_sort(&line, BACK_BIGGER_BEGINNING);
    qsort(line, comparator_back_bigger_beginning);
    output_beginning(line);
    printf("\n");

    quick_sort(&line, POINTERS);
    //qsort(line, comparator_pointers);
    output(line);

    strings_in_line_dtor(&line);

    return 0;
}

//--------------------------------------------------------------------------------------------------------------
