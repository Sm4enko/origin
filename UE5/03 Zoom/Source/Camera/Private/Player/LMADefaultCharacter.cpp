#include "Player/LMADefaultCharacter.h"
#include "GameFramework/SpringArmComponent.h"

ALMADefaultCharacter::ALMADefaultCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
    CameraComponent->bUsePawnControlRotation = false;
    CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));

    SpringArmComponent->TargetArmLength = ArmLength;
    SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f));
    SpringArmComponent->bDoCollisionTest = false;
    SpringArmComponent->bEnableCameraLag = true;
    CameraComponent->SetFieldOfView(FOV);

    MinZoomDistance = 100.0f;
    MaxZoomDistance = 1000.0f;
    ZoomSpeed = 100.0f;
}

void ALMADefaultCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ALMADefaultCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Zoom", this, &ALMADefaultCharacter::ZoomCamera);
}

void ALMADefaultCharacter::ZoomCamera(float AxisValue)
{
    float NewArmLength = FMath::Clamp(SpringArmComponent->TargetArmLength - AxisValue * ZoomSpeed, MinZoomDistance, MaxZoomDistance);
    SpringArmComponent->TargetArmLength = NewArmLength;
}
