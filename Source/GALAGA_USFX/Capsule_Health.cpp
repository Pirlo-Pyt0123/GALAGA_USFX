// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsule_Health.h"
#include "GALAGA_USFXPawn.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"


ACapsule_Health::ACapsule_Health()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/Meshes/Speed.Speed'"));
	mallaCapsula->SetStaticMesh(mallaC.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsule_Health::OnHit);
	//sonido de la capsula al desaparecer
	static ConstructorHelpers::FObjectFinder<USoundBase> SonidoCapsula(TEXT("SoundWave'/Game/Sound/Disparar1.Disparar1'"));
	SonidoCapsulaC = SonidoCapsula.Object;


	
}

void ACapsule_Health::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGALAGA_USFXPawn* Pawn = Cast<AGALAGA_USFXPawn>(OtherActor);
	if (Pawn)
	{
		Pawn->AumentarVida();
		FString Message = FString::Printf(TEXT("Vidas restantes: %d "), Pawn->GetVidasRestantes());
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message);
		//actualiza sobre si mismo el mensaje de vidas
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Vida Recogida");
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorLocation(), FRotator::ZeroRotator, true);

		Destroy();//Destruir la capsula
		//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "Capsula de vida recogida");
	}
}
