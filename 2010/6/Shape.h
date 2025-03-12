#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape {
public:
  virtual int calculate() = 0;
  void func() {};
  virtual ~Shape() = default;
};

#endif // !_SHAPE_H_
