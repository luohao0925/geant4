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
// $Id: G4Mg22GEMChannel.hh,v 1.2 2005/06/04 13:25:25 jwellisc Exp $
// GEANT4 tag $Name: geant4-08-00 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Sept. 2001)
//


#ifndef G4Mg22GEMChannel_h
#define G4Mg22GEMChannel_h 1

#include "G4GEMChannel.hh"
#include "G4Mg22GEMCoulombBarrier.hh"
#include "G4Mg22GEMProbability.hh"

class G4Mg22GEMChannel : public G4GEMChannel
{
public:
  // only available constructor
  G4Mg22GEMChannel() : G4GEMChannel(22,12,"Mg22",
				   &theEvaporationProbability,
				   &theCoulombBarrier)
  {
    theEvaporationProbability.SetCoulomBarrier(&theCoulombBarrier);
  }
  
  // destructor
  ~G4Mg22GEMChannel() {};
  
private:
  const G4Mg22GEMChannel & operator=(const G4Mg22GEMChannel & right);  
    
  G4Mg22GEMChannel(const G4Mg22GEMChannel & right);
  
public:
  G4bool operator==(const G4Mg22GEMChannel & right) const;
  G4bool operator!=(const G4Mg22GEMChannel & right) const;
    
private:
  
  G4Mg22GEMCoulombBarrier theCoulombBarrier;
	
  G4Mg22GEMProbability theEvaporationProbability;
  
};
#endif