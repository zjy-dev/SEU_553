#include <bits/stdc++.h>
using namespace std;

// 敲定每一个运算符究竟如何重载
class MyInt {
private:
  int value;

public:
  // 构造函数
  MyInt(int val = 0) : value(val) {}

  // 获取值
  int getValue() const { return value; }

  // 重载算术运算符
  // 能 const 就 const
  // 效率??? 如果 MyInt 是一个大对象
  MyInt operator+(const MyInt &other) const {
    return MyInt(value + other.value);
  }
  MyInt operator-(const MyInt &other) const {
    return MyInt(value - other.value);
  }
  MyInt operator*(const MyInt &other) const {
    return MyInt(value * other.value);
  }
  MyInt operator/(const MyInt &other) const {
    if (other.value == 0) {
      throw runtime_error("divide zero");
    }
    return MyInt(value / other.value);
  }
  MyInt operator%(const MyInt &other) const {
    if (other.value == 0) {
      throw runtime_error("divide zero");
    }
    return MyInt(value % other.value);
  }

  // 重载一元运算符
  MyInt operator-() const { return MyInt(-value); } // 取负
  MyInt operator+() const { return *this; } // 取正（无实际变化）

  // 重载自增自减运算符（前置和后置）
  MyInt &operator++() {
    ++this->value;
    return *this;
  } // 前置++

  // 告诉编译器
  MyInt operator++(int) {
    MyInt old = *this;
    ++this->value;
    return old;
  } // 后置++

  MyInt &operator--() {
    --value;
    return *this;
  } // 前置--
  MyInt operator--(int) {
    MyInt temp = *this;
    --value;
    return temp;
  } // 后置--

  // 重载赋值运算符
  // 深拷贝, 重载两个
  // ClassA other(a);
  // ClassA other = a;
  MyInt &operator=(const MyInt &other) {
    value = other.value;

    // 深拷贝
    // new
    // strcpy(this->arr, other.arr);

    return *this;
  }

  MyInt &operator+=(const MyInt &other) {
    value += other.value;
    return *this;
  }
  MyInt &operator-=(const MyInt &other) {
    value -= other.value;
    return *this;
  }
  MyInt &operator*=(const MyInt &other) {
    value *= other.value;
    return *this;
  }
  MyInt &operator/=(const MyInt &other) {
    if (other.value == 0)
      std::cerr << "Error: Division by zero!" << std::endl;
    else
      value /= other.value;
    return *this;
  }
  MyInt &operator%=(const MyInt &other) {
    if (other.value == 0)
      std::cerr << "Error: Modulo by zero!" << std::endl;
    else
      value %= other.value;
    return *this;
  }

  // 重载比较运算符
  // 最水, 但是喜欢考
  bool operator==(const MyInt &other) const { return value == other.value; }
  bool operator!=(const MyInt &other) const { return value != other.value; }
  bool operator<(const MyInt &other) const { return value < other.value; }
  bool operator>(const MyInt &other) const { return value > other.value; }
  bool operator<=(const MyInt &other) const { return value <= other.value; }
  bool operator>=(const MyInt &other) const { return value >= other.value; }

  // 重载逻辑运算符
  bool operator!() const { return !value; } // 逻辑非
  // && 和 || 通常不直接重载，因为它们有短路求值的特性，这里不实现

  // 重载位运算符
  MyInt operator&(const MyInt &other) const {
    return MyInt(value & other.value);
  }
  MyInt operator|(const MyInt &other) const {
    return MyInt(value | other.value);
  }
  MyInt operator^(const MyInt &other) const {
    return MyInt(value ^ other.value);
  }
  MyInt operator~() const { return MyInt(~value); } // 按位取反

  MyInt operator<<(const MyInt &other) const {
    return MyInt(value << other.value);
  }
  MyInt operator>>(const MyInt &other) const {
    return MyInt(value >> other.value);
  }

  // 重载复合位赋值运算符
  MyInt &operator&=(const MyInt &other) {
    value &= other.value;
    return *this;
  }
  MyInt &operator|=(const MyInt &other) {
    value |= other.value;
    return *this;
  }
  MyInt &operator^=(const MyInt &other) {
    value ^= other.value;
    return *this;
  }
  MyInt &operator<<=(const MyInt &other) {
    value <<= other.value;
    return *this;
  }

  // 底层的第一个参数是 MyInt *this
  MyInt &operator>>=(const MyInt &other) {
    value >>= other.value;
    return *this;
  }

  // 重载输出运算符（友元函数）
  friend std::ostream &operator<<(std::ostream &os, const MyInt &obj) {
    os << obj.value;
    return os;
  }

  // 重载输入运算符（友元函数）
  friend std::istream &operator>>(std::istream &is, MyInt &obj) {
    is >> obj.value;

    return is;
  }
};

// 主函数测试
int main() {
  MyInt a(5), b(3), c;

  // 测试算术运算符
  std::cout << "a + b = " << (a + b) << std::endl; // 8
  std::cout << "a - b = " << (a - b) << std::endl; // 2
  std::cout << "a * b = " << (a * b) << std::endl; // 15
  std::cout << "a / b = " << (a / b) << std::endl; // 1
  std::cout << "a % b = " << (a % b) << std::endl; // 2

  // 测试一元运算符
  std::cout << "-a = " << (-a) << std::endl; // -5
  std::cout << "+a = " << (+a) << std::endl; // 5

  // 测试自增自减
  std::cout << "++a = " << (++a) << std::endl; // 6
  std::cout << "a++ = " << (a++) << std::endl; // 6 (输出后变为 7)
  std::cout << "a = " << a << std::endl;       // 7
  std::cout << "--a = " << (--a) << std::endl; // 6
  std::cout << "a-- = " << (a--) << std::endl; // 6 (输出后变为 5)
  std::cout << "a = " << a << std::endl;       // 5

  // 测试赋值和复合赋值
  c = a;
  std::cout << "c = a, c = " << c << std::endl; // 5
  c += b;
  std::cout << "c += b, c = " << c << std::endl; // 8
  c -= b;
  std::cout << "c -= b, c = " << c << std::endl; // 5

  // 测试比较运算符
  std::cout << "a == b: " << (a == b) << std::endl; // 0 (false)
  std::cout << "a > b: " << (a > b) << std::endl;   // 1 (true)
  std::cout << "a <= b: " << (a <= b) << std::endl; // 0 (false)

  // 测试逻辑运算符
  std::cout << "!a: " << (!a) << std::endl; // 0 (false, 因为 a 非 0)

  // 测试位运算符
  MyInt x(5), y(3);                                         // 5: 0101, 3: 0011
  std::cout << "x & y = " << (x & y) << std::endl;          // 1 (0001)
  std::cout << "x | y = " << (x | y) << std::endl;          // 7 (0111)
  std::cout << "x ^ y = " << (x ^ y) << std::endl;          // 6 (0110)
  std::cout << "~x = " << (~x) << std::endl;                // -6 (按位取反)
  std::cout << "x << 1 = " << (x << MyInt(1)) << std::endl; // 10 (1010)
  std::cout << "x >> 1 = " << (x >> MyInt(1)) << std::endl; // 2 (0010)

  // 测试输入输出
  MyInt input;
  std::cout << "Enter a number for MyInt: ";
  std::cin >> input;
  std::cout << "You entered: " << input << std::endl;

  return 0;
}