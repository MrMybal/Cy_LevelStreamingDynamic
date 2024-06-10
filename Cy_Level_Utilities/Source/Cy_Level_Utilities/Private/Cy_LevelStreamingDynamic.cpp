// Copyright CyberAlien ,All Rights Reserved , 2024


#include "Cy_LevelStreamingDynamic.h"

// --------------------------------------------------------------
UCy_LevelStreamingDynamic::UCy_LevelStreamingDynamic()
{
	OnLevelLoaded.AddDynamic(this, &UCy_LevelStreamingDynamic::OnLevelLoadedHandler);
	OnLevelUnloaded.AddDynamic(this, &UCy_LevelStreamingDynamic::OnLevelUnloadedHandler);
	OnLevelShown.AddDynamic(this, &UCy_LevelStreamingDynamic::OnLevelShownHandler);
	OnLevelHidden.AddDynamic(this, &UCy_LevelStreamingDynamic::OnLevelHiddenHandler);
}
// --------------------------------------------------------------
void UCy_LevelStreamingDynamic::OnLevelLoadedHandler()
{
	OnLevelLoaded_ExtDelegate.Broadcast(this , Level_ID );
}
// --------------------------------------------------------------
void UCy_LevelStreamingDynamic::OnLevelUnloadedHandler()
{
	OnLevelUnLoaded_ExtDelegate.Broadcast(this , Level_ID );
}
// --------------------------------------------------------------
void UCy_LevelStreamingDynamic::OnLevelShownHandler()
{
	OnLevelShown_ExtDelegate.Broadcast(this , Level_ID );
}
// --------------------------------------------------------------
void UCy_LevelStreamingDynamic::OnLevelHiddenHandler()
{
	OnLevelHidden_ExtDelegate.Broadcast(this , Level_ID );
}
// --------------------------------------------------------------
bool UCy_LevelStreamingDynamic::Get_Level_Actors( TArray<AActor*>& OutActors )
{
	if ( Internal_IsActorGet )
	{
		OutActors = Internal_Level_Actor;
		return true;
	}
	if (GetLoadedLevel() != nullptr)
	{
		ULevel* Level = GetLoadedLevel();
		Internal_Level_Actor = Level->Actors;
		OutActors = Internal_Level_Actor;
		Internal_IsActorGet = true;
		return true;
	}
	return false;
}