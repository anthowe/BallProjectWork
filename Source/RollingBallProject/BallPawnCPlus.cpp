// Fill out your copyright notice in the Description page of Project Settings.

#include "BallPawnCPlus.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/BodySetup.h"
#include "PhysicsReplication.h"
#include "PhysicsPublic.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"


// Sets default values
ABallPawnCPlus::ABallPawnCPlus()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = BallMesh;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(BallMesh);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bInheritPitch = false;
	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;


	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(BallMesh);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	CurrentObjectCount = 0;
	
}

void ABallPawnCPlus::MoveForward(float Val)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Val);
	
}

void ABallPawnCPlus::MoveRight(float Val)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Val);
}

void ABallPawnCPlus::Turn(float Val)
{
	AddControllerYawInput(Val);
	
}

void ABallPawnCPlus::Lookup(float Val)
{
	AddControllerPitchInput(Val);
}

void ABallPawnCPlus::AddTorqueInRadians(float Val)
{
	AddTorqueInRadians(Val);
}



// Called when the game starts or when spawned
void ABallPawnCPlus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallPawnCPlus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABallPawnCPlus::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABallPawnCPlus::AddTorqueInRadians);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABallPawnCPlus::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ABallPawnCPlus::Turn);
	PlayerInputComponent->BindAxis("Lookup", this, &ABallPawnCPlus::Lookup);
	
}

void ABallPawnCPlus::IncrementObject(int32 Number)
{
	CurrentObjectCount += Number;
	UE_LOG(LogTemp, Warning, TEXT("Score: %i"), CurrentObjectCount);
	
}