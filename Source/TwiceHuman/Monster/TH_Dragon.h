#pragma once

#include "CoreMinimal.h"
#include "Monster/TH_MonsterBase.h"
#include "TH_Dragon.generated.h"

class ATH_Projectile;
class AAIController;

UCLASS()
class TWICEHUMAN_API ATH_Dragon : public ATH_MonsterBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float FlameDamage = 10.0f;
};
