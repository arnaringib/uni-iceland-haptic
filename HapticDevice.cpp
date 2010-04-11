#include "HapticDevice.h"

using namespace std;
using namespace H3D;

HapticDevice::HapticDevice(){
	enable = false;
	lastErrorMsg = "";
	deviceinfo_string = "<DeviceInfo>"
	"<AnyDevice positionCalibration=\"1 0 0 0"
	"								 0 1 0 0"
	"				   				0 0 1 0"
	"								0 0 0 1\" >"
	"	<Shape containerField=\"stylus\">"
	"		<Appearance>"
	"			<Material/>"
	"		</Appearance>"
	"		<Sphere radius=\"0.0025\"/>"
	"	</Shape>"
	"	<RuspiniRenderer/>"
	"</AnyDevice>"
	"	</DeviceInfo>";
}

HapticDevice::~HapticDevice(){
	delete di;
	delete hdev;
}
	
void HapticDevice::setupDevice(){
	if (!DeviceInfo::getActive()){
		try{
			deviceSetup = X3D::createX3DNodeFromString( deviceinfo_string );
		}
		catch( const Exception::H3DException &e ) {
			lastErrorMsg = e.message;
		}
	}
	di = DeviceInfo::getActive();
	hdev = NULL;

	if(di && di->device->size() > 0){
		hdev = di->device->getValueByIndex(0);
	}
}

void HapticDevice::enableDevice(){
	hdev->enableDevice();
	//hdev->initDevice();
	enable = true;
}

void HapticDevice::disableDevice(){
	hdev->disableDevice();
	enable = false;
}

string &HapticDevice::getLastErrorMsg(){
	return lastErrorMsg;
}

bool HapticDevice::enabled(){
	return enable;
}

void HapticDevice::setPosition(const Vec3f &position){
	try{
		hdev->devicePosition->setValue(position);
	}
	catch( const Exception::H3DException &e ) {
		lastErrorMsg = e.message;
	}
}

Node* HapticDevice::getNode(void){	
	return hdev;
}