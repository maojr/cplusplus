#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // appending random numbers
    FILE *fp = fopen("rand.txt", "a");
    if (fp == NULL) {
        printf("open error!");
        return 1;
    }
    for (int i = 0; i < 3; ++i)
        fprintf(fp, "%d ", rand());
    fclose(fp);

    // read and output the numbers
    int rand;
    fp = fopen("rand.txt", "r");
    if (fp == NULL) {
        printf("open error!");
        return 1;
    }
    while (fscanf(fp, "%d ", &rand) != EOF)
        printf("%d\n", rand);
    fclose(fp);

    return 0;
}
