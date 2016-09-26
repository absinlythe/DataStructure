//
//  BinaryTree.hpp
//  BTree
//
//  Created by 郑振宇 on 16/9/24.
//  Copyright © 2016年 郑振宇. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <vector>
#include <iostream>
#include <stack>
#include <queue>

template <typename T> struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <typename T> class BinaryTree {
public:
    BinaryTree() {
        m_pRoot = NULL;
    }
    
    // 从数组构建满二叉树
    BinaryTree(const std::vector<T> &nums) {
        if (nums.empty()) {
            m_pRoot = NULL;
            return;
        }
        
        m_pRoot = new TreeNode<T>(nums[0]);
        _BinaryTreeConstruct(nums, m_pRoot, 0);
    }
    
    ~BinaryTree() {
        if (m_pRoot) {
            _BinaryTreeDestroy(m_pRoot);
            m_pRoot = NULL;
        }
    }
    
    // 中序遍历二叉树
    const std::vector<T> InorderTraversal(const bool recursive = true) const {
        if (!m_pRoot) return std::vector<T>();
        
        if (recursive) {     // 递归
            std::vector<T> traversal;
            _InorderTraversal(traversal, m_pRoot);
            
            return traversal;
        } else {             // 非递归
            return _InorderTraversalNonrecursive();
        }
    }
    
    // 前序遍历二叉树
    const std::vector<T> PreorderTraversal(const bool recursive = true) const {
        if (!m_pRoot) return std::vector<T>();
        
        if (recursive) {     // 递归
            std::vector<T> traversal;
            _PreorderTraversal(traversal, m_pRoot);
            
            return traversal;
        } else {             // 非递归
            return _PreorderTraversalNonrecursive();
        }
    }
    
    // 后序遍历二叉树（递归）
    const std::vector<T> PostorderTraversal(const bool recursive = true) const {
        if (!m_pRoot) return std::vector<T>();
        
        if (recursive) {     // 递归
            std::vector<T> traversal;
            _PostorderTraversal(traversal, m_pRoot);
        
            return traversal;
        } else {             // 非递归
            return _PostorderTraversalNonrecursive();
        }
    }
    
    // 层序遍历二叉树（递归）
    const std::vector<T> LevelOrderTraversal() const;
    
    // 反转树
    void InvertSelf() {
        if (m_pRoot) {
            m_pRoot = _InvertSelf(m_pRoot);
        }
    }
    
    // 高度
    size_t GetHeight() const {
        if (!m_pRoot) return 0;
        
        return _GetHeight(m_pRoot);
    }
    
    // 节点数
    size_t GetNodeNum() const {
        if (!m_pRoot) return 0;
    }
    
    // 叶节点数
    size_t GetLeafNodeNum() const {
        if (!m_pRoot) return 0;
    }
    
protected:
	void _BinaryTreeConstruct(const std::vector<T> &nums, TreeNode<T> *root, size_t index) const;
    
    void _BinaryTreeDestroy(TreeNode<T> *root) const;
    
    // 中序遍历二叉树（递归）
    void _InorderTraversal(std::vector<T> &traversal, TreeNode<T> *root) const;
    
    // 中序遍历二叉树（非递归）
    const std::vector<T> _InorderTraversalNonrecursive() const;
    
    // 前序遍历二叉树（递归）
    void _PreorderTraversal(std::vector<T> &traversal, TreeNode<T> *root) const;
    
    // 前序遍历二叉树（非递归）
    const std::vector<T> _PreorderTraversalNonrecursive() const;
    
    // 后序遍历二叉树（递归）
    void _PostorderTraversal(std::vector<T> &traversal, TreeNode<T> *root) const;
    
    // 后序遍历二叉树（非递归）
    const std::vector<T> _PostorderTraversalNonrecursive() const;
    
    size_t _GetHeight(TreeNode<T> *root) const;
    
    TreeNode<T> * _InvertSelf(TreeNode<T> *root) const;
    
protected:
    TreeNode<T> *m_pRoot;
};

template <typename T>
void BinaryTree<T>::_BinaryTreeConstruct(const std::vector<T> &nums, TreeNode<T> *root, size_t index) const {
    if (!root) return;
    
    auto _index = 2 * index + 1;
    if (_index < nums.size()) {
        root->left = new TreeNode<T>(nums[_index]);
        _BinaryTreeConstruct(nums, root->left, _index);
    }
    
    _index += 1;
    if (_index < nums.size()) {
        root->right = new TreeNode<T>(nums[_index]);
        _BinaryTreeConstruct(nums, root->right, _index);
    }
}

template <typename T>
void BinaryTree<T>::_BinaryTreeDestroy(TreeNode<T> *root) const {
    if (root->left) _BinaryTreeDestroy(root->left);
    if (root->right) _BinaryTreeDestroy(root->right);
    
    delete root;
    root = NULL;
}

template <typename T>
void BinaryTree<T>::_InorderTraversal(std::vector<T> &traversal, TreeNode<T> *root) const {
    if (!root) return;
    
    if (root->left) _InorderTraversal(traversal, root->left);
    traversal.push_back(root->val);
    if (root->right) _InorderTraversal(traversal, root->right);
}

template <typename T>
void BinaryTree<T>::_PreorderTraversal(std::vector<T> &traversal, TreeNode<T> *root) const {
    if (!root) return;
    
    traversal.push_back(root->val);
    if (root->left) _PreorderTraversal(traversal, root->left);
    if (root->right) _PreorderTraversal(traversal, root->right);
}

template <typename T>
const std::vector<T> BinaryTree<T>::LevelOrderTraversal() const {
    if (!m_pRoot) return std::vector<T>();
    
    std::vector<T> traversal;
    std::queue<TreeNode<T> *> _queue;
    _queue.push(m_pRoot);
    
    while(!_queue.empty()) {
        TreeNode<T> *_root = _queue.front();
        _queue.pop();
        
        if (_root) {
            traversal.push_back(_root->val);
            
            if (_root->left) _queue.push(_root->left);
            if (_root->right) _queue.push(_root->right);
        }
    }
    
    return traversal;
}

template <typename T>
void BinaryTree<T>::_PostorderTraversal(std::vector<T> &traversal, TreeNode<T> *root) const {
    if (!root) return;
    
    if (root->left) _PostorderTraversal(traversal, root->left);
    if (root->right) _PostorderTraversal(traversal, root->right);
    traversal.push_back(root->val);
}

template <typename T>
const std::vector<T> BinaryTree<T>::_PreorderTraversalNonrecursive() const {
    if (m_pRoot == NULL) return std::vector<T>();
    
    std::vector<T> traversal;
    std::stack<TreeNode<T> *> _stack;
    
    _stack.push(m_pRoot);
    while (!_stack.empty()) {
        TreeNode<T> *_root = _stack.top();
        _stack.pop();
        
        traversal.push_back(_root->val);
        
        if (_root->right) _stack.push(_root->right);
        if (_root->left) _stack.push(_root->left);
    }
    
    return traversal;
}

template <typename T>
const std::vector<T> BinaryTree<T>::_InorderTraversalNonrecursive() const {
    if (m_pRoot == NULL) return std::vector<T>();
    
    std::vector<T> traversal;
    std::stack<TreeNode<T> *> _stack;
    TreeNode<T> *_root = m_pRoot;
    
    while (!_stack.empty() || _root != NULL) {
        while (_root != NULL) {
            _stack.push(_root);
            _root = _root->left;
        }
        
        if (!_stack.empty()) {
            _root = _stack.top();
            _stack.pop();
            
            traversal.push_back(_root->val);
            
            _root = _root->right;
        }
    }
    
    return traversal;
}

template <typename T>
const std::vector<T> BinaryTree<T>::_PostorderTraversalNonrecursive() const {
    if (m_pRoot == NULL) return std::vector<T>();
    
    std::vector<T> traversal;
    std::stack<std::pair<TreeNode<T> *, bool>> _stack;
    bool visited;
    TreeNode<T> *_root = NULL;
    
    _stack.push(std::make_pair(m_pRoot, false));
    
    while (!_stack.empty()) {
        _root = _stack.top().first;
        visited = _stack.top().second;
        
        // std::cout << (_root ? _root->val : -1) << " " << visited << std::endl;
        
        _stack.pop();
        
        if (_root == NULL)
            continue;
        
        if(visited) {
            traversal.push_back(_root->val);
        } else {
            _stack.push(std::make_pair(_root, true));
            _stack.push(std::make_pair(_root->right, false));
            _stack.push(std::make_pair(_root->left, false));
        }
    }
    
    return traversal;
}

template <typename T>
TreeNode<T> * BinaryTree<T>::_InvertSelf(TreeNode<T> *root) const {
    if (!root || (root->left == NULL && root->right == NULL)) return root;
    
    TreeNode<T> *temp = root->right;
    root->right = _InvertSelf(root->left);
    root->left = _InvertSelf(temp);
    
    return root;
}

template <typename T>
size_t BinaryTree<T>::_GetHeight(TreeNode<T> *root) const {
    if (!root) return 0;
    
    size_t n_left = _GetHeight(root->left);
    size_t n_right = _GetHeight(root->right);
    
    return (n_left > n_right) ? (n_left + 1) : (n_right + 1);
}

#endif /* BinaryTree_hpp */
