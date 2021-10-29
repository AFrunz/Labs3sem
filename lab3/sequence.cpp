#include <stdexcept>
#include <iostream>
#include "headers/sequence.hpp"
#include <cstring>


sequence::sequence(){
    nums = nullptr;
    current = 0;
    capacity = 0;
}

sequence::sequence(int a){
    nums = new int;
    nums[0] = a;
    current = 1;
    capacity = 1;
}

sequence::sequence(int n, const int* numbers){
    nums = new int[n];
    memcpy(nums, numbers, n * sizeof(int));
    current = n;
    capacity = n;
}

sequence::sequence(const sequence& c){
    current = c.current;
    nums = new int[c.capacity];
    memcpy(nums, c.nums, current * sizeof(int));
    capacity = c.capacity;
//    std::cout << "Copy constructor\n";
}

sequence::sequence(sequence&& c):current(c.current), nums(c.nums), capacity(c.capacity){
    c.nums = nullptr;
    c.capacity = 0;
    c.current = 0;
//    std::cout << "Relocate constructor\n";
}

sequence& sequence::operator= (const sequence& c){
    if (this != &c){
        if (nums){
            delete [] nums;
            nums = nullptr;
        }
        if ((current = c.current) != 0){
            nums = new int [c.capacity];
            memcpy(nums, c.nums, current * sizeof(int));
        }
        capacity = c.capacity;
    }
//    std::cout << "Copy equal\n";
    return *this;
}

sequence& sequence::operator= (sequence&& c){
    if (this != &c){
        current = c.current;
        int* bufCells = nums;
        nums = c.nums;
        c.nums = bufCells;
        capacity = c.capacity;
        c.capacity = 0;
        c.current = 0;
    }
//    std::cout << "Relocate equal\n";
    return *this;
}

const sequence sequence::operator+ (const sequence& c) const{
    int newCurrent = sequence::current + c.current;
    sequence res;
    res += *this;
    res += c;
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
    input >> n;
    if (!input.good()) return input;
    int x;
    int* buf = new int[n];
    for (int i = 0; i < n; i++){
        input >> buf[i];
        if (!input.good()){
            delete [] buf;
            return input;
        }
    }
    inputClass = sequence(n, buf);
    delete [] buf;
    return input;
}

sequence& sequence::operator+=(const sequence& x) {
    int newCurrent = current + x.current;
    if (capacity < newCurrent){
//        if (!capacity) capacity = 1;
        while (capacity < newCurrent){
            capacity += 10;
        }
        int* bufCell = new int[capacity];
        memcpy(bufCell, nums, current * sizeof(int));
        memcpy(bufCell + current, x.nums, x.current * sizeof(int));
        delete[] nums;
        nums = bufCell;
        current = newCurrent;
    }
    else {
        memcpy(nums + current, x.nums, x.current * sizeof(int));
        current = newCurrent;
    }
    return *this;
}

int sequence::frequencyOfEl(int x) const{
    int counter = 0;
    for (int i = 0; i < current; i++){
        if (nums[i] == x) counter++;
    }
    return counter;
}


int& sequence::operator[](int index){
    if (index < 0) throw std::runtime_error("Negative index");
    if (index >= current) throw std::runtime_error("The index is greater than the number of elements");
    return nums[index];
}

int sequence::getCurrent() const{
    return current;
}


// Sort по убыванию с лямбдой
int* sequence::sort(bool flag = false) const {
    int* newNums = new int[current];
    memcpy(newNums, nums, current * sizeof(int));
    if (flag){
        std::sort(newNums, newNums + current - 1, [](int a, int b){
            return a > b;
        });
    }
    else {
        std::sort(newNums, newNums + current);
    }
    return newNums;
}

int sequence::groupNumber() const{
    if (current == 0) return 0;
    int* arr = sort();
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


