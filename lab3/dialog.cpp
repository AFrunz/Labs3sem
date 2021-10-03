#include "headers/dialog.h"
#include <iostream>
#include "headers/sequence.h"

namespace dialog3{

    void dialogMenu(){
        std::string choices[] = {"0. Exit", "1. Add one el", "2. Frequency Of El", "3. Get first ascending "
                                "or descending sequence ", "4. Unique el number", "5. Get el with index",
                                "6. Get current", "7. Add sequence of el-s"};
        std::cout << "Max: "<< N << std::endl;
        sequence q;
        std::cin >> q;
        int choice = -1;
        int number;
        while (choice != 0){
            if (choice == 1){
                std::cout << "Enter number\n";
                getNum(number);
                q += number;
                std::cout << q;
            }
            else if (choice == 2){
                std::cout << "Enter number\n";
                getNum(number);
                std::cout << q.frequencyOfEl(number) << std::endl;
            }
            else if (choice == 3){
                std::cout << q.subSequence();
            }
            else if (choice == 4){
                std::cout << q.groupNumber();
            }
            else if (choice == 5){
                std::cout << "Enter index\n";
                getNum(number);
                std::cout << q.getElementWithIndex(number) << std::endl;
            }
            else if (choice == 6){
                std::cout << q.getCurrent() << std::endl;
            }
            else if (choice == 7){
                sequence c;
                std::cin >> c;
                sequence res = q + c;
                std::cout << q;
            }

            for (int i = 0; i < 8; i++){
                std::cout << choices[i] << "\n";
            }
            getNum(choice);
        }












    }


}

