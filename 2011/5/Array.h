#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

template <typename T> class Array {
  friend std::ostream &operator<<(std::ostream &out, const Array<T> &a) {
    for (int i = 0; i < a.row; ++i) {
      for (int j = 0; j < a.col; ++j)
        out << *(a.ptr + i * a.col + j) << " ";
      out << std::endl;
    }
    return out;
  }

public:
  Array(int r = 0, int c = 0);
  ~Array();
  Array(const Array<T> &a);
  T &operator()(int r, int c);

private:
  T *ptr;
  int row, col;
};

template <typename T> Array<T>::Array(int r, int c) {
  row = r;
  col = c;
  if (row * col == 0)
    ptr = nullptr;
  else
    ptr = new T[row * col]();
}

template <typename T> Array<T>::~Array() { delete[] ptr; }

template <typename T> Array<T>::Array(const Array<T> &a) {
  row = a.row;
  col = a.col;
  ptr = new T[row * col]();
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j)
      *(ptr + i * col + j) = *(a.ptr + i * col + j);
  }
}

// arr[3]++;
template <typename T> T &Array<T>::operator()(int r, int c) {
  if (r >= row || c >= col) {
    std::cerr << "Out of range" << std::endl;
    exit(EXIT_FAILURE);
  }

  return ptr[r * col + c];
}

#endif // !_ARRAY_H_