#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TH_Character.generated.h"

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

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(blueprintCallable)
	void Weapon(TSubclassOf<ATH_GunBase> WeaponClass, USkeletalMeshComponent* SkeletalMeshComponent);
	
	UFUNCTION()
	void PullTrigger();
};
