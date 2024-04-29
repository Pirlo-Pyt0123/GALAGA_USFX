// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PB_EscuadronBuild.h"
#include "PB_Diosito.generated.h"

UCLASS()
class GALAGA_USFX_API APB_Diosito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APB_Diosito();
	

private:

	IPB_EscuadronBuild* SquadBuilder;


public:
	void ElevandoPlegarias(FString _EscuadronCatolico);

	void setEscuadronDios(AActor* Builder);
};
