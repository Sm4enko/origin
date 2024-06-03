#include "Weapon/LMABaseWeapon.h"


ALMABaseWeapon::ALMABaseWeapon()
{
    PrimaryActorTick.bCanEverTick = true;
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

}

void ALMABaseWeapon::Reload()
{

}
