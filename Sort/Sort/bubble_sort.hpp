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

template <typename T>
void BubbleSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    for (auto i = 0; i < a.size() - 1; ++i) {
        for (auto j = 0; j <= a.size() - i - 2; ++j) {
            if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
        }
    }
}

#endif /* bubble_sort_hpp */
