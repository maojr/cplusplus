#include <stdio.h>

struct BitField
{
    unsigned char a : 7;
};

int main(int argc, char const *argv[])
{
    /* code */
    printf("%lu\n", sizeof(struct BitField));
    return 0;
}
