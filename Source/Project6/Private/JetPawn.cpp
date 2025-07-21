#include "JetPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AJetPawn::AJetPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;
	CapsuleComponent->SetSimulatePhysics(false);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetSimulatePhysics(false);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 2000.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void AJetPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AJetPawn::Move(const FInputActionValue& Value)
{
	CurrentMoveInput = Value.Get<FVector2D>();
}

void AJetPawn::StopMove(const FInputActionValue& Value)
{
	CurrentMoveInput = FVector2D::ZeroVector;
}

void AJetPawn::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddActorLocalRotation(FRotator(0.0f, LookAxisVector.X * LookSpeed * GetWorld()->GetDeltaSeconds(), 0.0f));

	FRotator CurrentSpringArmRotation = SpringArm->GetRelativeRotation();

	float NewPitch = CurrentSpringArmRotation.Pitch - LookAxisVector.Y * LookSpeed * GetWorld()->GetDeltaSeconds();

	NewPitch = FMath::Clamp(NewPitch, -75.f, 0.f);

	SpringArm->SetRelativeRotation(FRotator(NewPitch, 0.f, 0.f));
}

void AJetPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector DeltaLocation(CurrentMoveInput.X, CurrentMoveInput.Y, 0.0f);

	DeltaLocation.Normalize();

	AddActorLocalOffset(DeltaLocation * MoveSpeed * DeltaTime);
}

void AJetPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(
			MoveAction,
			ETriggerEvent::Triggered,
			this,
			&AJetPawn::Move
		);
		EnhancedInputComponent->BindAction(
			MoveAction,
			ETriggerEvent::Completed,
			this,
			&AJetPawn::StopMove
		);
		EnhancedInputComponent->BindAction(
			LookAction,
			ETriggerEvent::Triggered, 
			this,
			&AJetPawn::Look
		);
	}
}

