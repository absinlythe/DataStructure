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
#include "utils.hpp"

// 数组划分
template <typename T>
ssize_t Partition(std::vector<T> &a, const ssize_t p, const ssize_t r) {
    T x = a[r];
    ssize_t i = p - 1;
    
    for (auto j = p; j != r; ++j) {
        if (a[j] <= x) {
            i = i + 1;
            std::swap(a[i], a[j]);
        }
    }
    
    std::swap(a[i + 1], a[r]);
    
    return i + 1;
}

// 使用Hoare方法进行数组划分
template <typename T>
ssize_t HoarePartition(std::vector<T> &a, const ssize_t p, const ssize_t r) {
    T x = a[p];
    ssize_t i = p;
    ssize_t j = r;
    
    while(i != j) {
        while (a[j] >= x && i < j) {
            --j;
        }
        
        while (a[i] <= x && i < j) {
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
template <typename T>
void QuickSort(std::vector<T> &a, const ssize_t p, const ssize_t r) {
    if (p < r) {
        ssize_t q = Partition(a, p, r);
        
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用Hoare方法进行快速排序
template <typename T>
void HoareQuickSort(std::vector<T> &a, const ssize_t p, const ssize_t r) {
    if (p < r) {
        ssize_t q = HoarePartition(a, p, r);
        
        HoareQuickSort(a, p, q - 1);
        HoareQuickSort(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用随机的方式划分
template <typename T>
ssize_t RandomizedPartition(std::vector<T> &a, const ssize_t p, const ssize_t r) {
    int i = static_cast<int>(random(p, r));
    
    std::swap(a[i], a[r]);
    
    return Partition(a, p, r);
}

// 随机化版本的快速排序
template <typename T>
void RandomizedQuickSort(std::vector<T> &a, const ssize_t p, const ssize_t r) {
    if (p < r) {
        ssize_t q = RandomizedPartition(a, p, r);
        
        RandomizedQuickSort(a, p, q - 1);
        RandomizedQuickSort(a, q + 1, r);
    }
}

#endif /* quick_sort_hpp */
