// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PB_EscuadronBuild.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPB_EscuadronBuild : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_API IPB_EscuadronBuild
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void buildSquadronCaza() = 0;
	virtual void buildSquadronEspia() = 0;
	
};
