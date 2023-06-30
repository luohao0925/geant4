# - G4emdna-utils module build definition

# Define the Geant4 Module.
geant4_add_module(G4emdna-utils
  PUBLIC_HEADERS
    G4DNAChemistryManager.hh
    G4DNACPA100LogLogInterpolation.hh
    G4DNACPA100ExcitationStructure.hh
    G4DNACPA100IonisationStructure.hh
    G4DNACrossSectionDataSet.hh
    G4DNADamage.hh
    G4DNAGenericIonsManager.hh
    G4DNAIons.hh
    G4DNAMolecularMaterial.hh
    G4DNAMolecularReactionTable.hh
    G4DNAEmfietzoglouWaterExcitationStructure.hh
    G4DNAEmfietzoglouWaterIonisationStructure.hh
    G4DNAPTBExcitationStructure.hh
    G4DNAPTBIonisationStructure.hh
    G4DNARevertProbability.hh
    G4DNAWaterExcitationStructure.hh
    G4DNAWaterIonisationStructure.hh
    G4ErrorFunction.hh
    G4MoleculeGun.hh
    G4MoleculeGunMessenger.hh
    G4ReactionTableMessenger.hh
    G4VDNAReactionModel.hh
    G4VUserChemistryList.hh
    # physchemIO
    G4VPhysChemIO.hh
    G4PhysChemIO.hh
	G4IRTUtils.hh
	G4DNAScavengerMaterial.hh
	G4VChemistryWorld.hh
	G4DNAMesh.hh
	G4DNAEventSet.hh
	G4ChemicalMoleculeFinder.hh
	G4DNAMaterialManager.hh
  SOURCES
    G4DNAChemistryManager.cc
    G4DNACPA100LogLogInterpolation.cc
    G4DNACPA100ExcitationStructure.cc
    G4DNACPA100IonisationStructure.cc
    G4DNACrossSectionDataSet.cc
    G4DNADamage.cc
    G4DNAGenericIonsManager.cc
    G4DNAIons.cc
    G4DNAMolecularMaterial.cc
    G4DNAMolecularReactionTable.cc
    G4DNAEmfietzoglouWaterExcitationStructure.cc
    G4DNAEmfietzoglouWaterIonisationStructure.cc
    G4DNAPTBExcitationStructure.cc
    G4DNAPTBIonisationStructure.cc
    G4DNAWaterExcitationStructure.cc
    G4DNAWaterIonisationStructure.cc
    G4ErrorFunction.cc
    G4MoleculeGun.cc
    G4MoleculeGunMessenger.cc
    G4ReactionTableMessenger.cc
    G4VDNAReactionModel.cc
    G4VUserChemistryList.cc
    # physchemIO
    G4VPhysChemIO.cc
    G4PhysChemIO.cc
	G4IRTUtils.cc
	G4DNAScavengerMaterial.cc
	G4DNAMesh.cc
	G4DNAEventSet.cc
	G4DNAMaterialManager.cc)

geant4_module_link_libraries(G4emdna-utils
  PUBLIC
    G4emdna-man
    G4emdna-molman
    G4emlowenergy
    G4globman
    G4intercoms
    G4partman
  PRIVATE
    G4analysismng
    G4emdna-moltypes
    G4geometrymng
    G4heprandom
    G4ions
    G4materials
    G4procman
    G4track)
