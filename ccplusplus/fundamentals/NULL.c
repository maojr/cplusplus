#include <stdio.h>

int main() {
    printf("%p\n", NULL);
    // #undef NULL // NULL is a define value
    // printf("%d\n", NULL);
    int *a = NULL;
    int *b = (void*)0; // compile error in C++, but is ok in C
    return 0;
}
