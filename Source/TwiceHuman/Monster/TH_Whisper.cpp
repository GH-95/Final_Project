#include "Monster/TH_Whisper.h"

#include "Kismet/KismetSystemLibrary.h"

void ATH_Whisper::PunchAttack()
{
	UKismetSystemLibrary::PrintString(this, TEXT("몬스터 밀리 어택 시작!"), true, true, FLinearColor::Blue, 60.0f);

	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * MaxRange;

	FHitResult Hit;

	UKismetSystemLibrary::SphereTraceSingle(this, Start, End, AttackRadius,
	                                        UEngineTypes::ConvertToTraceType(ECC_Visibility), false, {this},
	                                        bIsDrawDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hit,
	                                        true, FLinearColor::Red, FLinearColor::Green, 3.0f);

	// if (Hit.bBlockingHit)
	// {
	// 	
	// }
}
