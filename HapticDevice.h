//
// �essi klasi s�r um alla virkni stafsins
// getur teki� alla �� stafi sem virka me� H3D.
//

#ifndef _HATPICDEVICE_H
#define _HATPICDEVICE_H

#include <H3D/X3D.h>
#include <H3D/DeviceInfo.h>
#include <H3D/H3DHapticsDevice.h>
#include <H3D/AnyDevice.h>
#include <H3D/HapticsRenderers.h>

using namespace std;
using namespace H3D;

class HapticDevice{
public:
	HapticDevice();
	~HapticDevice();
	
	// Notkun: hdevice->setupDevice();
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//         og stafur er tengdur vi� t�lvuna.
	// Eftir:  B�i� er tengjast stafnum 
	void setupDevice();

	// Notkun: hdevice->enableDevice();
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//         og b�i� a� tengjast stafnum.
	// Eftir:  B�i� er a� virka stafinn. 
	void enableDevice();

	// Notkun: hdevice->disableDevice();
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//         og b�i� a� virkja stafinn.
	// Eftir:  B�i� er a� af virkja stafinn. 
	void disableDevice();

	// Notkun: err = hdevice->getLastErrorMsg();
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//         err er string.
	// Eftir:  err inniheldur s��asta villubo�i
	//         fr� stafnum.
	string &getLastErrorMsg();

	// Notkun: en = hdevice->enabled();
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//         en er bool.
	// Eftir:  en er satt ef og a�eins ef 
	//         stafurinn er virkur, annars �satt.
	bool enabled();

	// Notkun: hdevice->setPosition(position);
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//         position er Vec3f.
	// Eftir:  stafurinn er stilltur � position hnit.
	void setPosition(const Vec3f &position);

	// Notkun: node = hdevice->getNode();
	// Fyrir:  hdevice er bendir � HapticDevice hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur HapticDevice hn�t.
	Node* getNode(void);

private:
	AutoRef< Node > deviceSetup;
	string deviceinfo_string;
	bool enable;
	string lastErrorMsg;
	DeviceInfo *di;
	H3DHapticsDevice *hdev;
};

#endif