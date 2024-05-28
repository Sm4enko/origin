#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LMAWeaponComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LEAVEMEALONE_API ULMAWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    ULMAWeaponComponent();

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<class ALMABaseWeapon> WeaponClass;

    void SpawnWeapon();
    void Fire();
    void Reload();

protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    ALMABaseWeapon* Weapon = nullptr;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
