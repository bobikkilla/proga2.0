#include <stdio.h>

char *s21_strstr(char *string, char *substring);

int main(int argc, char **argv) {
    printf("Program started\n");
    printf("First part of program:\n"); // info lines

    for(int i = 2; i < argc; i++) { // cycle for arg parsing
        if(s21_strstr(argv[i], argv[1]) != NULL) {
            printf("%s\n", argv[i]);
        }
    }
    printf("Second part of program:\n");
    return 0;
}


char *s21_strstr(char *string, char *substring) {
    char *a, *b;
    b = substring;
    if (*b == 0) {
        return string;
    }
    
    for (; *string != 0; string += 1) {
        if (*string != *b) {
            continue;
        }
        a = string;
        while (1) {
            if (*b == 0) {
                return string;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = substring;
    }
    return NULL;
}
