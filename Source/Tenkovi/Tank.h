// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// USTRUCT manages all possible tank inputs
// Inputs vary by tank, but same inputs will exist
USTRUCT()
struct FTankInput
{
	GENERATED_BODY()

public:
	// Sanitized movement input, ready to be used by game logic
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
	FVector2D MovementInput;

	void Sanitize();
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);

private:
	// Private because it's internal, raw data. Game code shouldn't see this
	FVector2D RawMovementInput;

};

UCLASS()
class TENKOVI_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);

public: 
	// Debug tool - which way the tank is facing
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* TankDirection;
	
	// Sprite for the tank body
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* TankSprite;

	//The actpr ised as the turret
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		UChildActorComponent* ChildTurret;

	// In-game camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraComponent;

protected:
	// Input stuct
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
		FTankInput TankInput;

	// Max turn rate (degrees/secs) of the tank
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
		float YawSpeed;

	// Max movement rate (units/secs) of the tank
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
		float MoveSpeed;
};
