#include "Date/MonsterStatComponent.h"

UMonsterStatComponent::UMonsterStatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UMonsterStatComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHP = MaxHP;
}


void UMonsterStatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
