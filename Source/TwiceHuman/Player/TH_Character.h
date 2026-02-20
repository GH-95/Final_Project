#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TH_Character.generated.h"

class UTakenDamageComponent;
class ATH_Rifle;
class ATH_GunBase;
class UInputAction;

UCLASS()
class TWICEHUMAN_API ATH_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ATH_Character();

	UPROPERTY()
	ATH_GunBase* CurrentWeapon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* FireAction;
	
	UPROPERTY()
	ATH_Rifle* Rifle;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "State")
	float CurrentHP = 0.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "State")
	float MaxHP = 100.0f;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(blueprintCallable)
	void Weapon(TSubclassOf<ATH_GunBase> WeaponClass, USkeletalMeshComponent* SkeletalMeshComponent);
	
	UFUNCTION()
	void PullTrigger();
	
protected:
	UPROPERTY()
	UTakenDamageComponent* DamageComponent;
};
