// Print two dimensions array as follows
// 1 2 3
// 4 5 6
// 7 8 9
// (1) print a matrix in spiral order - 1,2,3,6,9,8,7,4,5
// (2) print as following sequences - 3,2,6,1,5,9,4,8,7
#include <stdio.h>
#include <stdlib.h>

void array_print(int** arr, int m, int n)
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void spiral_print(int** arr, int m, int n)
{
    printf("spiral print: ");
    int num = 0;
    int size = m * n;
    int l1 = 0;
    int l2 = m - 1;
    int r1 = 0;
    int r2 = n - 1;
    while (num < size) {
        for (int i = r1; i <= r2; ++i) {
            ++num;
            printf("%d ", arr[l1][i]);
        }
        for (int i = l1 + 1; i <= l2; ++i) {
            ++num;
            printf("%d ", arr[i][r2]);
        }
        for (int i = r2 - 1; i >= r1; --i) {
            ++num;
            printf("%d ", arr[l2][i]);
        }
        for (int i = l2 - 1; i >= l1 + 1; --i) {
            ++num;
            printf("%d ", arr[i][r1]);
        }
        l1++;
        l2--;
        r1++;
        r2--;
    }
    printf("\n");
}

void slash_print(int** arr, int m, int n)
{
    printf("slash  print: ");
    for (int i = n - 1; i >= 0; --i) {
        int x = 0;
        int y = i;
        printf("%d ", arr[x][y]);
        while (++x < m && ++y < n)
            printf("%d ", arr[x][y]);
    }
    for (int i = 1; i < m; ++i) {
        int x = i;
        int y = 0;
        printf("%d ", arr[x][y]);
        while (++x < m && ++y < n)
            printf("%d ", arr[x][y]);
    }
    printf("\n");
}

int main()
{
    int m = 5;
    int n = 5;
    int counter = 0;

    /*int arr[m][n];*/
    int** arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i)
        *(arr + i) = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            arr[i][j] = ++counter;

    array_print(arr, m, n);
    spiral_print(arr, m, n);
    slash_print(arr, m, n);

    //free the heap memory
    for (int i = 0; i < m; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}
