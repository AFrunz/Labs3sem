#ifndef CPP_TRAKTRISA_H
#define CPP_TRAKTRISA_H

#define INF 1.7976931348623158E+308


struct dot {
    double x;
    double y;
};


class [[maybe_unused]] traktrisa {

private:
    double a; // Константа трактрисы
public:
    // Constructor
    explicit traktrisa(double a0) {a = a0;}
    traktrisa() {a = 1.;}

//    // Destructor
//    ~traktrisa() = default;
//
//    // Assignment constructor
//    traktrisa(const traktrisa& tr){
//        a = tr.a;
//    }


    //    Получение a
    double getA() const;
    void setA(double a0) {a = a0;}
    //    Площадь, ограниченная трактрисой и ее асимптотой
    double getSquare() const;
    //   Радиус кривизны
    double getRadius(double angle) const;
    // Координаты точки от угла поворота
    dot getCoordinates(double angle) const;
    //  Длина дуги от точки (0, a)
    double getArcLength(double angle) const;
    // Площадь поверхности тела вращения
    double getSquareOfSurface() const;
    // Объем тела вращения
    double getVolumeOfSurface() const;
};



#endif //CPP_TRAKTRISA_H
