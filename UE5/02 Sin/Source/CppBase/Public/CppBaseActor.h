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
        UFUNCTION(BlueprintCallable)
        void SinMovement();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Movement")
    float Amplitude;

    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Movement")
    float Frequency;

    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    FVector InitialLocation;
private:
	void ShowInFormation();
public:
	void ShowActorInformation();

};
