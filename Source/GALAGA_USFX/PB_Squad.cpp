// Fill out your copyright notice in the Description page of Project Settings.


#include "PB_Squad.h"
#include "NaveEnemigaCazaPrime.h"
#include "NaveEnemigaEspiaKamikaze.h"


// Sets default values
APB_Squad::APB_Squad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APB_Squad::setSquadronCaza()
{
	const FRotator Rotation = FRotator(0.f, 180.f, 0.f);
	float x = 1200;
	float y = -1000;
	//Localizacion de los enemigos
	const FVector Location1 = FVector(x, y, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location1, Rotation);

	const FVector Location2 = FVector(x, y+300, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location2, Rotation);

	const FVector Location3 = FVector(x, y+500, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location3, Rotation);

	const FVector Location4 = FVector(x, y+100, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location4, Rotation);

	const FVector Location5 = FVector(x, y-500, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location5, Rotation);

}

void APB_Squad::setSquadronEspia()
{
	const FRotator Rotation = FRotator(0.f, 180.f, 0.f);

	//Localizacion de los enemigos
	const FVector Location1 = FVector(750.f, -250.f, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location1, Rotation);

	const FVector Location2 = FVector(750.f, -180.f, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location2, Rotation);

	const FVector Location3 = FVector(750.f, -110.f, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location3, Rotation);

	const FVector Location4 = FVector(750.f, -40.f, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location4, Rotation);

	const FVector Location5 = FVector(750.f, 30.f, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location5, Rotation);

}



