#include <gtest//gtest.h>
#include "headers/sequence.h"

TEST(Construct, without_params){
    sequence a;
    EXPECT_EQ(a.getCurrent(), 0);
}

TEST(Construct, one_parametr){
    sequence a(12);
    EXPECT_EQ(a.getCurrent(), 1);
    EXPECT_EQ(a[0], 12);
}

TEST(Construct, many_parametrs){
    int test_n[] = {2, 3, 5, 7};
    sequence a(4, test_n);
    EXPECT_EQ(a.getCurrent(), 4);
    EXPECT_EQ(a[0], 2);
    EXPECT_EQ(a[1], 3);
    EXPECT_EQ(a[2], 5);
    EXPECT_EQ(a[3], 7);
}

TEST(Construct, copy){
    int test_n[] = {3, 4};
    sequence a(2, test_n);
    sequence b(a);
    EXPECT_EQ(b.getCurrent(), 2);
    EXPECT_EQ(b[0], 3);
    EXPECT_EQ(b[1], 4);
}

TEST(merge, full){
    int test_a[] = {1, 2, 3, 4};
    int test_b[] = {8, 9};
    sequence a(4, test_a);
    sequence b(2, test_b);
    EXPECT_ANY_THROW(a + b);
}

TEST(merge, normal){
    sequence a(1);
    int test_b[] = {8, 9};
    sequence b(2, test_b);
    sequence c = a + b;
    EXPECT_EQ(c.getCurrent(), 3);
    EXPECT_EQ(c[0], 1);
    EXPECT_EQ(c[1], 8);
    EXPECT_EQ(c[2], 9);
}

TEST(add, full){
    int test_b[] = {8, 9, 10, 11, 12};
    sequence b(5, test_b);
    EXPECT_ANY_THROW(b += 144);
}

TEST(add, normal){
    int test_b[] = {8, 9, 10, 11};
    sequence b(4, test_b);
    b += 133;
    EXPECT_EQ(b.getCurrent(), 5);
    EXPECT_EQ(b[0], 8);
    EXPECT_EQ(b[1], 9);
    EXPECT_EQ(b[2], 10);
    EXPECT_EQ(b[3], 11);
    EXPECT_EQ(b[4], 133);
}

TEST(frequency, normal){
    int test_b[] = {8, 8, 10, 10, 10};
    sequence b(5, test_b);
    EXPECT_EQ(b.frequencyOfEl(8), 2);
    EXPECT_EQ(b.frequencyOfEl(10), 3);
    EXPECT_EQ(b.frequencyOfEl(12), 0);
}

//TEST(sort, normal_1){
//    sequence b(5, 10, 3, 1, 12, 14);
//    EXPECT_EQ(b.groupNumber(), 5);
//};
//
//TEST(sort, normal_2){
//    sequence b(5, 10, 10, 10, 10, 11);
//    EXPECT_EQ(b.groupNumber(), 2);
//};
//
//TEST(sort, normal_3){
//    sequence b(5 );
//    EXPECT_EQ(b.groupNumber(), 1);
//};

TEST(subSequence, all_up){
    int test_b[] = {1, 2, 3, 4, 5};
    sequence b(5, test_b);
    sequence c = b.subSequence();
    EXPECT_EQ(c.getCurrent(), 5);
    EXPECT_EQ(c[0], 1);
    EXPECT_EQ(c[1], 2);
    EXPECT_EQ(c[2], 3);
    EXPECT_EQ(c[3], 4);
    EXPECT_EQ(c[4], 5);
}

TEST(subSequence, all_down){
    int test_b[] = {5, 4, 3, 2, 1};
    sequence b(5, test_b);
    sequence c = b.subSequence();
    EXPECT_EQ(c.getCurrent(), 5);
    EXPECT_EQ(c[0], 5);
    EXPECT_EQ(c[1], 4);
    EXPECT_EQ(c[2], 3);
    EXPECT_EQ(c[3], 2);
    EXPECT_EQ(c[4], 1);
}

TEST(subSequence, normal){
    int test_b[] = {1, 4, 3, 2, 1};
    sequence b(5, test_b);
    sequence c = b.subSequence();
    EXPECT_EQ(c.getCurrent(), 4);
    EXPECT_EQ(c[0], 4);
    EXPECT_EQ(c[1], 3);
    EXPECT_EQ(c[2], 2);
    EXPECT_EQ(c[3], 1);
}

TEST(subSequence, normal_2){
    int test_b[] = {1, 4, 3, 2, 6};
    sequence b(5, test_b);
    sequence c = b.subSequence();
    EXPECT_EQ(c.getCurrent(), 3);
    EXPECT_EQ(c[0], 4);
    EXPECT_EQ(c[1], 3);
    EXPECT_EQ(c[2], 2);
}

TEST(subSequence, void_){
    int test_b[] = {1, 4, 1, 4, 1};
    sequence b(5, test_b);
    sequence c = b.subSequence();
    EXPECT_EQ(c.getCurrent(), 0);
}


int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
