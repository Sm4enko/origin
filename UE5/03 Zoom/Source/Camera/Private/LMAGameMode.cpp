#include "LMAGameMode.h"
#include "Player/LMADefaultCharacter.h"
#include "Player/MyPlayerController.h"

ALMAGameMode::ALMAGameMode()
{
    DefaultPawnClass = ALMADefaultCharacter::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
}
