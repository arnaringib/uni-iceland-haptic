#ifndef _HSPHERE_H
#define _HSPHERE_H

#include <H3D/Sphere.h>
#include "Shapes.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

class hSphere : public Shapes{
public: 
	hSphere();
	~hSphere();
	// Notkun: hsphere->setRadius(radius);
	// Fyrir:  hsphere er bendir � hSphere hlut,
	//		   radius er float.
	// Eftir:  hsphere er me� rad�usinn radius.
	void setRadius(const float &radius);

	//Erf�ar a�ger�ir fr� Shapes
	void setSolid(const bool &solid);
	Node* getNode(void);
private:
	Sphere *sphere;
};

#endif