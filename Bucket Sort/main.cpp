//
//  main.cpp
//  Bucket Sort
//
//  Created by 郑振宇 on 15/9/22.
//  Copyright © 2015年 郑振宇. All rights reserved.
//
//  实现了桶排序算法

#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace::std;

// 获取数列的最大值和最小值
template <typename T>
pair<long long, long long> getMaxMin(vector<T> &a) {
    if (a.empty()) return make_pair(0, 0);
    if (a.size() == 1) return make_pair(static_cast<long long>(floor(a[0])), static_cast<long long>(ceil(a[0])));

    T max_elm = a[0], min_elm = a[0];
    a[1] > a[0] ? max_elm = a[1] : min_elm = a[1];

    for (typename vector<T>::iterator iter = a.begin() + 2; iter != a.end(); ++iter) {
        if (*iter > max_elm) {
            max_elm = *iter;
            continue;
        } else if (*iter < min_elm) {
            min_elm = *iter;
        }
    }

    return make_pair(static_cast<long long>(floor(min_elm)), static_cast<long long>(ceil(max_elm)));
}

// 打印数列
template <typename T>
void printVector(vector<T> &a) {
    for (typename vector<T>::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// 引用版
/////////////////////////////////////////////////////////////////////////////////////////////
// 插入排序（使用迭代器）
template <typename T>
void InsertionSort2(typename vector<vector<T> >::iterator &iter) {
    if (iter->size() <= 1) return;
    
    for (typename vector<T>::iterator iter_j = (*iter).begin() + 1; iter_j != (*iter).end(); ++iter_j) {
        T key = *iter_j;
        typename vector<T>::iterator iter_i = iter_j - 1;
        bool flag = true;
        
        while (iter_i >= (*iter).begin() && *iter_i > key) {
            *(iter_i + 1) = *iter_i;
            
            if (iter_i == (*iter).begin()) {
                *iter_i = key;
                flag = false;
                break;
            }
            --iter_i;
        }
        
        if (flag) {
            *(iter_i + 1) = key;
        }
    }
}

// 桶排序
template <typename T>
void BucketSort2(vector<T> &a, const bool reverse = false, const int bucket_num = 10) {
    if (bucket_num < 1) return;
    
    // 只小于两个元素
    if (a.size() <= 1) return;
    
    // 只有两个元素
    if (a.size() == 2) {
        if ((reverse == false && a[0] > a[1]) || (reverse == true && a[0] < a[1])) {
            swap(a[0], a[1]);
        }
        return;
    }
    
    vector<vector<T> > B;
    
    // 建桶
    for (typename vector<T>::size_type i = 0; i != bucket_num; ++i) {
        B.push_back(vector<T>());
    }
    
    // 往桶中填充数据
    pair<long long, long long> max_min = getMaxMin(a);
    double step = static_cast<double>(max_min.second - max_min.first) / bucket_num;
    for (typename vector<T>::size_type i = 0; i != a.size(); ++i) {
        int index = static_cast<int>((a[i] - max_min.first) / step);
        if (index >= bucket_num) index = bucket_num - 1;
        
        B[index].push_back(a[i]);
    }
    
    a.clear();
    typename vector<T>::iterator iter_a = a.begin();
    
    // 下面是使用迭代器版的桶排序
    for (typename vector<vector<T> >::iterator iter = B.begin(); iter != B.end(); ++iter) {
        if ((*iter).size() > 0) {
            if ((*iter).size() > 1) {
                InsertionSort2<T>(iter);
            }
            
            a.insert(iter_a, (*iter).begin(), (*iter).end());
            iter_a = a.end();
        }
    }
    
    if (reverse) {
        sort(a.rbegin(), a.rend());
    }
}

int main(int argc, const char * argv[]) {
    vector<double> a;
    vector<double> b;
    const int length = 1000;
    
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
    }
    
    //vector<double> c = { 0.2, 0.2, 1.2, -3.5, 2.7, 5.6, 5.7, 6.7, -6, 8, 3.5, 1.2, 3.1 };
    //vector<long long> d = {-4, 5465, -6546464656, 456, 456, 45544, 6878, -234, -46346, -345, 45};
    //BucketSort2(c);
    //printVector(c);
    
    BucketSort2(a);
    
    printf("排序：\n");
    for (vector<double>::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter) {
        printf("%f ", *iter);
    }
    printf("\n");
    
    BucketSort2(b, true, 20);
    
    printf("排序：\n");
    for (vector<double>::const_iterator iter = b.cbegin(); iter != b.cend(); ++iter) {
        printf("%f ", *iter);
    }
    printf("\n");
    
    return 0;
}
