#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "GameRewardItemWidget.generated.h"

/**
 * 奖励项枚举状态
 */
UENUM(BlueprintType)
enum class ERewardStatus : uint8
{
	Claimable   UMETA(DisplayName = "可领取"),
	Tomorrow    UMETA(DisplayName = "明天领取"),
	Locked      UMETA(DisplayName = "已锁定")
};

UCLASS()
class METALSLUG01_API UGameRewardItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// 初始化奖励数据
	UFUNCTION(BlueprintCallable, Category = "Reward")
	void SetRewardData(FString Title, ERewardStatus Status, int32 DayNumber);

protected:
	// 绑定 UI 控件（名称必须与蓝图中的控件名完全一致）
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_RewardTitle; // 奖励标题文字

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_StatusLabel; // 底部状态标签（CLAIM, DAY X 等）

	UPROPERTY(meta = (BindWidget))
	UImage* Img_HeaderBg;        // 顶部横条背景（蓝色/紫色）

	UPROPERTY(meta = (BindWidget))
	UImage* Img_SelectionFrame;  // 选中高亮边框
};