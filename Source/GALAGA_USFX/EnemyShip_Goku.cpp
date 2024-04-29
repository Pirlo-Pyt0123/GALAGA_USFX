// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip_Goku.h"

AEnemyShip_Goku::AEnemyShip_Goku()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	nombreNave = "EnemyGoku";
}

void AEnemyShip_Goku::BeginPlay()
{
	Super::BeginPlay();
	speed = 50.0f;
}

void AEnemyShip_Goku::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector MoveDirection = FVector(-1.f, 0.f, 0.f);		// direccion del movimiento
	const FVector Movement = MoveDirection * speed * DeltaTime;	// la velocidad en la que se va mover

	if (Movement.SizeSquared() > 0.0f) {
		const FRotator NewRotation = FRotator(180.0f, 0.0f, 180.0f); // la rotacion de la nave enemiga

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}
