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
#include <functional>

template <typename T, typename Compare = std::less<T> >
void SelectionSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    for (auto i = 0; i <= a.size() - 1; ++i) {
        auto index = i;
        
        for (auto j = i + 1; j != a.size(); ++j) {
            if (_comp(a[j], a[index])) {
                index = j;
            }
        }
        
        std::swap(a[index], a[i]);
    }
}

#endif /* selection_sort_hpp */
