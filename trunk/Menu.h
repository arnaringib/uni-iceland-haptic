#ifndef _MENU_H
#define _MENU_H

#include <H3D/Transform.h>
#include <H3D/UI/PopupMenu.h>
#include <H3D/UI/Frame.h>
#include <H3D/UI/TouchButton.h>
#include <H3D/UI/GridLayoutManager.h>
#include <H3D/UI/GridInfo.h>
#include "hScenes.h"

using namespace std;
using namespace H3D;

class Menu {
public:
	Menu();
	~Menu();
	// Notkun: menu->addButton(nr);
	// Fyrir:  menn er menu hlutur 
	//         og nr er heiltala á bilinu
	//         0 <= nr <= 3.
	// Eftir:  Ef nr er:
	//		   0 er gerður takki sem teiknar kúlu
	//		   1 er gerður takki sem teiknar kassa
	//		   2 er gerður takki sem teiknar keilu
	//		   3 er gerður takki sem teiknar strokk
	//		   4 er gerður takki sem bætir við segulkrafti
	//		   5 er gerður takki sem teiknar hálfkassa í kringum hlut
	void addButton(const int &nr);
	
	// Notkun: menu->setTranslation(translation);
	// Fyrir:  menu er bendir á Menu hlut, translation
	//		   er Vec3f.
	// Eftir:  Búið er að færa shapes hlutinn á translation((x,y,z))
	//		   hnit miðað við (0,0,0).
	void setTranslation(const Vec3f &translation);
	
	// Notkun: menu->setSize(size);
	// Fyrir:  menn er menu hlutur,
	//			size er Vec3f.
	// Eftir:  menu er með stærð size
	void setSize(Vec3f size);

	// Notkun: node = menu->getMenu();
	// Fyrir:  menu er bendir á Menu hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur senuna.
	Node* getMenu();

	static const int SPHERE = 0;
	static const int BOX = 1;
	static const int CONE = 2;
	static const int CYLINDER = 3;
	static const int MAGNETIC = 4;
	static const int COVER = 5;

private:
	Vec3f size;   // Stærðin á valmyndinni
	int selected; // Valið form.
	Transform *transform;
	PopupMenu *pMenu;
	Frame *frame;
	TouchButton *button;
	GridInfo *grid;
	vector<string> buttonText;
};
#endif