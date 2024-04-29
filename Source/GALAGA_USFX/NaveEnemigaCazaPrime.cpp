// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCazaPrime.h"
#include "GALAGA_USFXProjectile.h"
#include "GALAGA_USFXPawn.h"
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

void ANaveEnemigaCazaPrime::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveEnemigaCazaPrime::ANaveEnemigaCazaPrime()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	posicionPrime = GetActorLocation();

	//agreguemos collision 
	mallaNaveEnemiga->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	mallaNaveEnemiga->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	mallaNaveEnemiga->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	mallaNaveEnemiga->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ExplosionAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ExplosionParticles = ExplosionAsset.Object;
	//sonido explosion
	static ConstructorHelpers::FObjectFinder<USoundBase> explosionSound(TEXT("SoundWave'/Game/StarterContent/Audio/Explosion02.Explosion02'"));
	ExploSound = explosionSound.Object;
	////colisionar y fiumba
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaCazaPrime::FuncionDeManejoDeColision);
}

void ANaveEnemigaCazaPrime::FuncionDeManejoDeColision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    // Restar una vida al jugador
    if (OtherActor->IsA(AGALAGA_USFXPawn::StaticClass()))
    {
        AGALAGA_USFXPawn* MiNave = Cast<AGALAGA_USFXPawn>(OtherActor);
        if (MiNave != nullptr)
        {
            MiNave->RestarVida();
        }
    }

    //// Restar una vida a la nave enemiga
    //if (OtherActor->IsA(ANaveEnemigaCazaPrime::StaticClass()))
    //{
    //    ANaveEnemigaCazaPrime* NaveEnemiga = Cast<ANaveEnemigaCazaPrime>(OtherActor);
    //    if (NaveEnemiga != nullptr)
    //    {
    //        NaveEnemiga->Destruirse();
    //    }
    //}

    Destroy();
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorLocation());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExploSound, GetActorLocation());
}

void ANaveEnemigaCazaPrime::Mover(float DeltaTime)
{
	ANaveEnemigaCaza::Mover(DeltaTime);
	speed = 3;
	SetActorRotation(FRotator(0, 180, vueltas));
	vueltas += 2;
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y + speed * banderaA, GetActorLocation().Z));
	posicionPrime = GetActorLocation();
	if (GetActorLocation().Y > GetPosicion().Y + 500 || GetActorLocation().Y < GetPosicion().Y - 500) {
		banderaA *= -1;
	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
	if (vueltas > 360) {

		vueltas = 0;
	}
	if (vueltas % 60 <= 3) {
		const FVector FireDirection = FVector(-1.f, 0.f, 0.f);
		Disparar(FireDirection);
	}

}

void ANaveEnemigaCazaPrime::Disparar(FVector FireDirection)
{
	if (bCanFire)
	{
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AGALAGA_USFXProjectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;

			// Configura un temporizador para reactivar el disparo después de 3 segundos
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaCazaPrime::ShotTimerExpired, 0.5f, false);
			//
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaCazaPrime::ShotTimerExpired,2.0f, false);
		}
	}
}

void ANaveEnemigaCazaPrime::Destruirse()
{
	

}

void ANaveEnemigaCazaPrime::Escapar()
{
}
