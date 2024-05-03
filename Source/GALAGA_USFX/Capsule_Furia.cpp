// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsule_Furia.h"
#include "Kismet/GameplayStatics.h"
#include "GALAGA_USFXPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Components/BoxComponent.h"


ACapsule_Furia::ACapsule_Furia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaCa(TEXT("StaticMesh'/Game/Meshes/Energy.Energy'"));
	mallaCapsula->SetStaticMesh(mallaCa.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsule_Furia::OnHit);
    //OnActorBeginOverlap.AddDynamic(this, &ACapsule_Furia::OnBeginOverlap);
	


}

void ACapsule_Furia::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGALAGA_USFXPawn* Pawn = Cast<AGALAGA_USFXPawn>(OtherActor);
	    if (Pawn)
	    {
	        Pawn->AumentarVelocidad();
			FString Message = FString::Printf(TEXT("Energia Consumida %d "));
	        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, Message);
	
	        Destroy();//Destruir la capsula
	    }
}


