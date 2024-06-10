// Copyright CyberAlien ,All Rights Reserved , 2024

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Cy_LevelStreamingDynamic.generated.h"

UCLASS()
class CY_LEVEL_UTILITIES_API UCy_LevelStreamingDynamic : public ULevelStreamingDynamic
{
	GENERATED_BODY()

public:

	UCy_LevelStreamingDynamic();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelLoaded_Ext , UCy_LevelStreamingDynamic* , LevelObject , FName , ID );
	UPROPERTY(BlueprintAssignable, Category = "Custom Delegates")
	FOnLevelLoaded_Ext OnLevelLoaded_ExtDelegate;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelUnLoaded_Ext, UCy_LevelStreamingDynamic*, LevelObject, FName , ID );
	UPROPERTY(BlueprintAssignable, Category = "Custom Delegates")
	FOnLevelUnLoaded_Ext OnLevelUnLoaded_ExtDelegate;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelShown_Ext, UCy_LevelStreamingDynamic*, LevelObject, FName , ID );
	UPROPERTY(BlueprintAssignable, Category = "Custom Delegates")
	FOnLevelShown_Ext OnLevelShown_ExtDelegate;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelHidden_Ext, UCy_LevelStreamingDynamic*, LevelObject, FName , ID );
	UPROPERTY(BlueprintAssignable, Category = "Custom Delegates")
	FOnLevelHidden_Ext OnLevelHidden_ExtDelegate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cy_Level_StreamingDynamic")
	FName Level_Name = "none";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cy_Level_StreamingDynamic")
	FName Level_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cy_Level_StreamingDynamic")
	int32 Level_int_Seed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cy_Level_StreamingDynamic")
	FRandomStream Level_Seed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cy_Level_StreamingDynamic")
	TMap<FName,FString> Custom_String_Property;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cy_Level_StreamingDynamic")
	TMap<FName,UObject*> Custom_Object_Property;

	UFUNCTION(BlueprintCallable , Category = "Cy_Level_StreamingDynamic")
	bool Get_Level_Actors( TArray<AActor*>& OutActors );

protected:
	
	UFUNCTION()
	void OnLevelLoadedHandler();
	UFUNCTION()
	void OnLevelUnloadedHandler();
	UFUNCTION()
	void OnLevelShownHandler();
	UFUNCTION()
	void OnLevelHiddenHandler();

private:

	UPROPERTY()
	bool Internal_IsActorGet = false;
	UPROPERTY()
	TArray<AActor*> Internal_Level_Actor;
};
