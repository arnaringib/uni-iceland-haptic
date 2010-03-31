#include <H3D/X3D.h>
#include <H3D/Viewpoint.h>
#include <H3D/Scene.h>

#include <H3D/DeviceInfo.h>
#include <H3D/H3DHapticsDevice.h>
#include <H3D/AnyDevice.h>
#include <H3D/HapticsRenderers.h>

#include <H3D/GLUTWindow.h>
#include "hSphere.h"
#include "hBox.h"

using namespace H3D;

Viewpoint *vp;
hSphere *hsphere;
hBox *hbox;
AutoRef< Group > group( new Group );
AutoRef< Scene > scene( new Scene );
AutoRef< Node > deviceSetup;

string deviceinfo_string = "<DeviceInfo>\n"
"  <AnyDevice positionCalibration=\"1 0 0 0\n"
"                                  0 1 0 0\n"
"                                  0 0 1 0\n"
"                                  0 0 0 1\" >\n"
"        <Shape containerField=\"stylus\">"
"          <Appearance>"
"            <Material/>"
"          </Appearance>"
"          <Sphere radius=\"0.0025\"/>"
"        </Shape>"
"        <RuspiniRenderer/>"
//"    <GodObjectRenderer/>\n"
"  </AnyDevice>\n"
"</DeviceInfo>\n";

int main(int argc, char* argv[]) {

	if (!DeviceInfo::getActive()){
		if( deviceinfo_string.size() > 0){
			try{
				deviceSetup = X3D::createX3DNodeFromString( deviceinfo_string );
				cout << "Gets from a string" << endl;
			}
			catch( const Exception::H3DException &e ) {
				cerr << e.message << endl;
			}
		}
	}

	DeviceInfo *di = DeviceInfo::getActive();
	H3DHapticsDevice *hdev = NULL;

	if(di && di->device->size() > 0){
		hdev = di->device->getValueByIndex(0);
	}
	
	hdev->enableDevice();
	cout << hdev->enabled->getValueAsString() << endl;
	hdev->initDevice();
	
	try{
		hdev->devicePosition->setValue(Vec3f(0.2f,0.0f,0.0f));
	}
	catch( const Exception::H3DException &e ) {
		cerr << e.message << endl;
	}
	
	vp = new Viewpoint;

	vp->position->setValue(Vec3f(0,0,0.3f));

	hsphere = new hSphere();
	hsphere->setRadius(0.02f);
	hsphere->setSolid(true);
	hsphere->setDiffuseColor(1,0,0);
	hsphere->setSurface(0.5f,0.0f);

	hbox = new hBox();
	hbox->setSize(Vec3f(0.04f,0.04f,0.04f));
	hbox->setSolid(true);
	hbox->setDiffuseColor(0,1,0);
	hbox->setTranslation(Vec3f(0.03f,0.0f,0.0f));
	hbox->setTransparency(0.4f);
	hbox->setSurface(0.6f,0.0f);

	try{
		group->children->push_back(hdev);
	}
	catch( const Exception::H3DException &e ) {
		cerr << e.message << endl;
	}
	group->children->push_back(hsphere->getNode());
	group->children->push_back(hbox->getNode());

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
