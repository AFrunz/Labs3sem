#include <gtest//gtest.h>
#include "traktrisa.h"


TEST(Traktrisa, init_test) {
    traktrisa c(10.);
    double a = c.getA();
    EXPECT_EQ(10., a);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
