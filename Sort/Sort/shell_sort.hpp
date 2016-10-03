//
//  shell_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/10/3.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef shell_sort_hpp
#define shell_sort_hpp

#include <vector>

template <typename T, typename Compare = std::less<T> >
void ShellSort(std::vector<T> &a) {
    size_t gap, i, j;
    T key;
    Compare _comp;
    
    for (gap = a.size() >> 1; gap > 0; gap >>= 1) {
        for (j = gap; j != a.size(); j++) {
            key = a[j];
            i = j;
            
            while (i >= gap && _comp(key, a[i - gap])) {
                a[i] = a[i - gap];
                
                i -= gap;
            }
            
            a[i] = key;
        }
    }
}

#endif /* shell_sort_hpp */
