// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsule_Dios.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "GALAGA_USFXPawn.h"

// Sets default values
ACapsule_Dios::ACapsule_Dios()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaC(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaCapsula = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsulaMesh"));
	mallaCapsula->SetupAttachment(RootComponent);
	mallaCapsula->SetStaticMesh(mallaC.Object);
	RootComponent = mallaCapsula;
	InitialLifeSpan = 3.0f;
	//creemos las particulas despues del destroy
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_ThunderBallHit.P_ky_ThunderBallHit'"));
	if (ParticleSystemAsset.Succeeded())
	{
		DestructionParticle = ParticleSystemAsset.Object;
		//DestructionParticle->Deactivate(); // Desactivar el sistema de partículas inicialmente
	}

	
}

// Called when the game starts or when spawned
void ACapsule_Dios::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsule_Dios::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

