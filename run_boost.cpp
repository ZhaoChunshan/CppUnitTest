//
// Created by zcs on 5/28/23.
//

#define BOOST_TEST_MODULE  OurTest
#include <boost/test/included/unit_test.hpp>

#include <string>
#include "test_algorithm.h"
#include <fstream>

#define OUR_TEST_CASE_NUM 10

BOOST_AUTO_TEST_CASE(__sort__)
{
    int T = OUR_TEST_CASE_NUM;
    for(int t = 0; t < T; ++t){
        std::string input_file = "../data/sort" + std::to_string(t + 1) + ".in";
        std::string ground_truth = "../data/sort"+ std::to_string(t + 1) +".ans";
        std::ifstream infile(input_file);
        std::ifstream outfile(ground_truth);
        int n, m;
        int *a = new int[1000010], * res = new int[1000010];
        infile >> n;
        for(int i = 0; i < n; ++i) {
            infile >> a[i];
        }
        outfile >> m;
        for(int i = 0; i < n; ++i){
            outfile >> res[i];
        }
        std::sort(a,a+n);
        for(int i = 0; i < n; ++i){
            BOOST_TEST(a[i] == res[i]);
        }
        infile.close();
        outfile.close();
    }
}


BOOST_AUTO_TEST_CASE(__hash__)
{
int T = OUR_TEST_CASE_NUM;
for(int t = 0; t < T; ++t){
std::string input_file = "../data/hash" + std::to_string(t + 1) + ".in";
std::string ground_truth = "../data/hash"+ std::to_string(t + 1) +".ans";
std::ifstream infile(input_file);
std::ifstream outfile(ground_truth);
int n, m;
infile >> n >> m;
std::map<int, int> mmap;
for(int i = 0; i < n; ++i) {
int k, v;
infile >> k >> v;
auto it = mmap.find(k);
if(it != mmap.end())
it->second = v;
else
mmap.insert(std::make_pair(k,v));
}
for(int i = 0; i < m; ++i){
int k , v;
infile >> k;
outfile >> v;
int myans = -1;

if(mmap.find(k) != mmap.end())myans = mmap.at(k);
BOOST_TEST(myans == v);
}
infile.close();
outfile.close();
}
}

BOOST_AUTO_TEST_CASE(__fibonacci__)  {
    int T = OUR_TEST_CASE_NUM;
    for(int t = 0; t < T; ++t){
        std::string input_file = "../data/feb" + std::to_string(t + 1) + ".in";
        std::string ground_truth = "../data/feb"+ std::to_string(t + 1) +".ans";
        std::ifstream infile(input_file);
        std::ifstream outfile(ground_truth);
        int n;
        long long fb;
        infile >> n ;
        outfile >> fb;
        BOOST_TEST(fibonacci(n) == fb);
        infile.close();
        outfile.close();
    }
}

BOOST_AUTO_TEST_CASE(__matrix__) {
    int T = OUR_TEST_CASE_NUM;
    for(int t = 0; t < T; ++t){
        std::string input_file = "../data/matrix" + std::to_string(t + 1) + ".in";
        std::string ground_truth = "../data/matrix"+ std::to_string(t + 1) +".ans";
        std::ifstream infile(input_file);
        std::ifstream outfile(ground_truth);
        long long n;
        infile >> n ;
        std::vector<std::vector<long long>> mat1, mat2;
        for(long long i = 0; i < n; ++i){
        mat1.emplace_back();
        for(long long j = 0;j < n; ++j){
        long long v;
        infile >> v;
        mat1.back().push_back(v);
        }
    }
    for(int i = 0; i < n; ++i){
        mat2.emplace_back();
        for(int j = 0;j < n; ++j){
            long long v;
            infile >> v;
            mat2.back().push_back(v);
        }
    }
    auto mat_res = matrix_mul(mat1, mat2);
    mat1.clear();
    for(int i = 0; i < n; ++i){
    mat1.emplace_back();
    for(int j = 0;j < n; ++j){
    long long v;
    outfile >> v;
    mat1.back().push_back(v);
    }
    }
    for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)
    BOOST_TEST(mat1[i][j] == mat_res[i][j]);
}
infile.close();
outfile.close();
}
}


BOOST_AUTO_TEST_CASE( __list__) {
int T = OUR_TEST_CASE_NUM;
for(int t = 0; t < T; ++t){
std::string input_file = "../data/reserve" + std::to_string(t + 1) + ".in";
std::string ground_truth = "../data/reserve"+ std::to_string(t + 1) +".ans";
std::ifstream infile(input_file);
std::ifstream outfile(ground_truth);
int n;
infile >> n ;
ListNode * l = new ListNode;
ListNode * head = l , *tail = l;
for(int i =0 ;i < n; ++i){
tail->next_ = new ListNode;
infile >>  tail->next_->data_;
tail->next_->next_ = nullptr;
tail = tail->next_;
}
l = head->next_;
head->next_ = nullptr;
reverse_list(l);
head = l;
for(int i = 0; i  <n; ++i){
int v;
outfile >> v;
BOOST_TEST(head->data_ == v);
head = head->next_;
}
infile.close();
outfile.close();
}
}


BOOST_AUTO_TEST_CASE( __tree__) {
int T = OUR_TEST_CASE_NUM;
    for(int t = 0; t < T; ++t){
        std::string input_file = "../data/binary" + std::to_string(t + 1) + ".in";
        std::string ground_truth = "../data/binary"+ std::to_string(t + 1) +".ans";
        std::ifstream infile(input_file);
        std::ifstream outfile(ground_truth);

        int v, n;
        infile >> n;
        std::vector<int> vec ,res;
        for(int i = 0; i < n; ++i){
            infile >> v;
            vec.push_back(v);
        }
        vec = traverse_tree(vec);
        outfile >> n;
        for(int i = 0; i <n; ++i){
            outfile >> v;
            res.push_back(v);
        }
        for(int i = 0; i < n; ++i){
            BOOST_TEST(res[i] == vec[i]);
        }
        infile.close();
        outfile.close();
    }
}
