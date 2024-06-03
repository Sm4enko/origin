#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Weapon/LMAWeaponComponent.h"
#include "Player/LMAHealthComponent.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ALMADefaultCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    ULMAWeaponComponent* WeaponComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    ULMAHealthComponent* HealthComponent;

    UPROPERTY()
    UDecalComponent* CurrentCursor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
    UMaterialInterface* CursorMaterial = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
    FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    int PlayerStamina;

    bool Stop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    bool ISSprintON;

    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


    virtual void NotifyHit(
        class UPrimitiveComponent* MyComp,
        AActor* Other,
        class UPrimitiveComponent* OtherComp,
        bool bSelfMoved,
        FVector HitLocation,
        FVector HitNormal,
        FVector NormalImpulse,
        const FHitResult& Hit
    ) override;

private:
    float YRotation = -75.0f;
    float ArmLength = 1400.0f;
    float FOV = 55.0f;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void StartFire();
    void StopFire();
    void StartReload();

    void ApplyRadialDamage(float DamageAmount, float Radius); 
};
