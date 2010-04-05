#include "hCone.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

hCone::hCone() : Shapes(){
	cone = new Cone;
}

hCone::~hCone(){
	delete cone;
}

void hCone::setBottomRadius(const float &bottomRadius){
	cone->bottomRadius->setValue(bottomRadius);
}

void hCone::setBottom(const bool &bottom){
	cone->bottom->setValue(bottom);
}

void hCone::setHeight(const float &height){
	cone->height->setValue(height);
}

void hCone::setSide(const bool &side){
	cone->side->setValue(side);
}

void hCone::setSolid(const bool &solid){
	cone->solid->setValue(solid);
}

Node* hCone::getNode(void){
	shape->appearance->setValue(appearance);
	appearance->material->setValue(material);
	shape->geometry->setValue(cone);
	transform->children->push_back(shape);

	resultNode->children->push_back(transform);

	if(enableMagnetic)
	{
		magnetic->geometry->setValue(cone);

		resultNode->children->push_back(magnetic);
	}

	return resultNode;
}