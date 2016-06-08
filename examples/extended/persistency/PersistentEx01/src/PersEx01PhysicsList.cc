// $Id: PersEx01PhysicsList.cc,v 1.3 1999/12/15 14:49:17 gunter Exp $
// ------------------------------------------------------------
//	GEANT 4 class header file 
//
//      This is a version for maximum particle set
//	History
//        first version              10  Jan. 1998 by H.Kurashige
//        add decay at rest          26  Feb. 1998 by H.Kurashige
// ------------------------------------------------------------

#include "globals.hh"
#include "PersEx01PhysicsList.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4ios.hh"
#include "g4std/iomanip"                


PersEx01PhysicsList::PersEx01PhysicsList():  G4VUserPhysicsList()
{
  SetVerboseLevel(1);
}

PersEx01PhysicsList::~PersEx01PhysicsList()
{
}

void PersEx01PhysicsList::ConstructParticle()
{
  // In this method, static member functions should be called
  // for all particles which you want to use.
  // This ensures that objects of these particle types will be
  // created in the program. 

  ConstructBosons();
  ConstructLeptons();
  ConstructMesons();
  ConstructBaryons();

}

void PersEx01PhysicsList::ConstructBosons()
{
  // Construct all bosons
  G4BosonConstructor pConstructor;
  pConstructor.ConstructParticle();
}

void PersEx01PhysicsList::ConstructLeptons()
{
  // Construct all leptons
  G4LeptonConstructor pConstructor;
  pConstructor.ConstructParticle();
}

void PersEx01PhysicsList::ConstructMesons()
{
  //  Construct all mesons
  G4MesonConstructor pConstructor;
  pConstructor.ConstructParticle();
}

void PersEx01PhysicsList::ConstructBaryons()
{
  //  Construct all baryons
  G4BaryonConstructor pConstructor;
  pConstructor.ConstructParticle();
}

void PersEx01PhysicsList::ConstructIons()
{
  //  Construct light ions
  G4IonConstructor pConstructor;
  pConstructor.ConstructParticle();  
}


void PersEx01PhysicsList::ConstructProcess()
{
  AddTransportation();
  ConstructEM();
  ConstructLeptHad();
  ConstructHad();
  ConstructGeneral();
}

#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"

#include "G4MultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"
void PersEx01PhysicsList::ConstructEM()
{
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
     
    if (particleName == "gamma") {
    // gamma
      // Construct processes for gamma
      pmanager->AddDiscreteProcess(new G4GammaConversion());
      pmanager->AddDiscreteProcess(new G4ComptonScattering());      
      pmanager->AddDiscreteProcess(new G4PhotoElectricEffect());

    } else if (particleName == "e-") {
    //electron
      // Construct processes for electron
      pmanager->AddProcess(new G4MultipleScattering(),-1,1,1);
      pmanager->AddProcess(new G4eIonisation(),-1,2,2);
      pmanager->AddProcess(new G4eBremsstrahlung(),-1,-1,3);
  
    } else if (particleName == "e+") {
    //positron
      // Construct processes for positron
     pmanager->AddProcess(new G4MultipleScattering(),-1,1,1);
     
     pmanager->AddProcess(new G4eIonisation(),-1,2,2);
     pmanager->AddProcess(new G4eBremsstrahlung(),-1,-1,3);      
     pmanager->AddProcess(new G4eplusAnnihilation(),0,-1,4);
  
    } else if( particleName == "mu+" || 
               particleName == "mu-"    ) {
    //muon  
     // Construct processes for muon+
     pmanager->AddProcess(new G4MultipleScattering(),-1,1,1);
     pmanager->AddProcess(new G4MuIonisation(),-1,2,2);
     pmanager->AddProcess(new G4MuBremsstrahlung(),-1,-1,3);
     pmanager->AddProcess(new G4MuPairProduction(),-1,-1,4);       
     
    } else { 
      if ((particle->GetPDGCharge() != 0.0) && 
          (particle->GetParticleName() != "chargedgeantino")) {
     // all others charged particles except geantino
       pmanager->AddProcess(new G4MultipleScattering(),-1,1,1);
       pmanager->AddProcess(new G4hIonisation(),-1,2,2);       
     }
    }
  }
}

void PersEx01PhysicsList::ConstructHad()
{;}

void PersEx01PhysicsList::ConstructLeptHad()
{;}

#include "G4Decay.hh"
void PersEx01PhysicsList::ConstructGeneral()
{
  G4Decay* theDecayProcess = new G4Decay();
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    if (theDecayProcess->IsApplicable(*particle)) { 
      pmanager->AddProcess(theDecayProcess, INT_MAX, -1, INT_MAX); 
    }
  }
}

void PersEx01PhysicsList::SetCuts()
{
  if (verboseLevel >0){
    G4cout << "PersEx01PhysicsList::SetCuts:";
    G4cout << "CutLength : " << defaultCutValue/mm << " (mm)" << G4endl;
  }  

  //  " G4VUserPhysicsList::SetCutsWithDefault" method sets 
  //   the default cut value for all particle types 
  SetCutsWithDefault();   
}
