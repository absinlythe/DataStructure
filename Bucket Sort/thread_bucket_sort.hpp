//
//  thread_bucket_sort.hpp
//  Bucket Sort
//
//  Created by 郑振宇 on 16/9/8.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef thread_bucket_sort_hpp
#define thread_bucket_sort_hpp

#include <vector>
#include <thread>

#include "insert_sort.hpp"
#include "utils.hpp"

template <typename T>
void InsertionSortThread(typename std::vector<std::vector<T>>::iterator &begin, typename std::vector<std::vector<T>>::iterator &end) {
    for (typename std::vector<std::vector<T>>::iterator iter = begin; iter != end; ++iter) {
		InsertionSort<T>(&(*iter));
    }
}

// 桶排序算法（多线程）
//
// a: 待排序数组
// reverse: 是否降序
// bucket_num: 桶数
// thread_num: 线程数
template <typename T>
void ThreadBucketSort(std::vector<T> &a, const bool reverse = false, const int bucket_num = 10, const int thread_num = 5) {
    if (bucket_num < 1 || thread_num < 1) return;
    
    // 小于两个元素
    if (a.size() <= 1) return;
    
    // 只有两个元素
    if (a.size() == 2) {
        if ((reverse == false && a[0] > a[1]) || (reverse == true && a[0] < a[1])) {
            std::swap(a[0], a[1]);
        }
        return;
    }
    
    // 建桶
    std::vector<std::vector<T> > B;
    for (typename std::vector<T>::size_type i = 0; i != bucket_num; ++i) {
        B.push_back(std::vector<T>());
    }
    
    // 往桶中填充数据
    std::pair<T, T> max_min = GetMaxMin(a);
    T step = (max_min.second - max_min.first) / bucket_num;
    for (typename std::vector<T>::size_type i = 0; i != a.size(); ++i) {
        int index = static_cast<int>((a[i] - max_min.first) / step);
        if (index >= bucket_num) index = bucket_num - 1;
        
        B[index].push_back(a[i]);
    }
    
    // 初始化
    a.clear();
    typename std::vector<T>::iterator iter_a = a.begin();
    
#ifndef _MSC_VER  // 多线程版本暂时只能用于VC编译器
	// 构造线程
    std::vector<std::thread> t;
	typename std::vector<std::vector<T> >::iterator thread_iter = B.begin();
	typename std::vector<std::vector<T> >::size_type thread_step = bucket_num / thread_num;
	for (int i = 0; i != thread_num - 1; ++i) {
		t.push_back(std::thread(InsertionSortThread<T>, thread_iter, thread_iter + thread_step));
		thread_iter += thread_step;
	}
	t.push_back(std::thread(InsertionSortThread<T>, thread_iter, B.end()));

	for (int i = 0; i != thread_num; ++i) {
		t[i].join();
	}
    
    for (typename std::vector<std::vector<T> >::iterator iter = B.begin(); iter != B.end(); ++iter) {
        if ((*iter).size() > 0) {
            a.insert(iter_a, (*iter).begin(), (*iter).end());
            iter_a = a.end();
        }
    }
#else
	// 退化为单线程版本
    // 对每个桶进行插入排序
    for (typename std::vector<std::vector<T> >::iterator iter = B.begin(); iter != B.end(); ++iter) {
        if ((*iter).size() > 0) {
            if ((*iter).size() > 1) {
                InsertionSort<T>(&(*iter));
            }
            
            a.insert(iter_a, (*iter).begin(), (*iter).end());
            iter_a = a.end();
        }
    }
#endif // _MSC_VER
    
    // 是否要逆序排列
    if (reverse) {
        VectorReverse(a);
    }
}

#endif /* thread_bucket_sort_hpp */
