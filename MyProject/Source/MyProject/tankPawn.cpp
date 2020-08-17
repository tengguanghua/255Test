// Fill out your copyright notice in the Description page of Project Settings.


#include "tankPawn.h"

// Sets default values
AtankPawn::AtankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	body = CreateDefaultSubobject<UStaticMeshComponent>("body");
	RootComponent = body;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("springarm");
	Camera = CreateDefaultSubobject<UCameraComponent>("camera");

	SpringArm->AttachToComponent(body, FAttachmentTransformRules::KeepWorldTransform);
	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepWorldTransform);

	SpringArm->TargetArmLength = SpringArmDistance;
	SpringArm->SocketOffset = FVector(0.f, 0.f, 90.f);

}

// Called when the game starts or when spawned
void AtankPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AtankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementInput.IsZero())
	{
		FVector NewLocation = this->GetActorLocation();
		NewLocation += this->GetActorRightVector() * MovementInput.Y * MovementScale;
		NewLocation += this->GetActorForwardVector() * MovementInput.X * MovementScale;
		RootComponent->SetWorldLocation(NewLocation);

	}

}

// Called to bind functionality to input
void AtankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Tankmoveright", this, &AtankPawn::MoveRight);
	PlayerInputComponent->BindAxis("TankmoverForward", this, &AtankPawn::MoveForward);

}






void AtankPawn::MoveForward(float val)
{
	MovementInput.X = FMath::Clamp<float>(val, -1.0f, 1.0f);
}

void AtankPawn::MoveRight(float val)
{
	MovementInput.Y = FMath::Clamp<float>(val, -1.0f, 1.0f);
}
