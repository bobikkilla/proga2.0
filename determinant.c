#include <stddef.h>
#include <math.h>

int determinant(size_t size, const int matrix[size][size]) {
    int to_return = 0;
    if(size == 1) {
      to_return = matrix[0][0];
    }
    else if(size == 2) {
      to_return = (matrix[0][0] * matrix[1][1]) - 
        (matrix[0][1]*matrix[1][0]);
    }
    else {
      for(int i = 0; i < (int)size; i++) {
        int under_matrix[size-1][size-1];
        int count_main = size, count = 0;
        while(count <= (int)((size-1) * (size-1))) {
          if((count_main % size) != i) {
            under_matrix[count/(size-1)][count%(size-1)] = matrix[count_main/size][count_main%size];
            count++;
          }
          count_main++;
        }
        int minor = determinant(size-1,under_matrix);
        to_return += pow(-1,i) * (matrix[0][i] * minor);
      }
    }
  return to_return;
}
