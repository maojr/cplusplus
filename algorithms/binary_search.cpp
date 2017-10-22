#include <iostream>

int binary_search(int* a, int length, int val)
{
    int start = 0;
    int mid = 0;
    int end = length - 1;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if(a[mid] == val)
            return mid;
        else if(a[mid] < val)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int a[7] = {1, 3, 4, 5, 6, 7, 9};
    int result = binary_search(a, sizeof(a)/sizeof(a[0]), 110);

    if(result == -1)
        std::cout << "Not find!" << std::endl;
    else
        std::cout << "Find! index = " << result << std::endl;

    return 0;
}