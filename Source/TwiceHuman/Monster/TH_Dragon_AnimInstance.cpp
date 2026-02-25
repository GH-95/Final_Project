#include "Monster/TH_Dragon_AnimInstance.h"

#include "TH_Dragon.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystemComponent.h"

void UTH_Dragon_AnimInstance::AnimNotify_StartFlame()
{
	UKismetSystemLibrary::PrintString(this, TEXT("공격 시작 C++"), true, true, FLinearColor::Red, 60.0f);

	APawn* PawnOwner = TryGetPawnOwner();
	if (!PawnOwner) return;

	ATH_Dragon* Dragon = Cast<ATH_Dragon>(PawnOwner);
	if (!Dragon) return;

	if (!FlameParticleComponent)
	{
		FlameParticleComponent = UGameplayStatics::SpawnEmitterAttached(
			FlameParticleTemplate,
			Dragon->GetMesh(),
			TEXT("FlameSocket"),
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			EAttachLocation::SnapToTarget,
			true);
	}

	if (ProjectileClass)
	{
		GetWorld()->GetTimerManager().SetTimer(ProjectileTimer, this, &UTH_Dragon_AnimInstance::SpawnProjectile, 0.1f,
		                                       true, 0.0f);
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

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ProjectileTimer);
	}
}

void UTH_Dragon_AnimInstance::SpawnProjectile()
{
	APawn* PawnOwner = TryGetPawnOwner();
	if (!PawnOwner) return;

	ATH_Dragon* Dragon = Cast<ATH_Dragon>(PawnOwner);
	if (!Dragon) return;

	if (!ProjectileClass) return;

	FName DamageSocket = TEXT("DamageSocket");

	FVector SocketLocation = Dragon->GetMesh()->GetSocketLocation(DamageSocket);
	FRotator SocketRotation = Dragon->GetMesh()->GetSocketRotation(DamageSocket);

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Dragon;
	SpawnParams.Instigator = Dragon->GetInstigator();

	if (AActor* Projectile = GetWorld()->SpawnActor<AActor>(ProjectileClass, SocketLocation, SocketRotation, SpawnParams))
	{
		Projectile->SetLifeSpan(0.5f);
	}
}
