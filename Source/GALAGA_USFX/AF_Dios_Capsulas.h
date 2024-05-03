// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsule_Dios.h"
#include "AF_Dios_Capsulas.generated.h"
UCLASS()
class GALAGA_USFX_API AAF_Dios_Capsulas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAF_Dios_Capsulas();
	//como static para poder llamarlo desde cualquier parte del codigo
	UFUNCTION(BlueprintCallable, Category = "FabricaCapsulas")
	static ACapsule_Dios* GenerarCapsulas(FString tipoCapsula, UWorld* World, FVector SpawnLocation, FRotator ZeroRotator);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle SpawnTimerHandle;

};
