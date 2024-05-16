#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "LMADefaultCharacter.generated.h"

UCLASS()
class CAMERA_API ALMADefaultCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ALMADefaultCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void ZoomCamera(float AxisValue);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float MinZoomDistance;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float MaxZoomDistance;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float ZoomSpeed;

private:
    float YRotation = -75.0f;
    float ArmLength = 1400.0f;
    float FOV = 55.0f;
};
