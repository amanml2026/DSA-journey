#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int M[10][10];
}matrix;

int main()
{
    

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
