// Fill out your copyright notice in the Description page of Project Settings.


#include "Players/BirdPawn.h"

#include "Camera/CameraComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "BackgroundActor/BackgroudActor.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABirdPawn::ABirdPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	MainCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(GetRootComponent());
	MainCamera->SetRelativeLocation(FVector(0.0f, 200.f, 100.f));
	RnderBirdComponent=CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("RnderBirdComponent"));
	RnderBirdComponent->SetupAttachment(RootComponent);
	RnderBirdComponent->SetRelativeLocation(FVector(0.f, 0.0f, -10.f));
	RnderBirdComponent1=CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("RnderBirdComponent1"));
	RnderBirdComponent1->SetupAttachment(RootComponent);
	RnderBirdComponent1->SetRelativeLocation(FVector(0.0f, 0.0f, -45.f));
	BirdCollinsion=CreateDefaultSubobject<UCapsuleComponent>(TEXT("BirdCollinsion"));
	BirdCollinsion->SetupAttachment(RootComponent);
	BirdCollinsion->SetRelativeLocation(FVector(0.0f, 0.0f, -20.f));
	SpringArm->SetRelativeRotation(FRotator(0.0f, -90.f, 0.0f));
	SpringArm->bDoCollisionTest = false;
	MainCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	MainCamera->SetOrthoWidth(900.f);
	MainCamera->bConstrainAspectRatio=true;
	MainCamera->SetAspectRatio(4071.f/800.f);
	BirdCollinsion->SetCollisionProfileName(TEXT("OverLapAll"));
	BirdCollinsion->SetCapsuleRadius(35);
	BirdCollinsion->SetCapsuleHalfHeight(44);
	//设置触发器参数
	BirdCollinsion->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//只检测重叠，不参与物理碰撞	
	BirdCollinsion->SetCollisionObjectType(ECC_WorldDynamic);
	BirdCollinsion->SetCollisionResponseToAllChannels(ECR_Ignore);//默认忽略所有通道
	BirdCollinsion->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);//只与玩家Pawn发生重叠
	BirdCollinsion->SetGenerateOverlapEvents(true);
	//初始化动画播放设置
	RnderBirdComponent->SetLooping(true);
	RnderBirdComponent1->SetLooping(true);
	//相机绑定角色
	MainCamera->AttachToComponent(ABirdPawn::GetRootComponent(),FAttachmentTransformRules::KeepWorldTransform);
	static ConstructorHelpers::FObjectFinder<USoundBase>Math(TEXT("/Script/Engine.SoundWave'/Game/MetalSlug01/Sounds/声音229_sound229__爱给网_aigei_com.声音229_sound229__爱给网_aigei_com'"));
	Soundptr=Math.Object;
}//

// Called when the game starts or when spawned
void ABirdPawn::BeginPlay()
{	Super::BeginPlay();
	ackgroudActor=GetWorld()->SpawnActor<ABackgroudActor>(ABackgroudActor::StaticClass(),FVector(-460.f,0.f,-160.f),FRotator::ZeroRotator);
	UpPlayerBirdFlipbook=LoadObject<UPaperFlipbook>(this,TEXT("/Script/Paper2D.PaperFlipbook'/Game/MetalSlug01/Animations/PF_UpPlayer.PF_UpPlayer'"));
	UpPlayerBirdFlipbook1=LoadObject<UPaperFlipbook>(this,TEXT(""));
	DownPlayerBirdFlipbook=LoadObject<UPaperFlipbook>(this,TEXT("/Script/Paper2D.PaperFlipbook'/Game/MetalSlug01/Animations/PF_DownPlayer1.PF_DownPlayer1'"));
	DownPlayerBirdFlipbook1=LoadObject<UPaperFlipbook>(this,TEXT("/Script/Paper2D.PaperFlipbook'/Game/MetalSlug01/Animations/PF_DownPlayer.PF_DownPlayer'"));
	if (UpPlayerBirdFlipbook)
	{
		RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
	}
	if (DownPlayerBirdFlipbook)
	{
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook);
	}
	//绑定重叠事件
	BirdCollinsion->OnComponentBeginOverlap.AddDynamic(this,&ABirdPawn::OnComponentBeginOverlapEvent);
	//获取玩家控制器，并设置ViewTarget为当前Pawn
	APlayerController* PC=Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->SetViewTarget(this);
	}
	GetWorldTimerManager().SetTimer(TimeHandle1,this,&ABirdPawn::SetTimerFunction,1.f,false);
}

void ABirdPawn::SetTimerFunction()
{

	UGameplayStatics::PlaySound2D(GetWorld(),Soundptr);
	GetWorldTimerManager().SetTimer(TimeHandle1,this,&ABirdPawn::SetTimerFunction,30.f,true);
}

//只有状态发生变化才调用SetFlipbook
void ABirdPawn::UpdateAnimationState(EBirdAnimationState NewState)
{
	/*if (NewState==CurrentAnimState||!RnderBirdComponent||RnderBirdComponent1)
	{
		return;
	}*/
	CurrentAnimState=NewState;
	UPaperFlipbook*TargetFlipbook=nullptr;
	switch (NewState)
	{
	case EBirdAnimationState::Idle:
		{
			TargetFlipbook=UpPlayerBirdFlipbook;RnderBirdComponent->SetFlipbook(TargetFlipbook);
			//TargetFlipbook=DownPlayerBirdFlipbook;
		}   break;
	case EBirdAnimationState::MoveUp:
		TargetFlipbook=DownPlayerBirdFlipbook1;break;
	case EBirdAnimationState::MoveDown:
		TargetFlipbook=DownPlayerBirdFlipbook1;break;
	case EBirdAnimationState::MoveLeft:
		TargetFlipbook=DownPlayerBirdFlipbook1;break;
	case EBirdAnimationState::MoveRight:
		TargetFlipbook=DownPlayerBirdFlipbook1;break;
	default: break;	
	}
	
	if (TargetFlipbook)
	{
		RnderBirdComponent1->SetFlipbook(TargetFlipbook);
	}

	
}
// 在Tick中更新动画状态
void ABirdPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	EBirdAnimationState NewAnimState=EBirdAnimationState::Idle;
	//优先级判断当前状态，比如上下优先于左右
	if (InputDirection.Z>0.f)
	{
		NewAnimState=EBirdAnimationState::MoveUp;
	}
	else if (InputDirection.Z<0.f)
	{
		NewAnimState=EBirdAnimationState::MoveDown;
	}
	else if (InputDirection.X>0.f)
	{
		NewAnimState=EBirdAnimationState::MoveRight;
	}
	else if (InputDirection.X<0.f)
	{
		NewAnimState=EBirdAnimationState::MoveLeft;
	}
	UpdateAnimationState(NewAnimState);
	*/
	
	
	
	if (RnderBirdComponent&&RnderBirdComponent1)
	{
		RnderBirdComponent1->SetPlaybackPosition(RnderBirdComponent->GetPlaybackPosition(),false);
	}
	if (MainCamera)
	{
		FVector PlayerPos=GetActorLocation();
		FVector CameraOffset=FVector(0.f,200.f,100.f);
		/*MainCamera->SetWorldLocation(TaggetPos+CameraOffset);
		FVector CameraLookAt=TaggetPos+MainCamera->GetComponentLocation();
		MainCamera->SetWorldRotation(CameraLookAt.Rotation());*/
		//计算相机目标位置
		FVector TargetCamPos=PlayerPos+CameraOffset;
		//平滑跟随，避免相机抖动
		FVector SmoothCamPos=FMath::VInterpTo(MainCamera->GetComponentLocation(),TargetCamPos,DeltaTime,5.f);
		MainCamera->SetWorldLocation(SmoothCamPos);
		MainCamera->SetWorldRotation((PlayerPos-SmoothCamPos).Rotation());
		
	}
	
}
void ABirdPawn::OnComponentBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

// Called to bind functionality to input
void ABirdPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"),this,&ABirdPawn::LeftpressedFuntion);
	PlayerInputComponent->BindAxis(TEXT("UpDown"),this,&ABirdPawn::UPPressedFuntion);
}
//输入函数只记录方向
void ABirdPawn::LeftpressedFuntion(float AxisValue)
{
	if (AxisValue==0)
	{
		RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
			RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook);return;
	}
	if (AxisValue==1)
	{
		RnderBirdComponent1->SetRelativeRotation(FRotator(0,-180,0));
		RnderBirdComponent->SetRelativeRotation(FRotator(0,-180,0));
		RnderBirdComponent->AddRelativeLocation(FVector(AxisValue,0,0));
		RnderBirdComponent1->AddRelativeLocation(FVector(AxisValue,0,0));
		/*RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook1);*/
		
		UpdateAnimationState(EBirdAnimationState::MoveRight);
	}
	if (AxisValue==-1)
	{
		RnderBirdComponent1->SetRelativeRotation(FRotator(0,0,0));
		RnderBirdComponent->SetRelativeRotation(FRotator(0,0,0));
		RnderBirdComponent->AddRelativeLocation(FVector(AxisValue,0,0));
		RnderBirdComponent1->AddRelativeLocation(FVector(AxisValue,0,0));
		/*RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook1);*/
		UpdateAnimationState(EBirdAnimationState::MoveLeft);
	}

}

void ABirdPawn::UPPressedFuntion(float AxisValue)
{
	if (AxisValue==0)
	{
		RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
			RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook);return;
	}
	if (AxisValue==1)
	{
	
		RnderBirdComponent->AddRelativeLocation(FVector(0,0,AxisValue));
		RnderBirdComponent1->AddRelativeLocation(FVector(0,0,AxisValue));
		
		
		UpdateAnimationState(EBirdAnimationState::MoveUp);
	}
	if (AxisValue==-1)
	{
		
		RnderBirdComponent->AddRelativeLocation(FVector(0,0,AxisValue));
		RnderBirdComponent1->AddRelativeLocation(FVector(0,0,AxisValue));
		UpdateAnimationState(EBirdAnimationState::MoveDown);
	}
}




/*void ABirdPawn::LeftpressedFuntion(float AxisValue1)
{if (AxisValue1==0)
	{RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
	RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook);return;
	}
	if (AxisValue1==1)
	{RnderBirdComponent1->SetRelativeRotation(FRotator(0,-180,0));
		RnderBirdComponent->SetRelativeRotation(FRotator(0,-180,0));
		RnderBirdComponent->AddRelativeLocation(FVector(AxisValue1,0,0));
			RnderBirdComponent1->AddRelativeLocation(FVector(AxisValue1,0,0));
		RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook1);
	}
	if (AxisValue1==-1)
	{RnderBirdComponent1->SetRelativeRotation(FRotator(0,0,0));
		RnderBirdComponent->SetRelativeRotation(FRotator(0,0,0));
		RnderBirdComponent->AddRelativeLocation(FVector(AxisValue1,0,0));
		RnderBirdComponent1->AddRelativeLocation(FVector(AxisValue1,0,0));
		RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook1);
	}
}
void ABirdPawn::UPPressedFuntion(float AxisValue)
{if (AxisValue==0)
	{RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook);
		return;
	}
	if (AxisValue==1)
	{RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook1);
		RnderBirdComponent->AddRelativeLocation(FVector(0,0,AxisValue));
		RnderBirdComponent1->AddRelativeLocation(FVector(0,0,AxisValue));
	}
	if (AxisValue==-1)
	{RnderBirdComponent->SetFlipbook(UpPlayerBirdFlipbook);
		RnderBirdComponent1->SetFlipbook(DownPlayerBirdFlipbook1);
		RnderBirdComponent->AddRelativeLocation(FVector(0,0,AxisValue));
		RnderBirdComponent1->AddRelativeLocation(FVector(0,0,AxisValue));
	}
}*/

//RnderBirdComponent1->AddRelativeRotation(FRotator(0,0,0));
//RnderBirdComponent->AddRelativeRotation(FRotator(0,0,0));
/*FVector NewLVector=RnderBirdComponent->GetRelativeLocation();
NewLVector.Z+=AxisValue;
RnderBirdComponent->SetRelativeLocation(NewLVector);
FVector NewLVector1=RnderBirdComponent1->GetRelativeLocation();
NewLVector1.Z+=AxisValue;
RnderBirdComponent1->SetRelativeLocation(NewLVector1);*/

