// Fill out your copyright notice in the Description page of Project Settings.


#include "PB_Diosito.h"
#include "PB_Squad.h"

// Sets default values
APB_Diosito::APB_Diosito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APB_Diosito::ElevandoPlegarias(FString _EscuadronCatolico)
{
	
	//Crea las escuadras
	if (_EscuadronCatolico == "Squad_Caza")
		SquadBuilder->buildSquadronCaza();

	if (_EscuadronCatolico == "Squad_Espia")
		SquadBuilder->buildSquadronEspia();

	
	
}

void APB_Diosito::setEscuadronDios(AActor* Builder)
{
	SquadBuilder = Cast<IPB_EscuadronBuild>(Builder);
	if (!SquadBuilder) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("¡Cast no válido! Consulte Registro de salida para obtener más detalles."));
		UE_LOG(LogTemp, Error, TEXT("setSquadBuilder():¡El actor no es un SquadBuilder! ¿Está seguro de que el actor implementa esa interfaz? "));
	}
}



