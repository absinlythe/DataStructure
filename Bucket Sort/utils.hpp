//
//  utils.hpp
//  Bucket Sort
//
//  Created by zhengzhenyu on 16/9/7.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <vector>
#include <iostream>

// 打印数列
template <typename T>
void PrintVector(std::vector<T> &a) {
    for (typename std::vector<T>::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

// 获取数列的最大值和最小值
template <typename T>
std::pair<T, T> GetMaxMin(std::vector<T> &a) {
    if (a.empty()) return std::make_pair(0, 0);
    if (a.size() == 1) return std::make_pair(a[0], a[0]);
    
    T max_elm = a[0], min_elm = a[0];
    a[1] > a[0] ? max_elm = a[1] : min_elm = a[1];
    
    for (typename std::vector<T>::iterator iter = a.begin() + 2; iter != a.end(); ++iter) {
        if (*iter > max_elm) {
            max_elm = *iter;
            continue;
        } else if (*iter < min_elm) {
            min_elm = *iter;
        }
    }
    
    return std::make_pair(min_elm, max_elm);
}

// 数组反转
template <typename T>
void VectorReverse(std::vector<T> &a) {
    if (a.size() <= 1) return;
    if (a.size() <= 3) {
        std::swap(a[0], a[a.size() - 1]);
        return;
    }
    
    typename std::vector<T>::size_type right = a.size() / 2;
    for (typename std::vector<T>::size_type i = 0; i != right; ++i) {
        std::swap(a[i], a[a.size() - i - 1]);
    }
}

// 检测排序结果是否正确
template <typename T>
bool SortCheck(std::vector<T> &a, const bool reverse = false) {
    if (a.size() <= 1) return true;
    
    for (typename std::vector<T>::iterator iter = a.begin() + 1; iter != a.end(); ++iter) {
        if ((reverse == false && *iter < *(iter - 1)) || (reverse == true && *iter > *(iter - 1))) {
            std::cout << iter - a.begin() - 1 << ": " << *(iter - 1) << std::endl;
            std::cout << iter - a.begin() << ": " << *iter << std::endl;
            return false;
        }
    }
    
    return true;
}

#endif /* utils_hpp */
