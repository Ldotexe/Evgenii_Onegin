#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_comparator_test.h"

const int number_tests = 1;

char test_comparator(){
    struct strings_in_line test_line[number_tests] = {};
    char *check_text[number_tests][3] = {};
    test_line[0].text = "\nAce\nChikiFlex\nkekv\nMy room mates are strange\n I love polina!\n...ChikiFle...\n       \n\n\n\nDestroy everything!\n!!!Warning!!!\n?Atantion!\n";
    check_text[0][0] =  "\0\0\0\0       \0Ace\0?Atantion!\0...ChikiFle...\0ChikiFlex\0Destroy everything!\0 I love polina!\0My room mates are strange\0!!!Warning!!!\0kekv\0";
    check_text[0][1] = "\0\0\0\0       \0 I love polina!\0Ace\0My room mates are strange\0...ChikiFle...\0Destroy everything!\0!!!Warning!!!\0?Atantion!\0kekv\0ChikiFlex\0";
    check_text[0][2] = "\0Ace\0ChikiFlex\0kekv\0My room mates are strange\0 I love polina!\0...ChikiFle...\0       \0\0\0\0Destroy everything!\0!!!Warning!!!\0?Atantion!\0";
    for (int i = 0; i < number_tests; i++){
        test_line[i].number_of_strings = symbol_in_string(test_line[i].text, '\n');
        printf("Working... %d\n", test_line[i].number_of_strings);
        string_pointers_filling(&test_line[i]);
        printf("Working!\n");
        for (int j = 0; j < 3; j++){
            if (j == 0){
                qsort(test_line[i], comparator_bigger_beginning);
            }
            if (j == 1){
                qsort(test_line[i], comparator_back_bigger_beginning);
            }
            if (j == 2){
                quick_sort(&test_line[i], POINTERS);
            }
            if (strcmp(test_line[i].text, check_text[i][j]) != 0){
                printf("Error in test number %d part %d\n Expected text:\n", i, j);
                print_full_char(check_text[i][j]);
                printf("\n Result:\n");
                print_full_char(test_line[i].text);
                printf("\n");
                return 0;
            }
        }
    }
    return 1;
}

void print_full_char(char* text){
    for(int i = 0; i < strlen(text); i++){
        if (text[i] != '\0'){
            printf("%c", text[i]);
        }
        else{
            printf("\\0");
        }
    }
}
