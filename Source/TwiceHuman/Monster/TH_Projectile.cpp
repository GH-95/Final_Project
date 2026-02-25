#include "Monster/TH_Projectile.h"

#include "TH_Dragon.h"
#include "Date/TH_ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/TH_Character.h"

ATH_Projectile::ATH_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	RootComponent = SphereMesh;
	ProjectileMovementComponent = CreateDefaultSubobject<UTH_ProjectileMovementComponent>(
		TEXT("ProjectileMovementComponent"));
}

void ATH_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
	Dragon = Cast<ATH_Dragon>(GetOwner());
}

void ATH_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	Player = Cast<ATH_Character>(OtherActor);
	
	if (Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Overlap with C++: %s"), *OtherActor->GetName());
		
		UGameplayStatics::ApplyDamage(Player, Dragon->FlameDamage, Dragon->GetController(), this, UDamageType::StaticClass());
	}
}
 
