#include <iostream>

class Heap
{
private:
    int key_;
    int *massive_;
    int size_;
public:
    Heap();
    ~Heap();
    void insert(int num);
    void extract();
};

Heap::Heap()
{
}

Heap::~Heap()
{
}


int main() {

}

void Heap::insert(int num) {
    int tmp = size_;
    int swap = 0;
    massive_[size_] = num;
    while (tmp > 0) {
        if (massive_[(tmp - 1) / 2] < num) {
            swap = massive_[(tmp - 1) / 2];
            massive_[(tmp - 1) / 2] = num;
            massive_[tmp] = swap;
            tmp = (tmp - 1) / 2;
        }
    }
}

void Heap::extract() {

}


// Родитель (i - 1) / 2
// Дети 2i + 1, 2i + 2