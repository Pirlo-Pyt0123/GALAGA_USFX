// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaKamikaze.h"


void ANaveEnemigaEspiaKamikaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaEspiaKamikaze::Mover(float DeltaTime)
{
	ANaveEnemigaEspia::Mover(DeltaTime);
	SetActorRotation(FRotator(0, 180, 0));
	speed = 3;
	SetActorLocation(FVector(GetActorLocation().X - speed, GetActorLocation().Y + speed * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y < -1000 || GetActorLocation().Y > -600) {
		bandera *= -1;
	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
}

void ANaveEnemigaEspiaKamikaze::Escapar()
{
}
