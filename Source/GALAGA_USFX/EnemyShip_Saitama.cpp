// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip_Saitama.h"

AEnemyShip_Saitama::AEnemyShip_Saitama()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Mehes/Nave/Fighter_03.Fighter_03'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}

void AEnemyShip_Saitama::BeginPlay()
{
}

void AEnemyShip_Saitama::Tick(float DeltaTime)
{
}

void AEnemyShip_Saitama::Mover(float DeltaTime)
{
}

void AEnemyShip_Saitama::Disparar(FVector FireDirection)
{
}

void AEnemyShip_Saitama::Destruirse()
{
}
