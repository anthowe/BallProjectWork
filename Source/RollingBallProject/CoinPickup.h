// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "CoinPickup.generated.h"

/**
 * 
 */
UCLASS()
class ROLLINGBALLPROJECT_API ACoinPickup : public APickup
{
	GENERATED_BODY()
public:

	ACoinPickup();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
	int32 CurrentCoinCount;

	
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	virtual void BeginPlay() override;
	
};
