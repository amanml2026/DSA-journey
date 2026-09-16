#include <stdio.h>
#include <stdlib.h>

// matrix typedef struct
typedef struct{
    int size;
    int M[10][10]; // maximum size is 10x10
}matrix;

matrix Multiply(matrix A,matrix B); // matrix multiplication -> O(n^3)
void Display(matrix A); // displaying the matrix

int main()
{
    // Test matrices
    matrix A = {5,{{1,  2,  3,  4,  5},{6,  7,  8,  9,  10},{11, 12, 13, 14, 15},{16, 17, 18, 19, 20},{21, 22, 23, 24, 25}}};
    matrix B = {5,{{5,  4,  3,  2,  1},{10, 9,  8,  7,  6},{15, 14, 13, 12, 11},{20, 19, 18, 17, 16},{25, 24, 23, 22, 21}}};
    
    matrix C; // product matrix
    C = Multiply(A,B); // multiplication of A x B
    Display(C); // displaying the output product matrix
    
    return 0;
}
// direct multiplication
matrix Multiply(matrix A,matrix B)
{
    int n,i,j,k;
    n = A.size; // no. of rows/columns (square matrix only !)
    matrix C; // initialising the product matrix
    C.size = n; // (n x n) X (n x n) = (n x n) so size of C = n

    for(i=0;i<n;i++) // each row
    {
        for(j=0;j<n;j++) // each column
        {
            C.M[i][j] = 0; // setting each element to zero first
            for(k=0;k<n;k++) // multiplication
            {
                C.M[i][j] += (A.M[i][k])*(B.M[k][j]);
            }
        }
    }
    return C;
    
}
// displaying the matrix
void Display(matrix A)
{
    int i,j,k,n;
    n = A.size;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",A.M[i][j]); // displaying the elements
        }
        printf("\n");
    }
}
