// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsule_Dios.h"
//#include "Particles/ParticleSystemComponent.h"
#include "Capsule_Health.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ACapsule_Health : public ACapsule_Dios
{
	GENERATED_BODY()
public:
	ACapsule_Health();

	/*UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mallaCapsula;*/
	UPROPERTY(EditAnywhere)
	USoundBase* SonidoCapsulaC;



	FString tipoCapsula = "Vida";
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
