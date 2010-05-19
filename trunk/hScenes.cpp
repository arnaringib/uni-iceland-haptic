#include "hScenes.h"

using namespace std;
using namespace H3D;

hScenes::hScenes(){
	group = new Group();
	selected = -1;
	size = 0.06f;
}

hScenes::~hScenes(){
	delete group;
}

void hScenes::shape(const int &nr){
	selected = nr;
	if(selected == SPHERE){
		hSphere *hsphere = new hSphere();
		hsphere->setRadius(size/2.0f);
		hsphere->setSolid(true);
		hsphere->setDiffuseColor(1,0,0);
		hsphere->setSurface(0.5f,0.0f,0.6f,0.0f);
		
		item = hsphere;
		
	}
	else if(selected == BOX){
		hBox *hbox = new hBox();
		hbox->setSize(Vec3f(size,size,size));
		hbox->setSolid(true);
		hbox->setDiffuseColor(1,0,0);
		hbox->setSurface(0.5f,0.0f,0.6f,0.0f);

		item = hbox;
	}
	else if(selected == CONE){
		hCone *hcone = new hCone();
		hcone->setBottomRadius(size/2.0f);
		hcone->setHeight(size);
		hcone->setSide(true);
		hcone->setBottom(true);
		hcone->setSolid(true);
		hcone->setDiffuseColor(1,0,0);
		hcone->setSurface(0.5f,0.0f,0.6f,0.0f);

		item = hcone;
	}
	else if(selected == CYLINDER){
		hCylinder *hcylinder = new hCylinder();
		hcylinder->setRadius(size/2.0f);
		hcylinder->setHeight(size);
		hcylinder->setSide(true);
		hcylinder->setBottom(true);
		hcylinder->setTop(true);
		hcylinder->setSolid(true);
		hcylinder->setDiffuseColor(1,0,0);
		hcylinder->setSurface(0.5f,0.0f,0.6f,0.0f);

		item = hcylinder;
	}
}


void hScenes::addCover(){
	//Bottom Blue
	hBox *bottom = new hBox();
	bottom->setSize(Vec3f(0.10f,0.001f,0.10f));
	bottom->setSolid(true);
	bottom->setDiffuseColor(0,0,1);
	bottom->setSurface(1.0f,0.0f,0.0f,0.0f);
	bottom->setTranslation(Vec3f(0.0f,-0.05f,0.0f));

	//Rightside Blue
	hBox *rightSide = new hBox();
	rightSide->setSize(Vec3f(0.001f,0.10f,0.10f));
	rightSide->setSolid(true);
	rightSide->setDiffuseColor(0,0,1);
	rightSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	rightSide->setTranslation(Vec3f(0.05f,0.0f,0.0f));

	//Backside Blue
	hBox *backSide = new hBox();
	backSide->setSize(Vec3f(0.10f,0.10f,0.001f));
	backSide->setSolid(true);
	backSide->setDiffuseColor(0,0,1);
	backSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	backSide->setTranslation(Vec3f(0.0f,0.0f,-0.05f));

	//Leftside transparant
	hBox *leftSide = new hBox();
	leftSide->setSize(Vec3f(0.001f,0.10f,0.10f));
	leftSide->setSolid(true);
	leftSide->setTransparency(1.0f);
	leftSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	leftSide->setTranslation(Vec3f(-0.05f,0.0f,0.0f));

	//Bottom transparant
	hBox *top = new hBox();
	top->setSize(Vec3f(0.10f,0.001f,0.10f));
	top->setSolid(true);
	top->setTransparency(1.0f);
	top->setSurface(1.0f,0.0f,0.0f,0.0f);
	top->setTranslation(Vec3f(0.0f,0.05f,0.0f));

	group->children->push_back(bottom->getNode());
	group->children->push_back(leftSide->getNode());
	group->children->push_back(rightSide->getNode());
	group->children->push_back(backSide->getNode());
	group->children->push_back(backSide->getNode());
	group->children->push_back(top->getNode());
}

void hScenes::addMagnetic(){
	item->setMagnetic(0.01f,0.4f,300.0f);
}

Node* hScenes::getScene(){
	group->children->push_back(item->getNode());
	return group;
}



