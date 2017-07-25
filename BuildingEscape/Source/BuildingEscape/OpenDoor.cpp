// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenDoor::OpenDoor()
{
	// find the owning actor
	AActor* Owner = GetOwner();
	FString OwnerRotation = Owner->GetTransform().GetRotation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OwnerRotation);

	// create a rotator
	FRotator NewRotation = FRotator(0.f, -70.f, 0.f);

	// set the door rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// poll the trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	// if ActorThatOpens is in volume
	OpenDoor();
}

