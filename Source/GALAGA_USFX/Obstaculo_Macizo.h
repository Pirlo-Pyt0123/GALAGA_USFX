// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo_Macizo.generated.h"

UCLASS()
class GALAGA_USFX_API AObstaculo_Macizo : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaObstaculo;
private:
	//atributos
	FVector posicion;
	float tiempoSpaw;
	float danioImpacto;
	float LimiteLateralOX;

public:
	//metodos accesores
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE float GetTiempoSpaw() const { return tiempoSpaw; }
	FORCEINLINE float GetdanioImpacto() const { return danioImpacto; }

	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetTiempoSpaw(float _tiempoSpaw) { tiempoSpaw = _tiempoSpaw; }
	FORCEINLINE void SetdanioImpacto(float _danioImpacto) { danioImpacto = _danioImpacto; }

	//metodos de la clase


private:
	float VelocidadMovimiento;
	int speed;

public:	
	// Sets default values for this actor's properties
	AObstaculo_Macizo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int vueltas = 0;
	UPROPERTY(VisibleAnywhere)
	int banderaA = 3;
	UPROPERTY(VisibleAnywhere);
	FVector posicionPrime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void MoverObstaculo(float DeltaTime);

};
