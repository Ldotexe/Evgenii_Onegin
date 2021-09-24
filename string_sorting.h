#include <cstdlib> // calloc

#ifndef STRING_SORTING_H_INCLUDED
#define STRING_SORTING_H_INCLUDED

enum sorter_error_code{
    SORTER_ERROR_OK,
    SORTER_ERROR_NO_POINTER,
    SORTER_ERROR_NO_MEMORY
};

enum comparator_mode{
    BIGGER_BEGINNING,
    LESS_BEGINNING,
    BACK_BIGGER_BEGINNING,
    POINTERS
};

struct strings{
    char *pointer;
    int length;
};

struct strings_in_line{
    char* text;
    long long number_of_strings;
    struct strings* string;
};

#define CREATE_SWAP_DECLARATION(type) void swap(type * first, type * second)

/**
 * Quick sort algorithm for strings sorting
 * O(nlogn)
 * @param text - buffer start pointer
 */


/**
 * Function that finds the first symbol which is a letter
 * Compare symbols to numerical span which is match to all letters
 * until meets letter
*/

char* from_alpha_string(char *string);

/**
 * Comparator for strings from the first letter for each string
 * compares symbol by symbol until meet different or run out of symbols in one of strings
 * Return positive value if first sting is bigger than second else negative (including the case when they are equivalent)
*/


/**
 * Comparator for strings from the first letter for each string
 * compares symbol by symbol until meet different or run out of symbols in one of strings
 * Return positive value if first sting is less than second else negative (including the case when they are equivalent)
*/

/**
 * Outputs the text string by string
 * Uses the array of shifts of symbols '\n' to withdraw them in specific order
 * And integer strokinum to execute the exact number of operations
*/

sorter_error_code output(struct strings_in_line line);


/**
 * Outputs the text string by string but from the first symbol of latter for each string
 * Uses the array of shifts of symbols '\n' to withdraw them in specific order
 * And integer strokinum to execute the exact number of operations
*/

sorter_error_code output_beginning (struct strings_in_line line);

sorter_error_code strings_in_line_length_filling(struct strings_in_line *line);

int comparator(struct strings string1, struct strings string2,  comparator_mode mode);

sorter_error_code quick_sort(struct strings_in_line *line, long long leftpointer, long long rightpointer, comparator_mode mode);

sorter_error_code allocate_memory_strings (long long number_of_bytes, strings_in_line *line);

int comparator_bigger_beginning(const void* string1, const void* string2);

int comparator_back_bigger_beginning(const void* string1,const void* string2);

int comparator_pointers(const void* string1,const void* string2);

void strings_in_line_ctor(struct strings_in_line *line, FILE *readfile, long long filesize);

void strings_in_line_dtor(struct strings_in_line *line);


/**
 *
 * Finds the number of some symbol in a char array
*/

long long symbol_in_string(char *text, char sym);

long long filesizeoftext(FILE*);

sorter_error_code reverse_string(char *str);

sorter_error_code string_shifts_filling(strings_in_line *line);

/**
 * Algorithm for reversing text string by string
 * Uses the viceversa_string algorithm for each string
*/

sorter_error_code reverse_text(char *str[], int stringnumber);

/**
 * Swap using the tmp
*/

CREATE_SWAP_DECLARATION(int);
CREATE_SWAP_DECLARATION(char);
CREATE_SWAP_DECLARATION(char*);

#undef CREATE_SWAP_DECLARATION

#endif // ONEGIN_H_INCLUDED
