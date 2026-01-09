#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UI/Activity/Pages/DailyTask/DailyTaskData.h"
#include "DailyTaskItemObject.generated.h"

/**
 * ListView 使用的任务对象
 */
UCLASS(BlueprintType)
class METALSLUG01_API UDailyTaskItemObject : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FDailyTaskData TaskData;
};

