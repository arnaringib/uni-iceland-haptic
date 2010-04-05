#include "hCylinder.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

hCylinder::hCylinder() : Shapes(){
	cylinder = new Cylinder;
}

hCylinder::~hCylinder(){
	delete cylinder;
}

void hCylinder::setRadius(const float &radius){
	cylinder->radius->setValue(radius);
}

void hCylinder::setBottom(const bool &bottom){
	cylinder->bottom->setValue(bottom);
}

void hCylinder::setTop(const bool &top){
	cylinder->top->setValue(top);
}

void hCylinder::setHeight(const float &height){
	cylinder->height->setValue(height);
}

void hCylinder::setSide(const bool &side){
	cylinder->side->setValue(side);
}

void hCylinder::setSolid(const bool &solid){
	cylinder->solid->setValue(solid);
}

Node* hCylinder::getNode(void){
	shape->appearance->setValue(appearance);
	appearance->material->setValue(material);
	shape->geometry->setValue(cylinder);
	transform->children->push_back(shape);

	resultNode->children->push_back(transform);

	if(enableMagnetic)
	{
		magnetic->geometry->setValue(cylinder);

		resultNode->children->push_back(magnetic);
	}

	return resultNode;
}