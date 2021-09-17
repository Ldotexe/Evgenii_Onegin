#include <stdio.h>
#define CREATE_SWAP(type) \
void swap(type * first, type * second) { \
    type tmp = *first; \
    *first = *second; \
    *second = tmp; \
    \
}

CREATE_SWAP(int)

CREATE_SWAP(char)

CREATE_SWAP(char*)

void quick_sort (char *array[], int leftpointer, int rightpointer)
{
    int left = leftpointer;
    int right = rightpointer;
    char *pointer = array[leftpointer];
    while (leftpointer < rightpointer){
        while (leftpointer < rightpointer && array[rightpointer] >= pointer){
            rightpointer--;
        }
        if (leftpointer!=rightpointer){
            array[leftpointer] = array[rightpointer];
            leftpointer++;
        }
        while (leftpointer < rightpointer && array[leftpointer] <= pointer){
            leftpointer++;
        }
        if (leftpointer!=rightpointer){
            array[rightpointer] = array[leftpointer];
            rightpointer--;
        }
    }
    array[leftpointer] = pointer;
    int k = leftpointer;
    leftpointer = left;
    rightpointer = right;
    if (left < k){
        quick_sort(array, left, k - 1);
    }
    if (right > k){
        quick_sort(array, k + 1, right);
    }
}

void output(char *text, char *stroki[], int strokinum)
{
    for (int i = 0; i <= strokinum; i++){
        printf("%s\n", stroki[i]);
    }
}

char* from_alpha_string(char *string)
{
    char *beginning_string = string;
    while( (*beginning_string <= 'A'-1 || *beginning_string >= 'z'+1) && *beginning_string != '\0'){
        beginning_string++;
    }
    return beginning_string;
}

void output_beginning (char *text, char *stroki[], int strokinum)
{
    for (int i = 0; i <= strokinum; i++){
        printf("%s\n", from_alpha_string(stroki[i]));
    }
}

long long symbol_in_string(char *text, char sym){
    int result = 0;
    for (int i=0; text[i]!='\0'; i++){
        if (text[i] == sym){
            result++;
        }
    }
    return result;
}

void reverse_string(char *string)
{
    char *pointer = string;
    while(*pointer != '\0'){
        pointer++;
    }
    pointer--;
    while (pointer > string){
        swap(pointer, string);
        pointer--;
        string++;
    }
}

void reverse_text(char *str[], int strokinum){
    for (int i = 0; i <= strokinum; i++){
        reverse_string(str[i]);
    }
}

int comparison_bigger(const char *text, char *str, int s1, int s2){
    char *i1 = &str[s1];
    char *i2 = &str[s2];
    while(*i1 != '\n' && *i2 != '\n' && *i1 != '\0' && *i2 != '\0'){
       if(*i1 != *i2){
            return *i1 - *i2;
       }
        i1++;
        i2++;
    }
    if (*i1 == '\n' || *i1 == '\0'){
        return -1;
    }
    else{
        return 1;
    }
}

int comparison_bigger_beginning(char *string1, char *string2)
{
    char *beginningstring1 = from_alpha_string(string1);
    char *beginningstring2 = from_alpha_string(string2);
    while(*beginningstring1 != '\0' && *beginningstring2 != '\0')
    {
       if(*beginningstring1 != *beginningstring2){
            return *beginningstring1 - *beginningstring2;
       }
        beginningstring1++;
        beginningstring2++;
    }
    if (*beginningstring1 == '\0')
    {
        return -1;
    }
    else{
        return 1;
    }
}

int comparison_less (char *text, char *str, int s1, int s2)
{
    int i1=str[s1];
    int i2=str[s2];
    while(text[i1] != '\n' && text[i2] != '\n' && text[i1] != '\0' && text[i2] != '\0'){
       if(text[i1] != text[i2]){
            return text[i2] - text[i1];
       }
        i1++;
        i2++;
    }
    if (text[i1] == '\n' || text[i1] == '\0'){
        return 1;
    }
    else{
        return -1;
    }
}

int comparison_less_beginning(char *string1, char *string2)
{
    char *beginningstring1 = from_alpha_string(string1);
    char *beginningstring2 = from_alpha_string(string2);
    while(*beginningstring1 != '\n' && *beginningstring2 != '\n' && *beginningstring1 != '\0' && *beginningstring2 != '\0')
    {
       if(*beginningstring1 != *beginningstring2){
            return *beginningstring2 - *beginningstring1;
       }
        beginningstring1++;
        beginningstring2++;
    }
    if (*beginningstring1 == '\0')
    {
        return 1;
    }
    else{
        return -1;
    }
}

void bubble_sort(char *text, char *m, int n)
{
    for (int i = 0 ; i < n; i++){
        for (int j = 0; j < n-1; j++){
            if (comparison_bigger(text, m, j, j+1)>0){
                swap(m + j, m + j + 1);
            }
        }
    }
}

void bubble_sort_beginning(char *stringshifts[], int numberofstrings)
{
    for (int i = 0; i <= numberofstrings; i++){
        for (int j = 0; j < numberofstrings; j++){
            if (comparison_bigger_beginning(stringshifts[j], stringshifts[j + 1]) > 0){
                char *ptr = stringshifts[j];
                stringshifts[j] = stringshifts[j + 1];
                stringshifts[j + 1] = ptr;
            }
        }
    }
}
