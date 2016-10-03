//
//  radix_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/10/3.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef radix_sort_hpp
#define radix_sort_hpp

#include <vector>
#include "utils.hpp"

template <typename T>
void RadixSort(std::vector<T> &a, const size_t d, const bool reverse = false) {
    if (a.size() <= 1) return;
    
    std::vector<std::vector<T> > bucket(10, std::vector<T>());
    
    size_t tens = 1;  // 记录10的倍数
    for (size_t i = 0; i != d; ++i) {
        for (auto j = 0; j != a.size(); ++j) {
            size_t k = (a[j] / tens) % 10;
            bucket[k].push_back(a[j]);
        }
        
        tens *= 10;
        
        // 将桶中的数取出装入原数组
        size_t index = 0;
        for (auto j = 0; j != bucket.size(); ++j) {
            for (auto k = 0; k != bucket[j].size(); ++k) {
                a[index++] = bucket[j][k];
            }
            
            bucket[j].clear();  // 清空桶，为了下一次排序
        }
    }
    
    // 是否要逆序排列
    if (reverse) {
        VectorReverse(a);
    }
}

#endif /* radix_sort_hpp */
