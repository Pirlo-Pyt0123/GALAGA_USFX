// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFXGameMode.h"
#include "GALAGA_USFXPawn.h"

#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "Kismet/GameplayStatics.h"
#include "NaveEnemigaCazaPrime.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaKamikaze.h"

#include "Capsule_Dios.h"
#include "Capsule_Furia.h"
#include "Capsule_Health.h"
#include "AF_Dios_Capsulas.h"

#include "EnemyShip_Goku.h"
#include "EnemyShip_Saitama.h"
#include "EnemyShip_VivaPeru.h"
#include "FABRICA_PIRLOinc.h"
#include "PB_GoGoEscuadron.h"
#include "PB_Diosito.h"




AGALAGA_USFXGameMode::AGALAGA_USFXGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
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
	//LlamenADios->ElevandoPlegarias("Squad_Caza");

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AGALAGA_USFXGameMode::GenerarCapsulas, 3.0f, true);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hola Mundo"));
    UWorld* const World = GetWorld();
    if (World != nullptr)
    { 
		/*AEnemyShip_Goku* Goku = World->SpawnActor<AEnemyShip_Goku>(ubicacionNave01, rotacionNave);
		AEnemyShip_Saitama* Saitama = World->SpawnActor<AEnemyShip_Saitama>(ubicacionNave02, rotacionNave);
		AEnemyShip_VivaPeru* VivaPeru = World->SpawnActor<AEnemyShip_VivaPeru>(ubicacionNave03, rotacionNave);*/


        FTimerHandle TimerHandle;
		//spawn de naves enemigas goku
        LlamenADios->ElevandoPlegarias("Squad_Espia");
        LlamenADios->GetActorLocation();
           
        
		/*if (World->GetTimerManager().IsTimerActive(TimerHandle))
        {
			World->GetTimerManager().ClearTimer(TimerHandle);
		}*/
        //World->GetTimerManager().SetTimer(TimerHandle, [this]() {
            
            LlamenADios->ElevandoPlegarias("Squad_Caza");
            LlamenADios->GetActorLocation();
        //}, 3.0f, false);
		
		//}
		//World->GetTimerManager().SetTimer(TimerHandle, [this]() {
			LlamenADios->ElevandoPlegarias("Squad_Hard");
			LlamenADios->GetActorLocation();
		//}, 6.0f, false);

			LlamenADios->ElevandoPlegarias("Squad_Obstacle");
			LlamenADios->GetActorLocation();

			
			// declarando la fabrica de capsula
		
			
        
				
    }
}

void AGALAGA_USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Generando Capsulas"));
}
void AGALAGA_USFXGameMode::GenerarCapsulas()
{
	FVector SpawnLocation = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);
	FVector SpawnLocation2 = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);
	FRotator SpawnRotation = FRotator(80.0f, 90.0f, .0f);
	// Genera cápsulas
	if (FMath::RandBool())
	{
		AAF_Dios_Capsulas::GenerarCapsulas("Energia", GetWorld(), SpawnLocation, SpawnRotation);
	}
	else
	{
		AAF_Dios_Capsulas::GenerarCapsulas("Vida", GetWorld(), SpawnLocation2, SpawnRotation);

	}
    
}