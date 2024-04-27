

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:

	ACppBaseActor();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
private:
	void ShowInFormation();
public:
	void ShowActorInformation();

};
