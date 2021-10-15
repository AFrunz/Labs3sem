#ifndef CPP_SEQUENCE_H
#define CPP_SEQUENCE_H

const int MAX_OF_VECTOR = 5;

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
    int nums[MAX_OF_VECTOR];
public:
    myArray():nums{}{};
    int& operator[](int num){
        return nums[num];
    }
};




class sequence {

private:
    int current;
    int nums[MAX_OF_VECTOR];

public:
//    Конструкторы
    sequence();
    sequence(int a);
    sequence(int n, const int* numbers);
    sequence(const sequence& c);
//    Добавление одной последовательности в конец другой
    const sequence operator +(const sequence& c) const;
//    Добавление последовательности
    sequence& operator+= (const sequence& x);
//    Добавление одного эл-та
//    sequence& operator+=(int x);
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
    int operator[](int index) const;
    int getCurrent() const;


private:
    myArray sort() const;
};



#endif //CPP_SEQUENCE_H
