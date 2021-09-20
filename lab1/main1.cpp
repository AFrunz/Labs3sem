#include <iostream>
#include "prog1.h"
#include "binaryTree.h"


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
    cout << "Enter max number of columns" << endl;
    getNum(matr->n);
    while (matr->n < 0){
        cout << "Wrong input, number of lines can't be negative. Repeat" << endl;
        getNum(matr->n);
    }
    matr->lines = new arrayInt [matr->m];
    arrayInt* bufLines = matr->lines;
    for (int i = 0; i < matr->m; i++, bufLines++){
        cout << "Enter number in " << i + 1 << " line" << endl;
        getNum(bufLines->n);
        while (bufLines->n < 0 || bufLines->n > matr->n){
            cout << "Wrong input, repeat" << endl;
            getNum(bufLines->n);
        }
        bufLines->line = new item [bufLines->n];
        cout << "Enter numbers" << endl;
        int pos = 0;
        int nowPos = 0;
        int bufInfo;
        for (int j = 0; j < matr->n; j++){
            if (nowPos >= bufLines->n) break;
            getNum(bufInfo);
            if (bufInfo != 0){
                bufLines->line[nowPos].value = bufInfo;
                bufLines->line[nowPos].pos = pos;
                nowPos++;
            }
            pos++;
        }
    }
    return matr;
}

int getMaxCountEqualInLine(arrayInt* line){
//    максимальное количество одинаковых эл-в в строке
    Node* root = nullptr;
    for (int i = 0; i < line->n; i++){
        root = treeAdd(root, line->line[i].value);
    }
    int result =(int)treeGetMaxNumber(root);
    treeFree(root);
    return result;
}

int* maxCountEqual(matrix* matr){
//    Вектор из максимального количества одинаковых эл-в в строках
    if (!matr->m) return nullptr;
    int* b = new int [matr->m];
    arrayInt *line = matr->lines;
    for (int i = 0; i < matr->m; i++, line++){
        b[i] = getMaxCountEqualInLine(line);
    }
    return b;
}

void matrixFree(matrix* matr){
//    Освобождение памяти матрицы
    for (int i = 0; i < matr->m; i++){
        delete [] matr->lines[i].line;
    }
    delete [] matr->lines;
    delete matr;
}

void matrixPrint(matrix* matr){

    for (int i = 0; i < matr->m; i++){
        for (int j = 0; j < matr->lines[i].n; j++){
            cout << matr->lines[i].line[j].value << " " << matr->lines[i].line[j].pos << endl;
        }
    }
}


int main() {
    try {
        matrix* matr = matrixInput();
        int* b = maxCountEqual(matr);
        if (b){
            for (int i = 0; i < matr->m; i++){
                cout << b[i] << endl;
            }
        }
        matrixFree(matr);
        delete [] b;
    }
    catch (std::bad_alloc){
        cout << "Bad alloc" << endl;
    }

    return 0;
}
