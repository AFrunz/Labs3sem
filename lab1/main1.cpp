#include <iostream>
#include "prog1.h"
#include "binaryTree.h"

//int getNum(int& a){
//    std::cin >> a;
//    if (!std::cin.good()) return -1;        // Обнаружена ошибка ввода или конец файла
//    return 1;
//}
//
//inline int getNum(double& a){
//    std::cin >> a;
//    if (!std::cin.good()) return -1;
//    return 1;
//
//}

using std::cin;
using std::cout;
using std::endl;



matrix* matrixInput(){
    // Ввод матрицы с клавиатуры
    auto *matr = new matrix;
    cout << "Enter number of lines" << endl;
    getNum(matr->m);
    while (matr->m < 0){
        cout << "Wrong input, number of lines can't be negative. Repeat" << endl;
        getNum(matr->m);
    }
    matr->lines = new arrayDouble [matr->m];
    arrayDouble* bufLines = matr->lines;
    for (int i = 0; i < matr->m; i++, bufLines++){
        cout << "Enter number in " << i + 1 << " line" << endl;
        getNum(bufLines->n);
        while (bufLines->n < 0){
            cout << "Wrong input, number of lines can't be negative. Repeat" << endl;
            getNum(bufLines->n);
        }
        bufLines->line = new int [bufLines->n];
        cout << "Enter numbers" << endl;
        for (int j = 0; j < bufLines->n; j++){
            getNum(bufLines->line[j]);
        }
    }
    return matr;
}

int getMaxCountEqualInLine(arrayDouble* line){
    Node* root = nullptr;
    for (int i = 0; i < line->n; i++){
        root = treeAdd(root, line->line[i]);
    }
    int result =(int)treeGetMaxNumber(root);
    treeFree(root);
    return result;
}

int* maxCountEqual(matrix* matr){
    if (!matr->m) return nullptr;
    int* b = new int [matr->m];
    arrayDouble *line = matr->lines;
    for (int i = 0; i < matr->m; i++, line++){
        b[i] = getMaxCountEqualInLine(line);
    }
    return b;
}

void matrixFree(matrix* matr){
    for (int i = 0; i < matr->m; i++){
        delete [] matr->lines[i].line;
    }
    delete [] matr->lines;
    delete matr;
}


//double maximum(double* p, int n){
//    double max = *p;
//    p++;
//    for (int i = 1; i < n; i++, p++){
//        if (*p > max){
//            max = *p;
//        }
//    }
//    return max;
//}


int main() {
    matrix* matr = matrixInput();
    int* b = maxCountEqual(matr);
    if (b){
        for (int i = 0; i < matr->m; i++){
            cout << b[i] << endl;
        }
    }
    matrixFree(matr);
    delete [] b;
    return 0;
}
