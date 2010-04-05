#ifndef _HCONE_H
#define _HCONE_H

#include <H3D/Cone.h>
#include "Shapes.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

class hCone : public Shapes{
public: 
	hCone();
	~hCone();
	// Notkun: hcone->setBottomRadius(bottomRadius);
	// Fyrir:  hcone er bendir � hCone hlut,
	//		   bottomRadius er float.
	// Eftir:  hcone er me� botn rad�usinn bottomRadius.
	void setBottomRadius(const float &bottomRadius);

	// Notkun: hcone->setHeight(height);
	// Fyrir:  hcone er bendir � hCone hlut,
	//		   height er float.
	// Eftir:  hcone er me� h��ina height.
	void setHeight(const float &height);

	// Notkun: hcone->setSide(side);
	// Fyrir:  hcone er bendir � hCone hlut,
	//		   side er bool.
	// Eftir:  hcone er me� hli�arnar teikna�ar ef og
	//		   a�eins ef side er satt.
	void setSide(const bool &side);

	// Notkun: hcone->setBottom(bottom);
	// Fyrir:  hcone er bendir � hCone hlut,
	//		   bottom er bool.
	// Eftir:  hcone er me� botn teikna�an ef og
	//		   a�eins ef bottom er satt.
	void setBottom(const bool &bottom);

	//Erf�ar a�ger�ir fr� Shapes
	void setSolid(const bool &solid);
	Node* getNode(void);
private:
	Cone *cone;
};

#endif