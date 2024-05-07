#include "CppBaseActor.h"
#include <cstdlib> 
#include <ctime>
#include <string>
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"


ACppBaseActor::ACppBaseActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Amplitude = FMath::RandRange(0.0f, 100.0f); 
	Frequency = FMath::RandRange(0.0f, 10.0f);

	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	RootComponent = MeshComponent;
}


void ACppBaseActor::SinMovement()
{
	float Time = GetWorld()->GetTimeSeconds();

	float VerticalOffset = Amplitude * FMath::Sin(Frequency * Time);

	FVector CurrentLocation = GetActorLocation();

	FVector NewLocation = FVector(CurrentLocation.X, CurrentLocation.Y, InitialLocation.Z + VerticalOffset);

	SetActorLocation(NewLocation);
}

void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ShowActorInformation();
	InitialLocation = GetActorLocation();
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SinMovement();
}


void ACppBaseActor::ShowInFormation()
{
	static int count = 0;
	FString InstanceName = "A_CppBase_C_";

    std::string temp = std::to_string(count);
	FString TempString(temp.c_str());
	InstanceName += TempString;
	++count;
	
	
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *InstanceName);
	int EnemyNum = 1 + rand() % 20;
	int turn = 1 + rand() % 4;
	bool IsAlive = true;
	if (turn == 1) {
		IsAlive = false;
	}
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive ? 1 : 0);
}

void ACppBaseActor::ShowActorInformation()
{
	ShowInFormation();
}

int Main() {
	srand(time(NULL));
return 0;
}