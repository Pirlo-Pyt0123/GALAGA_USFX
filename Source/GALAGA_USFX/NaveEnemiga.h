// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS()
class GALAGA_USFX_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()
	


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga;


protected:
	//nombre de la nave
	FString nombreNave;
	float stamina = 2;
	float speed;
	float damage;
	FString name;
	float shutTime;
	UPROPERTY(VisibleAnywhere)
	FVector posicion;
	//enum trayectoria
	int capacidadPasajeros;
	int capacidadMunicion;
	//int tipoNave;   /////// la nave ya se define al ser hija las mallas
	int experiencia;
	float energia;

	float peso;
	float volumen;

public:
	//Para leer valores
	FORCEINLINE float GetStamina() const { return stamina; }
	FORCEINLINE float GetSpeed() const { return speed; }
	FORCEINLINE float GetDamage() const { return damage; }
	FORCEINLINE FString GetName() const { return name; }
	FORCEINLINE float GetShutTime()const { return shutTime; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE int GetCapacidadPasajeros() const { return capacidadPasajeros; }
	FORCEINLINE int GetCapacidadMunicion() const { return capacidadMunicion; }
	//FORCEINLINE int GetTipoNave() const { return tipoNave; }
	FORCEINLINE int GetExperiencia() const { return experiencia; }
	FORCEINLINE float GetEnergia() const { return energia; }
	FORCEINLINE float GetPeso() const { return peso; }
	FORCEINLINE float GetVolumen() const { return volumen; }
	FORCEINLINE void ReducirStamina() { stamina -= 1; }

	//Para reescribir valores
	FORCEINLINE void SetStamina(float _stamina) { stamina = _stamina; }
	FORCEINLINE void SetSpeed(float _speed) { speed = _speed; }
	FORCEINLINE void SetDamage(float _damage) { damage = _damage; }
	FORCEINLINE void SetName(FString _name) { name = _name; }
	FORCEINLINE void SetShutTime(float _shutTime) { shutTime = _shutTime; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetCapacidadPasajeros(int _capacidadPasajeros) { capacidadPasajeros = _capacidadPasajeros; }
	FORCEINLINE void SetCapacidadMunicion(int _capacidadMunicion) { capacidadMunicion = _capacidadMunicion; }
	//FORCEINLINE void SetTipoNave(int _tipoNave) { tipoNave = _tipoNave; }
	FORCEINLINE void SetExperiencia(int _experiencia) { experiencia = _experiencia; }
	FORCEINLINE void SetEnergia(float _energia) { energia = _energia; }
	FORCEINLINE void SetPeso(float _peso) { peso = _peso; }
	FORCEINLINE void SetVolumen(float _volumen) { volumen = _volumen; }


public:	
	// Sets default values for this actor's properties
	ANaveEnemiga();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the ship collides with another actor
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	//virtual void Mover()=0;

	void Mover(float DeltaTime) PURE_VIRTUAL(ANaveEnemiga::Mover, );
	void Disparar() PURE_VIRTUAL(ANaveEnemiga::Disparar, );
	void Destruirse() PURE_VIRTUAL(ANaveEnemiga::Destruirse, );
	void Escapar() PURE_VIRTUAL(ANaveEnemiga::Escapar, );

};
