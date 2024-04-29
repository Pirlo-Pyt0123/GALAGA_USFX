// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PB_EscuadronBuild.h"
#include "PB_GoGoEscuadron.generated.h"
UCLASS()
class GALAGA_USFX_API APB_GoGoEscuadron : public AActor, public IPB_EscuadronBuild
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APB_GoGoEscuadron();

private:

	class APB_Squad* Squadron;




	virtual void buildSquadronCaza() override;
	virtual void buildSquadronEspia() override;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
