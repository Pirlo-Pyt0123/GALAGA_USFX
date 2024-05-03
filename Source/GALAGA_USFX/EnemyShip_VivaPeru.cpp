// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip_VivaPeru.h"

AEnemyShip_VivaPeru::AEnemyShip_VivaPeru()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AEnemyShip_VivaPeru::BeginPlay()
{
	Super::BeginPlay();
	

}

void AEnemyShip_VivaPeru::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void AEnemyShip_VivaPeru::Mover(float DeltaTime)
{
	// Movimiento de la nave
	FVector NewLocation = GetActorLocation() + (GetActorForwardVector() * speed * DeltaTime);
	SetActorLocation(NewLocation);

}

void AEnemyShip_VivaPeru::Disparar(FVector FireDirection)
{
}

void AEnemyShip_VivaPeru::Destruirse()
{
}
