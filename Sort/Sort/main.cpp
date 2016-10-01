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
#include "test.hpp"

using namespace::std;

int main(int argc, const char * argv[]) {
    srand(unsigned(time(0)));
    
//    BucketSortTest();
    
    QuickSortTest();
    
//    InsertSortTest();
    
//    HeapSortTest();
    
//    SelectionSortTest();
    
#ifdef _MSC_VER
	system("pause");
#endif // _MSC_VER

    return 0;
}