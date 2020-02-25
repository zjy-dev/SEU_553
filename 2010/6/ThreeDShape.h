#ifndef _THREEDSHAPE_H_
#define _THREEDSHAPE_H_

#include "TwoDShape.h"

class ThreeDShape : public TwoDShape {
public:
	ThreeDShape(int a = 0, int b = 0, int c = 0)
		: TwoDShape(a, b), z(c) {}
	virtual int calculate() { return TwoDShape::calculate() * z; }
private:
	int z;
};

#endif // !_THREEDSHAPE_H_