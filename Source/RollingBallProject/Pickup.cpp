// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "BallPawnCPlus.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
APickup::APickup()
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(Capsule);

	

	CurrentObjectCount =1;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnOverlapBegin);
	PickupMesh->OnComponentEndOverlap.AddDynamic(this, &APickup::OnOverlapEnd);
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void APickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)

{
	ABallPawnCPlus* Main = Cast<ABallPawnCPlus>(OtherActor);

	if (Main)
	{
		UE_LOG(LogTemp, Warning, TEXT("PickupBeginOverlap"));
		Main->IncrementObject(CurrentObjectCount);
	
		Destroy();
	}
}

void APickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)

{
}
