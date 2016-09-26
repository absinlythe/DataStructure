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
    vector<int> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    
    BinaryTree<int> bt(a);
    
    vector<int> in = bt.InorderTraversal();
    PrintVector(in);
    in = bt.InorderTraversal(false);
    PrintVector(in);
    vector<int> pre = bt.PreorderTraversal();
    PrintVector(pre);
    pre = bt.PreorderTraversal(false);
    PrintVector(pre);
    vector<int> post = bt.PostorderTraversal();
    PrintVector(post);
    post = bt.PostorderTraversal(false);
    PrintVector(post);
    vector<int> level = bt.LevelOrderTraversal();
    PrintVector(level);
    
    bt.InvertSelf();
    in = bt.InorderTraversal(false);
    PrintVector(in);
    
    cout << bt.GetHeight() << endl;
    
    return 0;
}
