#include <H3D/X3D.h>
#include <H3D/Viewpoint.h>
#include <H3D/Scene.h>
#include <H3D/GLUTWindow.h>
#include <H3D/DeviceInfo.h>
#include "hSphere.h"
#include "hBox.h"

using namespace H3D;

Viewpoint *vp;
hSphere *hsphere;
hBox *hbox;
AutoRef< Group > group( new Group );
AutoRef< Scene > scene( new Scene );

int main(int argc, char* argv[]) {
	vp = new Viewpoint;

	vp->position->setValue(Vec3f(0,0,0.6f));

	hsphere = new hSphere();
	hsphere->setRadius(0.1f);
	hsphere->setSolid(true);
	hsphere->setDiffuseColor(1,0,0);


	hbox = new hBox();
	hbox->setSize(Vec3f(0.1f,0.1f,0.1f));
	hbox->setSolid(true);
	hbox->setDiffuseColor(0,1,0);
	hbox->setTranslation(Vec3f(0.1f,0.0f,0.0f));
	hbox->setTransparency(1.0f);
	
	group->children->push_back(hsphere->getNode());
	group->children->push_back(hbox->getNode());

	// create a window to display
	GLUTWindow *glwindow = new GLUTWindow;
	
	// add the window to the scene.
	scene->window->push_back( glwindow );

	// add our group node that is to be displayed to the scene.
	scene->sceneRoot->setValue(group.get());

	// start the main loop
	Scene::mainLoop();
}
