//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4PVParameterised.hh,v 1.5 2005/11/11 22:39:00 japost Exp $
// GEANT4 tag $Name: geant4-08-00 $
//
// 
// class G4PVParameterised
//
// Class description:
//
// Represents many touchable detector elements differing in their
// positioning and dimensions. Both are calculated by means
// of a G4VParameterisation object. The positioning is assumed to
// be dominant along a cartesian axis (specified).

// History:
// 29.07.95 P.Kent First non-stub version
// ----------------------------------------------------------------------
#ifndef G4PVPARAMETERISED_HH
#define G4PVPARAMETERISED_HH

#include "G4PVReplica.hh"

class G4PVParameterised : public G4PVReplica
{
  public:  // with description

    G4PVParameterised(const G4String& pName,
                            G4LogicalVolume* pLogical,
                            G4LogicalVolume* pMotherLogical,
                      const EAxis pAxis,
                      const G4int nReplicas,
                            G4VPVParameterisation *pParam,
                            G4bool pSurfChk=false);
      // Replicate the volume nReplicas Times using the paramaterisation pParam,
      // within the mother volume pMotherLogical.
      // The positioning of the replicas is dominant along the specified axis.
      // pSurfChk if true activates check for overlaps with existing volumes.
 
  public:  // without description

    G4PVParameterised(const G4String& pName,
                            G4LogicalVolume* pLogical,
                            G4VPhysicalVolume* pMother,
                      const EAxis pAxis,
                      const G4int nReplicas,
                            G4VPVParameterisation *pParam,
                            G4bool pSurfChk=false);
      // Almost exactly similar to first constructor, changing only mother 
      // pointer's type to PhysicalVolume.

    G4PVParameterised(__void__&);
      // Fake default constructor for usage restricted to direct object
      // persistency for clients requiring preallocation of memory for
      // persistifiable objects.

  public:  // with description

    virtual ~G4PVParameterised();
      // Virtual empty destructor.

    G4bool IsParameterised() const;
      // Returns true to identify it is a parameterised physical volume.

    G4VPVParameterisation* GetParameterisation() const;
      // Returns the current pointer to the parameterisation.

    void GetReplicationData(EAxis& axis,
                            G4int& nReplicas,
                            G4double& width,
                            G4double& offset,
                            G4bool& consuming) const;
      // Fills arguments with the attributes from the base replica.
    virtual void SetRegularStructureId( G4int Code ); 
      // Method sets code and can prepare for special type of regular volumes.

    G4bool CheckOverlaps(G4int res=1000);
      // Verifies if each instance of the parameterised volume is overlapping
      // with other instances or with the mother volume. Provides default
      // resolution for the number of points to be generated and verified.
      // Returns true if an overlap occurs.

  private:

    G4VPVParameterisation *fparam; 
};

#endif