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
    sequence();
    sequence(int a);
    sequence(int n, const int* numbers);
    sequence(const sequence& c);
    const sequence operator +(const sequence& c) const;
    friend std::ostream& operator<< (std::ostream &out, const sequence& outClass);
    friend std::istream& operator>> (std::istream &input, sequence& inputClass);
    sequence& operator+= (int x);
    int frequencyOfEl(int x) const;
    int getElementWithIndex(int index) const;
    int getCurrent() const;
    int groupNumber() const;
    sequence subSequence() const;
private:
    int* sort() const;
};



#endif //CPP_SECUENCE_H
