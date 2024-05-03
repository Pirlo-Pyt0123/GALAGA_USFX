// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PB_MiembrosEscuadron.h"
#include "PB_Squad.generated.h"

UCLASS()
class GALAGA_USFX_API APB_Squad : public AActor, public IPB_MiembrosEscuadron
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APB_Squad();

public:
	virtual void setSquadronCaza() override;
	virtual void setSquadronEspia() override;
	virtual void setSquadronHard() override;
	virtual void setObstacleGenerator() override;
	
			


};
