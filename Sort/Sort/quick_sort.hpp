//
//  quick_sort.hpp
//  Quick Sort
//
//  Created by 郑振宇 on 16/9/30.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <vector>
#include <cstddef>
#include "utils.hpp"

// 数组划分
template <typename T, typename Compare>
size_t Partition(std::vector<T> &a, const size_t p, const size_t r, Compare _comp) {
    T x = a[r];
    size_t i = p;
    
    for (auto j = p; j != r; ++j) {
        if (!_comp(x, a[j])) {
            std::swap(a[i], a[j]);
            i = i + 1;
        }
    }
    
    std::swap(a[i], a[r]);
    
    return i;
}

// 使用Hoare方法进行数组划分
template <typename T, typename Compare>
size_t HoarePartition(std::vector<T> &a, const size_t p, const size_t r, Compare _comp) {
    T x = a[p];
    size_t i = p;
    size_t j = r;
    
    while(i != j) {
        while (!_comp(a[j], x) && i < j) {
            --j;
        }
        
        while (!_comp(x, a[i]) && i < j) {
            ++i;
        }
        
        if (i < j) {
            std::swap(a[i], a[j]);
        }
    }
    
    a[p] = a[i];
    a[i] = x;
    
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 快速排序
template <typename T, typename Compare = std::less<T> >
void QuickSort(std::vector<T> &a, const size_t p, const size_t r) {
    if (a.size() <= 1) return;
    
    if (p < r) {
        Compare _comp;
        
        size_t q = Partition(a, p, r, _comp);
        
        if (q > 0) QuickSort<T, Compare>(a, p, q - 1);
        QuickSort<T, Compare>(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用Hoare方法进行快速排序
template <typename T, typename Compare = std::less<T> >
void HoareQuickSort(std::vector<T> &a, const size_t p, const size_t r) {
    if (a.size() <= 1) return;
    
    if (p < r) {
        Compare _comp;
        
        size_t q = HoarePartition(a, p, r, _comp);
        
        if (q > 0) HoareQuickSort<T, Compare>(a, p, q - 1);
        HoareQuickSort<T, Compare>(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用随机的方式划分
template <typename T, typename Compare>
size_t RandomizedPartition(std::vector<T> &a, const size_t p, const size_t r, Compare _comp) {
    int i = static_cast<int>(random(p, r));
    
    std::swap(a[i], a[r]);
    
    return Partition(a, p, r, _comp);
}

// 随机化版本的快速排序
template <typename T, typename Compare = std::less<T> >
void RandomizedQuickSort(std::vector<T> &a, const size_t p, const size_t r) {
    if (a.size() <= 1) return;
    
    if (p < r) {
        Compare _comp;
        
        size_t q = RandomizedPartition(a, p, r, _comp);
        
        if (q > 0) RandomizedQuickSort<T, Compare>(a, p, q - 1);
        RandomizedQuickSort<T, Compare>(a, q + 1, r);
    }
}

#endif /* quick_sort_hpp */
