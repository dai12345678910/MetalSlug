// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BirdPawn.generated.h"


UENUM()
enum class EBirdAnimationState:uint8
{
Idle,MoveUp,MoveDown,MoveLeft,MoveRight	
	
};
UCLASS()
class METALSLUG01_API ABirdPawn : public APawn
{
	GENERATED_BODY()
private:
	//动画切换函数
	void UpdateAnimationState(EBirdAnimationState NewState);
public:
	// Sets default values for this pawn's properties
	ABirdPawn();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY()
	EBirdAnimationState CurrentAnimState=EBirdAnimationState::Idle;//记录当前的动画状态
	UPROPERTY()
	FVector InputDirection=FVector::ZeroVector;//输入方向状态
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="PaperFlipbook")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* MainCamera;
	UPROPERTY(VisibleAnywhere,Category="PaperFlipbook")
	class UPaperFlipbookComponent*RnderBirdComponent;
	UPROPERTY(VisibleAnywhere,Category="PaperFlipbook")
	class UPaperFlipbookComponent*RnderBirdComponent1;
	UPROPERTY(VisibleAnywhere,Category="PaperFlipbook")
	class UCapsuleComponent* BirdCollinsion;
	//资产
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PaperFlipbook")
	class UPaperFlipbook*UpPlayerBirdFlipbook;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PaperFlipbook")
	UPaperFlipbook*UpPlayerBirdFlipbook1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PaperFlipbook")
	UPaperFlipbook*DownPlayerBirdFlipbook;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PaperFlipbook")
	UPaperFlipbook*DownPlayerBirdFlipbook1;
	//重叠事件
	void OnComponentBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                                  UPrimitiveComponent* OtherComp,
	                                  int32 OtherBodyIndex, bool bFromSweep,
	                                  const FHitResult& SweepResult);
//控制轴映射回调的函数
	
	void LeftpressedFuntion(float AxisValue1);
	void UPPressedFuntion(float AxisValue);
	UPROPERTY()
	class ABackgroudActor*ackgroudActor;
	USoundBase* Soundptr;

	FTimerHandle TimeHandle1;
	void SetTimerFunction();

};