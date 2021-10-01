#include "headers/traktrisa.h"
#include <cmath>
#include <stdexcept>
// explict

double traktrisa::getA() const{
    return this->a;
}


//    �������, ������������ ���������� � �� ����������
double traktrisa::getSquare() const{
    double s = M_PI * (this->a) * (this->a) / 2.;
    return s;
}


//   ������ ��������
double traktrisa::getRadius(double angle) const{
    if ((angle <= 0.) || (angle >= M_PI)) {
        throw std::runtime_error("Wrong angle");
    }
//    if (angle == (M_PI / 2.)) {
//        return INF;
//    }
    return std::abs((this->a) / std::tan(angle));
}


// ���������� ����� �� ���� ��������
dot traktrisa::getCoordinates(double angle) const{
    // ����������
    if ((angle <= 0.) || (angle >= M_PI)) {
        throw  std::runtime_error("Wrong angle");
    }
    dot result{};
    result.x =  -(this->a) * (log(tan(angle / 2.)) + cos(angle));
    result.y = (this->a) * sin(angle);
    return result;
}


//  ����� ���� �� ����� (0, a)
double traktrisa::getArcLength(double angle) const{
    // ����������
    if ((angle <= 0.) || (angle >= M_PI)) {
        throw std::runtime_error("Wrong angle");
    }
    return std::abs(-(this->a) * log(sin(angle)));
}


// ������� ����������� ���� ��������
double traktrisa::getSquareOfSurface() const{
    return 2. * M_PI * (this->a) * (this->a);
}


// ����� ���� ��������
double traktrisa::getVolumeOfSurface() const{
    return std::abs(M_PI * (this->a) * (this->a) * (this->a) / 3.);
}
