#include "Player/LMADefaultCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/DecalComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/DecalActor.h"
#include "Components/InputComponent.h"
#include "Weapon/LMAWeaponComponent.h"

ALMADefaultCharacter::ALMADefaultCharacter()
{
    WeaponComponent = CreateDefaultSubobject<ULMAWeaponComponent>("Weapon");
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    SpringArmComponent->SetUsingAbsoluteRotation(true);
    SpringArmComponent->TargetArmLength = ArmLength;
    SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f));
    SpringArmComponent->bDoCollisionTest = false;
    SpringArmComponent->bEnableCameraLag = true;
    CameraComponent->SetFieldOfView(FOV);
    CameraComponent->bUsePawnControlRotation = false;

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    PlayerStamina = 15;
    Stop = true;
}

void ALMADefaultCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (CursorMaterial)
    {
        CurrentCursor = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), CursorMaterial, CursorSize, FVector(0));
    }
}

void ALMADefaultCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC)
    {
        FHitResult ResultHit;
        PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, ResultHit);
        float FindRotatorResultYaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), ResultHit.Location).Yaw;
        SetActorRotation(FQuat(FRotator(0.0f, FindRotatorResultYaw, 0.0f)));
        if (CurrentCursor)
        {
            CurrentCursor->SetWorldLocation(ResultHit.Location);
        }
    }
}

void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &ALMADefaultCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ALMADefaultCharacter::MoveRight);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ALMADefaultCharacter::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, this, &ALMADefaultCharacter::StopFire);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ALMADefaultCharacter::StartReload);
}

void ALMADefaultCharacter::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector(), Value);
}

void ALMADefaultCharacter::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector(), Value);
}

void ALMADefaultCharacter::StartFire()
{
    if (WeaponComponent)
    {
        WeaponComponent->Fire();
    }
}

void ALMADefaultCharacter::StopFire()
{
    // Если потребуется функциональность для остановки стрельбы, можно добавить здесь.
}

void ALMADefaultCharacter::StartReload()
{
    if (WeaponComponent)
    {
        WeaponComponent->Reload();
    }
}
