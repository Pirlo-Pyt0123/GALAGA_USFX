// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip_Saitama.h"

AEnemyShip_Saitama::AEnemyShip_Saitama()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_In.Shape_Trim_90_In'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}

void AEnemyShip_Saitama::BeginPlay()
{
}

void AEnemyShip_Saitama::Tick(float DeltaTime)
{
}
