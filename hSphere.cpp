#include "hSphere.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

hSphere::hSphere() : Shapes(){
	sphere = new Sphere;
}

hSphere::~hSphere(){
	delete sphere;
}

void hSphere::setRadius(const float &radius){
	sphere->radius->setValue(radius);
}

void hSphere::setSolid(const bool &solid){
	sphere->solid->setValue(solid);
}

Node* hSphere::getNode(void){
	shape->appearance->setValue(appearance);
	appearance->material->setValue(material);
	shape->geometry->setValue(sphere);
	transform->children->push_back(shape);

	resultNode->children->push_back(transform);

	if(enableMagnetic)
	{
		magnetic->geometry->setValue(sphere);

		resultNode->children->push_back(magnetic);
	}

	return resultNode;
}