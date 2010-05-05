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
	//         og nr er heiltala á bilinu
	//         0 <= nr <= 3.
	// Eftir:  Ef nr er:
	//		   0 er kúla teiknuð,
	//		   1 er kassi teiknaður,
	//		   2 er keila teiknuð,
	//		   3 er strokkur teiknaður.
	void shape(const int &nr);

	// Notkun: hscene->addCover();
	// Fyrir:  hscene er hScenes hlutur
	// Eftir:  Bætt hefur verið við kassa utan
	//		   um hlutinn.
	void addCover();

	// Notkun: hscene->addMagnetic();
	// Fyrir:  hscene er hScenes hlutur
	// Eftir:  Bætt hefur verið segulkraft
	//		   við hlutinn.
	void addMagnetic();

	// Notkun: node = hscenes->getNode();
	// Fyrir:  hscenes er bendir á hScenes hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur senuna.
	Node* getScene();

	static const int SPHERE = 0;
	static const int BOX = 1;
	static const int CONE = 2;
	static const int CYLINDER = 3;

private:
	float size;   // Stærðin á hlutnum.
	int selected; // Valið form.
	Group *group; // Heldur utan um senuna.
	Shapes* item; // Hluturinn, notum
				  // fjölbrigðni(polymorphism).
};

#endif