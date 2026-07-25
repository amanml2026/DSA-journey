#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 2-d array in stack completely
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{3,5,7,9,}};

    // 2-d array with pointers in stack and arrays in heap
    int *B[3];
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    // 2-d arrays with both pointers and arrays in heap using a double pointer
    int **C;
    C = (int **)malloc(3 * sizeof(int*));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));

    printf("A\n");
    // traversing through A -> gives 2-d array of the provided values.
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d",A[i][j]);
            printf(",");
        }
        printf("\n");
    }

    printf("B\n");
    // traversing through B -> gives 2-d array of the garbage values.
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d",B[i][j]);
            printf(",");
        }
        printf("\n");
    }

    printf("C\n");
    // traversing through C -> gives 2-d array of the garbage values.
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d",C[i][j]);
            printf(",");
        }
        printf("\n");
    }

    return 0;
}
