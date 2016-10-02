//
//  selection_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/10/1.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef selection_sort_hpp
#define selection_sort_hpp

#include <vector>

// 选择排序（非递归版）
template <typename T, typename Compare>
void _SelectionSort(std::vector<T> &a, Compare _comp) {
    if (a.size() <= 1) return;
    
	for (typename std::vector<T>::size_type i = 0; i <= a.size() - 1; ++i) {
        auto index = i;
        
        for (auto j = i + 1; j != a.size(); ++j) {
            if (_comp(a[j], a[index])) {
                index = j;
            }
        }
        
        std::swap(a[index], a[i]);
    }
}

// 选择排序（递归版）
// 注意：当数组长度过大时，会出现栈溢出
template <typename T, typename Compare>
void _SelectionSortRecursive(std::vector<T> &a, size_t index, Compare _comp) {
    if (a.size() <= 1 || index == a.size()) return;

    size_t max_index = index;
    for (auto i = index + 1; i != a.size(); ++i) {
        if (_comp(a[i], a[max_index])) {
            max_index = i;
        }
    }
        
    std::swap(a[index], a[max_index]);
    
    _SelectionSortRecursive(a, index + 1, _comp);
}

// 选择排序
// 包括递归版和非递归版
template <typename T, typename Compare = std::less<T> >
void SelectionSort(std::vector<T> &a, const bool recursive = false) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    if (recursive) {
        _SelectionSortRecursive(a, 0, _comp);
    } else {
        _SelectionSort(a, _comp);
    }
}

#endif /* selection_sort_hpp */
