#include "Player/LMAHealthComponent.h"
#include "Player/LMAPlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

ULMAHealthComponent::ULMAHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = true;


    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
    TotalDamageTaken = 0.0f;   
}

void ULMAHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    AActor* OwnerComponent = GetOwner();
    if (OwnerComponent)
    {
        OwnerComponent->OnTakeAnyDamage.AddDynamic(this, &ULMAHealthComponent::OnTakeAnyDamage);
    }
}

void ULMAHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULMAHealthComponent::HandleTakeDamage(float DamageAmount)
{
    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, MinHealth, MaxHealth);
    TotalDamageTaken += DamageAmount;
    OnHealthChanged.Broadcast();

    if (CurrentHealth <= MinHealth)
    {
        AController* Controller = GetOwner()->GetInstigatorController();
        if (Controller)
        {
            ALMAPlayerController* LMAPlayerController = Cast<ALMAPlayerController>(Controller);
            if (LMAPlayerController)
            {
                LMAPlayerController->SimulateKeyPress1();
            }
        }
    }
}

void ULMAHealthComponent::TakeDamage(float DamageAmount)
{
    HandleTakeDamage(DamageAmount);
}

void ULMAHealthComponent::Heal(float HealAmount)
{
    CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, MinHealth, MaxHealth);
    OnHealthChanged.Broadcast();
}

float ULMAHealthComponent::GetHealth() const
{
    return CurrentHealth;
}

float ULMAHealthComponent::GetMaxHealth() const
{
    return MaxHealth;
}

bool ULMAHealthComponent::IsAlive() const
{
    return CurrentHealth > MinHealth;
}

float ULMAHealthComponent::GetHealthBarPercent() const
{
    return CurrentHealth / MaxHealth;
}

float ULMAHealthComponent::GetTotalDamageTaken() const
{
    return TotalDamageTaken;
}

void ULMAHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    HandleTakeDamage(Damage);
}
