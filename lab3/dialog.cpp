#include "headers/dialog.h"
#include <iostream>
#include "headers/sequence.h"

namespace dialog3{

    void inputMyClass(sequence& q){
        std::cout << "Enter number of numbers and numbers" << std::endl;
        std::cin >> q;
        while (!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::cout << "Wrong input, repeat" << std::endl;
            std::cin >> q;
        }
    }



    void dialogMenu(){
        std::string choices[] = {"0. Exit", "1. Add one el", "2. Frequency Of El", "3. Get first ascending "
                                "or descending sequence ", "4. Unique el number", "5. Get el with index",
                                "6. Get current", "7. Add sequence of el-s"};
//        std::cout << "Max: "<< MAX_OF_VECTOR << std::endl;
        sequence q;
        inputMyClass(q);
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
                std::cout << q[number] << std::endl;
            }
            else if (choice == 6){
                std::cout << q.getCurrent() << std::endl;
            }
            else if (choice == 7){
                sequence c;
                inputMyClass(c);
                sequence res = q + c;
                std::cout << q;
            }

            for (const auto& item : choices){
                std::cout << item << "\n";
            }
            getNum(choice);
        }

    }


}

