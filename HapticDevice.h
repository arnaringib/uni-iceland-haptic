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
	
	void setupDevice();
	void enableDevice();
	void disableDevice();
	string &getLastErrorMsg();
	bool enabled();
	void setPosition(const Vec3f &position);
	Node* getNode(void);

private:
	AutoRef< Node > deviceSetup;
	string deviceinfo_file;
	bool enable;
	string lastErrorMsg;
	DeviceInfo *di;
	H3DHapticsDevice *hdev;
};

#endif