#ifndef CPP_SECUENCE_H
#define CPP_SECUENCE_H
#define N 5

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


class [[maybe_unused]] sequence {

private:
    int max;
    int current;
    int nums[N];

public:
//    Конструкторы
    sequence();
    sequence(int a);
    sequence(int n, const int* numbers);
    sequence(const sequence& c);
//    Добавление одной последовательности в конец другой
    const sequence operator +(const sequence& c) const;
//    Добавление одного эл-та
    sequence& operator+= (int x);
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
    int getElementWithIndex(int index) const;
    int getCurrent() const;


private:
    int* sort() const;
};



#endif //CPP_SECUENCE_H
