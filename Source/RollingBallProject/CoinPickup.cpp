// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinPickup.h"
#include "Components/StaticMeshComponent.h"
#include "BallPawnCPlus.h"

ACoinPickup::ACoinPickup()
{
	
	
	CurrentObjectCount = CurrentCoinCount;
	CurrentCoinCount = 5;
	
}

void ACoinPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	ABallPawnCPlus* Main = Cast<ABallPawnCPlus>(OtherActor);

	if (Main)
	{
		UE_LOG(LogTemp, Warning, TEXT("CoinBeginOverlap"));
		Main->IncrementObject(CurrentObjectCount);

		Destroy();
	}
}

void ACoinPickup::OnOverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

void ACoinPickup::BeginPlay()
{
	Super::BeginPlay();


}
