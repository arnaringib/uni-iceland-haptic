#include <H3D/X3D.h>
#include <H3D/Viewpoint.h>
#include <H3D/Scene.h>
#include <H3D/GLUTWindow.h>
#include "hScenes.h"
#include "HapticDevice.h"

using namespace H3D;

Viewpoint *vp;
HapticDevice *hDevice;
hScenes *hscenes;
AutoRef< Group > group( new Group );
AutoRef< Scene > scene( new Scene );

int main(int argc, char* argv[]) {
	// Set Haptic Device
	hDevice = new HapticDevice;

	hDevice->setupDevice();
	cout << hDevice->getLastErrorMsg() << endl;
	hDevice->enableDevice();
	hDevice->setPosition(Vec3f(0.0f,0.0f,0.0f));

	try{
		group->children->push_back(hDevice->getNode());
	}
	catch( const Exception::H3DException &e ) {
		cerr << e.message << endl;
	}

	// Viewpoint
	vp = new Viewpoint;

	vp->position->setValue(Vec3f(0.0f,0.0f,0.3f));

	// Scene
	hscenes = new hScenes();

	hscenes->shape(hScenes::BOX);
	//hscenes->addCover();
	//hscenes->addMagnetic();

	group->children->push_back(hscenes->getScene());

	// Create a window to display
	GLUTWindow *glwindow = new GLUTWindow;
	glwindow->viewpoint->setValue(vp);

	// Add the window to the scene.
	scene->window->push_back( glwindow );

	// Add our group node that is to be displayed to the scene.
	scene->sceneRoot->setValue(group.get());

	// Start the main loop
	Scene::mainLoop();
}
