//
//  pluginMain.cpp
//  holyMagicEyeball
//
//  Created by Godfrey Huang on 2018/5/7.
//
////////////////////////////////////////////////////////////////////////
// DESCRIPTION:
//
// Produces the command "meshOp" and the dependency node "meshOpNode".
//
// Demonstrates the use of the high level polygon API methods that have been added to MFnMesh.
//
//	Syntax: meshOp $operationType
//
//	Where, $operationType is one of the following:
//
//		0 - Subdivide edge(s)
//
//		1 - Subdivide face(s)
//
//		2 - Extrude edge(s)
//
//		3 - Extrude face(s)
//
//		4 - Collapse edge(s)
//
//		5 - Collapse face(s)
//
//		6 - Duplicate face(s)
//
//		7 - Extract face(s)
//
//		8 - Split face(s)
//
//	Example usage:
//
//		- Select the appropriate component (edge, face)
//		- meshOp 2;
//
//	Note that this plug-in re-uses the following files from "splitUVCmd".
//
//		- polyModifierNode.cpp
//		- polyModifierCmd.cpp
//		- polyModifierFty.cpp
//
////////////////////////////////////////////////////////////////////////

#include "plugin.h"
#include "eyeDeformer.h"
#include "meshOpCmd.h"
#include "meshOpNode.h"

#include <maya/MFnPlugin.h>


MStatus initializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj, "Godfrey Huang - Holy Animation Studios", VERSION, "Any");

	status = plugin.registerCommand( "holyMeshOp", meshOp::creator );
	CHECK_MSTATUS_AND_RETURN_IT(status)

	status = plugin.registerNode( "holyMeshOpNode",
								  meshOpNode::id,
								  meshOpNode::creator,
								  meshOpNode::initialize );
	CHECK_MSTATUS_AND_RETURN_IT(status)

    status = plugin.registerNode("holyEyeDeformer", EyeDeformer::id,
		EyeDeformer::creator, EyeDeformer::initialize, MPxNode::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);


    return status;
}


MStatus uninitializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj);

	status = plugin.deregisterCommand( "holyMeshOp" );
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = plugin.deregisterNode( meshOpNode::id );
	CHECK_MSTATUS_AND_RETURN_IT(status);

    status = plugin.deregisterNode(EyeDeformer::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

    return status;
}