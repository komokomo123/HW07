#include "GoBackPallet.h"

AGoBackPallet::AGoBackPallet()
{
	// Scene Component를 생성하고 루트로 설정
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Tick 함수 켜기
	PrimaryActorTick.bCanEverTick = true;

	// 팔레트 스피드와 최대 높이 설정
	PalletSpeed = 150.0f;
	PalletMaxRange = 350.0f;

	// 초기 방향 설정: 처음엔 앞으로 이동하도록 설정
	bMovingGo = true;
}

void AGoBackPallet::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();  // BeginPlay에서 시작 위치 저장
}

void AGoBackPallet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector NowLocation = GetActorLocation();  // FVector로 현재 위치 값을 저장
    float ElevatorDelta = PalletSpeed * DeltaTime;  // 엘리베이터속도와 DeltaTime를 곱하여 일정한 움직임을 보장.

    // 앞으로 이동 중
    if (bMovingGo)
    {
        NowLocation.X += ElevatorDelta; // X 위치 값 더하기 -> 앞으로 움직임
        // 최대 길이를 넘거나 도달하면
        if (NowLocation.X >= StartLocation.X + PalletMaxRange)
        {
            NowLocation.X = StartLocation.X + PalletMaxRange; // 그 위치에 멈추고
            bMovingGo = false; // 다음 프레임부터는 뒤로감
        }
    }
    // 뒤로 이동 중
    else
    {
        NowLocation.X -= ElevatorDelta; // X 위치 값 줄이기 -> 뒤로 움직임
        // 시작 위치보다 뒤로 가면
        if (NowLocation.X <= StartLocation.X)
        {
            NowLocation.X = StartLocation.X; // 원래 위치로 고정
            bMovingGo = true; // 다음 프레임부터는 앞로 올라감
        }
    }

    SetActorLocation(NowLocation); // 계산된 위치로 액터 이동
}