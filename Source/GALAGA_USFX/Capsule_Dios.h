// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Capsule_Dios.generated.h"
UCLASS()
class GALAGA_USFX_API ACapsule_Dios : public AActor
{
	GENERATED_BODY()
	
public:	
	//creando la malla para capsula--->>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaCapsula;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystem* DestructionParticle;
	



	// Sets default values for this actor's properties
	ACapsule_Dios();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
