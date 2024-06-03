#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMABaseWeapon.generated.h"

UCLASS()
class LEAVEMEALONE_API ALMABaseWeapon : public AActor
{
    GENERATED_BODY()
    
public:
    ALMABaseWeapon();

    virtual void Tick(float DeltaTime) override;

    void Fire();
    void Reload();

protected:
    virtual void BeginPlay() override;
};
