#include "class_vector/vector.h"
#include <iostream>

double square(int N, vector* cords){
    if (N <= 2) return 0;
    vector first;
    vector second;
    vector start;
    double s = 0;

    for (int i = 2; i < N; i++){
        if (i == 2){
            start = cords[0];
            first = cords[1] - start;
        }
        else {
            first = second;
        }
        second = cords[i] - start;
        double scalar_mult = first * second;
        double magnitude_first = first.module();
        double magnitude_second = second.module();
        double _sin = sqrt(1 - (scalar_mult / magnitude_first / magnitude_second) *
                (scalar_mult / magnitude_first / magnitude_second));

        s = s + std::abs(magnitude_second * magnitude_first * _sin);
    }
    return s / 2;
}

int main(){
    int N;
    std::cin >> N;
//    Ввод вектора
    vector* vectors = new vector[N];
    for (int i = 0; i < N; i++){
        std::cin >> vectors[i];
    }

    double result = square(N, vectors);
    std::cout << result;

//    Очистка памяти
    delete[] vectors;
    return 0;
}
