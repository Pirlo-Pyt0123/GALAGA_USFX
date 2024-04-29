// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
protected:
	int tipoArma;
	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	ANaveEnemigaCaza();
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;
	FORCEINLINE int GetTipoArma()const { return tipoArma; }
	FORCEINLINE void SetTipoArma(int _tipoArma) { tipoArma = _tipoArma; }

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar(FVector FireDirection);
	virtual void Destruirse();
	virtual void Escapar();
	//complemento del disparo
	void ShotTimerExpired();
};
