// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4SmartVoxelNode.cc,v 2.1 1998/11/11 11:38:22 japost Exp $
// GEANT4 tag $Name: geant4-00 $
//
// Class G4SmartVoxelNode
//
// Implementation
//

#include "G4SmartVoxelNode.hh"

// Return true if contents equal
//
// Preconditions:
//
// Node contents were entered in the same order
G4bool G4SmartVoxelNode::operator == (const G4SmartVoxelNode& v) const
{
    G4int maxNode=GetNoContained();
    if (maxNode==v.GetNoContained())
	{
	    for (G4int node=0;node<maxNode;node++)
		{
		    if (GetVolume(node)!=v.GetVolume(node))
			{
			    return false;
			}
		}
	    return true;
	}
    return false;
}










