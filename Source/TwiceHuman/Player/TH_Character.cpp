#include "Player/TH_Character.h"

#include "Item/Gun/TH_GunBase.h"
#include "Item/Gun/TH_Rifle.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

ATH_Character::ATH_Character()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATH_Character::BeginPlay()
{
	Super::BeginPlay();
}

void ATH_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATH_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &ATH_Character::PullTrigger);
	}
}

void ATH_Character::Weapon(TSubclassOf<ATH_GunBase> WeaponClass, USkeletalMeshComponent* SkeletalMeshComponent)
{
	if (WeaponClass == nullptr) return;

	if (SkeletalMeshComponent == nullptr) return;

	if (SkeletalMeshComponent->DoesSocketExist(FName("hand_rSocket")))
	{
		UE_LOG(LogTemp, Warning, TEXT("소켓 있음"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("소켓 없음"));
	}

	FTransform SpawnTransform = SkeletalMeshComponent->GetSocketTransform(FName("hand_rSocket"));

	if (UWorld* World = GetWorld())
	{
		AActor* SpawnedActor = World->SpawnActor<AActor>(WeaponClass, SpawnTransform);
		CurrentWeapon = Cast<ATH_GunBase>(SpawnedActor);

		if (CurrentWeapon)
		{
			CurrentWeapon->SetOwner(this);
			CurrentWeapon->AttachToComponent(SkeletalMeshComponent,
											 FAttachmentTransformRules::SnapToTargetNotIncludingScale,
											 FName("hand_rSocket"));
		}
	}
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		CurrentWeapon->OwnerController = PC;
	}
}

void ATH_Character::PullTrigger()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Fire();
	}
	Rifle = Cast<ATH_Rifle>(UGameplayStatics::GetActorOfClass(GetWorld(), ATH_Rifle::StaticClass()));
	if (Rifle)
	{
		UE_LOG(LogTemp, Warning, TEXT("Rifle is %s"), Rifle ? TEXT("Valid") : TEXT("Null"));
		Rifle->RifleEffect();
	}
}
