//
//  counting_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/10/2.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef counting_sort_hpp
#define counting_sort_hpp

#include <vector>
#include "utils.hpp"

template <typename T>
void CountingSort(std::vector<T> &a, const bool reverse = false) {
    if (a.size() <= 1) return;
    
    std::pair<T, T> max_min = GetMaxMin(a);
    std::vector<T> count(max_min.second - max_min.first + 1, 0);
    
    // 计数
    for (auto i = 0; i != a.size(); ++i) {
        count[a[i] - max_min.first] += 1;
    }
    
    // 排序
    size_t index = 0;
    for (auto i = 0; i != count.size(); ++i) {
        while (count[i] > 0) {
            a[reverse ? a.size() - index - 1 : index] = i + max_min.first;
            
            ++index;
            --count[i];
        }
    }
}

#endif /* counting_sort_hpp */
