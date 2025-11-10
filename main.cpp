#include <iostream>

struct IntArray{
  void add(int i);
  int get(size_t id) const noexcept;
  size_t size() const noexcept;
  int last() const noexcept; 
  IntArray(int i);
  ~IntArray();

  int * a;
  size_t k;
};

IntArray::~IntArray(){
  delete [] a;
}

IntArray::IntArray(int i)
  : a(new int[1]),
    k(1)
{
  *a = i;
}

int IntArray::get(size_t id) const noexcept {
  return a[id];
}

size_t IntArray::size() const noexcept {
  return k;
}

int IntArray::last() const noexcept {
  return get(size()-1);
}

void IntArray::add(int i){
  int * tmp = new int[size() + 1];
  for (size_t j = 0; j < size(); ++j){
    tmp[j] = get(j);
  }
  tmp[size()] = i;
  delete [] a;
  a = tmp;
  ++k;
}

int main(){
  int next = 0;
  std::cin >> next;
  IntArray a(next);
  // IntArray a;
  // a.add(next);
  while (std::cin >> next){
    a.add(next);
    if(std::cin.fail() && !std::cin.eof()){
      return 1;
    }
  }

  size_t count = 0;

  if (a.size() == 0) {
      std::cout << 0 << "\n";
      return 0;
  }

  int last_val = a.last();

  for(size_t i = 0; i < a.size(); ++i){
    int d = a.get(i);
    if (last_val != 0) {
        count += !(d % last_val);
    }
  }

  std::cout << count << "\n";
  return 0;
}
