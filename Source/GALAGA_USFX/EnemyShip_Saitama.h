// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "EnemyShip_Saitama.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API AEnemyShip_Saitama : public ANaveEnemiga
{
	GENERATED_BODY()
	
public:
	AEnemyShip_Saitama();

protected:
	// Llamado cuando comienza el juego o cuando se genera
	virtual void BeginPlay() override;

public:
	// Llamado a cada cuadro (frame)
	virtual void Tick(float DeltaTime) override;
};