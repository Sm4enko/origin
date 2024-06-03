// LeaveMeAlone Game by Netologiya. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h" 
#include "Components/StaticMeshComponent.h" 
#include "LMADamageActor.generated.h"

UCLASS()
class LEAVEMEALONE_API ALMADamageActor : public AActor
{
    GENERATED_BODY()
    
public:    

    ALMADamageActor();

protected:

    virtual void BeginPlay() override;

public:    

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USphereComponent* SphereComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float Damage = 5.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float SphereRadius = 100.0f;
};
