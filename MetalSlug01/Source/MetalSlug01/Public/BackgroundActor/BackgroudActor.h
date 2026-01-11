// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroudActor.generated.h"

UCLASS()
class METALSLUG01_API ABackgroudActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABackgroudActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor1|a")
	class UPaperSpriteComponent* BackgroundComponent;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor2")
	UPaperSpriteComponent* BackgroundComponent1;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor3")
	UPaperSpriteComponent* BackgroundComponent2;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor4")
	UPaperSpriteComponent* BackgroundComponent3;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor5")
	UPaperSpriteComponent* BackgroundComponent4;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor6")
	UPaperSpriteComponent* BackgroundComponent5;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor7")
	UPaperSpriteComponent* BackgroundComponent6;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor8")
	UPaperSpriteComponent* BackgroundComponent7;
	UPROPERTY(VisibleAnywhere,Category="backgroudActor9")
	UPaperSpriteComponent* BackgroundComponent8;
	
	UPROPERTY(VisibleAnywhere,Category="backgroudActor1")
	class UPaperSprite* BackgroundSprite;
	UPROPERTY(EditAnywhere,Category="backgroudActor2")
	UPaperSprite* BackgroundSprite1;
	UPROPERTY(EditAnywhere,Category="backgroudActor3")
	UPaperSprite* BackgroundSprite2;
	UPROPERTY(EditAnywhere,Category="backgroudActor4")
	UPaperSprite* BackgroundSprite3;
	UPROPERTY(EditAnywhere,Category="backgroudActor5")
	UPaperSprite* BackgroundSprite4;
	UPROPERTY(EditAnywhere,Category="backgroudActor6")
	UPaperSprite* BackgroundSprite5;
	UPROPERTY(EditAnywhere,Category="backgroudActor7")
	UPaperSprite* BackgroundSprite6;
	UPROPERTY(EditAnywhere,Category="backgroudActor8")
	UPaperSprite* BackgroundSprite7;
	UPROPERTY(EditAnywhere,Category="backgroudActor9")
	UPaperSprite* BackgroundSprite8;
};
