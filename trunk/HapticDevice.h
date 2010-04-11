//
// Þessi klasi sér um alla virkni stafsins
// getur tekið alla þá stafi sem virka með H3D.
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
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//         og stafur er tengdur við tölvuna.
	// Eftir:  Búið er tengjast stafnum 
	void setupDevice();

	// Notkun: hdevice->enableDevice();
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//         og búið að tengjast stafnum.
	// Eftir:  Búið er að virka stafinn. 
	void enableDevice();

	// Notkun: hdevice->disableDevice();
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//         og búið að virkja stafinn.
	// Eftir:  Búið er að af virkja stafinn. 
	void disableDevice();

	// Notkun: err = hdevice->getLastErrorMsg();
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//         err er string.
	// Eftir:  err inniheldur síðasta villuboði
	//         frá stafnum.
	string &getLastErrorMsg();

	// Notkun: en = hdevice->enabled();
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//         en er bool.
	// Eftir:  en er satt ef og aðeins ef 
	//         stafurinn er virkur, annars ósatt.
	bool enabled();

	// Notkun: hdevice->setPosition(position);
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//         position er Vec3f.
	// Eftir:  stafurinn er stilltur á position hnit.
	void setPosition(const Vec3f &position);

	// Notkun: node = hdevice->getNode();
	// Fyrir:  hdevice er bendir á HapticDevice hlut,
	//		   node er Node hlutur.
	// Eftir:  node inniheldur HapticDevice hnút.
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