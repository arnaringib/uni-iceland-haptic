Create a New Project. Choose a project type as 'Win32 Console Application', type in a name for the project and press OK.

In the Win32 Application Wizard->Overview click on a Next button, in the Application type make sure that 'Console Application' is selected and Additional options has 'Empty project', click on the Finish button.

Before compiling you need to include a few header files and a few libraries. So go to Tools->Options, and click the plus next to 'Project and Solutions' and select 'VC++ Directories'. In the drop down box show directories for: choose 'Include Files' and add the following directories(C:\H3D is the default select your own directory if you need to):
C:\H3D\External\include
C:\H3D\H3DUtil\include
C:\H3D\HAPI\include
C:\H3D\H3DAPI\include
Next select 'Library Files' in Show Directories for, and add the following directories:
C:\H3D\lib
C:\H3D\External\lib
Click on OK.

Next go to Project->Properties. In the Configuration drop down box make sure 'All configuration' is selected. Then click on the plus next to Configuration Properties, then click on the plus next to Linker and select 'Input'. In Additional Dependencies add this string: opengl32.lib glut32.lib glu32.lib H3DAPI\_vc9.lib H3Dutil\_vc9.lib HAPI\_vc9.lib  (VC9 is for Visual 2008)
Click on OK, and start coding.
Notice: Run in Release mode - not debug mode!

To use the UI-library with H3D:
Download the UI and follow the directions on http://www.h3dapi.org/modules/mediawiki/index.php/UI
Copy the lib and dll files you get from building the INSTALL project. Put UI\_vc9.lib in C:\H3D\lib, and UI\_vc9.dll in C:\H3D\bin. Copy the folder UI from UI-2.0-Source\UI\include\H3D and paste it into C:\H3D\H3DAPI\include\H3D. Copy the source files from UI-2.0-Source\UI\src into C:\H3D\H3DAPI\src. Remember to also link to these files! Add UI\_vc9.lib in Project->Properties....->Linker->Input

Attention: This may no work for everyone, so if you get a error with including a header file, you can usually find them in the H3D directory. You can just search for the file and add the directory they are in, to the 'Include Files' as was shown above.
And the same can be done to a linker problem as to the header files.