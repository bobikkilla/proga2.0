#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    FILE *fp = fopen("matriza.txt","r"); // file open
    if(!fp) {
        perror("matriza.txt");           // file error
        exit(1);
    }

    int sz;
    fscanf(fp,"%d",&sz);                // scan size from file

    int *mtr1 = (int*) malloc(sz*sz *sizeof(int)); // 1 massiv
    int i = 0, k = 0;                               // dlya ziklov
    while(i<(sz*sz)) {                              //zapoln 1 massiva
        fscanf(fp,"%d %d %d", &mtr1[i],&mtr1[i+1],&mtr1[i+2]);
        i = i+sz;
    }
    printf("%d %d %d\n", mtr1[0], mtr1[1], mtr1[2]);
    printf("%d %d %d\n", mtr1[3], mtr1[4], mtr1[5]);
    printf("%d %d %d\n", mtr1[6], mtr1[7], mtr1[8]);
    printf("\n");

    int sz2;
    fscanf(fp,"%d",&sz2);
    int *mtr2 = (int*) malloc(sz2*sz2*sizeof(int)); //2 massiv
    while(k<(sz2*sz2)) {                              //zapoln 2 massiva
        fscanf(fp,"%d %d %d", &mtr2[k],&mtr2[k+1],&mtr2[k+2]);
        k = k+sz2;
    }
    printf("%d %d %d\n", mtr2[0], mtr2[1], mtr2[2]);
    printf("%d %d %d\n", mtr2[3], mtr2[4], mtr2[5]);
    printf("%d %d %d\n", mtr2[6], mtr2[7], mtr2[8]);
    fclose(fp);
    int mtr3
    return 0;
}