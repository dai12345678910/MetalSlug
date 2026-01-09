// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MetalSlug01GameModeBase.generated.h"

/**
 * 工业级规范：GameMode 负责定义本局游戏的核心类映射
 */
UCLASS()
class METALSLUG01_API AMyBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyBaseGameMode();

protected:
	/** 重写初始化函数，可以在此处进行游戏开始前的逻辑处理 */
	virtual void BeginPlay() override;

private:
	/** * 规范化类搜索：通过静态函数在构造函数中寻找蓝图类 
	 * 这样可以避免在代码中硬编码资源路径
	 */
	void SetupDefaultClasses();
};
