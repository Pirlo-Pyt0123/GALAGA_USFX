// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFXGameMode.h"
#include "GALAGA_USFXPawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "Kismet/GameplayStatics.h"
#include "NaveEnemigaCazaPrime.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaKamikaze.h"
#include "FABRICA_PIRLOinc.h"
#include "PB_GoGoEscuadron.h"
#include "PB_Diosito.h"



AGALAGA_USFXGameMode::AGALAGA_USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFXPawn::StaticClass();

	
}



void AGALAGA_USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    float x = 1200;
    float y = -1000;
    FVector ubicacionNave01 = FVector(x, y, 250.0f);
    FVector ubicacionNave02 = FVector(x+400, y + 100, 250.0f);
	FVector ubicacionNave03 = FVector(x, y + 200, 250.0f);
    FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
   
    BattleSquadsReady = GetWorld()->SpawnActor<APB_GoGoEscuadron>(APB_GoGoEscuadron::StaticClass());
    // Creamos al jefe maestro enemigo
    LlamenADios = GetWorld()->SpawnActor<APB_Diosito>(APB_Diosito::StaticClass());
    // Mandamos al jefe enemigo las escuadras listas para llamar
    LlamenADios->setEscuadronDios(BattleSquadsReady);



    UWorld* const World = GetWorld();
    if (World != nullptr)
    {  
        
		
            LlamenADios->ElevandoPlegarias("Squad_Caza");
            LlamenADios->GetActorLocation();
		
		for (int i = 0; i < 5; i++) {
			LlamenADios->ElevandoPlegarias("Squad_Espia");
			LlamenADios->GetActorLocation();
		}
    }
}

void AGALAGA_USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    //naves Goku+su nave Dios
 //   SpawnSquatLevel1 += DeltaTime;
 //   if (SpawnSquatLevel1 >= 34.f && SpawnSquatLevel1 <= 36.f) {
 //       LlamenADios->ElevandoPlegarias("Squad_Caza");
 //       SpawnSquatLevel1 += 10;
 //       LlamenADios->GetActorLocation();
 //   }
	////naves Saitama+su nave Dios
	//
 //   SpawnSquatLevel2 += DeltaTime;
 //   if (SpawnSquatLevel2 >= 40.f && SpawnSquatLevel2 <= 42.f) {
 //       LlamenADios->ElevandoPlegarias("Squad_Espia");
 //       SpawnSquatLevel2 += 10;
 //       LlamenADios->GetActorLocation();
 //   }

	



	//SpawnNaveEnemiga();
	//SpawnNaveEnemigaCaza();
	
}