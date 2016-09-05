//
//  main.cpp
//  Bucket Sort
//
//  Created by 郑振宇 on 15/9/22.
//  Copyright © 2015年 郑振宇. All rights reserved.
//
//  实现了桶排序算法

#include <iostream>
#include <vector>

using namespace::std;

// 插入排序
void InsertionSort(vector<double> &a) {
    for (vector<double>::size_type j = 1; j != a.size(); ++j) {
        double key = a[j];
        
        int i = static_cast<int>(j) - 1;
        
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            --i;
        }
        
        a[i + 1] = key;
    }
}

// 插入排序（使用迭代器）
void InsertionSort(vector<vector<double> *>::iterator iter) {
    for (vector<double>::iterator iter_j = (*iter)->begin(); iter_j != (*iter)->end(); ++iter_j) {
        double key = *iter_j;
        
        vector<double>::iterator iter_i = iter_j - 1;
        
        while (iter_i >= (*iter)->begin() && *iter_i > key) {
            *(iter_i + 1) = *iter_i;
            --iter_i;
        }
        
        *(iter_i + 1) = key;
    }
}

// 桶排序
void BucketSort(vector<double> &a) {
    vector<vector<double> *> B;
    
    for (vector<double>::size_type i = 0; i != a.size(); ++i) {
        vector<double> *temp = new vector<double>;
        temp->clear();
        
        B.push_back(temp);
    }
    
    for (vector<double>::size_type i = 0; i != a.size(); ++i) {
        B[static_cast<int>(a.size() * a[i])]->push_back(a[i]);
    }
    
    a.clear();
    vector<double>::iterator iter_a = a.begin();
    
    // 下面是使用迭代器版的桶排序
    for (vector<vector<double> *>::iterator iter = B.begin(); iter != B.end(); ++iter) {
        if ((*iter)->size() > 0) {
            InsertionSort(iter);
            
            a.insert(iter_a, (*iter)->begin(), (*iter)->end());
            iter_a = a.end();
        }
    }
    
    // 下面是不使用迭代器版的桶排序
//    for (vector<vector<double> *>::size_type i = 0; i != B.size(); ++i) {
//        if (B[i]->size() > 0) {
//            InsertionSort(*B[i]);
//            
//            a.insert(iter_a, B[i]->begin(), B[i]->end());
//            iter_a = a.end();
//        }
//    }
    
    for (vector<vector<double> *>::iterator iter = B.begin(); iter != B.end(); ++iter) {
        delete *iter;
    }
}

int main(int argc, const char * argv[]) {
    vector<double> a{0.78, 0.17, 0.39, 0.23, 0.72, 0.94, 0.21, 0.12, 0.26, 0.68};
    vector<double> b{0.79, 0.13, 0.16, 0.64, 0.39, 0.20, 0.89, 0.53, 0.71, 0.42};
    
//    vector<double>::iterator iter = a.begin();
//    --iter;

    BucketSort(a);
    
    printf("排序：\n");
    for (vector<double>::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter) {
        printf("%f ", *iter);
    }
    printf("\n");
    
    BucketSort(b);
    
    printf("排序：\n");
    for (vector<double>::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter) {
        printf("%f ", *iter);
    }
    printf("\n");
    
    return 0;
}
