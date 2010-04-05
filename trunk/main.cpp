#include <H3D/X3D.h>
#include <H3D/Viewpoint.h>
#include <H3D/Scene.h>
#include <H3D/GLUTWindow.h>
#include "hSphere.h"
#include "hBox.h"
#include "hCone.h"
#include "hCylinder.h"
#include "HapticDevice.h"

using namespace H3D;

Viewpoint *vp;
hSphere *hsphere;
hBox *hbox;
hCone *hcone;
hCylinder *hcylinder;
HapticDevice *hDevice;
AutoRef< Group > group( new Group );
AutoRef< Scene > scene( new Scene );

int main(int argc, char* argv[]) {
	hDevice = new HapticDevice;

	hDevice->setupDevice();
	cout << hDevice->getLastErrorMsg() << endl;
	hDevice->enableDevice();
	hDevice->setPosition(Vec3f(0.02f,0.0f,0.0f));
	
	vp = new Viewpoint;

	vp->position->setValue(Vec3f(0,0,0.3f));

	hsphere = new hSphere();
	hsphere->setRadius(0.02f);
	hsphere->setSolid(true);
	hsphere->setDiffuseColor(1,0,0);
	hsphere->setSurface(0.5f,0.0f,0.0f,0.0f);
	hsphere->setMagnetic(0.3f,0.3f,300);

	hcone = new hCone();
	hcone->setBottomRadius(0.02f);
	hcone->setHeight(0.03f);
	hcone->setBottom(true);
	hcone->setSolid(true);
	hcone->setSide(true);
	hcone->setDiffuseColor(0,0,1);
	hcone->setSurface(0.5f,0.0f,0.0f,0.0f);
	hcone->setTranslation(Vec3f(0.0f,0.03f,0.0f));
	hcone->setMagnetic(0.3f,0.3f,300);

	hcylinder = new hCylinder();
	hcylinder->setRadius(0.02f);
	hcylinder->setHeight(0.03f);
	hcylinder->setBottom(true);
	hcylinder->setTop(true);
	hcylinder->setSolid(true);
	hcylinder->setSide(true);
	hcylinder->setDiffuseColor(0,0.5f,0.5f);
	hcylinder->setSurface(0.5f,0.0f,0.0f,0.0f);
	hcylinder->setTranslation(Vec3f(0.0f,0.0f,0.03f));
	hcylinder->setMagnetic(0.3f,0.3f,300);

	hbox = new hBox();
	hbox->setSize(Vec3f(0.04f,0.04f,0.04f));
	hbox->setSolid(true);
	hbox->setDiffuseColor(0,1,0);
	hbox->setTranslation(Vec3f(0.03f,0.0f,0.0f));
	hbox->setTransparency(0.4f);
	hbox->setSurface(0.6f,0.0f,0.0f,0.0f);

	try{
		group->children->push_back(hDevice->getNode());
	}
	catch( const Exception::H3DException &e ) {
		cerr << e.message << endl;
	}
	group->children->push_back(hsphere->getNode());
	group->children->push_back(hbox->getNode());
	group->children->push_back(hcone->getNode());
	group->children->push_back(hcylinder->getNode());

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
