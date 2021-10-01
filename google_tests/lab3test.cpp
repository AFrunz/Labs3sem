#include <gtest//gtest.h>
#include "headers/sequence.h"
#include <stdio.h>

TEST(Construct, without_params){
    sequence a;
    EXPECT_EQ(a.getCurrent(), 0);
}

TEST(Construct, one_parametr){
    sequence a(12);
    EXPECT_EQ(a.getCurrent(), 1);
    EXPECT_EQ(a.getElementWithIndex(0), 12);
}

TEST(Construct, many_parametrs){
    sequence a(4, 2, 3, 5, 7);
    EXPECT_EQ(a.getCurrent(), 4);
    EXPECT_EQ(a.getElementWithIndex(0), 2);
    EXPECT_EQ(a.getElementWithIndex(1), 3);
    EXPECT_EQ(a.getElementWithIndex(2), 5);
    EXPECT_EQ(a.getElementWithIndex(3), 7);
};

TEST(Construct, copy){
    sequence a(2, 3, 4);
    sequence b(a);
    EXPECT_EQ(b.getCurrent(), 2);
    EXPECT_EQ(b.getElementWithIndex(0), 3);
    EXPECT_EQ(b.getElementWithIndex(1), 4);
}

TEST(merge, full){
    sequence a(4, 1, 2, 3, 4);
    sequence b(2, 8, 9);
    EXPECT_ANY_THROW(a.merge(b));
}

TEST(merge, normal){
    sequence a(1);
    sequence b(2, 8, 9);
    sequence c = a.merge(b);
    EXPECT_EQ(c.getCurrent(), 3);
    EXPECT_EQ(c.getElementWithIndex(0), 1);
    EXPECT_EQ(c.getElementWithIndex(1), 8);
    EXPECT_EQ(c.getElementWithIndex(2), 9);
}

TEST(add, full){
    sequence b(5, 8, 9, 10, 11, 12);
    EXPECT_ANY_THROW(b.add(144));
};

TEST(add, normal){
    sequence b(4, 8, 9, 10, 11);
    b.add(133);
    EXPECT_EQ(b.getCurrent(), 5);
    EXPECT_EQ(b.getElementWithIndex(0), 8);
    EXPECT_EQ(b.getElementWithIndex(1), 9);
    EXPECT_EQ(b.getElementWithIndex(2), 10);
    EXPECT_EQ(b.getElementWithIndex(3), 11);
    EXPECT_EQ(b.getElementWithIndex(4), 133);
};

TEST(frequency, normal){
    sequence b(5, 8, 8, 10, 10, 10);
    EXPECT_EQ(b.frequencyOfEl(8), 2);
    EXPECT_EQ(b.frequencyOfEl(10), 3);
    EXPECT_EQ(b.frequencyOfEl(12), 0);
}

TEST(sort, normal_1){
    sequence b(5, 10, 3, 1, 12, 14);
    EXPECT_EQ(b.groupNumber(), 5);
};

TEST(sort, normal_2){
    sequence b(5, 10, 10, 10, 10, 11);
    EXPECT_EQ(b.groupNumber(), 2);
};

TEST(sort, normal_3){
    sequence b(5 );
    EXPECT_EQ(b.groupNumber(), 1);
};




int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
