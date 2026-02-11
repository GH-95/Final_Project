#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MonsterStatComponent.generated.h"

UENUM()
enum EMonsterState : uint8
{
	Idle       UMETA(DisplayName = "Idle"),
	Attacking  UMETA(DisplayName = "Attacking"),
	Dead       UMETA(DisplayName = "Dead")
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TWICEHUMAN_API UMonsterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMonsterStatComponent();
	
	EMonsterState CurrentState;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	UPROPERTY(EditAnywhere)
	float MaxHP = 100.0f;
	
	UPROPERTY(EditAnywhere)
	float CurrentHP = 0.0f;
};
