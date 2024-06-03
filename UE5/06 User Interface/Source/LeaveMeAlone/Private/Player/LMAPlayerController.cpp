// LMAPlayerController.cpp

#include "Player/LMAPlayerController.h"
#include "GameFramework/InputSettings.h"

ALMAPlayerController::ALMAPlayerController()
{
}

void ALMAPlayerController::BeginPlay() {
    Super::BeginPlay();

    SetInputMode(FInputModeGameOnly());
    bShowMouseCursor = false;
}

void ALMAPlayerController::SimulateKeyPress1()
{
    const FKey KeyToPress = EKeys::One;

    InputKey(KeyToPress, EInputEvent::IE_Pressed, 1.0f, false);

    InputKey(KeyToPress, EInputEvent::IE_Released, 1.0f, false);
}
