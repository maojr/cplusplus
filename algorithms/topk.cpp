#include <vector>
#include <iostream>
#include <algorithm>

// use a min heap
std::vector<int> topk(std::vector<int> v, int k) {
    std::vector<int> result;
    if (k > v.size())
        return result;
    std::make_heap(v.begin(), v.begin() + k, std::greater<int>());
    for (int i = k; i < v.size(); ++i)
        if (v[i] > v[0]) {
            std::swap(v[i], v[0]);
            std::make_heap(v.begin(), v.begin() + k, std::greater<int>());
        }
    std::copy(v.begin(), v.begin() + k, std::back_inserter(result));
    return result;
}

// adapted from quick sort
std::vector<int> quick_topk(std::vector<int> v, int k) {
    std::vector<int> result;
    if (k > v.size())
        return result;
    // quick_sort partition
    int pivot = v.back();
    int i = -1;
    int j = v.size() - 1;
    while (i < j) {
        while (v[++i] < pivot);
        while (j > 0 && v[--j] > pivot);
        if (i < j)
            std::swap(v[i], v[j]);
    }
    std::swap(v[i], v.back());
    if (v.size() - k == i){
        std::copy(v.begin() + i, v.end(), std::back_inserter(result));
    }
    else if (v.size() - k < i) {
        std::vector<int> vec;
        std::vector<int> res;
        std::copy(v.begin(), v.begin() + i, std::back_inserter(vec));
        res = quick_topk(vec, k + i - v.size());
        std::copy(res.begin(), res.end(), std::back_inserter(result));
        std::copy(v.begin() + i, v.end(), std::back_inserter(result));
    }
    else {
        std::vector<int> vec;
        std::copy(v.begin() + i + 1, v.end(), std::back_inserter(vec));
        result = quick_topk(vec, k);
    }
    return result;
}

std::vector<int> topk_min_heap(std::vector<int> v, int k) {
    std::vector<int> result;
    if (k > v.size())
        return result;
    std::copy(v.begin(), v.begin() + k, std::back_inserter(result));
    std::make_heap(result.begin(), result.end(), std::greater<int>());
    for (int i = k; i < v.size(); ++i)
        if (v[i] > result[0]) {
            std::swap(v[i], result[0]);
            std::make_heap(result.begin(), result.end(), std::greater<int>());
        }
    return result;
}

std::vector<int> topk_max_heap(std::vector<int> v, int k) {
    std::vector<int> result;
    if (k > v.size())
        return result;
    std::make_heap(v.begin(), v.end());
    for (int i = 0; i < k; ++i)
        std::pop_heap(v.begin(), v.end() - i);
    std::copy(v.end() - k, v.end(), std::back_inserter(result));
    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {3, 2, 6, 9, 0, 1, 8, 4, 5, 7};
    // std::vector<int> result = topk(v, 2);
    std::vector<int> result = quick_topk(v, 3);
    for (const auto & val : result)
        std::cout << val << " ";
    return 0;
}
