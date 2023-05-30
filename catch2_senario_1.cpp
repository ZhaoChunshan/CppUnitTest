//
// Created by zcs on 5/29/23.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <map>
#include "catch.hpp"

using STU_ID_TYPE = unsigned long long;
class StudentInfo{
public:
    std::map<STU_ID_TYPE, std::string> stu_info_;
public:
    StudentInfo() = default;
    ~StudentInfo() = default;
    void addStudent(STU_ID_TYPE id, const std::string & str){
        auto it = stu_info_.find(id);
        if(it == stu_info_.end()){
            stu_info_.insert(std::make_pair(id, str));
        } else {
            it->second = str;
        }
    }
    void removeStudent(STU_ID_TYPE id){
        stu_info_.erase(id);
    }
    bool exists(STU_ID_TYPE id){
        return stu_info_.find(id) != stu_info_.end();
    }
    std::string getStuName(STU_ID_TYPE id){
        auto it = stu_info_.find(id);
        if(it == stu_info_.end()) return "";
        else return it->second;
    }
    unsigned getStuNum(){return stu_info_.size();}
};

TEST_CASE( "Test student information management.", "[student]" ){
    StudentInfo stu;
    // Insert data to stu
    STU_ID_TYPE id = 0;
    unsigned cur_stu_num = 100000;
    std::string cur_name = "A";
    for(int i = 0; i < cur_stu_num; ++i){
        stu.addStudent(id++, cur_name);
        if(cur_name.back() == 'Z'){
            cur_name.push_back('A');
        } else {
            cur_name.back() = (char)(1 + (int)cur_name.back());
        }
    }
    REQUIRE(cur_stu_num == stu.getStuNum());

    SECTION("Test add some new students."){

        std::vector<std::string> names= {"Alice", "Bob", "Carol", "Dave", "Eve"};
        std::vector<STU_ID_TYPE> ids= {1900016633, 1900016627, 1800012811, 1900016637, 1900016623};
        for(int i = 0; i < names.size(); ++i){
            stu.addStudent(ids[i], names[i]);
        }
        for(int i = 0; i < ids.size(); ++i){
            REQUIRE(stu.exists(ids[i]));
            REQUIRE(stu.getStuName(ids[i]) == names[i]);
        }
        REQUIRE(cur_stu_num + names.size() == stu.getStuNum());
    }

    SECTION("Test remove some students."){
        std::vector<STU_ID_TYPE> ids= {0, 1, 2, 3, 4};
        for(STU_ID_TYPE id_ : ids){
            stu.removeStudent(id_);
        }
        for(STU_ID_TYPE id_ : ids){
            REQUIRE(!stu.exists(id_));
        }
        REQUIRE(cur_stu_num - ids.size() == stu.getStuNum());
    }

    SECTION("Test both add and remove."){
        std::vector<STU_ID_TYPE> idss= {0, 1, 2, 3, 4};
        for(STU_ID_TYPE id_ : idss){
            stu.removeStudent(id_);
        }
        REQUIRE(cur_stu_num - idss.size() == stu.getStuNum());
        for(int i = 0; i < 2; ++i){
            stu.addStudent(idss[i], "@stu" + std::to_string(i));
        }
        REQUIRE(cur_stu_num - idss.size() + 2 == stu.getStuNum());
    }
}
