#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TH_MonsterBase.generated.h"

class UMonsterStatComponent;
class UTakenDamageComponent;

UCLASS()
class TWICEHUMAN_API ATH_MonsterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATH_MonsterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY()
	UTakenDamageComponent* DamageComponent;
	
	UPROPERTY()
	UMonsterStatComponent* MonsterStat;
	
};
