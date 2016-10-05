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
#include "merge_sort.hpp"
#include "counting_sort.hpp"
#include "shell_sort.hpp"
#include "radix_sort.hpp"

using namespace std;

void BucketSortTest() {
    vector<double> a;
    vector<double> b;
    vector<int> c;
    const int length = 10000000;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    vector<int> d(c);
    vector<int> e(c);
    
    time_t st = clock();
    
//    BucketSort(a);
////    PrintVector(a);
//    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
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
    
    const int length = 10000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    vector<int> d{13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6};
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    time_t st = clock();
    
    QuickSort(a, 0, a.size() - 1);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    RandomizedQuickSort<double, greater<double> >(b, 0, b.size() - 1);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    HoareQuickSort(c, 0, c.size() - 1);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    HoareQuickSort(d, 0, d.size() - 1);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
	//    PrintVector(a);
	cout << SortCheck(a) << endl;
	//    PrintVector(b);
	cout << SortCheck(b, true) << endl;
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
    
    vector<int> d(c);
    
    time_t st = clock();
    
    InsertionSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    InsertionSort(a);
    InsertionSort<double, greater<double> >(b);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    InsertionSort(c, true);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    InsertionSortIterator(d);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;

//        PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
    //    PrintVector(d);
    cout << SortCheck(d) << endl;
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
    
    st = clock();
    HeapSort(b, true);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
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
//    vector<int> d { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6 };
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    vector<int> d(c);
    
    time_t st = clock();
    
    SelectionSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    SelectionSort<double, greater<double> >(b);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    SelectionSort(c);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    SelectionSort(d, true);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
    //    PrintVector(d);
    cout << SortCheck(d) << endl;
}

void BubbleSortTest() {
    const int length = 20000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
//    vector<int> d { 1, 2, 3, 4, 5, 6, 7, 9, 8 };
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    vector<int> d(c);
    
    time_t st = clock();
    
    BubbleSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    BubbleSort<double, greater<double> >(b);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    BubbleSort(c, true);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    BubbleSortImprove(d);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
    //    PrintVector(d);
    cout << SortCheck(d) << endl;
}

void MergeSortTest() {
    const int length = 100000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    time_t st = clock();
    
    MergeSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    MergeSort<double, greater<double> >(b);
    MergeSort(c);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
}

void CountingSortTest() {
    const int length = 1000000;
    
    vector<long long> a;
    vector<long> b;
    vector<int> c;
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 100000));
        b.push_back((rand() % 10000) - 5000);
        c.push_back((rand() % 1000));
    }
    
    time_t st = clock();
    
    CountingSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    CountingSort(b, true);
    CountingSort(c);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
}

void ShellSortTest() {
    const int length = 100000;
    
    vector<double> a;
    vector<double> b;
    vector<int> c;
    vector<int> d { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6 };
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 10000) / 10000.0 - 0.5);
        b.push_back((rand() % 10000) / 100.0);
        c.push_back((rand() % 100000));
    }
    
    time_t st = clock();
    
    ShellSort(a);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    ShellSort<double, greater<double> >(b);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    ShellSort(c);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    ShellSort(d);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b, true) << endl;
    //    PrintVector(c);
    cout << SortCheck(c) << endl;
    //    PrintVector(d);
    cout << SortCheck(d) << endl;
}

void RadixSortTest() {
    const int length = 1000000;
    
    vector<int> a;
    vector<long> b;
    vector<long long> c;
    vector<int> d { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11, 6 };
    
    for (int i = 0; i != length; ++i) {
        a.push_back((rand() % 100));
        b.push_back((rand() % 10000));
        c.push_back((rand() % 1000000));
    }
    
    time_t st = clock();
    
    RadixSort(a, 2);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    RadixSort(b, 4);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    st = clock();
    RadixSort(c, 6, true);
    cout << "cost:" << static_cast<double>(clock() - st) / CLOCKS_PER_SEC << endl;
    
    RadixSort(d, 2);
    
    //    PrintVector(a);
    cout << SortCheck(a) << endl;
    //    PrintVector(b);
    cout << SortCheck(b) << endl;
    //    PrintVector(c);
    cout << SortCheck(c, true) << endl;
    //    PrintVector(d);
    cout << SortCheck(d) << endl;
}

void SortTimeTest() {
    const int length = 10000;
    const int times = 100;
    
    vector<vector<int> > a(times, vector<int>());
    
    for (int i = 0; i != times; ++i) {
        for (int j = 0; j != length; ++j) {
            a[i].push_back((rand() % 1000));
        }
    }
    
    srand(unsigned(time(0)));
    
    time_t st = clock();
    for (int i = 0; i != times; ++i) {
//        BubbleSort(a[i]);
//        BubbleSort(a[i], true);
//        BubbleSortImprove(a[i]);
//        BucketSort(a[i], false, 1000);
//        CountingSort(a[i]);
//        HeapSort(a[i]);
//        HeapSort(a[i], true);
//        InsertionSort(a[i]);
//        InsertionSort(a[i], true);
//        InsertionSortIterator(a[i]);
//        MergeSort(a[i]);
//        QuickSort(a[i], 0, a[i].size() - 1);
//        RandomizedQuickSort(a[i], 0, a[i].size() - 1);
//        HoareQuickSort(a[i], 0, a[i].size() - 1);
//        RadixSort(a[i], 7);
//        SelectionSort(a[i]);
//        SelectionSort(a[i], true);
//        ShellSort(a[i]);
        
//        cout << SortCheck(a[i]) << endl;
    }
    
    cout << static_cast<double>(clock() - st) / CLOCKS_PER_SEC / times << endl;
}