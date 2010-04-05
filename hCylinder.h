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
	// Fyrir:  hcylinder er bendir � hCylinder hlut,
	//		   radius er float.
	// Eftir:  hcylinder er me� rad�usinn radius.
	void setRadius(const float &radius);

	// Notkun: hcylinder->setHeight(height);
	// Fyrir:  hcylinder er bendir � hCylinder hlut,
	//		   height er float.
	// Eftir:  hcylinder er me� h��ina height.
	void setHeight(const float &height);

	// Notkun: hcylinder->setSide(side);
	// Fyrir:  hcylinder er bendir � hCylinder hlut,
	//		   side er bool.
	// Eftir:  hcylinder er me� hli�arnar teikna�ar ef og
	//		   a�eins ef side er satt.
	void setSide(const bool &side);

	// Notkun: hcylinder->setBottom(bottom);
	// Fyrir:  hcylinder er bendir � hCylinder hlut,
	//		   bottom er bool.
	// Eftir:  hcylinder er me� botn teikna�an ef og
	//		   a�eins ef bottom er satt.
	void setBottom(const bool &bottom);

	// Notkun: hcylinder->setTop(top);
	// Fyrir:  hcylinder er bendir � hCylinder hlut,
	//		   top er bool.
	// Eftir:  hcylinder er me� top teikna�an ef og
	//		   a�eins ef top er satt.
	void setTop(const bool &top);

	//Erf�ar a�ger�ir fr� Shapes
	void setSolid(const bool &solid);
	Node* getNode(void);
private:
	Cylinder *cylinder;
};

#endif