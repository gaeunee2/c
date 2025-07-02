#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    
    scanf("%s", input); //gets(input)

    int len = strlen(input);
    char result[100];
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] != 'X') {
            result[index] = input[i];
            index++;
        }
    }
    result[index] = '\0';

    puts(result);
    return 0;
}