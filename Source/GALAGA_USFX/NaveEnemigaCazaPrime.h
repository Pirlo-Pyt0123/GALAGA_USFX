// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "Particles/ParticleSystemComponent.h"
#include "NaveEnemigaCazaPrime.generated.h"


UCLASS()
class GALAGA_USFX_API ANaveEnemigaCazaPrime : public ANaveEnemigaCaza
{
	GENERATED_BODY()

private:
	int cantidadBombas;
	int vueltas = 0;
	UPROPERTY(VisibleAnywhere)
	int banderaA = 3;
	UPROPERTY(VisibleAnywhere);
	FVector posicionPrime;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	class UParticleSystem* PowerParticle;

public:
	virtual void Tick(float DeltaTime) override;
	ANaveEnemigaCazaPrime();

	UFUNCTION()
	void FuncionDeManejoDeColision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);


	FORCEINLINE int GetCantidadBombas()const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
protected:
	virtual void Mover(float DeltaTime) override;
	virtual void Disparar(FVector FireDirection);
	virtual void Destruirse();
	virtual void Escapar();
};
