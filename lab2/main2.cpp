#include "traktrisa.h"
#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

int main(){
    std::string msgs[] = {"0. Exit", "1. Get coordinates", "2. Get arc length", "3. Get radius", "4. Get square",
                          "5. Get square of surface", "6. Get volume of surface"};
    int msgLength = 7;
    int choice = -1;
    double a;
    cout << "Enter const of traktrisa\n";
    cin >> a;
    traktrisa tr(a);
    double angle;
    while (choice != 0){
//        ПОЛУЧЕНИЕ КООРДИНАТ
        if (choice == 1) {
            cout << "Enter angle (0; pi)";
            cin >> angle;
            dot res = tr.getCoordinates(angle);
            if (res.x == 0. && res.y == 0.) {
                cout << "Wrong angle\n";
            } else {
                cout << "X : " << res.x << " Y : " << res.y << endl;
            }
        }
//        ПОЛУЧЕНИЕ ДЛИНЫ ДУГИ
        else if (choice == 2) {
            cout << "Enter angle (0; pi)";
            cin >> angle;
            double res = tr.getArcLength(angle);
            if (res == -1.) {
                cout << "Wrong angle\n";
            } else {
                cout << res << endl;
            }
        }
//        ПОЛУЧЕНИЕ РАДИУСА КРИВИЗНЫ
        else if (choice == 3) {
            cout << "Enter angle (0; pi)";
            cin >> angle;
            double res = tr.getRadius(angle);
            if (res == -1.) {
                cout << "Wrong angle\n";
            } else {
                cout << res << endl;
            }
        }
//        ПОЛУЧЕНИЕ ПЛОЩАДИ ПЛОСКИ
        else if (choice == 4) {
            double res = tr.getSquare();
            cout << res << endl;
        }
//        ПОЛУЧЕНИЕ ПЛОЩАДИ ПОВЕРХНОСТИ ФИГУРЫ ВРАЩЕНИЯ
        else if (choice == 5) {
            double res = tr.getSquareOfSurface();
            cout << res << endl;
        }
//        ПОЛУЧЕНИЕ ОБЪЕМА ФИГУРЫ ВРАЩЕНИЯ
        else if (choice == 6) {
            double res = tr.getVolumeOfSurface();
            cout << res << endl;
        }


        for (int i = 0; i < msgLength; i++){
            cout << msgs[i] << endl;
        }
        cin >> choice;
    }

    return 0;
}