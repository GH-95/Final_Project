#include "TH_Rifle.h"
#include "NiagaraComponent.h"

ATH_Rifle::ATH_Rifle()
{
	RifleMuzzleComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RifleMuzzleComp"));
	RifleMuzzleComp->SetAutoActivate(false);
}

void ATH_Rifle::RifleEffect()
{
	RifleMuzzleComp->AttachToComponent(GunMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
	                                   TEXT("Muzzle"));
	if (GunMesh && GunMesh->DoesSocketExist(TEXT("Muzzle")))
	{
		FTransform MuzzleTransform = GunMesh->GetSocketTransform(TEXT("Muzzle"));
		RifleMuzzleComp->SetWorldTransform(MuzzleTransform);
	}
	RifleMuzzleComp->Activate();
}
