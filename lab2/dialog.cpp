#include <iostream>
#include "headers/dialog.h"


namespace dialogSp{
    using std::cin, std::cout, std::endl;
    void dialogMenu(){
        std::string msgs[] = {"0. Exit", "1. Get coordinates", "2. Get arc length", "3. Get radius", "4. Get square",
                              "5. Get square of surface", "6. Get volume of surface", "7. Get const of traktrisa"};
        int msgLength = 8;
        int choice = -1;
        double a;
        cout << "Enter const of traktrisa\n";
        getNum(a);
        traktrisa tr(a);
        double angle;

        while (choice != 0){
//        Получение координат
            if (choice == 1) {
                cout << "Enter angle (0; pi)";
               getNum(angle);
                dot res = tr.getCoordinates(angle);
                if (res.x == 0. && res.y == 0.) {
                    cout << "Wrong angle\n";
                } else {
                    cout << "X : " << res.x << " Y : " << res.y << endl;
                }
            }
//        Получение длины дуги
            else if (choice == 2) {
                cout << "Enter angle (0; pi)";
                getNum(angle);
                double res = tr.getArcLength(angle);
                if (res == -1.) {
                    cout << "Wrong angle\n";
                } else {
                    cout << res << endl;
                }
            }
//        Получение радиуса кривизны
            else if (choice == 3) {
                cout << "Enter angle (0; pi)";
                getNum(angle);
                double res = tr.getRadius(angle);
                if (res == -1.) {
                    cout << "Wrong angle\n";
                } else if (res == -2){
                    cout << "Inf" << endl;
                } else {
                    cout << res << endl;
                }
            }
//        Получение площади полоски
            else if (choice == 4) {
                double res = tr.getSquare();
                cout << res << endl;
            }
//        Получение площади поверхности фигуры вращения
            else if (choice == 5) {
                double res = tr.getSquareOfSurface();
                cout << res << endl;
            }
//        Получение объема фигуры вращения
            else if (choice == 6) {
                double res = tr.getVolumeOfSurface();
                cout << res << endl;
            }
            else if (choice == 7){
                cout << tr.getA() << endl;
            }

            for (int i = 0; i < msgLength; i++){
                cout << msgs[i] << endl;
            }
            getNum(choice);
        }

    }

}
