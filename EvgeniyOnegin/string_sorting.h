#ifndef STRING_SORTING_H_INCLUDED
#define STRING_SORTING_H_INCLUDED

enum sorter_error_code{
    SORTER_ERROR_OK,
    SORTER_ERROR_NO_MEMORY
};

#define CREATE_SWAP_DECLARATION(type) void swap(type * first, type * second)

/**
 * Quick sort algorithm for strings sorting
 * O(nlogn)
 * @param text - buffer start pointer
 */

void quick_sortalf (char *text, char *m, int l, int r);


/**
 * Test for program solving the "EvgeniiOnegin" problem
*/

char test_Comparator();


/**
 * Function that finds the first symbol which is a letter
 * Compare symbols to numerical span which is match to all letters
 * until meets letter
*/

char* from_alpha_string(char *string);


/**
 * Comparator for strings
 * compares symbol by symbol until meet different or run out of symbols in one of strings
 * Return positive value if first sting is bigger than second else negative (including the case when they are equivalent)
*/

int comparison_bigger(const char *text, char str, int s1, int s2);


/**
 * Comparator for strings
 * compares symbol by symbol until meet different or run out of symbols in one of strings
 * Return positive value if first sting is less than second else negative (including the case when they are equivalent)
*/

int comparison_less(char *text, char str);


/**
 * Comparator for strings from the first letter for each string
 * compares symbol by symbol until meet different or run out of symbols in one of strings
 * Return positive value if first sting is bigger than second else negative (including the case when they are equivalent)
*/

int comparison_bigger_beginning(char *text, char *str);


/**
 * Comparator for strings from the first letter for each string
 * compares symbol by symbol until meet different or run out of symbols in one of strings
 * Return positive value if first sting is less than second else negative (including the case when they are equivalent)
*/

int comparison_less_beginning(char *text, char *str);


/**
 * Outputs the text string by string
 * Uses the array of shifts of symbols '\n' to withdraw them in specific order
 * And integer strokinum to execute the exact number of operations
*/

void output(char *text, char* stroki[], int strokinum);


/**
 * Outputs the text string by string but from the first symbol of latter for each string
 * Uses the array of shifts of symbols '\n' to withdraw them in specific order
 * And integer strokinum to execute the exact number of operations
*/

void output_beginning (char *text, char *stroki[], int strokinum);


/**
 * Ordinary algorithm of bubble sorting but for strings
 * Uses the strings comparator "comparison_bigger"
 * O(n^2{*m})
*/

void bubble_sort(char *text, char *m, int n);

/**
 * Algorithm for reversing string from the first symbol to the '\n'
 * O(n)
*/

void bubble_sort_beginning(char *stringshifts[], int numberofstrings);

void reverse_string(char *str);

/**
 * Algorithm for reversing text string by string
 * Uses the viceversa_string algorithm for each string
*/

void reverse_text(char *str[], int strokinum);


/**
 * Not working!!!
 * Basic quick_sort algorithm but for strings
 * Uses the string comparators "comparison_bigger" and "comparison_less"
*/

void quick_sort (char *m[], int l, int r);


/**
 * Finds the number of some symbol in a char array
*/

long long symbol_in_string(char *text, char sym);

long long filesizeoftext(FILE*);


/**
 * Swap using the tmp
*/

CREATE_SWAP_DECLARATION(int);
CREATE_SWAP_DECLARATION(char);
CREATE_SWAP_DECLARATION(char*);

#undef CREATE_SWAP_DECLARATION

#endif // ONEGIN_H_INCLUDED
