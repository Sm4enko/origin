// LMAPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LMAPlayerController.generated.h"

UCLASS()
class LEAVEMEALONE_API ALMAPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    ALMAPlayerController();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SimulateKeyPress1();
};
