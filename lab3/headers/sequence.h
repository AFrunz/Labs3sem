#ifndef CPP_SEQUENCE_H
#define CPP_SEQUENCE_H

//const int MAX_OF_VECTOR = 5;

template <class T>
void getNum(T &a){
    std::cin >> a;
    while (!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Wrong input, repeat" << std::endl;
        std::cin >> a;
    }
}


class myArray {
private:
    int* nums;
public:
    myArray(int k){
        nums = new int[k];
    }
    myArray(){
        nums = nullptr;
    }
    int& operator[](int num){
        return nums[num];
    }
    ~myArray(){
        delete [] nums;
    }
};



class sequence {

private:
    int capacity;
    int current;
    int* nums;

public:
//    Конструкторы
    sequence();
    sequence(int a);
    sequence(int n, const int* numbers);
    sequence(const sequence& c);
    sequence(sequence&& c):current(c.current), nums(c.nums), capacity(c.capacity){
        c.nums = nullptr;
        c.capacity = 0;
    };
//    Сложение последовательностей
    const sequence operator+ (const sequence& c) const;
//    Добавление последовательности в конец
    sequence& operator+= (const sequence& x);
//    Частота встречаемости элемента
    int frequencyOfEl(int x) const;
//    Получение первой возр или убыв подпоследовательности
    sequence subSequence() const;
//    Количество уникальных элементов
    int groupNumber() const;
//    Ввод
    friend std::ostream& operator<< (std::ostream &out, const sequence& outClass);
//    Вывод
    friend std::istream& operator>> (std::istream &input, sequence& inputClass);
//    Селекторы
    int& operator[](int index) const;
    int getCurrent() const;
//    Оператор присваивания копированием
    sequence& operator= (const sequence& c);
//    Оператор присваивания копированием
    sequence& operator= (sequence&& c);
//    Деструктор
    ~sequence(){
        if (nums) delete [] nums;
    }

private:
    int* sort() const;
};



#endif //CPP_SEQUENCE_H
