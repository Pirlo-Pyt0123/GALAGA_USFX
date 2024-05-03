// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsule_Dios.h"
#include "Capsule_Furia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ACapsule_Furia : public ACapsule_Dios
{
	GENERATED_BODY()
	
public:
	ACapsule_Furia();


	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	//UFUNCTION()
	//void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;

};
