// Fill out your copyright notice in the Description page of Project Settings.


#include "HomeAGameModeBase.h"

#include "Players/SuperMarioPaperCharacter.h"


class ASuperMarioPaperCharacter;

AHomeAGameModeBase::AHomeAGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ASuperMarioPaperCharacter> Path(TEXT(
	"/Script/Engine.Blueprint'/Game/Blueprints/BP_SuperMarioPaperCharacter.BP_SuperMarioPaperCharacter_C'"));
	DefaultPawnClass = Path.Class;
}
