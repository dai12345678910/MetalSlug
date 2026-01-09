// Fill out your copyright notice in the Description page of Project Settings.


#include "MetalSlug01/Public/UI/GameRewardItemWidget.h"

// 在 GameRewardItemWidget.cpp 中实现
void UGameRewardItemWidget::SetRewardData(FString Title, ERewardStatus Status, int32 DayNumber)
{
	// 1. 设置顶部标题
	if (Text_RewardTitle)
	{
		Text_RewardTitle->SetText(FText::FromString(Title)); // 设置奖励名称
	}

	// 2. 根据状态切换底部显示和颜色
	if (Text_StatusLabel)
	{
		switch (Status)
		{
		case ERewardStatus::Claimable:
			Text_StatusLabel->SetText(FText::FromString(TEXT("CLAIM"))); // 显示领取
			// 这里可以添加逻辑：改变背景为黄色
			break;
		case ERewardStatus::Tomorrow:
			Text_StatusLabel->SetText(FText::FromString(TEXT("AVAILABLE\nTOMORROW"))); // 换行显示明天领取
			break;
		case ERewardStatus::Locked:
			Text_StatusLabel->SetText(FText::Format(FText::FromString(TEXT("DAY {0}")), DayNumber)); // 显示天数
			break;
		}
	}
}
