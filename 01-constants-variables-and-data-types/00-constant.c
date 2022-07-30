#include<stdio.h>
#include<limits.h>

int main() {
    /* 
        Integer Constant
     */
    printf("%d %d %d", 123, 0123, 0x123);
    printf("%d\n", INT_MAX);

    /* 
        Real Constant
     */
    printf("Num: %f ", 215.65);
    printf("Same Num: %f\n", 2.1564e2);

    /* 
        Single character constant
     */
    printf("ASCII (a): %d\n", 'a');
    printf("CHAR (97): %c\n", 97);

    /* 
        String Constant
     */
    printf("This is string: %s\n", "lets-learn-it");
    printf("\'x\' == \"x\": %d\n", 'x' == "x");

    /* 
        Backslash Character Constant
     */
    printf("\bdemoo");
    printf("\t");
    return 0;
}
