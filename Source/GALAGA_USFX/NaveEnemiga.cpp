// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include  "GALAGA_USFXPawn.h"

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
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	posicion = GetActorLocation();

}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when the ship collides with another actor
void ANaveEnemiga::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	// Check if the other actor is the player ship
	AGALAGA_USFXPawn* MiNave = Cast<AGALAGA_USFXPawn>(OtherActor);
	if (MiNave != nullptr)
	{
		MiNave->RestarVida();
		//hagamos un mensaje que se actualize sobre si mismo de la cantidada de vidas que me quedan
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Vidas")));
		GEngine->ClearOnScreenDebugMessages();
	}
	// Destroy the projectile
	Destroy();
}
