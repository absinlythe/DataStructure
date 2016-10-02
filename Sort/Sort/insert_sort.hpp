//
//  insert_sort.hpp
//  Bucket Sort
//
//  Created by 郑振宇 on 16/9/8.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef insert_sort_hpp
#define insert_sort_hpp

#include <vector>

// 插入排序（用于桶排序）
template <typename T>
void InsertionSort(std::vector<T> *iter) {
    if (!iter || iter->size() <= 1) return;
    
    for (auto j = 1; j != iter->size(); ++j) {
        T key = (*iter)[j];
        auto i = j;
        
        while (i > 0 && (*iter)[i - 1] > key) {
            (*iter)[i] = (*iter)[i - 1];
            
            --i;
        }
        
        (*iter)[i] = key;
    }
}

// 插入排序（迭代器版）
// 注意：迭代器版本要慢于下面的下标版本
template <typename T, typename Compare = std::less<T> >
void InsertionSortIterator(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    for (auto iter_j = a.begin() + 1; iter_j != a.end(); ++iter_j) {
        T key = *iter_j;
        auto iter_i = iter_j;
        
        while (iter_i > a.begin() && _comp(key, *(iter_i - 1))) {
            *iter_i = *(iter_i - 1);
            
            --iter_i;
        }
        
        *iter_i = key;
    }
}

// 插入排序（下标版）
template <typename T, typename Compare = std::less<T> >
void InsertionSort(std::vector<T> &a, const bool recursive = false) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    for (auto j = 1; j != a.size(); ++j) {
        T key = a[j];
        auto i = j;
        
        while (i > 0 && _comp(key, a[i - 1])) {
            a[i] = a[i - 1];
            
            --i;
        }
        
        a[i] = key;
    }
}

#endif /* insert_sort_hpp */
