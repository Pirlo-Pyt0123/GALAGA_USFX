// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Mehes/NavesEnemigas/Spaceships_10.Spaceships_10'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	MoviminetoMediocre = CreateDefaultSubobject<UMove_naves_mediocres>(TEXT("MoviminetoMediocre"));
}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{

}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
}

void ANaveEnemigaEspia::Escapar()
{
}
