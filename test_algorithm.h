//
// Created by zcs on 5/28/23.
//

#ifndef CPPUNITTEST_TEST_ALGORITHM_H
#define CPPUNITTEST_TEST_ALGORITHM_H

#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

struct ListNode{
    int data_;
    ListNode * next_;
    ListNode():data_(0), next_(nullptr){}
    ~ListNode(){
        if(next_ != nullptr)
            delete next_;
    }
};

struct TreeNode{
    int data_;
    TreeNode *left_, *right_;
    TreeNode():data_(0), left_(nullptr), right_(nullptr){}
    ~TreeNode(){
        if(left_!= nullptr) delete left_;
        if(right_!= nullptr) delete right_;
    }
};

// Algorithm1: Sort
void quick_sort(std::vector<int> & vec){
    std::sort(vec.begin(), vec.end());
}

// Algorithm2: Hash Map
int search_hash_map(const std::unordered_map<int,int> & m, int k){
    if(m.find(k) == m.end())
        return -1;
    return m.at(k);
}

// Algorithm3: Fibonacci
 long long fibonacci(int n){
    //f[0] = 0,f[1] = 1
long long x = 0, y = 1, z = 0;
    if(n <= 1) return n;
    for(int i = 2; i <= n; ++i){
        z = x + y;
        x = y;
        y = z;
    }
    return y;
}

// Algorithm4: Matrix Product
std::vector<std::vector<long long>> matrix_mul(const std::vector<std::vector<long long>> & mat1, const std::vector<std::vector<long long>> & mat2){
    int m = mat1.size(), n = mat1[0].size(), p = mat2[0].size();
    assert(n = mat2.size());
    std::vector<std::vector<long long>> res;
    res.resize(m);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < p; ++j){
            long long sum = 0;
            for(int k = 0; k < n; ++k)
                sum += mat1[i][k] * mat2[k][j];
            res[i].push_back(sum);
        }
    }
    return res;
}

// Algorithm5: Reverse List
void reverse_list(ListNode * & lst){
    if(lst == nullptr) return;

    ListNode * head = lst;
    ListNode * next = head->next_;
    head->next_ = nullptr;
    while(next != nullptr){
        ListNode * tmp = next;
        next = next->next_;
        tmp->next_ = head;
        head = tmp;
    }
    lst = head;
}

// Algorithm6: Traverse Binary Search Tree
std::vector<int> traverse_tree(const std::vector<int> & vec){
    std::vector<int> res;
    std::multiset<int> tree;
    for(int v : vec) tree.insert(v);
    for(int v : tree) res.push_back(v);
    return res;
}


#endif //CPPUNITTEST_TEST_ALGORITHM_H
