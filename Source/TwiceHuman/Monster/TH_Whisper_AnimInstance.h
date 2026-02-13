#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TH_Whisper_AnimInstance.generated.h"

UCLASS()
class TWICEHUMAN_API UTH_Whisper_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_StartAttack();
};
