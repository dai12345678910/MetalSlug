// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CameraMain.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Players/SuperMarioPaperCharacter.h"


// Sets default values


ACameraMain::ACameraMain()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent=CreateDefaultSubobject<USceneComponent>("RootComponent");
	USpringArm=CreateDefaultSubobject<USpringArmComponent>("USpringArm");
	MainCameraComponent=CreateDefaultSubobject<UCameraComponent>("MainCameraComponent");
	USpringArm->SetupAttachment(RootComponent);
	MainCameraComponent->SetupAttachment(USpringArm);
	
	ScreenBlock=CreateDefaultSubobject<UBoxComponent>("ScreenBlock");
	ScreenBlock->SetupAttachment(RootComponent);
	ScreenBlock->SetCollisionProfileName(TEXT("BlockAll"));
}

// Called when the game starts or when spawned
void ACameraMain::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle,this,&ACameraMain::SetScreenBlock,0.2f);
	
	//玩家控制器第一种赋值方式
	PlayerController=UGameplayStatics::GetPlayerController(GetWorld(),0);
	//玩家控制器第二种赋值方式
	//PlayerController=GetWorld()->GetFirstPlayerController();
	//直接切视角
	if (PlayerController)
	{
		PlayerController->SetViewTarget(this);
	}
	//过渡切视角
	/*if (PlayerController)
	{
		PlayerController->SetViewTargetWithBlend(this,3.f);
	}*/
}

// Called every frame
void ACameraMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CameraFollowMario();
}

void ACameraMain::CameraFollowMario()
{
	if (!Mario)
	{
		Mario=Cast<ASuperMarioPaperCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	}
	if (Mario)
	{
		if (GetActorLocation().X+CameraFollowOffset<=Mario->GetActorLocation().X)
		{
			FVector FollowLocation=GetActorLocation();
			FollowLocation.X=Mario->GetActorLocation().X-CameraFollowOffset;
			SetActorLocation(FollowLocation);
		}
		
		
	}
}
//设置屏幕左侧的遮挡物功能
void ACameraMain::SetScreenBlock()
{
	if (PlayerController)
	{
		FVector WorldLocation,WorldDirection;
		PlayerController->DeprojectScreenPositionToWorld(0,0,WorldLocation,WorldDirection);
		WorldLocation.X+=CameraBlockOffset;
		if (!Mario)
		{
			Mario=Cast<ASuperMarioPaperCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
		}
		if (Mario)
		{
			WorldLocation.Y=Mario->GetActorLocation().Y;	
		}
		ScreenBlock->SetWorldLocation(WorldLocation);
	}
}
