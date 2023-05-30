//
// Created by zcs on 5/28/23.
//

#include "googletest/googletest/include/gtest/gtest.h"
#include <vector>

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


class StudentInfoTest : public ::testing::Test {
protected:
    void SetUp() override {
        stu.reset(new StudentInfo());

    }
    void TearDown() override { stu.reset(); }
    std::unique_ptr<StudentInfo> stu;
};

TEST_F(StudentInfoTest, addTest) {
    // Setup: Insert data to stu
    STU_ID_TYPE id = 0;
    unsigned cur_stu_num = 100000;
    std::string cur_name = "A";
    for(int i = 0; i < cur_stu_num; ++i){
        stu->addStudent(id++, cur_name);
        if(cur_name.back() == 'Z'){
            cur_name.push_back('A');
        } else {
            cur_name.back() = (char)(1 + (int)cur_name.back());
        }
    }

    // SECTION1: Add Student
    cur_stu_num = stu->getStuNum();
    std::vector<std::string> names= {"Alice", "Bob", "Carol", "Dave", "Eve"};
    std::vector<STU_ID_TYPE> ids= {1900016633, 1900016627, 1800012811, 1900016637, 1900016623};
    for(int i = 0; i < names.size(); ++i){
        stu->addStudent(ids[i], names[i]);
    }
    for(int i = 0; i < ids.size(); ++i){
        EXPECT_TRUE(stu->exists(ids[i]));
        EXPECT_EQ(stu->getStuName(ids[i]), names[i]);
    }
    EXPECT_EQ(cur_stu_num + names.size(), stu->getStuNum());

    // SECTION2: del Student
    cur_stu_num = stu->getStuNum();
    std::vector<STU_ID_TYPE> idsss= {0, 1, 2, 3, 4};

    for(STU_ID_TYPE id_ : idsss){
        stu->removeStudent(id_);
    }
    for(STU_ID_TYPE id_ : idsss){
        EXPECT_FALSE(stu->exists(id_));
    }
    EXPECT_EQ(cur_stu_num - idsss.size(), stu->getStuNum());

    //SECTION3: add && del student.
    cur_stu_num = stu->getStuNum();
    std::vector<STU_ID_TYPE> idss= {5, 6, 7, 8, 9};
    for(STU_ID_TYPE id_ : idss){
        stu->removeStudent(id_);
    }
    EXPECT_EQ(cur_stu_num - idss.size(), stu->getStuNum());
    for(int i = 0; i < 2; ++i){
        stu->addStudent(idss[i], "@stu" + std::to_string(i));
    }
    EXPECT_EQ(cur_stu_num - idss.size() + 2 , stu->getStuNum());
}