// calloc vs malloc in C

// void *
// calloc(size_t count, size_t size);
// void *
// malloc(size_t size);
// void
// free(void *ptr);

// The malloc() function allocates size bytes of memory and returns a pointer to the allocated memory.
// The calloc() function contiguously allocates enough space for count objects that are size bytes of memory each and returns a
// pointer to the allocated memory.  The allocated memory is filled with bytes of value zero.

#include <stdio.h>
#include <stdlib.h>

void print_array(int* a, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\t", a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    const int len = 10;
    int *a = (int*)malloc(sizeof(int) * len);
    print_array(a, len);
    int *b = (int*)calloc(len, sizeof(int));
    print_array(b, len);
    return 0;
}
