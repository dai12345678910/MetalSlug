// Fill out your copyright notice in the Description page of Project Settings.


#include "MetalSlug01/Public/UI/GameRewardMainWidget.h"
#include "MetalSlug01/Public/UI/GameRewardItemWidget.h"

void UGameRewardMainWidget::NativeConstruct()
{
	Super::NativeConstruct(); // 调用父类构造

	// 1. 注册按钮点击事件回调
	if (Btn_ClaimAll)
	{
		Btn_ClaimAll->OnClicked.AddDynamic(this, &UGameRewardMainWidget::OnClaimAllClicked);
	}

	// 2. 模拟加载数据并刷新列表
	RefreshRewardList();
}

void UGameRewardMainWidget::RefreshRewardList()
{
	if (!RewardItemClass || !RewardListContainer) return; // 安全检查

	RewardListContainer->ClearChildren(); // 清空当前旧列表

	// 模拟循环创建 7 天的奖励卡片
	for (int32 i = 1; i <= 5; i++)
	{
		// 创建子项 Widget 实例
		UGameRewardItemWidget* NewItem = CreateWidget<UGameRewardItemWidget>(this, RewardItemClass);
		if (NewItem)
		{
			// 设置状态：第一天设为可领取，第二天设为明天，之后设为锁定
			ERewardStatus Status = (i == 1) ? ERewardStatus::Claimable : 
								   (i == 2) ? ERewardStatus::Tomorrow : ERewardStatus::Locked;
            
			// 初始化数据
			NewItem->SetRewardData(TEXT("夹克派对宝箱"), Status, i);
            
			// 将子项添加到水平布局容器中
			RewardListContainer->AddChildToHorizontalBox(NewItem);
		}
	}
}

void UGameRewardMainWidget::OnClaimAllClicked()
{
	// 这里处理点击“全部领取”的逻辑（如发送网络请求、播放音效）
	UE_LOG(LogTemp, Warning, TEXT("用户点击了全部领取按钮！"));
}