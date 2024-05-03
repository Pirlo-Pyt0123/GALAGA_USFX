// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include  "GALAGA_USFXPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	// Enable collision
	mallaNaveEnemiga->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	mallaNaveEnemiga->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	mallaNaveEnemiga->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	mallaNaveEnemiga->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	//sonido de la explosion y particulas 
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_magicCircle1.P_ky_magicCircle1'"));
	ExplosionParticles = ParticleAsset.Object;
	//sonido explosion
	static ConstructorHelpers::FObjectFinder<USoundBase> explosionSound(TEXT("SoundWave'/Game/StarterContent/Audio/Collapse01.Collapse01'"));
	ExploSound = explosionSound.Object;

	
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemiga::OnHit);


}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
    Super::BeginPlay();
    posicion = GetActorLocation();

    // Create a particle system component
    UParticleSystemComponent* ParticleSystemComponent = UGameplayStatics::SpawnEmitterAttached(ExplosionParticles, mallaNaveEnemiga);
    //ParticleSystemComponent->SetRelativeLocation(GetActorLocation()); // Set the relative location to (0,0,0)
    //ParticleSystemComponent->SetRelativeRotation(GetActorRotation()); // Set the relative rotation to (0,0,0)
    //ParticleSystemComponent->SetRelativeScale3D(FVector::OneVector); // Set the relative scale to (1,1,1)

    // Play the particle system
    ParticleSystemComponent->ActivateSystem();

    // ...
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nave Enemiga"));


}

void ANaveEnemiga::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorLocation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExploSound, GetActorLocation());
	Destroy();
}


