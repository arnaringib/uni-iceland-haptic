#include <H3D/X3D.h>
#include <H3D/Viewpoint.h>
#include <H3D/Scene.h>
#include <H3D/GLUTWindow.h>
#include "hSphere.h"
#include "hBox.h"
/*#include "hCone.h"
#include "hCylinder.h"*/
#include "HapticDevice.h"

using namespace H3D;

Viewpoint *vp;
HapticDevice *hDevice;
AutoRef< Group > group( new Group );
AutoRef< Scene > scene( new Scene );

void simpleBall(){
	hSphere *hsphere = new hSphere();
	hsphere->setRadius(0.05f);
	hsphere->setSolid(true);
	hsphere->setDiffuseColor(1,0,0);
	hsphere->setSurface(0.5f,0.0f,0.0f,0.0f);

	group->children->push_back(hsphere->getNode());
}

void boxCover(){
	//Bottom Blue
	hBox *bottom = new hBox();
	bottom->setSize(Vec3f(0.16f,0.001f,0.2f));
	bottom->setSolid(true);
	bottom->setDiffuseColor(0,0,1);
	bottom->setSurface(1.0f,0.0f,0.0f,0.0f);
	bottom->setTranslation(Vec3f(0.0f,-0.08f,0.0f));

	//Leftside Blue
	hBox *leftSide = new hBox();
	leftSide->setSize(Vec3f(0.001f,0.16f,0.2f));
	leftSide->setSolid(true);
	leftSide->setDiffuseColor(0,0,1);
	leftSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	leftSide->setTranslation(Vec3f(-0.08f,0.0f,0.0f));

	//Rightside Blue
	hBox *rightSide = new hBox();
	rightSide->setSize(Vec3f(0.001f,0.16f,0.2f));
	rightSide->setSolid(true);
	rightSide->setDiffuseColor(0,0,1);
	rightSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	rightSide->setTranslation(Vec3f(0.08f,0.0f,0.0f));

	//Backside Blue
	hBox *backSide = new hBox();
	backSide->setSize(Vec3f(0.16f,0.16f,0.001f));
	backSide->setSolid(true);
	backSide->setDiffuseColor(0,0,1);
	backSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	backSide->setTranslation(Vec3f(0.0f,0.0f,-0.1f));

	//Frontside transparant
	hBox *frontSide = new hBox();
	frontSide->setSize(Vec3f(0.16f,0.16f,0.001f));
	frontSide->setSolid(true);
	frontSide->setTransparency(1.0f);
	frontSide->setSurface(1.0f,0.0f,0.0f,0.0f);
	frontSide->setTranslation(Vec3f(0.0f,0.0f,0.1f));

	//Bottom transparant
	hBox *top = new hBox();
	top->setSize(Vec3f(0.16f,0.001f,0.2f));
	top->setSolid(true);
	top->setTransparency(1.0f);
	top->setSurface(1.0f,0.0f,0.0f,0.0f);
	top->setTranslation(Vec3f(0.0f,0.08f,0.0f));

	group->children->push_back(bottom->getNode());
	group->children->push_back(leftSide->getNode());
	group->children->push_back(rightSide->getNode());
	group->children->push_back(backSide->getNode());
	group->children->push_back(backSide->getNode());
	group->children->push_back(frontSide->getNode());
	group->children->push_back(top->getNode());
}

int main(int argc, char* argv[]) {
	hDevice = new HapticDevice;

	hDevice->setupDevice();
	cout << hDevice->getLastErrorMsg() << endl;
	hDevice->enableDevice();
	hDevice->setPosition(Vec3f(0.02f,0.0f,0.0f));

	vp = new Viewpoint;

	vp->position->setValue(Vec3f(0.0f,0.0f,0.3f));

	try{
		group->children->push_back(hDevice->getNode());
	}
	catch( const Exception::H3DException &e ) {
		cerr << e.message << endl;
	}

	simpleBall();
	boxCover();

	// create a window to display
	GLUTWindow *glwindow = new GLUTWindow;
	glwindow->viewpoint->setValue(vp);

	// add the window to the scene.
	scene->window->push_back( glwindow );

	// add our group node that is to be displayed to the scene.
	scene->sceneRoot->setValue(group.get());

	// start the main loop
	Scene::mainLoop();
}
