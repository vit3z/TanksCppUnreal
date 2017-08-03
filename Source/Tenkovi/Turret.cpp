// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Tank.h"
#include "Components/ArrowComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*if (RootComponent == nullptr)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TurretBase"));
	}*/

	RootComponent = TurretDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("TankDirection"));

	TurretSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TurretSprite"));
	TurretSprite->SetupAttachment(TurretDirection);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

