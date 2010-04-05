#ifndef _HCYLINDER_H
#define _HCYLINDER_H

#include <H3D/Cylinder.h>
#include "Shapes.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

class hCylinder : public Shapes{
public: 
	hCylinder();
	~hCylinder();

	// Notkun: hcylinder->setRadius(radius);
	// Fyrir:  hcylinder er bendir á hCylinder hlut,
	//		   radius er float.
	// Eftir:  hcylinder er með radíusinn radius.
	void setRadius(const float &radius);

	// Notkun: hcylinder->setHeight(height);
	// Fyrir:  hcylinder er bendir á hCylinder hlut,
	//		   height er float.
	// Eftir:  hcylinder er með hæðina height.
	void setHeight(const float &height);

	// Notkun: hcylinder->setSide(side);
	// Fyrir:  hcylinder er bendir á hCylinder hlut,
	//		   side er bool.
	// Eftir:  hcylinder er með hliðarnar teiknaðar ef og
	//		   aðeins ef side er satt.
	void setSide(const bool &side);

	// Notkun: hcylinder->setBottom(bottom);
	// Fyrir:  hcylinder er bendir á hCylinder hlut,
	//		   bottom er bool.
	// Eftir:  hcylinder er með botn teiknaðan ef og
	//		   aðeins ef bottom er satt.
	void setBottom(const bool &bottom);

	// Notkun: hcylinder->setTop(top);
	// Fyrir:  hcylinder er bendir á hCylinder hlut,
	//		   top er bool.
	// Eftir:  hcylinder er með top teiknaðan ef og
	//		   aðeins ef top er satt.
	void setTop(const bool &top);

	//Erfðar aðgerðir frá Shapes
	void setSolid(const bool &solid);
	Node* getNode(void);
private:
	Cylinder *cylinder;
};

#endif