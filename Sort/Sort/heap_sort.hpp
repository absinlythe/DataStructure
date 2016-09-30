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

template <typename T>
void MaxHeapify(std::vector<T> &a, const size_t index, const size_t heap_size) {
    size_t l = LEFT(index);
    size_t r = RIGHT(index);
    size_t largest = index + 1;
    
    largest = (l < heap_size && a[l] > a[index]) ? l : index;
    largest = (r < heap_size && a[r] > a[largest]) ? r : largest;

    if (largest != index) {
        std::swap(a[index], a[largest]);
        MaxHeapify(a, largest, heap_size);
    }
}

template <typename T>
void BuildMaxHeap(std::vector<T> &a) {
    for (auto i = (a.size() >> 1) - 1; i >= 1; --i) {
        MaxHeapify(a, i, a.size());
    }
    MaxHeapify(a, 0, a.size());
}

template <typename T>
void HeapSort(std::vector<T> &a) {
    BuildMaxHeap(a);
    
    for (auto i = a.size() - 1; i >= 1; --i) {
        std::swap(a[0], a[i]);
        
        MaxHeapify(a, 0, i);
    }
}

#endif /* heap_sort_hpp */
