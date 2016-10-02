//
//  bubble_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/10/1.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef bubble_sort_hpp
#define bubble_sort_hpp

#include <vector>

// 冒泡排序（非递归版）
template <typename T, typename Compare>
void _BubbleSort(std::vector<T> &a, Compare _comp) {
    if (a.size() <= 1) return;
    
    for (typename std::vector<T>::size_type i = 0; i < a.size() - 1; ++i) {
		for (typename std::vector<T>::size_type j = 0; j <= a.size() - i - 2; ++j) {
            if (_comp(a[j + 1], a[j])) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

// 冒泡排序（递归版）
// 注意：当数组长度过大时，会出现栈溢出；速度要快于非递归版本
template <typename T, typename Compare>
void _BubbleSortRecursive(std::vector<T> &a, size_t index, Compare _comp) {
    if (a.size() <= 1 || index == 1) return;
    
    for (auto i = 0; i != index; ++i) {
        if (_comp(a[i + 1], a[i])) {
            std::swap(a[i], a[i + 1]);
        }
    }
    
    _BubbleSortRecursive(a, index - 1, _comp);
}

// 冒泡排序
// 包括递归版和非递归版
template <typename T, typename Compare = std::less<T> >
void BubbleSort(std::vector<T> &a, const bool recursive = false) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    if (recursive) {
        _BubbleSortRecursive(a, a.size() - 1, _comp);
    } else {
        _BubbleSort(a, _comp);
    }
}

// 冒泡排序（非递归改进版）
// 在排序的同时检查数组是否已经有序
template <typename T, typename Compare = std::less<T> >
void BubbleSortImprove(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    bool flag;
    
    for (typename std::vector<T>::size_type i = 0; i < a.size() - 1; ++i) {
        flag = true;
        
        for (typename std::vector<T>::size_type j = 0; j <= a.size() - i - 2; ++j) {
            if (_comp(a[j + 1], a[j])) {
                std::swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        
        if (flag) return;
    }
}

#endif /* bubble_sort_hpp */
