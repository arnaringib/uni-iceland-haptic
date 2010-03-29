//
// �essi abstract klasi er hugsa�ur sem undirsta�a
// fyrir �ll �nnur einf�ld form.
//
// -Arnar Ingi Bragason

#ifndef _SHAPES_H
#define _SHAPES_H

#include <H3D/X3D.h>
#include <H3D/Shape.h>
#include <H3D/Appearance.h>
#include <H3D/Material.h>
#include <H3D/Transform.h>
#include <H3D/MagneticSurface.h>
#include <H3DUtil/Rotation.h>

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

class Shapes{
public: 
	Shapes();
	virtual ~Shapes();

	// Notkun: shapes->setTranslation(translation);
	// Fyrir:  shapes er bendir � Shapes hlut, translation
	//		   er Vec3f.
	// Eftir:  B�i� er a� f�ra shapes hlutinn � translation((x,y,z))
	//		   hnit mi�a� vi� (0,0,0).
	void setTranslation(const Vec3f &translation);
	
	// Notkun: shapes->setDiffuseColor(red,green,blue);
	// Fyrir:  shapes er bendir � Shapes hlut, 
	//		   red, green og blue eru float.
	// Eftir:  shapes er teikna� � (red,green,blue) dreif�um lit. 
	void setDiffuseColor(const float &red, const float &green, const float &blue);

	// Notkun: shapes->setRotation(axis,angle);
	// Fyrir:  shapes er bendir � Shapes hlut, 
	//		   axis er Vec3f og angle er float.
	// Eftir:  shapes er sn�i� vi� � axis og � angle gr��ur.
	void setRotation(const Vec3f &axis, const float &angle);

	// Notkun: shapes->setSurface(stiffness, damping, staticf, dynamicf, snap);
	// Fyrir:  shapes er bendir � Shapes hlut,
	//		   stiffness, damping, staticf, dynamicf og snap eru float.
	// Eftir:  Fl�turinn er me� ��ttleikan stiffness, damping � mj�kleika,
	//		   n�ningurinn er staticf, hreyfin�ningurinn er dynamicf og 
	//		   snap er lengd fr� hlutnum sem a�dr�ttur � a� virka.
	void setSurface(const float &stiffness, const float &damping, const float &staticf, const float &dynamicf, const float &snap);

	// Notkun: shapes->setTransparency(transparency);
	// Fyrir:  shapes er bendir � Shapes hlut, 
	//		   transparency er float.
	// Eftir:  shapes er transparency gegnums�tt
	void setTransparency(const float &transparency);

	// Notkun: shapes->setSpecularColor(red,green,blue);
	// Fyrir:  shapes er bendir � Shapes hlut, 
	//		   red, green og blue eru float.
	// Eftir:  shapes er teikna� � (red,green,blue) endurkastanlegum lit. 
	void setSpecularColor(const float &red, const float &green, const float &blue);

	// Notkun: shapes->setShininess(shininess);
	// Fyrir:  shapes er bendir � Shapes hlut, 
	//		   shininess float.
	// Eftir:  shapes er teikna� me� shininess glansa. 
	void setShininess(const float &shininess);

	// Notkun: shapes->setSolid(solid);
	// Fyrir:  shapes er bendir � Shapes hlut, solid er bool.
	// Eftir:  shapes er teikna� b��um megin ef og 
	//		   a�eins ef solid er true. Upphafsgildi� er true.
	virtual void setSolid(const bool &solid)=0;

	// Notkun: node = shapes->getNode();
	// Fyrir:  shapes er bendir � Shapes hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur shapes hn�t.
	virtual Node* getNode(void)=0;
protected:
	Transform *transform;
	Shape *shape;
	Appearance *appearance;
	Material *material;
	MagneticSurface *surface;
};

#endif