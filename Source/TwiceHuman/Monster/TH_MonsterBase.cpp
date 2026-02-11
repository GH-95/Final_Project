#include "Monster/TH_MonsterBase.h"

#include "Date/MonsterStatComponent.h"
#include "Date/TakenDamageComponent.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"

ATH_MonsterBase::ATH_MonsterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	MonsterStat = CreateDefaultSubobject<UMonsterStatComponent>(TEXT("MonsterStat"));
	DamageComponent = CreateDefaultSubobject<UTakenDamageComponent>(TEXT("DamageComponent"));
}

void ATH_MonsterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATH_MonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATH_MonsterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
