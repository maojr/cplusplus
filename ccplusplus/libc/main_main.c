#include <stdio.h>

int main(void)
{
    static int a = 6;
    if (a > 0) {
        printf("%d\n", a--);
        main();
    }
    return 0;
}