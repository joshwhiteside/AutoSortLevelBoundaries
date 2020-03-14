// Copyright Josh Whiteside megaeggz 2018

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

#if UE_BUILD_DEBUG
#include "Editor.h"
#include "LevelEditor.h"
#endif 

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/LevelStreaming.h"
#include "Engine/LevelStreamingVolume.h"
#include "ULevelBoundarySortUtilities.generated.h"

UCLASS()
class PROJECTNAME_API ULevelBoundarySortUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//Gets a 'level streaming' from a level streaming name.
	UFUNCTION(BlueprintCallable)
	static ULevelStreaming* GetLevelStreamingFromName(FName LevelName, AActor contextActor);	
};
