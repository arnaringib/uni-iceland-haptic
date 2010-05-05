#ifndef _HSCENES_H
#define _HSCENES_H

#include <H3D/X3D.h>
#include "hSphere.h"
#include "hBox.h"
#include "hCone.h"
#include "hCylinder.h"

class hScenes
{
public:
	hScenes();
	~hScenes();
	
	// Notkun: hscene->shape(nr);
	// Fyrir:  hscene er hScenes hlutur 
	//         og nr er heiltala � bilinu
	//         0 <= nr <= 3.
	// Eftir:  Ef nr er:
	//		   0 er k�la teiknu�,
	//		   1 er kassi teikna�ur,
	//		   2 er keila teiknu�,
	//		   3 er strokkur teikna�ur.
	void shape(const int &nr);

	// Notkun: hscene->addCover();
	// Fyrir:  hscene er hScenes hlutur
	// Eftir:  B�tt hefur veri� vi� kassa utan
	//		   um hlutinn.
	void addCover();

	// Notkun: hscene->addMagnetic();
	// Fyrir:  hscene er hScenes hlutur
	// Eftir:  B�tt hefur veri� segulkraft
	//		   vi� hlutinn.
	void addMagnetic();

	// Notkun: node = hscenes->getNode();
	// Fyrir:  hscenes er bendir � hScenes hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur senuna.
	Node* getScene();

	static const int SPHERE = 0;
	static const int BOX = 1;
	static const int CONE = 2;
	static const int CYLINDER = 3;

private:
	float size;   // St�r�in � hlutnum.
	int selected; // Vali� form.
	Group *group; // Heldur utan um senuna.
	Shapes* item; // Hluturinn, notum
				  // fj�lbrig�ni(polymorphism).
};

#endif