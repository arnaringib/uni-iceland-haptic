#include "Shapes.h"

using namespace std;
using namespace H3D;
using namespace H3DUtil::ArithmeticTypes;

Shapes::Shapes(){
	transform = new Transform;
	shape = new Shape;
	appearance = new Appearance;
	material = new Material;
	surface = new SmoothSurface;
	//surface = new MagneticSurface;
}

Shapes::~Shapes(){
	delete transform;
	delete shape;
	delete appearance;
	delete material;
	delete surface;
}

void Shapes::setTranslation(const Vec3f &translation){
	transform->translation->setValue(translation);
}


void Shapes::setDiffuseColor(const float &red, const float &green, const float &blue){
	material->diffuseColor->setValue(RGB(red,green,blue));
}

void Shapes::setRotation(const Vec3f &axis, const float &angle){
	transform->rotation->setValue(Rotation(axis,angle));
}

//void Shapes::setSurface(const float &stiffness, const float &damping, const float &staticf, const float &dynamicf, const float &snap){
void Shapes::setSurface(const float &stiffness, const float &damping){
	surface->stiffness->setValue(stiffness);
	surface->damping->setValue(damping);
	//surface->dynamicFriction->setValue(dynamicf);
	//surface->staticFriction->setValue(staticf);
	//surface->snapDistance->setValue(snap);
	appearance->surface->setValue(surface);
}

void Shapes::setTransparency(const float &transparency){
	material->transparency->setValue(transparency);
}

void Shapes::setSpecularColor(const float &red, const float &green, const float &blue){
	material->specularColor->setValue(RGB(red,green,blue));
}

void Shapes::setShininess(const float &shininess){
	material->shininess->setValue(shininess);
}