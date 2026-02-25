#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TH_Dragon_AnimInstance.generated.h"

class ATH_Dragon;

UCLASS()
class TWICEHUMAN_API UTH_Dragon_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	UParticleSystem* FlameParticleTemplate;
	
	UPROPERTY(Transient)
	UParticleSystemComponent* FlameParticleComponent;
	
	FTimerHandle ProjectileTimer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TSubclassOf<AActor> ProjectileClass;
	
	UFUNCTION()
	void AnimNotify_StartFlame();
	
	UFUNCTION()
	void AnimNotify_EndFlame();
	
	UFUNCTION()
	void SpawnProjectile();
};
