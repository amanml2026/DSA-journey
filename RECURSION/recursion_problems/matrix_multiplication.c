#include <stdio.h>
#include <stdlib.h>

// matrix typedef struct
typedef struct{
    int size;
    int M[10][10]; // maximum size is 10x10
}matrix;

matrix Multiply(matrix A,matrix B); // matrix multiplication -> O(n^3)
void Display(matrix A); // displaying the matrix
matrix RecursiveMultiply(matrix A,matrix B);

int main()
{
    // Test matrices
    matrix A = {4,{{1,  2,  3,  4},{6,  7,  8,  9},{11, 12, 13, 14},{16, 17, 18, 19}}};
    matrix B = {4,{{5,  4,  3,  2},{10, 9,  8,  7},{15, 14, 13, 12},{20, 19, 18, 17}}};
    
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

// Recursive matrix multiplication
matrix RecursiveMultiply(matrix A,matrix B)
{
    int n,i,j;
    n = A.size;
    matrix C;
    matrix A_00,A_01,A_10,A_11,B_00,B_01,B_10,B_11;
    C.size = n;
    matrix C_00,C_01,C_10,C_11;
    int k = n/2;
    A_00.size = A_01.size = A_10.size = A_11.size = B_00.size = B_01.size = B_10.size = B_11.size = k;
    C_00.size = C_01.size = C_10.size = C_11.size = k;

    if(n == 1)
    {
        C.M[0][0] = (A.M[0][0]) * (B.M[0][0]);
        return C;
    }
    else{
        for(i=0;i<k;i++){
            for(j=0;j<k;j++)
            {
                A_00.M[i][j] = A.M[i][j];
                B_00.M[i][j] = B.M[i][j];
            }
        }
        for(i=0;i<k;i++){
            for(j=k;j<n;j++)
            {
                A_01.M[i][j-k] = A.M[i][j];
                B_01.M[i][j-k] = B.M[i][j];
            }
        }
        for(i=k;i<n;i++){
            for(j=0;j<k;j++)
            {
                A_10.M[i-k][j] = A.M[i][j];
                B_10.M[i-k][j] = B.M[i][j];
            }
        }        
        for(i=k;i<n;i++){
            for(j=k;j<n;j++)
            {
                A_11.M[i-k][j-k] = A.M[i][j];
                B_11.M[i-k][j-k] = B.M[i][j];
            }
        }
    C_00 = RecursiveMultiply(A_00, B_00);
    C_01 = RecursiveMultiply(A_00, B_01);
    C_10 = RecursiveMultiply(A_10, B_00);
    C_11 = RecursiveMultiply(A_10, B_01);

    matrix temp;

    temp = RecursiveMultiply(A_01, B_10);
    for(i = 0; i < k; i++)
        for(j = 0; j < k; j++)
            C_00.M[i][j] += temp.M[i][j];

    temp = RecursiveMultiply(A_01, B_11);
    for(i = 0; i < k; i++)
        for(j = 0; j < k; j++)
            C_01.M[i][j] += temp.M[i][j];

    temp = RecursiveMultiply(A_11, B_10);
    for(i = 0; i < k; i++)
        for(j = 0; j < k; j++)
            C_10.M[i][j] += temp.M[i][j];

    temp = RecursiveMultiply(A_11, B_11);
    for(i = 0; i < k; i++)
        for(j = 0; j < k; j++)
            C_11.M[i][j] += temp.M[i][j];

    }
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            C.M[i][j] = C_00.M[i][j];
            C.M[i+k][j] = C_10.M[i][j];
            C.M[i][j+k] = C_01.M[i][j];
            C.M[i+k][j+k] = C_11.M[i][j];
        }
    }
    return C;
}
