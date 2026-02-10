#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TH_MonsterBase.generated.h"

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
	
private:
	UPROPERTY()
	float MaxHP = 100.0f;
	UPROPERTY()
	float CurrentHP = 0.0f;
	
	UPROPERTY()
	bool bIsAlive = true;
	
	UFUNCTION()
	void TakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController*
					   InstigatedBy, AActor* DamageCauser);
};
