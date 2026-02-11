#include "Date/TakenDamageComponent.h"
#include "Date/MonsterStatComponent.h"
#include "Monster/TH_MonsterBase.h"

UTakenDamageComponent::UTakenDamageComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTakenDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UTakenDamageComponent::TakenDamage);
	}

	MonsterStat = GetOwner()->FindComponentByClass<UMonsterStatComponent>();
	MonsterBase = Cast<ATH_MonsterBase>(GetOwner());
}


void UTakenDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTakenDamageComponent::TakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                        AController* InstigatedBy, AActor* DamageCauser)
{
	if (MonsterStat && MonsterBase && MonsterStat->CurrentHP > 0)
	{
		MonsterStat->CurrentHP -= Damage;
		UE_LOG(LogTemp, Error, TEXT("%f"), MonsterStat->CurrentHP);

		if (MonsterStat->CurrentHP <= 0)
		{
			MonsterStat->CurrentState = Dead;
			MonsterBase->Destroy();
			UE_LOG(LogTemp, Error, TEXT("State changed to Dead: %hhd"), MonsterStat->CurrentState);
		}
	}
}
