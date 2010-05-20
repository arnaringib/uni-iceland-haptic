#include "Menu.h"

using namespace std;
using namespace H3D;

hScenes *hscenes;
Group *group = new Group; 

class selectSphere: public AutoUpdate< SFBool > {
	virtual void update(){
		AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "sphere" << endl; 
			hscenes->shape(hScenes::SPHERE); 
			group->children->push_back(hscenes->getScene()); 
		}
	 }
 };
class selectBox: public AutoUpdate< SFBool > {
	virtual void update(){
		 AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "clicked" << endl;
			hscenes->shape(hScenes::BOX); 
			group->children->push_back(hscenes->getScene());
		} 
	 }
};
class selectCone: public AutoUpdate< SFBool > {
	virtual void update(){
		AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "cone" << endl; 
			hscenes->shape(hScenes::CONE); 
			group->children->push_back(hscenes->getScene()); 
		}
	 }
};
class selectCylinder: public AutoUpdate< SFBool > {
	virtual void update(){
		AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "cylinder" << endl; 
			hscenes->shape(hScenes::CYLINDER); 
			group->children->push_back(hscenes->getScene()); 
		}
	 }
};
class selectForce: public AutoUpdate< SFBool > {
	virtual void update(){
		AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "force" << endl; 
			hscenes->addMagnetic(); 
			group->children->push_back(hscenes->getScene()); 
		}
	 }
 };
class selectCover: public AutoUpdate< SFBool > {
	virtual void update(){
		AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "force" << endl; 
			hscenes->addCover(); 
			group->children->push_back(hscenes->getScene()); 
		}
	 }
};

Menu::Menu() {
	frame = new Frame;
	transform = new Transform;
	hscenes = new hScenes();
	selected = -1;
	hscenes->shape(hScenes::CONE); 

	frame->desiredSize->setValue(Vec3f(0.05f, 0.1f, 0.001f));
	frame->layoutManager->setValue(new GridLayoutManager);

}

Menu::~Menu(){
	delete frame;
	delete pMenu;
	delete transform;
	delete grid;
}

void Menu:: addButton(const int &nr){
	selected = nr;

	pMenu = new PopupMenu;
	button = new TouchButton;
	grid = new GridInfo;
	grid->padding->setValue(Vec2f(0.001f,0.001f));
	grid->sticky->setValue("W+E+N+S");

	//event handlers
	selectSphere *sSphere = new selectSphere();
	selectBox *sBox = new selectBox();
	selectCone *sCone = new selectCone();
	selectCylinder *sCylinder = new selectCylinder();
	selectForce *sForce = new selectForce();
	selectCover *sCover = new selectCover();

	if(selected == SPHERE){
		button->buttonMode->setValue("NORMAL");
		buttonText.push_back("Sphere");
		button->text->setValue(buttonText);
		//staðsetningin í grid-inu
		grid->row->setValue(SPHERE);
		// event handler
		button->isPressed->route(sSphere); 
	}
	if(selected == BOX){
		button->buttonMode->setValue("NORMAL");
		buttonText.push_back("Box");
		button->text->setValue(buttonText);
		grid->row->setValue(BOX);
		button->isPressed->route(sBox);
	}
	if(selected == CONE){
		button->buttonMode->setValue("NORMAL");
		buttonText.push_back("Cone");
		button->text->setValue(buttonText);
		grid->row->setValue(CONE);
		button->isPressed->route(sCone);
	}
	if(selected == CYLINDER){
		button->buttonMode->setValue("NORMAL");
		buttonText.push_back("Cylinder");
		button->text->setValue(buttonText);
		grid->row->setValue(CYLINDER);
		button->isPressed->route(sCylinder);
	}
	if(selected == MAGNETIC){
		button->buttonMode->setValue("NORMAL");
		buttonText.push_back("Magnetic Force");
		button->text->setValue(buttonText);
		grid->row->setValue(MAGNETIC);
		button->isPressed->route(sForce);
	}
	if(selected == COVER){
		button->buttonMode->setValue("NORMAL");
		buttonText.push_back("Cover");
		button->text->setValue(buttonText);
		grid->row->setValue(COVER);
		button->isPressed->route(sCover);
	}

	//Bæta tökkum á menu-ið með gridlayout
	pMenu->button->setValue(button);
	pMenu->layoutInfo->setValue(grid);

	//bæta popupmenu-unum  við frame
	frame->children->push_back(pMenu);
	buttonText.pop_back();

}

void Menu::setSize(Vec3f size) {
	frame->desiredSize->setValue(size);
}

Node* Menu::getMenu(){
	transform->children->push_back(frame);
	group->children->push_back(transform);
	group->children->push_back(hscenes->getScene()); 
	return group;
}

void Menu::setTranslation(const Vec3f &translation){
	transform->translation->setValue(translation);
}