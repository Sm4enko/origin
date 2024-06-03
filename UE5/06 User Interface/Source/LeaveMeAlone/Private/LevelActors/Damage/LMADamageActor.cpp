// LeaveMeAlone Game by Netologiya. All Rights Reserved

#include "LevelActors/Damage/LMADamageActor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h" 
#include "Components/StaticMeshComponent.h" 

ALMADamageActor::ALMADamageActor()
{

    PrimaryActorTick.bCanEverTick = true;

    SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    SphereComponent->SetSphereRadius(SphereRadius);
    SetRootComponent(SphereComponent);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
    StaticMesh->SetupAttachment(SphereComponent);
    StaticMesh->SetRelativeScale3D(FVector(2.0f, 2.0f, 0.05f));
    StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -4.0f));
}

void ALMADamageActor::BeginPlay()
{
    Super::BeginPlay();

    UGameplayStatics::ApplyRadialDamage(
        GetWorld(),
        Damage,
        GetActorLocation(),
        SphereRadius,
        nullptr,
        {},
        this,
        nullptr,
        false
    );
}

void ALMADamageActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
