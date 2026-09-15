#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int M[10][10];
}matrix;

matrix Multiply(matrix A,matrix B);

int main()
{
    matrix A = {5,{{1,  2,  3,  4,  5},{6,  7,  8,  9,  10},{11, 12, 13, 14, 15},{16, 17, 18, 19, 20},{21, 22, 23, 24, 25}}};
    matrix B = {5,{{5,  4,  3,  2,  1},{10, 9,  8,  7,  6},{15, 14, 13, 12, 11},{20, 19, 18, 17, 16},{25, 24, 23, 22, 21}}};
    return 0;
}

matrix Multiply(matrix A,matrix B)
{
    int n,i,j,k;
    n = A.size;
    matrix C;
    C.size = n;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            C.M[i][j] = 0;
            for(k=0;k<n;k++)
            {
                C.M[i][j] += (A.M[i][k])*(B.M[k][j]);
            }
        }
    }
    return C;
    
}

void Display(matrix A)
{
    int i,j,k,n;
    n = A.size;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",A.M[i][j]);
        }
        printf("\n");
    }
}
