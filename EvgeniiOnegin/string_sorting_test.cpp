#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_test.h"

const int number_tests = 3;

char test_comparator(){

    struct strings_in_line test_line = {}, answer = {};
    char* file_name_in[number_tests] = {"1test.txt", "2test.txt", "3test.txt"};
    char* file_name_result[number_tests] = {"1answer.txt", "2answer.txt", "3answer.txt"};
    for (int i = 0; i < number_tests; i++){
        strings_in_line_ctor_file(&test_line, file_name_in[i]);
        strings_in_line_ctor_file(&answer, file_name_result[i]);
        strings_in_line_qsort(test_line, strings_in_line_comparator_back_bigger_beginning);
        if (test_line.number_of_strings != answer.number_of_strings){
            printf("Error in test number %ld\n Expected number of strings: %ld\n Result: %ld\n", i, answer.number_of_strings, test_line.number_of_strings);
            return 0;
        }
        for (int j = 0; j < test_line.number_of_strings; j++){
                if (strcmp(test_line.string[j].pointer, answer.string[j].pointer) != 0){
                    printf("Error when comparing strings:\nresult: %s\nanswer: %s\n\n", test_line.string[j].pointer, answer.string[j].pointer);
                    printf("Error in test number %d\nExpected text:\n\n", i);
                    strings_in_line_output(answer);
                    printf("\nResult:\n");
                    strings_in_line_output(test_line);
                    printf("number of strings: %d\n", test_line.number_of_strings);
                    printf("\n");
                    return 0;
                }
        }
    }
    return 1;
}
