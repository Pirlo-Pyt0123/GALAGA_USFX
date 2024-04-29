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

}

void AEnemyShip_VivaPeru::Tick(float DeltaTime)
{
}
