#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TH_GunBase.generated.h"

UCLASS()
class TWICEHUMAN_API ATH_GunBase : public AActor
{
	GENERATED_BODY()

public:
	ATH_GunBase();

	UPROPERTY()
	APlayerController* OwnerController = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun")
	float MaxRange = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bDrawDebug = true;
	
	UPROPERTY(EditAnywhere)
	float BulletDamage = 10.0f;	
	
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess), Category = "WeaponEffect")
	UParticleSystem* ImpactBulletEffect;

public:
	UFUNCTION()
	void Fire();
};
