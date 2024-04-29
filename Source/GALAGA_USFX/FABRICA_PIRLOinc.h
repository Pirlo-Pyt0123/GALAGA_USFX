// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "FABRICA_PIRLOinc.generated.h"

UCLASS()
class GALAGA_USFX_API AFABRICA_PIRLOinc : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFABRICA_PIRLOinc();

	UFUNCTION(BlueprintCallable, Category = "FABRICA")
	static ANaveEnemiga* FabricarNave(FString NaveaFabricar, UWorld* World, FVector SpawnLocation, FRotator SpawnRotation);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	
	
};
