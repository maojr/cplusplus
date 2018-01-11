// https://leetcode.com/problems/climbing-stairs/description/
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.
#include <iostream>

int climb_stairs(int n) {
    if (n <= 2)
        return n;
    int result;
    int result_step_one = 2;
    int result_step_two = 1;
    for (int i = 2; i < n; ++i) {
        result = result_step_one + result_step_two;
        result_step_two = result_step_one;
        result_step_one = result;
    }
    return result;
}

int climb_stairs_recursive(int n) {
    if (n <= 2)
        return n;
    return climb_stairs_recursive(n - 1) + climb_stairs_recursive(n - 2);
}

int _recursive_internal(int n, int* data) {
    if (n <= 2)
        return n;
    if (data[n] > 0)
        return data[n];
    data[n] = _recursive_internal(n - 1, data) + _recursive_internal(n - 2, data);
    return data[n];
}

int climb_stairs_recursive_optimized(int n) {
    int* data = new int[n + 1];
    for (int i = 0; i < n + 1; ++i)
        data[i] = 0;
    return _recursive_internal(n, data);
}

int main() {
    std::cout << climb_stairs(44) << std::endl;
    std::cout << climb_stairs_recursive(44) << std::endl;
    std::cout << climb_stairs_recursive_optimized(44) << std::endl;
    return 0;
}
