//
//  test.cpp
//  Sort
//
//  Created by 郑振宇 on 16/9/30.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#include <vector>
#include "test.hpp"
#include "quick_sort.hpp"
#include "bucket_sort.hpp"
#include "thread_bucket_sort.hpp"
#include "heap_sort.hpp"
#include "selection_sort.hpp"
#include "bubble_sort.hpp"

using namespace std;

void BucketSortTest() {
    vector<double> a;
    vector<double> b;
    vector<int> c;
    const int length = 100000;
    
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
    
    //    st = clock();
    //    BucketSort(b, true, 100);
    ////    PrintVector(b);
    //    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    //    cout << SortCheck(b, true) << endl;
    //
    //    st = clock();
    //    BucketSort(c, true, 10000);
    ////    PrintVector(c);
    //    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    //    cout << SortCheck(c, true) << endl;
    
    st = clock();
    BucketSort(d, true, 1000);
    //    PrintVector(d);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    cout << SortCheck(d, true) << endl;
    
    st = clock();
    ThreadBucketSort(e, true, 1000, 5);
    //    PrintVector(d);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    cout << SortCheck(e, true) << endl;
}

void QuickSortTest() {
//    vector<int> a{13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6};
//    vector<long> b{13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6};
//    vector<double> c{13.1, 19.5, 9.9, 5.5, 12.1, 8.4, 7.6, 4.3, 21.2, 5.9, 12.1, 8.1, 2.7, 6.8, 11.9, 6.8};
    
    const int length = 10000000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    vector<int> d{13};
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    time_t st = clock();
    
    QuickSort(a, 0, a.size() - 1);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    QuickSort(d, 0, d.size() - 1);
    RandomizedQuickSort(b, 0, b.size() - 1);
    
    st = clock();
    HoareQuickSort(c, 0, c.size() - 1);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
	//    PrintVector(a);
	cout << SortCheck(a) << endl;
	//    PrintVector(b);
	cout << SortCheck(b) << endl;
	//    PrintVector(c);
	cout << SortCheck(c) << endl;
	//    PrintVector(d);
	cout << SortCheck(d) << endl;
}

void InsertSortTest() {
    const int length = 10000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    InsertionSort(a);
    InsertionSort<double, greater<double> >(b);
    InsertionSort(c);

//        PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
}

void HeapSortTest() {
    const int length = 10000000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }

    time_t st = clock();
    
    HeapSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    HeapSort(b);
    HeapSort(c);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
}

void SelectionSortTest() {
    const int length = 10000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    time_t st = clock();
    
    SelectionSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    SelectionSort<double, greater<double> >(b);
    SelectionSort(c);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
}

void BubbleSortTest() {
    const int length = 10000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    time_t st = clock();
    
    BubbleSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    BubbleSort<double, greater<double> >(b);
    BubbleSort(c);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
}