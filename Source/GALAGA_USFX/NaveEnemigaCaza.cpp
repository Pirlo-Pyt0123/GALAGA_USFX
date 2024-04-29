// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "GALAGA_USFXProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	PrimaryActorTick.bCanEverTick = true;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	/*speed = 1;
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y, GetActorLocation().Z)); 

	if (Super::GetPosicion().X == -1600.0f) {
		SetPosicion(FVector(200, 200, 250)); 
	} */
}

void ANaveEnemigaCaza::Disparar(FVector FireDirection)
{
	if (bCanFire)
	{
		// Si la dirección de disparo tiene un tamaño cuadrado mayor que 0 (es decir, si hay una dirección válida)
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Calcula la ubicación de donde se debe disparar el proyectil
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			// Obtiene el mundo
			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// Spawnea el proyectil
				World->SpawnActor<AGALAGA_USFXProjectile>(SpawnLocation, FireRotation);
			}

			// Establece bCanFire en falso para evitar disparos continuos
			bCanFire = false;

			// Configura un temporizador para reactivar el disparo después de 3 segundos
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaCaza::ShotTimerExpired, 1.0f, false);
		}
	}
}

void ANaveEnemigaCaza::Destruirse()
{
}

void ANaveEnemigaCaza::Escapar()
{
}

void ANaveEnemigaCaza::ShotTimerExpired()
{
	bCanFire = true;
}
