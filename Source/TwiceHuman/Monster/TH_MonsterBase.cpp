#include "Monster/TH_MonsterBase.h"

ATH_MonsterBase::ATH_MonsterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATH_MonsterBase::BeginPlay()
{
	Super::BeginPlay();
	
	OnTakeAnyDamage.AddDynamic(this, &ATH_MonsterBase::TakenDamage);
	CurrentHP = MaxHP;
}

void ATH_MonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATH_MonsterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATH_MonsterBase::TakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHP -= Damage;
	if (CurrentHP <= 0)
	{
		Destroy();
	}
}

