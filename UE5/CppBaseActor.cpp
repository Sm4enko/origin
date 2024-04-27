#include "CppBaseActor.h"
#include <cstdlib> 
#include <ctime>
#include <string>


ACppBaseActor::ACppBaseActor()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ShowActorInformation();
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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