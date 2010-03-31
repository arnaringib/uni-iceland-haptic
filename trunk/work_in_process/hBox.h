#ifndef _HBOX_H
#define _HBOX_H

#include <H3D/Box.h>
#include "Shapes.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

class hBox : public Shapes{
public: 
	hBox();
	~hBox();
	// Notkun: hbox->setSize(size);
	// Fyrir:  hbox er bendir á hBox hlut,
	//		   size er Vec3f hlutur.
	// Eftir:  hbox er með stærðina size.
	void setSize(const Vec3f &size);

	//Erft frá Shapes
	void setSolid(const bool &solid);
	Node* getNode(void);
private:
	Box *box;
};

#endif