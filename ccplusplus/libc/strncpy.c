// interview at sogou.com
// char* strncpy(char * dst, const char * src, size_t len);
// If src is less than len characters long, the
//      remainder of dst is filled with `\0' characters.  Otherwise, dst is not terminated.

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char dst[8];
    const char *src = "abcdefhijklmn";
    strncpy(dst, src, sizeof(dst));
    dst[7] = 0;
    printf("%s\n", dst); // what will happen if dst[7] = 0 is comment out
    return 0;
}
