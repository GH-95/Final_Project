#include "Date/TakenDamageComponent.h"

UTakenDamageComponent::UTakenDamageComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTakenDamageComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTakenDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
