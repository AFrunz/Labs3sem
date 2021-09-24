#include "headers/traktrisa.h"
#include <cmath>
// explict

double traktrisa::getA() const{
    return this->a;
}


//    Площадь, ограниченная трактрисой и ее асимптотой
double traktrisa::getSquare() const{
    double s = M_PI * (this->a) * (this->a) / 2.;
    return s;
}


//   Радиус кривизны
double traktrisa::getRadius(double angle) const{
    if ((angle <= 0.) || (angle >= M_PI)) {
        return -1.;
    }
    if (angle == (M_PI / 2.)) {
        return -2.;
    }
    return (this->a) / std::tan(angle);
}


// Координаты точки от угла поворота
dot traktrisa::getCoordinates(double angle) const{
    if ((angle <= 0.) || (angle >= M_PI)) {
        dot result{0., 0.};
        return result;
    }
    dot result{};
    result.x =  -(this->a) * (log(tan(angle / 2.)) + cos(angle));
    result.y = (this->a) * sin(angle);
    return result;
}


//  Длина дуги от точки (0, a)
double traktrisa::getArcLength(double angle) const{
    if ((angle <= 0.) || (angle >= M_PI)) {
        return -1.;
    }
    return -(this->a) * log(sin(angle));
}


// Площадь поверхности тела вращения
double traktrisa::getSquareOfSurface() const{
    return 2. * M_PI * (this->a) * (this->a);
}


// Объем тела вращения
double traktrisa::getVolumeOfSurface() const{
    return M_PI * (this->a) * (this->a) * (this->a) / 3.;
}
