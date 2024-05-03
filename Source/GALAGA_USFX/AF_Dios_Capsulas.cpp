// Fill out your copyright notice in the Description page of Project Settings.


#include "AF_Dios_Capsulas.h"
#include "Capsule_Furia.h"
#include "Capsule_Health.h"

// Sets default values
AAF_Dios_Capsulas::AAF_Dios_Capsulas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ACapsule_Dios* AAF_Dios_Capsulas::GenerarCapsulas(FString tipoCapsula, UWorld* World, FVector SpawnLocation, FRotator ZeroRotator)
{
	FVector SpawnLocat = SpawnLocation;
	if (tipoCapsula == "Energia")
	{
		ACapsule_Furia* CapsulaEnergia = World->SpawnActor<ACapsule_Furia>(SpawnLocat, ZeroRotator);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Generando Capsula de Energia"));
		return CapsulaEnergia;
	}
	else if (tipoCapsula == "Vida")
	{
		ACapsule_Health* CapsulaVida = World->SpawnActor<ACapsule_Health>(SpawnLocat, ZeroRotator);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Generando Capsula de Vida"));
		return CapsulaVida;
	}
	return nullptr;
	
}

// Called when the game starts or when spawned
void AAF_Dios_Capsulas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAF_Dios_Capsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

