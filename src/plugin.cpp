//
//  pluginMain.cpp
//  pluginTemplate
//
//  Created by Godfrey Huang on 2018/5/7.
//
#include "plugin.h"

#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
    MStatus status;

    return status;
}


MStatus uninitializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj);

    return status;
}
