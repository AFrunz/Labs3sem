#ifndef CPP_PROG1_H
#define CPP_PROG1_H

struct arrayDouble {
    int n;
    int* line;
};

struct matrix {
    int m;
    arrayDouble *lines;
};

matrix* matrixInput();

void matrixFree(matrix * matr);

//double maximum(double* p, int n);

template <class T>
int getNum(T &a){
    std::cin >> a;
    while (!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Wrong input, repeat" << std::endl;
        std::cin >> a;
    }
    return 0;
}





#endif //CPP_PROG1_H
