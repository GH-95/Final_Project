#include "Item/Gun/TH_GunBase.h"

ATH_GunBase::ATH_GunBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = GunMesh;
}

void ATH_GunBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATH_GunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATH_GunBase::Fire()
{
	if (!OwnerController)
	{
		UE_LOG(LogTemp, Error, TEXT("No Controller"));
	}

	FVector ViewLoc;
	FRotator ViewRot;
	OwnerController->GetPlayerViewPoint(ViewLoc, ViewRot);

	const FVector Start = ViewLoc;
	const FVector End = Start + ViewRot.Vector() * MaxRange;

	FHitResult Hit;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	if (AActor* OwnerActor = GetOwner())
	{
		CollisionParams.AddIgnoredActor(OwnerActor);
	}

	const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CollisionParams);

	if (bDrawDebug)
	{
		const FColor Color = bHit ? FColor::Green : FColor::Red;
		DrawDebugLine(GetWorld(), Start, bHit ? Hit.ImpactPoint : End, Color, false, 5.0f, 0, 2.0f);
	}

	if (GEngine)
	{
		const FString Msg = bHit && Hit.GetActor()
								? FString::Printf(TEXT("Hit: %s"), *Hit.GetActor()->GetName())
								: TEXT("No Hit");
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Msg);
	}
}
