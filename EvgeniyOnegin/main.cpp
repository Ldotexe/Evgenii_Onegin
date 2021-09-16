#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_comparator_test.h"

const char* my_error[] = {
    "1",
    "2",
    "3"
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

    // FILE *readfile = fopen("EvgeniiOnegin.txt", "r");
    FILE *readfile = fopen("Gamlet.test.txt", "r");
    if (readfile == 0){
        printf("There is no text to work with it\n");
        return 0;
    }

    long long filesize = filesizeoftext(readfile);

    char *text = 0;

    text_read(&text, filesize, readfile);
    if (text == 0){
        printf("Not enough memory to work");
        return 0;
    }
    long long stringnumber = symbol_in_string(text, '\n');

    //char **stringshifts = 0;
    char **stringshifts = (char**) calloc(stringnumber + 1, sizeof(char*));

    if (stringnumber == 0){
        printf("Not enough memory to work");
    }

    string_shifts_filling(text, &stringshifts, stringnumber);

    output(text, stringshifts, stringnumber); // Выводим текст
    printf("\n");

    bubble_sort_beginning(stringshifts, stringnumber);
    output_beginning(text, stringshifts, stringnumber); // Выводим текст в алфавитном порядке
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

/*void string_shifts_filling(char *text, char ***string_shifts, long long strokinum){

    //*string_shifts = (char**) calloc(strokinum + 1, sizeof(char*));
    long long amount_of_strings = 1;
    (*string_shifts)[0] = &text[0];
    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\n'){
            text[i] = '\0';
            (*string_shifts)[amount_of_strings] = &text [i + 1];
            amount_of_strings++;
        }
    }
}*/
