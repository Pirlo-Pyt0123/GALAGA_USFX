// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip_Goku.h"

AEnemyShip_Goku::AEnemyShip_Goku()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Meshes/Nodriza1.Nodriza1'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

    mallaNaveEnemiga->SetWorldScale3D(FVector(3.0f, 3.0f, 3.0f));

	speed = 150.0f;
}

void AEnemyShip_Goku::BeginPlay()
{
	Super::BeginPlay();
	

	


}

void AEnemyShip_Goku::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void AEnemyShip_Goku::Mover(float DeltaTime)
{
    const FVector MoveDirection = FVector(0.f, -1.f, 0.f);    // dirección del movimiento en el eje y
    const FVector Movement = MoveDirection * speed * DeltaTime;    // la velocidad a la que se va a mover

    if (Movement.SizeSquared() > 0.0f) {
        const FRotator NewRotation = FRotator(180.0f, 0.0f, 180.0f); // la rotación de la nave enemiga

        FHitResult Hit(1.0f);
        RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
    }

 
}

void AEnemyShip_Goku::Disparar(FVector FireDirection)
{

}

void AEnemyShip_Goku::Destruirse()
{

}
