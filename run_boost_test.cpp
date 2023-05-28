//
// Created by zcs on 5/28/23.
//

#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
using namespace boost::unit_test;

#include <string>
#include "test_algorithm.h"
#include <iostream>
#include <fstream>

void test_sort( const std::string & file_name )
{
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


