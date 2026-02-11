#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TakenDamageComponent.generated.h"

class ATH_Character;
class ATH_MonsterBase;
class UMonsterStatComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TWICEHUMAN_API UTakenDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTakenDamageComponent();
	
	UPROPERTY()
	ATH_MonsterBase* MonsterBase;
	
	UPROPERTY()
	ATH_Character* Player;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	UPROPERTY()
	UMonsterStatComponent* MonsterStat;
	
	UFUNCTION()
	void TakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController*
					   InstigatedBy, AActor* DamageCauser);
};
