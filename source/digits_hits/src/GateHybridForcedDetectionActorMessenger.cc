/*----------------------
   GATE version name: gate_v6

   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See GATE/LICENSE.txt for further details
----------------------*/

#include "GateConfiguration.h"
#ifdef GATE_USE_RTK

#ifndef GATEHYBRIDFORCEDDECTECTIONACTORMESSENGER_CC
#define GATEHYBRIDFORCEDDECTECTIONACTORMESSENGER_CC

#include "GateHybridForcedDetectionActorMessenger.hh"

#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"

//-----------------------------------------------------------------------------
GateHybridForcedDetectionActorMessenger::GateHybridForcedDetectionActorMessenger(GateHybridForcedDetectionActor* sensor):
  GateActorMessenger(sensor),pHybridActor(sensor)
{
  BuildCommands(baseName+sensor->GetObjectName());
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
GateHybridForcedDetectionActorMessenger::~GateHybridForcedDetectionActorMessenger()
{
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void GateHybridForcedDetectionActorMessenger::BuildCommands(G4String base)
{
  G4String guidance;
  G4String bb;
 
  bb = base+"/setDetector";
  pSetDetectorCmd = new G4UIcmdWithAString(bb, this);
  guidance = "Set the name of the volume used for detector (must be a Box).";
  pSetDetectorCmd->SetGuidance(guidance);

  bb = base+"/setDetectorResolution";
  pSetDetectorResolCmd = new GateUIcmdWith2Vector(bb, this);
  guidance = "Set the resolution of the detector (2D).";
  pSetDetectorResolCmd->SetGuidance(guidance);

  bb = base+"/geometryFilename";
  pSetGeometryFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for the RTK geometry filename.";
  pSetGeometryFilenameCmd->SetGuidance(guidance);

  bb = base+"/primaryFilename";
  pSetPrimaryFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for the primary x-rays (printf format with runId as a single parameter).";
  pSetPrimaryFilenameCmd->SetGuidance(guidance);

  bb = base+"/materialMuFilename";
  pSetMaterialMuFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the attenuation of each material at each energy.";
  pSetMaterialMuFilenameCmd->SetGuidance(guidance);

  bb = base+"/attenuationFilename";
  pSetAttenuationFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the attenuation image.";
  pSetAttenuationFilenameCmd->SetGuidance(guidance);

  bb = base+"/responseDetectorFilename";
  pSetResponseDetectorFilenameCmd = new G4UIcmdWithAString(bb, this);
  guidance = G4String( "Response detector curve (weight to each energy)");
  pSetResponseDetectorFilenameCmd->SetGuidance( guidance);

  bb = base+"/flatFieldFilename";
  pSetFlatFieldFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the flat field image.";
  pSetFlatFieldFilenameCmd->SetGuidance(guidance);

  bb = base+"/comptonFilename";
  pSetComptonFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the Compton image.";
  pSetComptonFilenameCmd->SetGuidance(guidance);

  bb = base+"/rayleighFilename";
  pSetRayleighFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the rayleigh image.";
  pSetRayleighFilenameCmd->SetGuidance(guidance);

  bb = base+"/fluorescenceFilename";
  pSetFluorescenceFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the fluorescence image.";
  pSetFluorescenceFilenameCmd->SetGuidance(guidance);

  bb = base+"/secondaryFilename";
  pSetSecondaryFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the scattering image.";
  pSetSecondaryFilenameCmd->SetGuidance(guidance);

  bb = base+"/enableSquaredSecondary";
  pEnableSecondarySquaredCmd = new G4UIcmdWithABool(bb, this);
  guidance = G4String("Enable squared secondary computation");
  pEnableSecondarySquaredCmd->SetGuidance(guidance);

  bb = base+"/enableUncertaintySecondary";
  pEnableSecondaryUncertaintyCmd = new G4UIcmdWithABool(bb, this);
  guidance = G4String("Enable uncertainty secondary computation");
  pEnableSecondaryUncertaintyCmd->SetGuidance(guidance);

  bb = base+"/totalFilename";
  pSetTotalFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the image that provides the total (primary + scaterring) image.";
  pSetTotalFilenameCmd->SetGuidance(guidance);
  
  bb = base+"/singleInteractionFilename";
  pSetSingleInteractionFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for writing the result of a single interaction.";
  pSetSingleInteractionFilenameCmd->SetGuidance(guidance);

  bb = base+"/singleInteractionType";
  pSetSingleInteractionTypeCmd = new G4UIcmdWithAString(bb, this);
  guidance = "Set the type of the single interaction (Compton or Rayleigh).";
  pSetSingleInteractionTypeCmd->SetGuidance(guidance);

  bb = base+"/singleInteractionPosition";
  pSetSingleInteractionPositionCmd = new G4UIcmdWith3VectorAndUnit(bb, this);
  guidance = "Set the position of the single interaction (3D).";
  pSetSingleInteractionPositionCmd->SetGuidance(guidance);

  bb = base+"/singleInteractionDirection";
  pSetSingleInteractionDirectionCmd = new G4UIcmdWith3Vector(bb, this);
  guidance = "Set the direction of the single interaction (3D).";
  pSetSingleInteractionDirectionCmd->SetGuidance(guidance);

  bb = base+"/singleInteractionEnergy";
  pSetSingleInteractionEnergyCmd = new G4UIcmdWithADoubleAndUnit(bb, this);
  guidance = "Set the energy of the single interaction.";
  pSetSingleInteractionEnergyCmd->SetGuidance(guidance);

  bb = base+"/singleInteractionZ";
  pSetSingleInteractionZCmd = new G4UIcmdWithAnInteger(bb, this);
  guidance = "Set the Z of the single interaction.";
  pSetSingleInteractionZCmd->SetGuidance(guidance);

  bb = base+"/phaseSpaceFilename";
  pSetPhaseSpaceFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for storing all interactions in a phase space file in root format.";
  pSetPhaseSpaceFilenameCmd->SetGuidance(guidance);

  bb = base+"/waterLUTFilename";
  pSetWaterLUTFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the file name for storing all interactions in a phase space file in root format.";
  pSetWaterLUTFilenameCmd->SetGuidance(guidance);

  bb = base+"/waterLUTMaterial";
  pSetWaterLUTMaterialCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the material name for computing the lookup table. Default is G4_WATER.";
  pSetWaterLUTMaterialCmd->SetGuidance(guidance);

  bb = base+"/setSecondPassPrefix";
  pSetSecondPassPrefixCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set the prefix for file names in the second pass.";
  pSetSecondPassPrefixCmd->SetGuidance(guidance);

  bb = base+"/setSecondPassDetectorResolution";
  pSetSecondPassDetectorResolCmd = new GateUIcmdWith2Vector(bb, this);
  guidance = "Set the resolution of the detector (2D) in the second pass.";
  pSetSecondPassDetectorResolCmd->SetGuidance(guidance);

  bb = base+"/setRussianRouletteFilename";
  pSetRussianRouletteFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set filename for the image of the regional contribution to scatter, used by the russian roulette.";
  pSetRussianRouletteFilenameCmd->SetGuidance(guidance);

  bb = base+"/setRussianRouletteSpacing";
  pSetRussianRouletteSpacingCmd = new G4UIcmdWithADoubleAndUnit(bb,this);
  guidance = "Set spacing for the russian roulette images.";
  pSetRussianRouletteSpacingCmd->SetGuidance(guidance);

  bb = base+"/setRussianRouletteMinimumCountInRegion";
  pSetRussianRouletteMinimumCountInRegionCmd = new G4UIcmdWithAnInteger(bb,this);
  guidance = "Set minimum interaction count in a pixel of the russian roulette images to apply it.";
  pSetRussianRouletteMinimumCountInRegionCmd->SetGuidance(guidance);

  bb = base+"/setRussianRouletteMinimumProbability";
  pSetRussianRouletteMinimumProbabilityCmd = new G4UIcmdWithADouble(bb,this);
  guidance = "Set minimum survival probability for the russian roulette images.";
  pSetRussianRouletteMinimumProbabilityCmd->SetGuidance(guidance);

  bb = base+"/setInputRTKGeometryFilename";
  pSetInputRTKGeometryFilenameCmd = new G4UIcmdWithAString(bb,this);
  guidance = "Set filename for using an RTK geometry file as input.";
  pSetInputRTKGeometryFilenameCmd->SetGuidance(guidance);

  bb = base+"/noisePrimaryNumber";
  pSetNoisePrimaryCmd = new G4UIcmdWithAnInteger(bb,this);
  guidance = "Set a number of primary for noise estimate in a phase space file in root format.";
  pSetNoisePrimaryCmd->SetGuidance(guidance);
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void GateHybridForcedDetectionActorMessenger::SetNewValue(G4UIcommand* command, G4String param)
{
  if(command == pSetDetectorCmd) pHybridActor->SetDetectorVolumeName(param);
  if(command == pSetDetectorResolCmd) pHybridActor->SetDetectorResolution(pSetDetectorResolCmd->GetNew2VectorValue(param)[0], pSetDetectorResolCmd->GetNew2VectorValue(param)[1]);
  if(command == pSetGeometryFilenameCmd) pHybridActor->SetGeometryFilename(param);
  if(command == pSetPrimaryFilenameCmd) pHybridActor->SetPrimaryFilename(param);
  if(command == pSetMaterialMuFilenameCmd) pHybridActor->SetMaterialMuFilename(param);
  if(command == pSetAttenuationFilenameCmd) pHybridActor->SetAttenuationFilename(param);
  if(command == pSetFlatFieldFilenameCmd) pHybridActor->SetFlatFieldFilename(param);
  if(command == pSetComptonFilenameCmd) pHybridActor->SetComptonFilename(param);
  if(command == pSetRayleighFilenameCmd) pHybridActor->SetRayleighFilename(param);
  if(command == pSetResponseDetectorFilenameCmd) pHybridActor->SetResponseDetectorFilename(param);
  if(command == pSetFluorescenceFilenameCmd) pHybridActor->SetFluorescenceFilename(param);
  if(command == pSetSecondaryFilenameCmd) pHybridActor->SetSecondaryFilename(param);
  if(command == pEnableSecondarySquaredCmd) pHybridActor->EnableSecondarySquaredImage(pEnableSecondarySquaredCmd->GetNewBoolValue(param));
  if(command == pEnableSecondaryUncertaintyCmd) pHybridActor->EnableSecondaryUncertaintyImage(pEnableSecondaryUncertaintyCmd->GetNewBoolValue(param));
  if(command == pSetTotalFilenameCmd) pHybridActor->SetTotalFilename(param);
  if(command == pSetSingleInteractionFilenameCmd) pHybridActor->SetSingleInteractionFilename(param);
  if(command == pSetSingleInteractionTypeCmd) pHybridActor->SetSingleInteractionType(param);
  if(command == pSetSingleInteractionPositionCmd) pHybridActor->SetSingleInteractionPosition(pSetSingleInteractionPositionCmd->GetNew3VectorValue(param));
  if(command == pSetSingleInteractionDirectionCmd) pHybridActor->SetSingleInteractionDirection(pSetSingleInteractionDirectionCmd->GetNew3VectorValue(param));
  if(command == pSetSingleInteractionEnergyCmd) pHybridActor->SetSingleInteractionEnergy(pSetSingleInteractionEnergyCmd->GetNewDoubleValue(param));
  if(command == pSetSingleInteractionZCmd) pHybridActor->SetSingleInteractionZ(pSetSingleInteractionZCmd->GetNewIntValue(param));
  if(command == pSetPhaseSpaceFilenameCmd) pHybridActor->SetPhaseSpaceFilename(param);
  if(command == pSetWaterLUTFilenameCmd) pHybridActor->SetWaterLUTFilename(param);
  if(command == pSetWaterLUTMaterialCmd) pHybridActor->SetWaterLUTMaterial(param);
  if(command == pSetSecondPassPrefixCmd) pHybridActor->SetSecondPassPrefix(param);
  if(command == pSetSecondPassDetectorResolCmd) pHybridActor->SetSecondPassDetectorResolution(pSetSecondPassDetectorResolCmd->GetNew2VectorValue(param)[0], pSetSecondPassDetectorResolCmd->GetNew2VectorValue(param)[1]);
  if(command == pSetRussianRouletteFilenameCmd) pHybridActor->SetRussianRouletteFilename(param);
  if(command == pSetRussianRouletteSpacingCmd) pHybridActor->SetRussianRouletteSpacing (pSetRussianRouletteSpacingCmd->GetNewDoubleValue(param));
  if(command == pSetRussianRouletteMinimumCountInRegionCmd) pHybridActor->SetRussianRouletteMinimumCountInRegion(pSetRussianRouletteMinimumCountInRegionCmd->GetNewIntValue(param));
  if(command == pSetRussianRouletteMinimumProbabilityCmd) pHybridActor->SetRussianRouletteMinimumProbability(pSetRussianRouletteMinimumProbabilityCmd->GetNewDoubleValue(param));
  if(command == pSetInputRTKGeometryFilenameCmd) pHybridActor->SetInputRTKGeometryFilename(param);
  if(command == pSetNoisePrimaryCmd) pHybridActor->SetNoisePrimary(pSetNoisePrimaryCmd->GetNewIntValue(param));

  GateActorMessenger::SetNewValue(command ,param );
}
//-----------------------------------------------------------------------------

#endif /* end #define GATEHYBRIDFORCEDDECTECTIONACTORMESSENGER_CC */
#endif // GATE_USE_RTK
