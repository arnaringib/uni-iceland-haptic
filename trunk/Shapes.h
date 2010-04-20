//
// Þessi abstract klasi er hugsaður sem undirstaða
// fyrir öll önnur einföld form.
//
// -Arnar Ingi Bragason

#ifndef _SHAPES_H
#define _SHAPES_H

#include <H3D/X3D.h>
#include <H3D/Shape.h>
#include <H3D/Appearance.h>
#include <H3D/Material.h>
#include <H3D/Transform.h>
#include <H3D/MagneticGeometryEffect.h>
#include <H3D/SmoothSurface.h>
#include <H3D/H3DFrictionalSurfaceNode.h>
#include <H3DUtil/Rotation.h>

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

class Shapes{
public: 
	Shapes();
	virtual ~Shapes();

	// Notkun: shapes->setTranslation(translation);
	// Fyrir:  shapes er bendir á Shapes hlut, translation
	//		   er Vec3f.
	// Eftir:  Búið er að færa shapes hlutinn á translation((x,y,z))
	//		   hnit miðað við (0,0,0).
	void setTranslation(const Vec3f &translation);
	
	// Notkun: shapes->setDiffuseColor(red,green,blue);
	// Fyrir:  shapes er bendir á Shapes hlut, 
	//		   red, green og blue eru float.
	// Eftir:  shapes er teiknað í (red,green,blue) dreifðum lit. 
	void setDiffuseColor(const float &red, const float &green, const float &blue);

	// Notkun: shapes->setRotation(axis,angle);
	// Fyrir:  shapes er bendir á Shapes hlut, 
	//		   axis er Vec3f og angle er float.
	// Eftir:  shapes er snúið við á axis og í angle gráður.
	void setRotation(const Vec3f &axis, const float &angle);

	// Notkun: shapes->setSurface(stiffness, damping, staticf, dynamicf);
	// Fyrir:  shapes er bendir á Shapes hlut,
	//		   stiffness, damping, staticf og dynamicf eru float.
	// Eftir:  Flöturinn er með þéttleikan stiffness, damping í mjúkleika,
	//		   núningurinn er staticf og hreyfinúningurinn er dynamicf.
	void setSurface(const float &stiffness, const float &damping, const float &staticf, const float &dynamicf);

	// Notkun: shapes->setTransparency(transparency);
	// Fyrir:  shapes er bendir á Shapes hlut, 
	//		   transparency er float.
	// Eftir:  shapes er transparency gegnumsætt
	void setTransparency(const float &transparency);

	// Notkun: shapes->setSpecularColor(red,green,blue);
	// Fyrir:  shapes er bendir á Shapes hlut, 
	//		   red, green og blue eru float.
	// Eftir:  shapes er teiknað í (red,green,blue) endurkastanlegum lit. 
	void setSpecularColor(const float &red, const float &green, const float &blue);

	// Notkun: shapes->setShininess(shininess);
	// Fyrir:  shapes er bendir á Shapes hlut, 
	//		   shininess float.
	// Eftir:  shapes er teiknað með shininess glansa. 
	void setShininess(const float &shininess);

	// Notkun: shapes->setMagnetic(startDistance, escapeDistance, springConstant);
	// Fyrir:  shapes er bendir á Shapes hlut, 
	//		   startDistance, escapeDistance
	//		   og springConstant eru float.
	// Eftir:  shapes startDistance er sú lengd sem segulkrafturinn 
	//		   byrjar að toga að sér, escapeDistance er sú lengd
	//		   sem segulkraturinn hættir að hafa áhrif, springConstant
	//		   er hversu mikið á að toga að hlutinum.
	void setMagnetic(const float &startDistance, const float &escapeDistance, const float &springConstant);

	// Notkun: shapes->setSolid(solid);
	// Fyrir:  shapes er bendir á Shapes hlut, solid er bool.
	// Eftir:  shapes er teiknað báðum megin ef og 
	//		   aðeins ef solid er true. Upphafsgildið er true.
	virtual void setSolid(const bool &solid)=0;

	// Notkun: node = shapes->getNode();
	// Fyrir:  shapes er bendir á Shapes hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur shapes hnút.
	virtual Node* getNode(void)=0;
protected:
	Transform *transform;
	Shape *shape;
	Appearance *appearance;
	Material *material;
	MagneticGeometryEffect *magnetic;
	SmoothSurface *surface;
	//H3DFrictionalSurfaceNode *surface;
	Group *resultNode;
	bool enableMagnetic;
};

#endif