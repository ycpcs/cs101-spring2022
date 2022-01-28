#include<stdio.h>
#include<stdbool.h>


/* function prototypes */
void print_spaces(int num_spaces);
void print_line(int line_length);


int main(void) {

    // TODO: Enter your code here
    
    
    return 0;
}



void print_spaces(int num_spaces) {
    for (int i=1; i <= num_spaces; i++) {
        printf(" ");
    }
}



void print_line(int line_length) {
    for (int i=1; i <= line_length; i++) {
        printf("*");
    }
}