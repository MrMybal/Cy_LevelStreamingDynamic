// Copyright CyberAlien ,All Rights Reserved , 2024


#include "Cy_Level_Library.h"
#include "Kismet/GameplayStatics.h"

// ---------------------------------------------------------
bool UCy_Level_Library::Cy_Level_GetStreamingLevel_From_Actor(const UObject* WorldContextObject , const AActor* Actor , ULevelStreaming*& LevelStreamingObject )
{
	if (Actor != nullptr)
	{
		FName LevelPackage = Actor->GetLevel()->GetOuter()->GetOuter()->GetFName();
		ULevelStreaming* LStream = UGameplayStatics::GetStreamingLevel( WorldContextObject , LevelPackage);
		;
		if (LStream != nullptr)
		{
			LevelStreamingObject = LStream;
			return true;
		}
	}
	return false;
}
// ---------------------------------------------------------
bool UCy_Level_Library::Cy_Level_GetCyStreamingLevel_From_Actor(const UObject* WorldContextObject , const AActor* Actor , UCy_LevelStreamingDynamic*& CyLevelStreamingObject )
{
	if (Actor != nullptr)
	{
		FName LevelPackage = Actor->GetLevel()->GetOuter()->GetOuter()->GetFName();
		ULevelStreaming* LStream = UGameplayStatics::GetStreamingLevel( WorldContextObject , LevelPackage);
		;
		if (LStream != nullptr)
		{
			CyLevelStreamingObject = StaticCast<UCy_LevelStreamingDynamic*>(LStream);
			if ( CyLevelStreamingObject )
			{
				return true;
			}
		}
	}
	return false;
}
// ---------------------------------------------------------
void UCy_Level_Library::Cy_GetAllActorsOfClassFromStreamingLevel( const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass, ULevelStreaming* StreamingLevel, TArray<AActor*>& OutActors)
{
	OutActors.Reset();
	if (ActorClass && StreamingLevel)
	{
		ULevel* Level = StreamingLevel->GetLoadedLevel();
		OutActors.Reserve(Level->Actors.Num());
		for (const auto& LevelActor : Level->Actors)
		{
			if (IsValid(LevelActor) && LevelActor->IsA(ActorClass))
			{
				OutActors.Add(LevelActor);
			}
		}
	}
}