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
    
    for (typename std::vector<T>::iterator iter_j = iter->begin() + 1; iter_j != iter->end(); ++iter_j) {
        T key = *iter_j;
        typename std::vector<T>::iterator iter_i = iter_j;
        
        while (iter_i > (*iter).begin() && *(iter_i - 1) > key) {
            *iter_i = *(iter_i - 1);
            
            --iter_i;
        }
        
        *iter_i = key;
    }
}

// 插入排序
template <typename T, typename Compare = std::less<T> >
void InsertionSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    for (auto iter_j = a.begin() + 1; iter_j != a.end(); ++iter_j) {
        T key = *iter_j;
        auto iter_i = iter_j;

//        std::cout << _comp(*a.begin(), *iter_i) << std::endl;
        
//        while (iter_i > a.begin() && *(iter_i - 1) > key) {
        
        while (iter_i > a.begin() && _comp(key, *(iter_i - 1))) {
            *iter_i = *(iter_i - 1);
            
            --iter_i;
        }
        
        *iter_i = key;
    }
}

#endif /* insert_sort_hpp */
