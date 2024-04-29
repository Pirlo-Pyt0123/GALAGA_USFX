// Fill out your copyright notice in the Description page of Project Settings.


#include "FABRICA_PIRLOinc.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaPrime.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaKamikaze.h"


// Sets default values
AFABRICA_PIRLOinc::AFABRICA_PIRLOinc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ANaveEnemiga* AFABRICA_PIRLOinc::FabricarNave(FString NaveaFabricar, UWorld* World, FVector SpawnLocation, FRotator SpawnRotation)
{
    FVector UbicacionSpawneo = SpawnLocation;
    if (NaveaFabricar == "NaveEnemigaCaza")
    {
        ANaveEnemigaCaza* NaveFabricada = World->SpawnActor<ANaveEnemigaCazaPrime>(UbicacionSpawneo, SpawnRotation);
        return NaveFabricada;
    }
    else if (NaveaFabricar == "NaveEnemigaEspia")
    {
        ANaveEnemigaEspia* NaveFabricada = World->SpawnActor<ANaveEnemigaEspiaKamikaze>(UbicacionSpawneo, SpawnRotation);
        return NaveFabricada;
    }

	return nullptr;
}

// Called when the game starts or when spawned
void AFABRICA_PIRLOinc::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFABRICA_PIRLOinc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

