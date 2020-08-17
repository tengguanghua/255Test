// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "tankPawn.generated.h"

UCLASS()
class MYPROJECT_API AtankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AtankPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float SpringArmDistance = 500.f;

	//movement scale
	float MovementScale = 5.f;

	FVector2D MovementInput;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
		UStaticMeshComponent* body;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
		USpringArmComponent* SpringArm;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
		UCameraComponent* Camera;

	void MoveForward(float Value);
	void MoveRight(float Value);


};
