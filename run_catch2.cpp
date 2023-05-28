//
// Created by zcs on 5/28/23.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "test_algorithm.h"
#define OUR_TEST_CASE_NUM 10

TEST_CASE( "SortTest", "[sort]" ) {
    int t = OUR_TEST_CASE_NUM;
    for(int i = 0; i < t; ++i){
        std::string input_file = "../data/sort" + std::to_string(i + 1) + ".in";
        std::string ground_truth = "../data/sort"+ std::to_string(i + 1) +".ans";
        std::ifstream infile(input_file);
        std::ifstream outfile(ground_truth);
        int n, m;
        std::vector<int> vec;
        std::vector<int> res;
        infile >> n;
        for(int i = 0; i < n; ++i) {
            infile >> m;
            vec.push_back(m);
        }
        outfile >> m;
        for(int i = 0; i < n; ++i){
            outfile >> m;
            res.push_back(m);
        }
        quick_sort(vec);
        REQUIRE((vec.size() == n && res.size() == n));
        for(int i = 0; i < n; ++i){
            REQUIRE(vec[i] == res[i]);
        }
    }
}


TEST_CASE( "HashTest", "[hash]" ) {
    int t = OUR_TEST_CASE_NUM;
    for(int i = 0; i < t; ++i){
        std::string input_file = "../data/hash" + std::to_string(i + 1) + ".in";
        std::string ground_truth = "../data/sort"+ std::to_string(i + 1) +".ans";
        std::ifstream infile(input_file);
        std::ifstream outfile(ground_truth);
        int n, m;
        std::vector<int> vec;
        std::vector<int> res;
        infile >> n;
        for(int i = 0; i < n; ++i) {
            infile >> m;
            vec.push_back(m);
        }
        outfile >> m;
        for(int i = 0; i < n; ++i){
            outfile >> m;
            res.push_back(m);
        }
        quick_sort(vec);
        REQUIRE((vec.size() == n && res.size() == n));
        for(int i = 0; i < n; ++i){
            REQUIRE(vec[i] == res[i]);
        }
    }
}

