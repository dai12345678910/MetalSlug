// Fill out your copyright notice in the Description page of Project Settings.


#include "MetalSlug01GameModeBase.h"



#include "ClassIconFinder.h"
#include "UI/MyGameHUD.h"  // 引入我们之前写的 HUD 头文件
#include "UObject/ConstructorHelpers.h"

class ASuperMarioPaperCharacter;

AMyBaseGameMode::AMyBaseGameMode()
{
	// 1. 指定 HUD 类（这是核心：确保客户端生成我们自定义的 HUD 管理器）
	// 注意：如果是 C++ 类，直接使用 StaticClass()
	HUDClass = AMyGameHUD::StaticClass();

	// 2. 如果你的 HUD 是蓝图实现的（例如 WBP_MyHUD），则需要路径搜索：

	{
		//DefaultPawnClass=ASuperMarioPaperCharacter::StaticClass();
	


	}

	// 3. 指定默认的 PlayerController（负责处理输入切换逻辑）
	// PlayerControllerClass = AMyPlayerController::StaticClass();

	// 4. 指定默认的 Pawn（玩家控制的角色）
	// DefaultPawnClass = AMyCharacter::StaticClass();
}

void AMyBaseGameMode::BeginPlay()
{
	Super::BeginPlay();
    
	// 可以在此处打印日志，确认 HUD 是否正确加载
	if (HUDClass)
	{
		UE_LOG(LogTemp, Log, TEXT("GameMode: HUD 类已初始化为 %s"), *HUDClass->GetName());
	}
}