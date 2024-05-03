// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GALAGA_USFXGameMode.generated.h"


class ANaveEnemiga;
class ANaveEnemigaCaza;
class ANaveEnemigaCazaPrime;
class ANaveEnemigaEspiaKamikaze;
class ACapsule_Furia;
class ACapsule_Health;
UCLASS(MinimalAPI)
class AGALAGA_USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGALAGA_USFXGameMode();


	class ABuilderReparacion* ReparacionPorta;
	class AB_DirectorSupremo* IngenieroPortaNave;
private:
	// Instancia de la fábrica de enemigos

public:
	//TArray <ANaveEnemigaKamikaze*> NavesEnemigasEspia;
	ANaveEnemigaCazaPrime* NaveEnemigaCazaPrime01;
	ANaveEnemigaEspiaKamikaze* NaveEnemigaEspiaKamikaze01;

	TArray <ANaveEnemiga*> TANavesEnemigas;


private:
	// Propiedades para la creación de escuadrones goku
	float SpawnSquatLevel1;

	// Propiedades para la creación de escuadrones saitama
	float SpawnSquatLevel2;

	// Propiedades para la creación de escuadrones vivaPeru
	float SpawnSquatLevel3;

private:
	// propiedades para la creacion de capsulas
	/*float inicioCapsulas;
	float TopeCapsulas;*/







	// declarando propiedades para el uso de la creacion de escuadrones
	class APB_GoGoEscuadron* BattleSquadsReady;	// escuadrones listos
	class APB_Diosito* LlamenADios;		// enemigo jefe maestro


	virtual void Tick(float DeltaTime) override;



public:

	void GenerarCapsulas();
	FTimerHandle SpawnTimerHandle;

protected:
	virtual void BeginPlay() override;
};



