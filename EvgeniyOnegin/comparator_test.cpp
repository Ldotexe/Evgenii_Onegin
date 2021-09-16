#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "string_sorting.h"
#include "FILE_working.h"

/**
 * Test for comparator from program solving the "EvgeniiOnegin" problem
*/

struct TestCmpCase {
    char* str;
    char* shifts[2];
    char result; // 1 - first > second, -1 - second >= first
};

char testComparator(){
        char string1[] = "a\0b";              char *p11 = &string1[0];  char *p12 = &string1[2];
        char string2[] = "anb\0i";            char *p21 = &string2[0];  char *p22 = &string2[4];
        char string3[] = "dd\0aaa";           char *p31 = &string3[0];  char *p32 = &string3[3];
        char string4[] = "...abcd\0!nb";      char *p41 = &string4[0];  char *p42 = &string4[8];
        char string5[] = "!abcd\0...nbasdf";  char *p51 = &string4[0];  char *p52 = &string4[6];
        char string6[] = "\0...nbasdf";       char *p61 = &string4[0];  char *p62 = &string4[5];
    TestCmpCase cases[] = {
        {string1, {p11, p12}, -1},
        {string2, {p21, p22}, -1},
        {string3, {p31, p32},  1},
        {string4, {p41, p42}, -1},
        {string5, {p51, p52}, -1},
        {string6, {p61, p62}, -1}
    };
    int counter = 0;
    for (int i = 0; i < sizeof(cases)/sizeof(TestCmpCase); i++)
    {
        //printf("%s %p %p %p\n", cases[i].str, cases[i].shifts, cases[i].shifts[0], cases[i].shifts[1]);
        //printf("%d\n", comparison_bigger_beginning(cases[i].shifts[0], cases[i].shifts[1]));
        if (comparison_bigger_beginning(cases[i].shifts[0], cases[i].shifts[1]) * cases[i].result <= 0)
            {
                counter++;
            }
    }
    if (counter > 0){
        return 0;
    }
    return 1;
}

