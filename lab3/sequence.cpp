#include <stdexcept>
#include <iostream>
#include "headers/sequence.h"


sequence::sequence(){
    current = 0;
}

sequence::sequence(int a):nums{}{
    nums[0] = a;
    current = 1;
}

sequence::sequence(int n, const int* numbers):nums{}{
    if (n > MAX_OF_VECTOR) throw std::runtime_error("Too many elements");
    for (int i = 0; i < n; i++){
        nums[i] = numbers[i];
    }
    current = n;
}

sequence::sequence(const sequence& c):nums{}{
    current = c.current;
    for (int i = 0; i < current; i++){
        nums[i] = c.nums[i];
    }
}

const sequence sequence::operator+ (const sequence& c) const{
    int newCurrent = sequence::current + c.current;
    if (newCurrent >= MAX_OF_VECTOR) throw std::runtime_error("Too many elements");
    sequence res;
    for (int i = 0; i < newCurrent; i++){
        if (i < sequence::current){
            res += sequence::nums[i];
        }
        else {
            res +=c.nums[i - sequence::current];
        }
    }
    return res;
}

std::ostream& operator<< (std::ostream &out, const sequence& outClass){
    for (int i = 0; i < outClass.current; i++){
        out << outClass.nums[i] << " ";
    }
    out << std::endl;
    return out;
}

std::istream& operator>> (std::istream &input, sequence& inputClass){
    int n;
    getNum(n);
    if ((n + inputClass.current) > MAX_OF_VECTOR || n <= 0){
        input.fail();
        return input;
    }
    int x;
    int* buf = new int[n];
    for (int i = 0; i < n; i++){
        getNum(buf[i]);
    }
    inputClass = sequence(n, buf);
    delete [] buf;
    return input;
}

sequence& sequence::operator+=(const sequence& x) {
    int newCurrent = current + x.current;
    if (newCurrent > MAX_OF_VECTOR) throw std::runtime_error("Too many elements");
    for (int i = current; i < newCurrent; i++){
        nums[i] = x[i - current];
    }
    current = newCurrent;
    return *this;
}

int sequence::frequencyOfEl(int x) const{
    int counter = 0;
    for (int i = 0; i < current; i++){
        if (nums[i] == x) counter++;
    }
    return counter;
}

int sequence::operator[](int index) const{
    if (index < 0) throw std::runtime_error("Negative index");
    if (index >= current) throw std::runtime_error("The index is greater than the number of elements");
    return nums[index];
}

int sequence::getCurrent() const{
    return current;
}

myArray sequence::sort() const {
    myArray newNums;
    for (int i = 0; i < current; i++){
        newNums[i] = nums[i];
    }
    for (int i = 0; i < current - 1; i++){
        for (int j = i + 1; j < current; j++){
            if (newNums[i] > newNums[j]){
                int buf = newNums[i];
                newNums[i] = newNums[j];
                newNums[j] = buf;
            }
        }
    }
    return newNums;
}

int sequence::groupNumber() const{
    if (current == 0) return 0;
    myArray arr = sort();
    int x;
    int counter = 1;
    x = arr[0];
    for (int i = 1; i < current; i++){
        if (arr[i] != x){
            x = arr[i];
            counter++;
        }
    }
    return counter;
}

sequence sequence::subSequence() const{
    int seqLength = 1;
    int flag = 0; //-1 - down, 1 - up
    sequence res;
    if (sequence::current == 0) {                           //если посл-ть пустая
        return res;
    }
    int a = sequence::nums[0];
    for (int i = 1; i <= sequence::current; i++){           // Обход последовательности
        if (i == sequence::current){                        // Последовательность закончилась
            if (seqLength >= 3){
                for (int j = i - seqLength; j < i; j++){
                    res +=sequence::nums[j];
                }
                return res;
            }
        }

        if (sequence::nums[i] > a){                                     // Возрастающая
            if ((flag == 0) || (flag == 1)){
                seqLength++;
                flag = 1;
            }
            else {
                if (seqLength >= 3) {
                    for (int j = i - seqLength; j < i; j++) {
                        res +=sequence::nums[j];
                    }
                    return res;
                }
                seqLength = 2;
                flag = 1;
            }
        }
        else if (sequence::nums[i] < a){                // Убывающая
            if ((flag == 0) || (flag == -1)){
                seqLength++;
                flag = -1;
            }
            else {
                if (seqLength >= 3){
                    for (int j = i - seqLength; j < i; j++){
                        res +=sequence::nums[j];
                    }
                    return res;
                }
                seqLength = 2;
                flag = -1;
            }
        }
        else {
            seqLength++;                                    //место для возможного исправления
        }
        a = sequence::nums[i];
    }
    return res;
}


