#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <iostream>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_test.h"

int working_with_commands(int argc, const char** argv, FILE** answer, char** filename);

//-------------------------------------------------------------------------------------------------------------------

int main(int argc, const char** argv)
{
    FILE* answer = nullptr;
    char* file_name = nullptr;

    if (working_with_commands(argc, argv, &answer, &file_name) == 0){
        return 0;
    }

    sorter_error_code main_error_code = SORTER_ERROR_OK;

    struct strings_in_line document = {};
    main_error_code = strings_in_line_ctor_file(&document, file_name);
    if (main_error_code != SORTER_ERROR_OK){
        printf("%s", sorter_errors_value[main_error_code]);
        return 0;
    }


    strings_in_line_output_beginning_file(document, answer);

    //strings_in_line_quick_sort(&line, 0, line.number_of_strings, BIGGER_BEGINNING);
    strings_in_line_qsort(document, strings_in_line_comparator_bigger_beginning);
    strings_in_line_output_beginning_file(document, answer);

    //strings_in_line_quick_sort_no_boulders(&line, BACK_BIGGER_BEGINNING);
    strings_in_line_qsort(document, strings_in_line_comparator_back_bigger_beginning);
    strings_in_line_output_beginning_file(document, answer);
    strings_in_line_quick_sort_no_boulders(&document, COMPARATOR_STRINGS_POINTERS);

    //strings_in_line_qsort(line, strings_in_line_comparator_pointers);
    strings_in_line_output_file(document, answer);
    strings_in_line_dtor(&document);
    fclose(answer);

    return 0;
}

//--------------------------------------------------------------------------------------------------------------

int working_with_commands(int argc, const char** argv, FILE** answer_out, char** file_name_in){
    *file_name_in = "Gamlet.test.txt";
    if(argc > 1){
        if (strcmp(argv[1], "Test!") == 0){
            printf("%s\n", test_comparator() == 0 ? "Test passed: No" : "Test passed: Yes");
            return 0;
        }
        else if (strcmp(argv[1], "Sort!") != 0){
            printf("Wrong command!\nUse \"Test!%\" or \"Sort!\"\n");
            return 0;
        }
        else{
            if (argc == 2){
                *answer_out = fopen("Result.txt", "w");
            }
            if (argc > 2){
                *file_name_in = (char*)argv[2];
                if (argc > 3){
                    char* file_name_out = (char*)argv[3];
                    *answer_out = fopen(file_name_out, "w");
                }
                else{
                    *answer_out = fopen("Result.txt", "w");
                }
            }
        }
    }
    else{
        *answer_out = fopen("Result.txt", "w");
    }
    return 1;
}
