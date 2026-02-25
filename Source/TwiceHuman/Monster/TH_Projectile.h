#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TH_Projectile.generated.h"

class ATH_Dragon;
class ATH_Character;
class UTH_ProjectileMovementComponent;

UCLASS()
class TWICEHUMAN_API ATH_Projectile : public AActor
{
	GENERATED_BODY()

public:
	ATH_Projectile();
	
	UPROPERTY()
	ATH_Character* Player;
	
	UPROPERTY()
	ATH_Dragon* Dragon;

protected:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	UTH_ProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sphere")
	UStaticMeshComponent* SphereMesh;
};
