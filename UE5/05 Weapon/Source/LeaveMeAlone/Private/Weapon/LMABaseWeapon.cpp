#include "Weapon/LMABaseWeapon.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"

ALMABaseWeapon::ALMABaseWeapon()
{
    PrimaryActorTick.bCanEverTick = true;
    WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
    SetRootComponent(WeaponComponent);
}

void ALMABaseWeapon::BeginPlay()
{
    Super::BeginPlay();
}

void ALMABaseWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ALMABaseWeapon::Fire()
{
    if (AmmoCount <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Out of ammo!"));
        return;
    }

    AmmoCount--;

    FVector Start = WeaponComponent->GetSocketLocation("MuzzleFlashSocket");
    FRotator Rotation(0.0f, 130.0f, 0.0f);
    FVector ForwardVector = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
    FVector End = Start + WeaponComponent->GetSocketRotation("MuzzleFlashSocket").RotateVector(ForwardVector) * MaxTraceDistance;

    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(this);
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);

    if (bHit)
    {
        DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Red, false, 1.0f, 0, 1.0f);
    }
    else
    {
        DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 1.0f);
    }
}

void ALMABaseWeapon::Reload()
{
    if (ReloadMontage && WeaponComponent && WeaponComponent->GetAnimInstance())
    {
        UAnimInstance* AnimInstance = WeaponComponent->GetAnimInstance();
        if (!AnimInstance->Montage_IsPlaying(ReloadMontage))
        {
            AnimInstance->Montage_Play(ReloadMontage);
            AmmoCount = 30;
        }
    }
}
