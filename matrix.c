#include <stdio.h>

/* Type definitions */
typedef unsigned long long ull;

/* Function to multiply two matrices */
void  matmul(int size, ull A[size][size], ull B[size][size], ull result[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result[i][j] = 0;
            for(int k = 0; k < size; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


/* Function to print a matrix */
void matprint(int size, ull A[size][size]){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%llu ", A[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int size = 3;
    ull A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    ull result[size][size];
    matmul(size, A, result);
    matprint(size,result);
    return 0;
}
