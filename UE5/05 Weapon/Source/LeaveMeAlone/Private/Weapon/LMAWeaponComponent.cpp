#include "Weapon/LMAWeaponComponent.h"
#include "Weapon/LMABaseWeapon.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"

ULMAWeaponComponent::ULMAWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void ULMAWeaponComponent::BeginPlay()
{
    Super::BeginPlay();
    SpawnWeapon();
}

void ULMAWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULMAWeaponComponent::SpawnWeapon()
{
    Weapon = GetWorld()->SpawnActor<ALMABaseWeapon>(WeaponClass);
    if (Weapon)
    {
        const auto Character = Cast<ACharacter>(GetOwner());
        if (Character)
        {
            FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
            Weapon->AttachToComponent(Character->GetMesh(), AttachmentRules, "r_Weapon_Socket");
        }
    }
}

void ULMAWeaponComponent::Fire()
{
    if (Weapon)
    {
        Weapon->Fire();
    }
}

void ULMAWeaponComponent::Reload()
{
    if (Weapon)
    {
        Weapon->Reload();
    }
}
