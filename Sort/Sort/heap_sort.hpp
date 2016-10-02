//
//  heap_sort.hpp
//  Sort
//
//  Created by 郑振宇 on 16/9/30.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef heap_sort_hpp
#define heap_sort_hpp

#include <vector>

#define PARENT(i) (i >> 1)

#define LEFT(i) ((i << 1) + 1)

#define RIGHT(i) ((i << 1) + 2)

template <typename T, typename Compare>
void Heapify(std::vector<T> &a, const size_t index, const size_t heap_size, Compare _comp) {
    size_t l = LEFT(index);
    size_t r = RIGHT(index);
    size_t largest = index + 1;
    
    largest = (l < heap_size && _comp(a[index], a[l])) ? l : index;
    largest = (r < heap_size && _comp(a[largest], a[r])) ? r : largest;

    if (largest != index) {
        std::swap(a[index], a[largest]);
        Heapify(a, largest, heap_size, _comp);
    }
}

template <typename T, typename Compare>
void BuildMaxHeap(std::vector<T> &a, Compare _comp) {
    for (auto i = (a.size() >> 1) - 1; i >= 1; --i) {
        Heapify(a, i, a.size(), _comp);
    }
    Heapify(a, 0, a.size(), _comp);
}

template <typename T, typename Compare = std::less<T> >
void HeapSort(std::vector<T> &a) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    // 建堆
    BuildMaxHeap(a, _comp);
    
    // 从尾至头依次调整堆
    for (auto i = a.size() - 1; i >= 1; --i) {
        std::swap(a[0], a[i]);
        
        Heapify(a, 0, i, _comp);
    }
}

#endif /* heap_sort_hpp */
