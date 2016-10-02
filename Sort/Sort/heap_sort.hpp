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

// 以递归的方式调整堆
template <typename T, typename Compare>
void HeapifyRecursive(std::vector<T> &a, const size_t index, const size_t heap_size, Compare _comp) {
    size_t l = LEFT(index);
    size_t r = RIGHT(index);
    size_t largest;
    
    largest = (l < heap_size && _comp(a[index], a[l])) ? l : index;
    largest = (r < heap_size && _comp(a[largest], a[r])) ? r : largest;

    if (largest != index) {
        std::swap(a[index], a[largest]);
        HeapifyRecursive(a, largest, heap_size, _comp);
    }
}

// 以非递归的方式调整堆
template <typename T, typename Compare>
void Heapify(std::vector<T> &a, const size_t index, const size_t heap_size, Compare _comp) {
    size_t largest = index;
    size_t l, r, last;
    
    while (true) {
        l = LEFT(largest);
        r = RIGHT(largest);
        
        if (l >= heap_size && r >= heap_size) return;
        
        last = largest;
    
        if (l < heap_size && _comp(a[largest], a[l])) largest = l;
        if (r < heap_size && _comp(a[largest], a[r])) largest = r;
        
        if (largest != last) {
            std::swap(a[last], a[largest]);
        } else {
            return;
        }
    }
}

// 以递归的方式建堆
template <typename T, typename Compare>
void BuildMaxHeapRecursive(std::vector<T> &a, Compare _comp) {
    for (auto i = (a.size() >> 1) - 1; i >= 1; --i) {
        HeapifyRecursive(a, i, a.size(), _comp);
    }
    HeapifyRecursive(a, 0, a.size(), _comp);
}

// 以非递归的方式建堆
template <typename T, typename Compare>
void BuildMaxHeap(std::vector<T> &a, Compare _comp) {
    for (auto i = (a.size() >> 1) - 1; i >= 1; --i) {
        Heapify(a, i, a.size(), _comp);
    }
    Heapify(a, 0, a.size(), _comp);
}

template <typename T, typename Compare = std::less<T> >
void HeapSort(std::vector<T> &a, const bool recursive = false) {
    if (a.size() <= 1) return;
    
    Compare _comp;
    
    // 建堆
    recursive ? BuildMaxHeapRecursive(a, _comp) : BuildMaxHeap(a, _comp);
    
    // 从尾至头依次调整堆
    for (auto i = a.size() - 1; i >= 1; --i) {
        std::swap(a[0], a[i]);
        
        recursive ? HeapifyRecursive(a, 0, i, _comp) : Heapify(a, 0, i, _comp);
    }
}

#endif /* heap_sort_hpp */
