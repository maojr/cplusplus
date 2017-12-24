// https://www.zhihu.com/question/66949737/answer/248056268
// 缺点: 效率太低
#include <stdio.h>

int main()
{
    for (int i = 0;; i++)
        if (i + 1 < i) {
            printf("%d\n", i);
            break;
        }

    for (int i = 0;; i--)
        if (i - 1 > i) {
            printf("%d\n", i);
            break;
        }

    return 0;
}