// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_naves_mediocres.h"

// Sets default values for this component's properties
UMove_naves_mediocres::UMove_naves_mediocres()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMove_naves_mediocres::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMove_naves_mediocres::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AActor* Actor = GetOwner();
	if (Actor)
	{
		FVector PosicionActual = Actor->GetActorLocation();
		FVector NuevaPosicion = FVector(PosicionActual.X - 100 * DeltaTime * 2, PosicionActual.Y, PosicionActual.Z + sin(PosicionActual.X / 180) * 2 * 2);
		Actor->SetActorLocation(NuevaPosicion);
		if (NuevaPosicion.X < -1600) {
			Actor->SetActorLocation(FVector(1500.0f, PosicionActual.Y, 250.0f));
		}
	}
}

