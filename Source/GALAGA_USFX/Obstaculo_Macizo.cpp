// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo_Macizo.h"



// Sets default values
AObstaculo_Macizo::AObstaculo_Macizo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Obstaculo(TEXT("StaticMesh'/Game/Meshes/Food.Food'"));
	// Create the mesh componentq
	mallaObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstaculo"));
	mallaObstaculo->SetStaticMesh(Obstaculo.Object);
	mallaObstaculo->SetupAttachment(RootComponent);
	RootComponent = mallaObstaculo;

	//aumenta tamano
	mallaObstaculo->SetWorldScale3D(FVector(4.0f, 4.0f, 3.0f));

	

}

// Called when the game starts or when spawned
void AObstaculo_Macizo::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AObstaculo_Macizo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverObstaculo(DeltaTime);

}

void AObstaculo_Macizo::MoverObstaculo(float DeltaTime)
{
	//crea movimiento del obstaculo
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
	

}

