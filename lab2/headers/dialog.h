#ifndef CPP_DIALOG_H
#define CPP_DIALOG_H
#include "traktrisa.h"

namespace dialogSp {
    template <class T>
    void getNum(T &a){
        std::cin >> a;
        while (!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::cout << "Wrong input, repeat" << std::endl;
            std::cin >> a;
        }
    }

    void dialogMenu();
}



#endif //CPP_DIALOG_H
