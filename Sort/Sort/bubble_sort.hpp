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
#include <functional>

template <typename T, typename Compare = std::less<T> >
void BubbleSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    for (std::vector<T>::size_type i = 0; i < a.size() - 1; ++i) {
		for (std::vector<T>::size_type j = 0; j <= a.size() - i - 2; ++j) {
            if (_comp(a[j + 1], a[j])) std::swap(a[j], a[j + 1]);
        }
    }
}

#endif /* bubble_sort_hpp */
