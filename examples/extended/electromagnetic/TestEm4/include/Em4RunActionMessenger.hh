// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em4RunActionMessenger.hh,v 1.3 2000/01/20 17:27:56 maire Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em4RunActionMessenger_h
#define Em4RunActionMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class Em4RunAction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em4RunActionMessenger: public G4UImessenger
{
  public:
    Em4RunActionMessenger(Em4RunAction*);
   ~Em4RunActionMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    Em4RunAction*          Em4Run;   
    G4UIdirectory*         RndmDir;
    G4UIcmdWithAnInteger*  RndmSaveCmd;    
    G4UIcmdWithAString*    RndmReadCmd;
    
};

#endif