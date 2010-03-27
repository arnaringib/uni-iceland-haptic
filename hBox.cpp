#include "hBox.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

hBox::hBox() : Shapes(){
	box = new Box;
}

hBox::~hBox(){
	delete box;
}

void hBox::setSize(const Vec3f &size){
	box->size->setValue(size);
}

void hBox::setSolid(const bool &solid){
	box->solid->setValue(solid);
}

Node* hBox::getNode(void){
	shape->appearance->setValue(appearance);
	appearance->material->setValue(material);
	shape->geometry->setValue(box);
	transform->children->push_back(shape);

	return transform;
}