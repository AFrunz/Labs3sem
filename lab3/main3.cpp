#include "headers/dialog.h"
#include <iostream>


int main(){
    try {
        dialog3::dialogMenu();
    }
    catch (std::runtime_error &c){
        std::cout << c.what();
    }
    return 0;
}

