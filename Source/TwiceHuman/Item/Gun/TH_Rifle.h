#pragma once

#include "CoreMinimal.h"
#include "Item/Gun/TH_GunBase.h"
#include "TH_Rifle.generated.h"

class UNiagaraComponent;

UCLASS()
class TWICEHUMAN_API ATH_Rifle : public ATH_GunBase
{
	GENERATED_BODY()

public:
	ATH_Rifle();
	
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess))
	UNiagaraComponent* RifleMuzzleComp;
	
public:
	UFUNCTION()
	void RifleEffect();
};
