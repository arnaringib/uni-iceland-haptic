#include <H3D/X3D.h> 
  
 #include <H3D/Viewpoint.h> 
  
 #include <H3D/Scene.h> 
  
 #include <H3D/GLUTWindow.h> 
  
 #include "hScenes.h" 
 #include <H3D/MouseSensor.h>
 #include "HapticDevice.h" 


 #include <H3D/UI/PopupMenu.h>
 #include <H3D/UI/Frame.h>
 #include <H3D/UI/TouchButton.h>
 #include <H3D/UI/GridLayoutManager.h>
 #include <H3D/UI/GridInfo.h>

//#include "Menu.h"
  
 using namespace H3D; 

 Viewpoint *vp, *uiVp; 
  
 HapticDevice *hDevice; 
  
 hScenes *hscenes; 
 
// Menu *menu;
 PopupMenu *pmBox, *pmSphere, *pmCone, *pmCylinder, *pmMagnetic, *pmCover;
 Frame *mainFrame;
 TouchButton *bBox, *bSphere, *bCone, *bCylinder, *bMagnetic, *bCover;
 GridLayoutManager *gridLayout;
 GridInfo *gridBox, *gridSphere, *gridCone, *gridCylinder, *gridMagnetic, *gridCover;

 AutoRef< Group > group( new Group ); 

 AutoRef< Scene > scene( new Scene ); 

 // update klasar (kannski hægt að sameina með TypedField< > í stað AutoUpdate?
 class selectBox: public AutoUpdate< SFBool > {
	virtual void update(){
		 AutoUpdate< SFBool >::update();
		 if( value ){
			cout << "clicked" << endl;
			//hscenes = new hScenes();
			hscenes->shape(hScenes::BOX); 
			Node *g;
			//group->children->erase(1);
			//group.reset(hscenes->getScene());
			g = hscenes->getScene();
			group->children->push_back(g);
		} 
	 }
};
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
		 hscenes->shape(hScenes::CONE);
		 //hscenes->addCover(); 
		// hscenes->addMagnetic(); 
		
		// Bæta við valmynd(menu)
		//menu = new Menu; afkommenta þegar búið er að virkja Menu-klasann
		mainFrame = new Frame;
		pmBox = new PopupMenu;
		pmSphere = new PopupMenu;
		pmCylinder = new PopupMenu;
		pmCone = new PopupMenu;
		pmMagnetic = new PopupMenu;
		pmCover = new PopupMenu;
		PopupMenu *pMenus[6]  = {pmBox, pmSphere, pmCone, pmCylinder, pmMagnetic, pmCover};

		bBox = new TouchButton;
		bSphere  = new TouchButton;
		bCone = new TouchButton;
		bCylinder = new TouchButton;
		bMagnetic = new TouchButton;
		bCover  = new TouchButton;
		TouchButton *buttons[6] = {bBox, bSphere, bCone, bCylinder, bMagnetic, bCover};

		gridBox = new GridInfo;
	 	gridSphere = new GridInfo;
		gridCone= new GridInfo;
		gridCylinder = new GridInfo;
		gridMagnetic = new GridInfo;
		gridCover = new GridInfo;
		GridInfo *grids[] = {gridBox, gridSphere, gridCone, gridCylinder, gridMagnetic, gridCover};

		mainFrame->desiredSize->setValue(Vec3f(0.05f, 0.1f, 0.001f));
		mainFrame->layoutManager->setValue(new GridLayoutManager);

		string bText[] = {"Box", "Sphere", "Cone", "Cylinder", "Magnetic Force", "Cover"};
		vector<string> buttonText;

		for(int i=0; i<=5;i++){
			// stilla takkana
			buttons[i]->buttonMode->setValue("NORMAL");
			buttonText.push_back(bText[i]);
			buttons[i]->text->setValue(buttonText);

			// grid-upplýsingar fyrir hvert popupmenu með takka 
			grids[i]->row->setValue(i);
			grids[i]->padding->setValue(Vec2f(0.001f,0.001f));
			grids[i]->sticky->setValue("W+E+N+S");

			//Bæta tökkum á menu-ið með gridlayout
			pMenus[i]->button->setValue(buttons[i]);
			pMenus[i]->layoutInfo->setValue(grids[i]);

			//bæta popupmenu-unum  við frame
			mainFrame->children->push_back(pMenus[i]);
			buttonText.pop_back();
		}
		
		selectBox *sBox = new selectBox();
		selectSphere *sSphere = new selectSphere();
		selectCone *sCone = new selectCone();
		selectCylinder *sCylinder = new selectCylinder();
		selectForce *sForce = new selectForce();
		selectCover *sCover = new selectCover();

		//atburðir sem gerast þegar ýtt er á takkana
		 bBox->isPressed->route(sBox);
		 bSphere->isPressed->route(sSphere);
		 bCone->isPressed->route(sCone);
		 bCylinder->isPressed->route(sCylinder);
		// bMagnetic->isPressed->route(sForce); //kemur villa
		 bCover->isPressed->route(sCover);

		 // staðsetja menu-inn
		 AutoRef< Transform > popup_transform(new Transform); 
		 popup_transform->children->push_back(mainFrame);
		 popup_transform->translation->setValue( Vec3f(0.135f,0.07f,-0.001f));
	
		 group->children->push_back(popup_transform.get()); 
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
  
 