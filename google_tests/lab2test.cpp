#include <gtest//gtest.h>
#include "headers/traktrisa.h"
#include <cmath>


//3) Вернуть координаты точки принадлежащей трактрисе в декартовой системе координат от угла поворота (0;π) луча PM c положительным направлением оси абсцисс.
//3 test
// Угол меньше 0
TEST(getCoord, negativeNum) {
    traktrisa tr(12.);
    dot res = tr.getCoordinates(-1.);
    EXPECT_EQ(0., res.x);
    EXPECT_EQ(0., res.y);
}
// Угол больше pi
TEST(getCoord, morePiNum) {
    traktrisa tr(12.);
    dot res = tr.getCoordinates(3.15);
    EXPECT_EQ(0., res.x);
    EXPECT_EQ(0., res.y);
}
// Нормальный угол
TEST(getCoord, normalSit) {
    traktrisa tr(12.);
    dot res = tr.getCoordinates(M_PI / 2.);
    EXPECT_EQ(0, (int)res.x);
    EXPECT_EQ(12., res.y);
}
//4) Вернуть длину дуги от угла поворота (0;π) луча PM c положительным направлением оси абсцисс.
// 3 test

TEST(getArcLen, negativeNum) {
    traktrisa tr(12.);
    double res = tr.getArcLength(-1.);
    EXPECT_EQ(-1., res);
}

TEST(getArcLen, morePiNum) {
    traktrisa tr(12.);
    double res = tr.getArcLength(M_PI);
    EXPECT_EQ(-1., res);
}

TEST(getArcLen, inf) {
    traktrisa tr(12.);
    double res = tr.getArcLength(M_PI / 2.);
    EXPECT_EQ(0, res);
}

TEST(getArcLen, normalNum) {
    traktrisa tr(12.);
    double res = tr.getArcLength(M_PI / 4.);
    EXPECT_EQ(4.15888, res);
}

//5) Вернуть радиус кривизны трактрисы от поворота (0;π) луча PM c положительным направлением оси абсцисс.
// 3 test
//6) Вернуть площадь бесконечной полосы заключенной между трактрисой и ее асимптотой.
// 1 test
//7) Вернуть поверхность тела вращения трактрисы относительно ее асимптоты.
// 1 test
//8) Вернуть объем тела вращения трактрисы относительно ее асимптоты.
// 1 test




TEST(Traktrisa, init_test) {
    traktrisa c(10.);
    double a = c.getA();
    EXPECT_EQ(10., a);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
