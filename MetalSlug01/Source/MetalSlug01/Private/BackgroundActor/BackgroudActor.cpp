// Fill out your copyright notice in the Description page of Project Settings.


#include "BackgroundActor/BackgroudActor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

#include "Camera/CameraComponent.h"


// Sets default values
ABackgroudActor::ABackgroudActor()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BackgroundComponent=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent"));
	BackgroundComponent1=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent1"));
	BackgroundComponent2=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent2"));
	BackgroundComponent3=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent3"));
	BackgroundComponent4=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent4"));
	BackgroundComponent5=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent5"));
	BackgroundComponent6=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent6"));
	BackgroundComponent7=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent7"));
	BackgroundComponent8=CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackgroundComponent8"));
	BackgroundComponent->SetupAttachment(RootComponent);
	BackgroundComponent1->SetupAttachment(RootComponent);
	BackgroundComponent2->SetupAttachment(RootComponent);
	BackgroundComponent3->SetupAttachment(RootComponent);
	BackgroundComponent4->SetupAttachment(RootComponent);
	BackgroundComponent5->SetupAttachment(RootComponent);
	BackgroundComponent6->SetupAttachment(RootComponent);
	BackgroundComponent7->SetupAttachment(RootComponent);
	BackgroundComponent8->SetupAttachment(RootComponent);

	//设置组件位置
	BackgroundComponent->SetRelativeLocation(FVector(0.5f, 0.0f, 0.0f));
	BackgroundComponent1->SetRelativeLocation(FVector(711.5f, 0.0f, -80.f));
	BackgroundComponent2->SetRelativeLocation(FVector(1271.5f, 0.0f, -80.f));
	BackgroundComponent3->SetRelativeLocation(FVector(1831.5f, 0.0f, -80.f));
	BackgroundComponent4->SetRelativeLocation(FVector(2391.5f, 0.0f, -80.f));
	BackgroundComponent5->SetRelativeLocation(FVector(2951.5f, 0.0f, -80.f));
	BackgroundComponent6->SetRelativeLocation(FVector(3511.5f, 0.0f, -80.f));
	BackgroundComponent7->SetRelativeLocation(FVector(4071.5f, 0.0f, -80.f));
	BackgroundComponent8->SetRelativeLocation(FVector(4741.5f, 0.0f, -80.f));
	

	
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABackgroudActor::BeginPlay()
{
	Super::BeginPlay();
	
	BackgroundSprite=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image242_Sprite.image242_Sprite'"));
	BackgroundSprite1=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image259_Sprite.image259_Sprite'"));
	BackgroundSprite2=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image261_Sprite.image261_Sprite'"));
	BackgroundSprite3=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image263_Sprite.image263_Sprite'"));
	BackgroundSprite4=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image265_Sprite.image265_Sprite'"));
	BackgroundSprite5=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image267_Sprite.image267_Sprite'"));
	BackgroundSprite6=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image269_Sprite.image269_Sprite'"));
	BackgroundSprite7=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image271_Sprite.image271_Sprite'"));
	BackgroundSprite8=LoadObject<UPaperSprite>(this,TEXT("/Script/Paper2D.PaperSprite'/Game/MetalSlug01/Textures/Prop/image275_Sprite.image275_Sprite'"));
	BackgroundComponent->SetSprite(BackgroundSprite);
	BackgroundComponent1->SetSprite(BackgroundSprite1);
	BackgroundComponent2->SetSprite(BackgroundSprite2);
	BackgroundComponent3->SetSprite(BackgroundSprite3);
	BackgroundComponent4->SetSprite(BackgroundSprite4);
	BackgroundComponent5->SetSprite(BackgroundSprite5);
	BackgroundComponent6->SetSprite(BackgroundSprite6);
	BackgroundComponent7->SetSprite(BackgroundSprite7);
	BackgroundComponent8->SetSprite(BackgroundSprite8);
	
	
	
	
	
	
}

// Called every frame
void ABackgroudActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

