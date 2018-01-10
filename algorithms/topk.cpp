#include <stdlib.h>

#include <vector>
#include <iostream>
#include <algorithm>

#include <gtest/gtest.h>

#define VECTOR_SIZE 5000000
#define K           3

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

std::vector<int> vec;
std::vector<int> topk_vec;
std::vector<int> get_vector() {
    if (vec.size() == 0)
        for (int i = 0; i < VECTOR_SIZE; ++i)
            vec.push_back(rand());
    std::cout << vec.size() << std::endl;
    return vec;
}
std::vector<int> top_vector() {
    if (topk_vec.size() == 0) {
        topk_vec = vec;
        std::sort(topk_vec.begin(), topk_vec.end(), std::greater<int>());
        topk_vec.resize(K);
    }
    return topk_vec;
}
void print_vector(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << '\t';
    std::cout << std::endl;
}

TEST(TOPK, topk) {
    std::vector<int> vec1 = get_vector();
    std::vector<int> top1 = top_vector();
    std::vector<int> res1 = topk(vec1, K);
    std::sort(res1.begin(), res1.end(), std::greater<int>());
    ASSERT_TRUE(res1 == top1);
}

TEST(TOPK, quick_topk) {
    std::vector<int> vec2 = get_vector();
    std::vector<int> top2 = top_vector();
    std::vector<int> res2 = quick_topk(vec2, K);
    std::sort(res2.begin(), res2.end(), std::greater<int>());
    ASSERT_TRUE(res2 == top2);
}

TEST(TOPK, topk_min_heap) {
    std::vector<int> vec3 = get_vector();
    std::vector<int> top3 = top_vector();
    std::vector<int> res3 = topk_min_heap(vec3, K);
    std::sort(res3.begin(), res3.end(), std::greater<int>());
    ASSERT_TRUE(res3 == top3);
}

TEST(TOPK, topk_max_heap) {
    std::vector<int> vec4 = get_vector();
    std::vector<int> top4 = top_vector();
    std::vector<int> res4 = topk_max_heap(vec4, K);
    std::sort(res4.begin(), res4.end(), std::greater<int>());
    ASSERT_TRUE(res4 == top4);
}

int main(int argc, char** argv)
{
    get_vector();
    top_vector();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}