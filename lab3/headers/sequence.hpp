#ifndef CPP_SEQUENCE_HPP
#define CPP_SEQUENCE_HPP
#include <iostream>


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
    sequence(sequence&& c);
///    Сложение последовательностей
    const sequence operator+ (const sequence& c) const;
///    Добавление последовательности в конец
    sequence& operator+= (const sequence& x);
///    Частота встречаемости элемента
    int frequencyOfEl(int x) const;
///    Получение первой возрастающей или убывающей подпоследовательности
    sequence subSequence() const;
///    Количество уникальных элементов
    int groupNumber() const;
///    Ввод
    friend std::ostream& operator<< (std::ostream &out, const sequence& outClass);
///    Вывод
    friend std::istream& operator>> (std::istream &input, sequence& inputClass);
///    Получение и изменение элемента по индексу
    int& operator[](int index);
    /// Получение количества элементов
    int getCurrent() const;
///    Оператор присваивания копированием
    sequence& operator= (const sequence& c);
///    Оператор присваивания перемещения
    sequence& operator= (sequence&& c);
//    Деструктор
    ~sequence(){
        delete [] nums;
    }

private:
    int* sort(bool) const;
};



#endif //CPP_SEQUENCE_HPP
