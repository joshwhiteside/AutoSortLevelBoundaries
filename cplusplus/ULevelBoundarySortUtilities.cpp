// Copyright Josh Whiteside megaeggz 2018

#include "ULevelBoundarySortUtilities.h"

ULevelStreaming* ULevelBoundarySortUtilities::GetLevelStreamingFromName(FName LevelName, AActor contextActor) {
	UWorld* currentWorld = contextActor.GetWorld();

	TArray<ULevelStreaming*> levels = currentWorld->GetStreamingLevels();

	ULevelStreaming* ret = *levels.GetData();
	for (auto itr = levels.CreateConstIterator(); itr; ++itr)
	{
		FString toCompare = (*itr)->GetWorldAssetPackageFName().ToString();

		FName compareVal = FName(*toCompare);

		if (LevelName == compareVal)
		{
			ret = (*itr);
		}
	}
	return ret;
}