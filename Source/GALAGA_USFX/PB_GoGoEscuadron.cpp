// Fill out your copyright notice in the Description page of Project Settings.


#include "PB_GoGoEscuadron.h"
#include "PB_Squad.h"
#include "NaveEnemigaCazaPrime.h"
#include "NaveEnemigaEspiaKamikaze.h"

// Sets default values
APB_GoGoEscuadron::APB_GoGoEscuadron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APB_GoGoEscuadron::BeginPlay()
{
	Super::BeginPlay();
	Squadron = GetWorld()->SpawnActor<APB_Squad>(APB_Squad::StaticClass());

	// Adjuntarlo al constructor
	Squadron->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called every frame
void APB_GoGoEscuadron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APB_GoGoEscuadron::buildSquadronCaza()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron1(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir escuadron de nivel 1
	Squadron->setSquadronCaza();
}

void APB_GoGoEscuadron::buildSquadronEspia()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron1(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir escuadron de nivel 1
	Squadron->setSquadronEspia();
}

void APB_GoGoEscuadron::buildSquadronHard()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron1(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir escuadron de nivel 1
	Squadron->setSquadronHard();
}

void APB_GoGoEscuadron::buildObstacleGenerator()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildObstacleGenerator(): ObstacleGenerator es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir generador de obstaculos
	Squadron->setObstacleGenerator();
}



