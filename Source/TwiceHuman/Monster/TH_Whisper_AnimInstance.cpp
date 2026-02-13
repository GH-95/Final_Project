#include "Monster/TH_Whisper_AnimInstance.h"

#include "Kismet/KismetSystemLibrary.h"

void UTH_Whisper_AnimInstance::AnimNotify_StartAttack()
{
	UKismetSystemLibrary::PrintString(this, TEXT("공격 시작 C++"), true, true, FLinearColor::Red, 60.0f);
	
	UE_LOG(LogTemp, Error, TEXT("공격 시작 C+++"));
}
