#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TakenDamageComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TWICEHUMAN_API UTakenDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTakenDamageComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
