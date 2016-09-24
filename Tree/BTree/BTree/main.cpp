//
//  main.cpp
//  BTree
//
//  Created by 郑振宇 on 16/9/24.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#include <iostream>
#include <vector>

#include "BinaryTree.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    BinaryTree<int> bt(a);
    
    vector<int> in = bt.InorderTraversal();
    PrintVector(in);
    in = bt.InorderTraversalNonrecursive();
    PrintVector(in);
    vector<int> pre = bt.PreorderTraversal();
    PrintVector(pre);
    pre = bt.PreorderTraversalNonrecursive();
    PrintVector(pre);
    vector<int> post = bt.PostorderTraversal();
    PrintVector(post);
    post = bt.PostorderTraversalNonrecursive();
    PrintVector(post);
    
    BinaryTree<long> bt2;
    
    return 0;
}
