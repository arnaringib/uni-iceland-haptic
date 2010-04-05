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
	// Fyrir:  hcone er bendir á hCone hlut,
	//		   bottomRadius er float.
	// Eftir:  hcone er með botn radíusinn bottomRadius.
	void setBottomRadius(const float &bottomRadius);

	// Notkun: hcone->setHeight(height);
	// Fyrir:  hcone er bendir á hCone hlut,
	//		   height er float.
	// Eftir:  hcone er með hæðina height.
	void setHeight(const float &height);

	// Notkun: hcone->setSide(side);
	// Fyrir:  hcone er bendir á hCone hlut,
	//		   side er bool.
	// Eftir:  hcone er með hliðarnar teiknaðar ef og
	//		   aðeins ef side er satt.
	void setSide(const bool &side);

	// Notkun: hcone->setBottom(bottom);
	// Fyrir:  hcone er bendir á hCone hlut,
	//		   bottom er bool.
	// Eftir:  hcone er með botn teiknaðan ef og
	//		   aðeins ef bottom er satt.
	void setBottom(const bool &bottom);

	//Erfðar aðgerðir frá Shapes
	void setSolid(const bool &solid);
	Node* getNode(void);
private:
	Cone *cone;
};

#endif