#include "Monster/TH_Dragon_AnimInstance.h"

#include "TH_Dragon.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystemComponent.h"

void UTH_Dragon_AnimInstance::AnimNotify_StartFlame()
{
	UKismetSystemLibrary::PrintString(this, TEXT("공격 시작 C++"), true, true, FLinearColor::Red, 60.0f);

	if (!FlameParticleTemplate)
	{
		UE_LOG(LogTemp, Warning, TEXT("FlameParticleTemplate이 설정되지 않았습니다."));
		return;
	}

	APawn* PawnOwner = TryGetPawnOwner();
	if (!PawnOwner) return;

	ATH_Dragon* Dragon = Cast<ATH_Dragon>(PawnOwner);
	if (!Dragon) return;

	if (!FlameParticleComponent)
	{
		FlameParticleComponent = UGameplayStatics::SpawnEmitterAttached(
			FlameParticleTemplate,
			Dragon->GetMesh(),
			TEXT("FlameSocket"),         // 소켓 이름을 정확히 맞춰주세요
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			EAttachLocation::SnapToTarget,
			true);
	}
}

void UTH_Dragon_AnimInstance::AnimNotify_EndFlame()
{
	UKismetSystemLibrary::PrintString(this, TEXT("공격 끝 C++"), true, true, FLinearColor::Red, 60.0f);
	
	if (FlameParticleComponent)
	{
		FlameParticleComponent->DeactivateSystem();
		FlameParticleComponent = nullptr;
	}
}
