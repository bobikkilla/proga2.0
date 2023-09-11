#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    FILE *fp = fopen("matrix.txt","r"); // file open
    if(!fp) {
        perror("matrix.txt");           // file error
        exit(1);
    }

    int sz;
    fscanf(fp,"%d",&sz);                // scan size from file


    return 0;
}