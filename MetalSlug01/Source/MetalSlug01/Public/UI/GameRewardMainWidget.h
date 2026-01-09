#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "GameRewardMainWidget.generated.h"

UCLASS()
class METALSLUG01_API UGameRewardMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// 生命周期：当 Widget 构造时调用
	virtual void NativeConstruct() override;

	// 绑定主容器和按钮
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* RewardListContainer; // 放置奖励卡片的水平容器

	UPROPERTY(meta = (BindWidget))
	UButton* Btn_ClaimAll;               // “全部领取”按钮

	// 引用子项的蓝图类，用于动态生成
	UPROPERTY(EditAnywhere, Category = "UI Config")
	TSubclassOf<class UGameRewardItemWidget> RewardItemClass;

private:
	// 点击全部领取的回调
	UFUNCTION()
	void OnClaimAllClicked();

	// 初始化奖励列表的方法
	void RefreshRewardList();
};