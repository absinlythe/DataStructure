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

template <typename T>
void SelectionSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    for (auto i = 0; i <= a.size() - 1; ++i) {
        auto index = i;
        
        for (auto j = i + 1; j != a.size(); ++j) {
            if (a[index] > a[j]) {
                index = j;
            }
        }
        
        std::swap(a[index], a[i]);
    }
}

#endif /* selection_sort_hpp */
