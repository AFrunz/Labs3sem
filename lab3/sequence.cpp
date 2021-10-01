#include <stdexcept>
#include <stdarg.h>
#include <iostream>
#include "headers/sequence.h"


sequence::sequence(){
    max = N;
    current = 0;
}
sequence::sequence(int a){
    max = N;
    nums[0] = a;
    current = 1;
}
sequence::sequence(int n, int first, ...){
    if (n > N) throw std::runtime_error("Too many elements");
    va_list start;
    va_start(start, first);
    for (int i = 0; i < n; i++){
        if (i == 0) nums[i] = first;
        else {
            nums[i] = va_arg(start, int);
        }
    }
    va_end(start);
    sequence::current = n;
    sequence::max = N;
}
sequence::sequence(const sequence& c){
    max = c.max;
    current = c.current;
    for (int i = 0; i < current; i++){
        nums[i] = c.nums[i];
    }
}
sequence sequence::merge(const sequence& c) const{
    int newCurrent = sequence::current + c.current;
    if (newCurrent >= sequence::max) throw std::runtime_error("Too many elements");
    sequence res;
    for (int i = 0; i < newCurrent; i++){
        if (i < sequence::current){
            res.add(sequence::nums[i]);
        }
        else {
            res.add(c.nums[i - sequence::current]);
        }
    }
    return res;
}

void sequence::print() const{
    for (int i = 0; i < this->current; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

sequence& sequence::add(int x){
    if (current == max) throw std::runtime_error("Sequence is full");
    nums[current] = x;
    current++;
    return *this;
}

int sequence::frequencyOfEl(int x) const{
    int counter = 0;
    for (int i = 0; i < current; i++){
        if (nums[i] == x) counter++;
    }
    return counter;
}
int sequence::getElementWithIndex(int index) const{
    if (index < 0) throw std::runtime_error("Negative index");
    if (index >= current) throw std::runtime_error("The index is greater than the number of elements");
    return nums[index];
}

int sequence::getCurrent() const{
    return current;
}

int* sequence::sort() const {
    int *newNums = new int [N];
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
    delete[] arr;
    return counter;
}

sequence* sequence::subSequence() const{
    return nullptr;
}
