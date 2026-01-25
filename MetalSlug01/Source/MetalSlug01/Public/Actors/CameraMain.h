// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraMain.generated.h"

UCLASS()
class METALSLUG01_API ACameraMain : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACameraMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//弹簧臂
	UPROPERTY(VisibleAnywhere,Category="CameraActor")
	class USpringArmComponent* USpringArm;
	//相机
	UPROPERTY(VisibleAnywhere,Category="CameraActor")
	class UCameraComponent* MainCameraComponent;
	//玩家控制器
	UPROPERTY()
	APlayerController* PlayerController;
	void CameraFollowMario();
	UPROPERTY(EditAnywhere,category="CameraActor",meta=(ClampMax=1200.f,ClampMin=0.f))
	float CameraFollowOffset=800.f;
	UPROPERTY()
	class ASuperMarioPaperCharacter*Mario;
	//设置屏幕左侧的遮挡物功能
	void SetScreenBlock();
	//持有屏幕左侧的遮挡物组件
	UPROPERTY(VisibleAnywhere,Category="CameraActor")
	class UBoxComponent*ScreenBlock;
	//用于修正阻挡物位置的参数
	UPROPERTY(EditAnywhere,Category="CameraActor",meta=(ClampMin=-40.f,ClampMax=40.f))
	float CameraBlockOffset=0.f;
	
};
