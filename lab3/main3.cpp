#include "headers/dialog.h"
#include <iostream>
//sstream или тп для тестирования вывода

int main(){
    try {
        dialog3::dialogMenu();
    }
    catch (std::runtime_error &c){
        std::cout << c.what();
    }
    return 0;
}

