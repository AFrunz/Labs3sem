#include <iostream>

struct arrayDouble {
    int n;
    double* line;
};

struct matrix {
    int m;
    arrayDouble *lines;
};

matrix* matrixInput();
void matrixFree(matrix * matr);
double maximum(double* p, int n);


matrix* matrixInput(){
    auto *matr = new matrix;
    std::cout << "Enter number of lines" << std::endl;
    std::cin >> matr->m;
    matr->lines = new arrayDouble [matr->m];
    arrayDouble* bufLines = matr->lines;
    for (int i = 0; i < matr->m; i++, bufLines++){
        std::cout << "Enter number in " << i + 1 << " line" << std::endl;
        std::cin >> bufLines->n;
        bufLines->line = new double [bufLines->n];
        std::cout << "Enter numbers" << std::endl;
        for (int j = 0; j < bufLines->n; j++){
            std::cin >> bufLines->line[j];
        }
    }
    return matr;
}


void matrixFree(matrix * matr){
    for (int i = 0; i < matr->m; i++){
        delete [] matr->lines[i].line;
    }
    delete [] matr->lines;
    delete matr;
}


double maximum(double* p, int n){
    double max = *p;
    p++;
    for (int i = 1; i < n; i++, p++){
        if (*p > max){
            max = *p;
        }
    }
    return max;
}


int main() {
    matrix* matr = matrixInput();
    double min;
    double buf;
    min = maximum(matr->lines[0].line, matr->lines[0].n);
    for (int i = 1; i < matr->m; i++){
        buf = maximum(matr->lines[i].line, matr->lines[i].n);
        if (buf < min){
            min = buf;
        }
    }
    std::cout << min;
    matrixFree(matr);
    return 0;
}
