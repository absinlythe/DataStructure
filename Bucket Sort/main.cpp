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
#include <vector>

#include "utils.hpp"
#include "bucket_sort.hpp"

using namespace::std;

int main(int argc, const char * argv[]) {
    vector<double> a;
    vector<double> b;
    vector<int> c;
    vector<int> d;
    const int length = 50000;
    
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
        d.push_back((rand() % 100000));
    }
    
    time_t st = clock();
//    BucketSort(a);
//    PrintVector(a);
//    cout << " cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
//    cout << SortCheck(a) << endl;
    
    st = clock();
    BucketSort(b, true, 100);
//    PrintVector(b);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    cout << SortCheck(b, true) << endl;
    
    st = clock();
    BucketSort(c, true, 10000);
//    PrintVector(c);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    cout << SortCheck(c, true) << endl;
    
    st = clock();
    BucketSort(d, true, 1000);
    //    PrintVector(d);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    cout << SortCheck(d, true) << endl;
    
    return 0;
}
