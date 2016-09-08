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
#include <cstdlib>
#include <vector>

#include "utils.hpp"
#include "bucket_sort.hpp"
#include "thread_bucket_sort.hpp"

using namespace::std;

int main(int argc, const char * argv[]) {
    vector<double> a;
    vector<double> b;
    vector<int> c;
    const int length = 1000000;
    
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    vector<int> d(c);
    vector<int> e(c);
    
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
    
    st = clock();
    ThreadBucketSort(e, true, 1000, 2);
//    PrintVector(d);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    cout << SortCheck(e, true) << endl;
    
#ifdef _MSC_VER
	system("pause");
#endif // _MSC_VER

    return 0;
}