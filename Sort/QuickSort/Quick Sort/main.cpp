//
//  main.cpp
//  Quick Sort
//
//  Created by 郑振宇 on 15/9/22.
//  Copyright © 2015年 郑振宇. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "utils.hpp"

using namespace::std;

// 数组划分
template <typename T>
ssize_t Partition(vector<T> &a, const ssize_t p, const ssize_t r) {
    T x = a[r];
    ssize_t i = p - 1;
    
    for (vector<int>::size_type j = p; j != r; ++j) {
        if (a[j] <= x) {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[i + 1], a[r]);
    
    return i + 1;
}

// 使用Hoare方法进行数组划分
template <typename T>
ssize_t HoarePartition(vector<T> &a, const ssize_t p, const ssize_t r) {
    T x = a[p];
    ssize_t i = p;
    ssize_t j = r;
    
    while(i != j) {
        while (a[j] >= x && i < j) {
            --j;
        }
        
        while (a[i] <= x && i < j) {
            ++i;
        }
        
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    
    a[p] = a[i];
    a[i] = x;
    
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 快速排序
template <typename T>
void QuickSort(vector<T> &a, const ssize_t p, const ssize_t r) {
    if (p < r) {
        ssize_t q = Partition(a, p, r);
        
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用Hoare方法进行快速排序
template <typename T>
void HoareQuickSort(vector<T> &a, const ssize_t p, const ssize_t r) {
    if (p < r) {
        ssize_t q = HoarePartition(a, p, r);
        
        HoareQuickSort(a, p, q - 1);
        HoareQuickSort(a, q + 1, r);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// 使用随机的方式划分
template <typename T>
ssize_t RandomizedPartition(vector<T> &a, const ssize_t p, const ssize_t r) {
    int i = static_cast<int>(random(p, r));
    
    swap(a[i], a[r]);
    
    return Partition(a, p, r);
}

// 随机化版本的快速排序
template <typename T>
void RandomizedQuickSort(vector<T> &a, const ssize_t p, const ssize_t r) {
    if (p < r) {
        ssize_t q = RandomizedPartition(a, p, r);
        
        RandomizedQuickSort(a, p, q - 1);
        RandomizedQuickSort(a, q + 1, r);
    }
}


int main(int argc, const char * argv[]) {
    srand(unsigned(time(0)));
    
    vector<int> a{13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6};
    vector<long> b{13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6};
    vector<double> c{13.1, 19.5, 9.9, 5.5, 12.1, 8.4, 7.6, 4.3, 21.2, 2.7, 6.8, 11.9, 6.8};
    
    QuickSort(a, 0, a.size() - 1);
    RandomizedQuickSort(b, 0, b.size() - 1);
    HoareQuickSort(c, 0, c.size() - 1);
    
    printf("排序：\n");
    PrintVector(a);
    PrintVector(b);
    PrintVector(c);
    printf("\n");
    
    return 0;
}
