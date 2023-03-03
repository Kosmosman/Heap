#include <iostream>
#include <vector>

class Heap {
 private:
  std::vector<int> massive_;

 public:
  Heap();
  ~Heap();
  void insert(int num);
  int extract();
};

Heap::Heap() {}

Heap::~Heap() {}

void Heap::insert(int num) {
  massive_.push_back(num);
  int tmp = massive_.size() - 1;
  while (tmp > 0) {
    if (massive_[(tmp - 1) / 2] < num) {
      massive_[tmp] = massive_[(tmp - 1) / 2];
      massive_[(tmp - 1) / 2] = num;
      tmp = (tmp - 1) / 2;
    } else {
      tmp = 0;
    }
  }
}

int Heap::extract() {
  int res = massive_[0];
  int tmp = massive_.back();
  int size = 0;
  massive_[0] = tmp;
  while (size < massive_.size()) {
    if (size * 2 + 2 < massive_.size()) {
      if (massive_[size * 2 + 1] >= massive_[size * 2 + 2] &&
          massive_[size] <= massive_[size * 2 + 1]) {
        massive_[size] = massive_[size * 2 + 1];
        massive_[size * 2 + 1] = tmp;
        size = size * 2 + 1;
      } else if (massive_[size * 2 + 2] >= massive_[size * 2 + 1] &&
                 massive_[size] <= massive_[size * 2 + 2]) {
        massive_[size] = massive_[size * 2 + 2];
        massive_[size * 2 + 2] = tmp;
        size = size * 2 + 2;
      } else {
        massive_.pop_back();
        size = massive_.size();
      }
    } else if (size * 2 + 1 < massive_.size() &&
               massive_[size] <= massive_[size * 2 + 1]) {
      massive_[size] = massive_[size * 2 + 1];
      massive_[size * 2 + 1] = tmp;
      size = size * 2 + 1;
    } else {
      massive_.pop_back();
      size = massive_.size();
    }
  }
  return res;
}

int main() {
  Heap h;
  int count = 0, num = 0;
  (std::cin >> count).get();
  for (int i = 0; i < count; i++) {
    (std::cin >> num).get();
    switch (num) {
      case 0:
        (std::cin >> num).get();
        h.insert(num);
        break;
      case 1:
        std::cout << h.extract() << std::endl;
        break;
      default:
        break;
    }
  }
  return 0;
}

// Родитель (i - 1) / 2
// Дети 2i + 1, 2i + 2