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
#include "NaveEnemiga.h"
#include "Sound/SoundBase.h"

void ANaveEnemigaCazaPrime::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	
}

ANaveEnemigaCazaPrime::ANaveEnemigaCazaPrime()
{
	
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Mehes/NavesEnemigas/B-2_v1_obj.B-2_v1_obj'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	


	posicionPrime = GetActorLocation();

	//agreguemos collision 
	mallaNaveEnemiga->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	mallaNaveEnemiga->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	mallaNaveEnemiga->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	mallaNaveEnemiga->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	
	//colisionar y fiumba
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaCazaPrime::FuncionDeManejoDeColision);

	//agranda el mesh
	mallaNaveEnemiga->SetWorldScale3D(FVector(1.0f, 1.0f, 3.0f));

	//particulas que se generan al destruirse
	/*static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_lightning1.P_ky_lightning1'"));
	ExplosionParticles = ParticleAsset.Object;*/
	
	//aumenta el tamano de las particulas
	
	//particulas que se generan todo el tiempo
	/*static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset2(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_darkStorm.P_ky_darkStorm'"));
	ExplosionParticles = ParticleAsset2.Object;*/


	


}

void ANaveEnemigaCazaPrime::FuncionDeManejoDeColision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // Restar una vida al jugador


	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		
		
	}
	Destroy();

   
}

void ANaveEnemigaCazaPrime::Mover(float DeltaTime)
{

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
