#include <stdio.h>
#include <string.h>

void* new_memmove(void* dst, const void* src, size_t len)
{
    if (dst == src) return dst;

    char* pdst = (char*)dst;
    char* psrc = (char*)src;

    if (psrc - pdst < 0)
        for (size_t i = 0; i < len; ++i)
            *(pdst + len - i - 1) = *(psrc + len - i - 1);
    else
        for (size_t i = 0; i < len; ++i)
            *(pdst + i) = *(psrc + i);

    return dst;
}

int main()
{
    char str1[] = "abcdefghij";
    printf("%s\n", str1);
    // memcpy(str1 + 1, str1, 2);
    new_memmove(str1 + 1, str1, 2);
    printf("%s\n", str1);
    return 0;
}
