#pragma once

#include "CoreMinimal.h"
#include "Monster/TH_MonsterBase.h"
#include "TH_Whisper.generated.h"

class AController;

UCLASS()
class TWICEHUMAN_API ATH_Whisper : public ATH_MonsterBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	AController* AIController;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PunchAttack")
	float PunchDamage = 10.0f;

private:
	UPROPERTY(EditAnywhere)
	float MaxRange = 100.0f;
	
	UPROPERTY(EditAnywhere)
	bool bIsDrawDebug = true;
	
	UPROPERTY(EditAnywhere)
	float AttackRadius = 25.0f;
	
public:
	UFUNCTION()
	void PunchAttack();
};
