// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

private:

	int avanceEspia;
public:

	ANaveEnemigaEspia();
	FORCEINLINE int GetRangoSondeo() const { return avanceEspia; }

	FORCEINLINE void SetRangoSondeo(int _avanceEspia) { avanceEspia = _avanceEspia; }
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void Mover(float DeltaTime);
	
	virtual void Escapar();
};
