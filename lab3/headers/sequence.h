#ifndef CPP_SECUENCE_H
#define CPP_SECUENCE_H
#define N 5


class [[maybe_unused]] sequence {

private:
    int max;
    int current;
    int nums[N];

public:
    sequence();
    sequence(int a);
    sequence(int n, int first, ...);
    sequence(const sequence& c);
    sequence merge(const sequence& c) const;
    void print() const;
    sequence& add(int x);
    int frequencyOfEl(int x) const;
    int getElementWithIndex(int index) const;
    int getCurrent() const;
    int groupNumber() const;
    sequence* subSequence() const;
    sequence* subSequence();
private:
    int* sort() const;
};





#endif //CPP_SECUENCE_H
