#pragma once

#include "CoreMinimal.h"
#include "DailyTaskData.generated.h"

/**
 * 单条每日任务数据
 */
USTRUCT(BlueprintType)
struct FDailyTaskData
{
	GENERATED_BODY()

public:

	// 任务 ID（服务器用）
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 TaskId = 0;

	// 任务标题
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Title;

	// 当前进度
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 CurrentValue = 0;

	// 目标值
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 TargetValue = 0;

	// 是否已完成
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bCompleted = false;

	// 是否已领取奖励
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bRewardClaimed = false;
};
