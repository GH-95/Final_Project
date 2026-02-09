#include "TH_Rifle.h"
#include "NiagaraComponent.h"

ATH_Rifle::ATH_Rifle()
{
	RifleMuzzleComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RifleMuzzleComp"));
	RifleMuzzleComp->AttachToComponent(GunMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
	                                   TEXT("Muzzle"));
	RifleMuzzleComp->SetAutoActivate(false);
	
	bool bAttached = RifleMuzzleComp->AttachToComponent(GunMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("Muzzle"));
	UE_LOG(LogTemp, Warning, TEXT("AttachTo Muzzle socket success: %s"), bAttached ? TEXT("true") : TEXT("false"));
}

void ATH_Rifle::RifleEffect()
{
	if (GunMesh && GunMesh->DoesSocketExist(TEXT("Muzzle")))
	{
		FTransform MuzzleTransform = GunMesh->GetSocketTransform(TEXT("Muzzle"));
		RifleMuzzleComp->SetWorldTransform(MuzzleTransform);
	}
	RifleMuzzleComp->Activate();
}
