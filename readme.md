# Auto Sort Level Boundaries

This is a Python Script that will move all of the selected objects in the editor to the Level of their nearest LevelStreamingVolume.

This does not take into consideration the size or shape of the level streaming volume, only their position.

There is also a C++ method that has to be added to the project to expose some methods to Blueprints. 

Tested on versions 4.24.3 & 4.22.x



----
## References


[Epic Tutorial for Enabling Python Plugin](https://docs.unrealengine.com/en-US/Engine/Editor/ScriptingAndAutomation/Python/index.html)

----
## Usage

###Enable Python Plugin

Enable the [python plugin](https://docs.unrealengine.com/en-US/Engine/Editor/ScriptingAndAutomation/Python/index.html)
 for your project

###C++ Classes
Create a new C++ class and paste the code into it. Make sure you change the PROJECTNAME_API in the header file to the appropriate name for your project.



###Using the Script

Select the objects you want to sort in the editor and then press "File" - "Execute Python Script". Navigate to autoSortLevelBoundaries.py on disk.

Actors are sorted one at a time so it is possible to undo one by one.

###License

License is MIT license, Unreal Engine 4 is subject to its respective license, Epic Games etc..
