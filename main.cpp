#include <H3D/X3D.h> 
#include <H3D/Viewpoint.h> 
#include <H3D/Scene.h> 
#include <H3D/GLUTWindow.h> 
#include "HapticDevice.h" 
#include "Menu.h"
  
 using namespace H3D; 

 Viewpoint *vp, *uiVp; 
 HapticDevice *hDevice; 
	 Menu *menu;

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
		
		// Bæta við valmynd(menu)
		menu = new Menu();
		menu->addButton(Menu::SPHERE);
		menu->addButton(Menu::BOX);
		menu->addButton(Menu::CONE);
		menu->addButton(Menu::CYLINDER);
		menu->addButton(Menu::MAGNETIC);
		menu->addButton(Menu::COVER);
		menu->setTranslation(Vec3f(0.135f,0.07f,-0.001f));
		
		group->children->push_back(menu->getMenu()); 

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
  
 