// Fill out your copyright notice in the Description page of Project Settings.


#include "PB_Squad.h"
#include "NaveEnemigaCazaPrime.h"
#include "NaveEnemigaEspiaKamikaze.h"
#include "EnemyShip_Goku.h"
#include "EnemyShip_Saitama.h"
#include "EnemyShip_Saitama_T2.h"
#include "Obstaculo_Macizo.h"


// Sets default values
APB_Squad::APB_Squad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APB_Squad::setSquadronCaza()
{
	const FRotator Rotation = FRotator(0.f, 180.f, 0.f);
	float x = 1600;
	float y = -2580;
	//Localizacion de los enemigos
	const FVector Location1 = FVector(x, y, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location1, Rotation);

	const FVector Location2 = FVector(x, y+500, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location2, Rotation);

	const FVector Location3 = FVector(x, y+1000, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location3, Rotation);

	const FVector Location4 = FVector(x+1800, y+1350, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Goku>(Location4, Rotation);

	const FVector Location5 = FVector(x, y+1600, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Saitama_T2>(Location5, Rotation);

}

void APB_Squad::setSquadronEspia()
{
	const FRotator Rotation = FRotator(0.f, 180.f, 0.f);
	float x = 1800;
	float y = 800;
	//Localizacion de los enemigos
	const FVector Location1 = FVector(x, y, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location1, Rotation);

	const FVector Location2 = FVector(x, y+500, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location2, Rotation);

	const FVector Location3 = FVector(x, y+800, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location3, Rotation);

	const FVector Location4 = FVector(x, y+1100, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaCazaPrime>(Location4, Rotation);

	const FVector Location5 = FVector(x, y+1500, 214.f);
	GetWorld()->SpawnActor<ANaveEnemigaEspiaKamikaze>(Location5, Rotation);

}

void APB_Squad::setSquadronHard()
{
	const FRotator Rotation = FRotator(0.f, 180.f, 0.f);
	float x = 1800;
	float y = 800;
	//Localizacion de los enemigos
	const FVector Location1 = FVector(x, y, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Goku>(Location1, Rotation);

	const FVector Location2 = FVector(x, y + 500, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Saitama>(Location2, Rotation);

	const FVector Location3 = FVector(x, y + 800, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Saitama>(Location3, Rotation);

	const FVector Location4 = FVector(x, y + 1100, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Saitama>(Location4, Rotation);

	const FVector Location5 = FVector(x, y + 1500, 214.f);
	GetWorld()->SpawnActor<AEnemyShip_Saitama>(Location5, Rotation);
}

void APB_Squad::setObstacleGenerator()
{
	const FRotator Rotation = FRotator(0.f, 180.f, 0.f);
	float x = 1800;
	float y = 500;
	//Localizacion de los enemigos
	const FVector Location1 = FVector(x+540, y, 214.f);
	GetWorld()->SpawnActor<AObstaculo_Macizo>(Location1, Rotation);

	const FVector Location2 = FVector(x-1000, y + 500, 214.f);
	GetWorld()->SpawnActor<AObstaculo_Macizo>(Location2, Rotation);

	const FVector Location3 = FVector(x+1000, y + 800, 214.f);
	GetWorld()->SpawnActor<AObstaculo_Macizo>(Location3, Rotation);

	const FVector Location4 = FVector(x+800, y + 1100, 214.f);
	GetWorld()->SpawnActor<AObstaculo_Macizo>(Location4, Rotation);

	const FVector Location5 = FVector(x+650, y + 1500, 214.f);
	GetWorld()->SpawnActor<AObstaculo_Macizo>(Location5, Rotation);
}



