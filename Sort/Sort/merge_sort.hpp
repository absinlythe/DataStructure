//
//  merge_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/10/2.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef merge_sort_hpp
#define merge_sort_hpp

#include <vector>

// 按顺序归并两个数组
template <typename T, typename Compare>
void MergeVector(std::vector<T> &a, size_t first, size_t mid, size_t last, std::vector<T> &temp, Compare _comp) {
    size_t i = first, j = mid + 1;
    size_t m = mid, n = last;
    size_t k = 0;
    
    while (i <= m && j <= n) {
        if (_comp(a[i], a[j]))
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while (i <= m)
        temp[k++] = a[i++];
    
    while (j <= n)
        temp[k++] = a[j++];
    
    for (i = 0; i < k; ++i)
        a[first + i] = temp[i];
}

template <typename T, typename Compare>
void _MergeSort(std::vector<T> &a, size_t first, size_t last, std::vector<T> &temp, Compare _comp) {
    if (first < last) {
        size_t mid = ((last - first) >> 1) + first;
        
        _MergeSort(a, first, mid, temp, _comp);
        _MergeSort(a, mid + 1, last, temp, _comp);
        
        MergeVector(a, first, mid, last, temp, _comp);
    }
}

template <typename T, typename Compare = std::less<T> >
void MergeSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    std::vector<T> temp(a.size());
    _MergeSort(a, 0, a.size() - 1, temp, _comp);
}

#endif /* merge_sort_hpp */
