#include <stdlib.h>
#include <stdio.h>

void pairing_func(int *numbers, int num_count);

int main() {
    printf("Program Started\n");
    int *numbers = NULL;
    int num_count = 0;
    int status = 0;

    while(status == 0) {
            int num;
            char ch;
            if(scanf("%d%c", &num, &ch) == 2 && (ch == ' ' || ch == '\n')) {
                numbers = realloc(numbers, sizeof(int) * (num_count + 1));
                numbers[num_count] = num;
                num_count++;

                if(ch == '\n') break;
            } else {
                status = 1;
            }
        }

    if(status == 1) {
        printf("Program stopped due to error\n");
        free(numbers);
    }
    else{
        pairing_func(numbers, num_count);

        free(numbers);
        printf("\nProgram finished correctly\n");
    }

    return 0;
}   //1 2 3 4 5 \n

void pairing_func(int *numbers, int num_count) {
    for(int i = 0; i < num_count-1; i++) {
            int difference;
            if(abs(numbers[i]) < abs(numbers[i+1])) {
                difference = abs(numbers[i+1]) - abs(numbers[i]);
            }
            else {
                difference = abs(numbers[i]) - abs(numbers[i+1]);
            }   // module difference

            if(difference < 5) {
                printf("%d  %d\n", numbers[i], numbers[i+1]);
                //i++; // если числа в парах повторяться не должны
            }   // pring if diff mod correct
        }
}