// Copyright CyberAlien ,All Rights Reserved , 2024

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cy_Level_Library.generated.h"

class UCy_LevelStreamingDynamic;

UCLASS()
class CY_LEVEL_UTILITIES_API UCy_Level_Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Cy_Level")
	static bool Cy_Level_GetStreamingLevel_From_Actor(const UObject* WorldContextObject , const AActor* Actor , ULevelStreaming*& LevelStreamingObject );

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Cy_Level")
	static bool Cy_Level_GetCyStreamingLevel_From_Actor(const UObject* WorldContextObject , const AActor* Actor , UCy_LevelStreamingDynamic*& CyLevelStreamingObject );

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Cy_Level")
	static TSoftObjectPtr<UWorld> Cy_CastAsSoftLevel(UObject* InObject)
	{
		TSoftObjectPtr<UWorld> Level = Cast<UWorld>(InObject);
		ensure(Level);
		return Level;
	}

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Cy_Level")
	static void Cy_GetAllActorsOfClassFromStreamingLevel( const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass, ULevelStreaming* StreamingLevel, TArray<AActor*>& OutActors);
};
