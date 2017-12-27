#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a = 0.01f;
    float b = 0.010f;
    float c = 0.001f;
    printf("%d\n", a == b);
    printf("%d\n", a == 10 * c);
    // we can view a == 10 * c with following method
    printf("%d\n", (a - 10 * c) < 0.00001f);
    return 0;
}
