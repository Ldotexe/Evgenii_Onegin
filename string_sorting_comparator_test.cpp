#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "string_sorting.h"
#include "FILE_working.h"
#include "string_sorting_comparator_test.h"

struct TestCmpCase {
    char* str;
    char* shifts[2];
    char result; // 1 - first > second, -1 - second >= first
};

char test_comparator(){
        char string1[] = "a\0b";              char *p11 = &string1[0];  char *p12 = &string1[2];
        char string2[] = "anb\0i";            char *p21 = &string2[0];  char *p22 = &string2[4];
        char string3[] = "dd\0aaa";           char *p31 = &string3[0];  char *p32 = &string3[3];
        char string4[] = "...abcd\0!nb";      char *p41 = &string4[0];  char *p42 = &string4[8];
        char string5[] = "!abcd\0...nbasdf";  char *p51 = &string5[0];  char *p52 = &string5[6];
        char string6[] = "\0...nbasdf";       char *p61 = &string6[0];  char *p62 = &string6[5];
        char string7[] = "\0";                char *p71 = &string7[0];  char *p72 = &string7[1];
    TestCmpCase cases[] = {
        {string1, {p11, p12}, -1},
        {string2, {p21, p22}, -1},
        {string3, {p31, p32},  1},
        {string4, {p41, p42}, -1},
        {string5, {p51, p52}, -1},
        {string6, {p61, p62}, -1},
        {string7, {p71, p72}, -1}
    };
    /*for (int i = 0; i < sizeof(cases)/sizeof(TestCmpCase); i++)
    {
        if (comparison_bigger_beginning(cases[i].shifts[0], cases[i].shifts[1]) * cases[i].result <= 0)
            {
                printf("Test not passed: strings: \"%s\" and \"%s\" comparison_bigger result is %d expected value is %d\n",
                cases[i].shifts[0], cases[i].shifts[1],
                comparison_bigger_beginning(cases[i].shifts[0], cases[i].shifts[1]), cases[i].result);
                return 0;
            }
    }*/
    return 1;
}
