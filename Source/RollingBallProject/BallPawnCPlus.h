// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BallPawnCPlus.generated.h"

UCLASS()
class ROLLINGBALLPROJECT_API ABallPawnCPlus : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABallPawnCPlus();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
	class UStaticMeshComponent* BallMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pawn Setup")
	class USphereComponent* CollisionSphere;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Val);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float Val);

	void Turn(float Val);

	void Lookup(float Val);

	virtual void AddTorqueInRadians(float Val);

	

	void IncrementObject(int32 Number);

	UPROPERTY(VisibleAnywhere, Category = "Score")
	int32 CurrentObjectCount;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
