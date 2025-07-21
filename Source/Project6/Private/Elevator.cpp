#include "Elevator.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h" 
#include "Materials/Material.h"

AElevator::AElevator()
{
	// Scene Component를 생성하고 루트로 설정
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Tick 함수 켜기
	PrimaryActorTick.bCanEverTick = true;

    // 엘리베이터 스피드와 최대 높이 설정
	ElevatorSpeed = 90.0f;
	ElevatorMaxHigh = 250.0f;

	// 초기 방향 설정: 처음엔 위로 올라가도록 설정
	bMovingUp = true;
}

void AElevator::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();  // BeginPlay에서 시작 위치 저장
}

void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NowLocation = GetActorLocation();  // FVector로 현재 위치 값을 저장
	float ElevatorDelta = ElevatorSpeed * DeltaTime;  // 엘리베이터속도와 DeltaTime를 곱하여 일정한 움직임을 보장.

    // 위로 이동 중
    if (bMovingUp)
    {
        NowLocation.Z += ElevatorDelta; // Z 위치 값 더하기 -> 위로 움직임
        // 최대 높이를 넘거나 도달하면
        if (NowLocation.Z >= StartLocation.Z + ElevatorMaxHigh)
        {
            NowLocation.Z = StartLocation.Z + ElevatorMaxHigh; // 그 위치에 멈추고
            bMovingUp = false; // 다음 프레임부터는 내려감
        }
    }
    // 아래로 이동 중
    else
    {
        NowLocation.Z -= ElevatorDelta; // Z 위치 값 줄이기 -> 아래로 움직임
        // 시작 위치보다 낮아지면
        if (NowLocation.Z <= StartLocation.Z)
        {
            NowLocation.Z = StartLocation.Z; // 원래 위치로 고정
            bMovingUp = true; // 다음 프레임부터는 위로 올라감
        }
    }

    SetActorLocation(NowLocation); // 계산된 위치로 액터 이동
}