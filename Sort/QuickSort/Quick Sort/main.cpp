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
#include "quick_sort.hpp"

using namespace::std;

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
    cout << SortCheck(a) << endl;
    PrintVector(b);
    cout << SortCheck(b) << endl;
    PrintVector(c);
    cout << SortCheck(c) << endl;
    printf("\n");
    
    return 0;
}
