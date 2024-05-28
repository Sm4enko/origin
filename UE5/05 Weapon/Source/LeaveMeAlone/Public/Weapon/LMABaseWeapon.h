#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimMontage.h"
#include "LMABaseWeapon.generated.h"

UCLASS()
class LEAVEMEALONE_API ALMABaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ALMABaseWeapon();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void Fire();
    void Reload();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    int32 AmmoCount = 30;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    class USkeletalMeshComponent* WeaponComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float MaxTraceDistance = 10000.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    UAnimMontage* ReloadMontage;
};
