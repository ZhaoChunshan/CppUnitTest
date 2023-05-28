//
// Created by zcs on 5/28/23.
//

#define BOOST_TEST_MODULE Sort Test
#include <boost/test/included/unit_test.hpp>

#include <string>
#include "test_algorithm.h"
#include <fstream>


BOOST_AUTO_TEST_CASE(__sort_1)
{
    std::string file_name = "../data.txt";
    std::ifstream infile(file_name);
    int n, m;
    std::vector<int> vec;
    std::vector<int> res;
    infile >> n;
    for(int i = 0; i < n; ++i) {
        infile >> m;
        vec.push_back(m);
    }
    infile >> m;
    for(int i = 0; i < n; ++i){
        infile >> m;
        res.push_back(m);
    }
    quick_sort(vec);
    BOOST_TEST((vec.size() == n && res.size() == n));
    for(int i = 0; i < n; ++i){
        BOOST_TEST(vec[i] == res[i]);
    }
}

