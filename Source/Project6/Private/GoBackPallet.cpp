#include "GoBackPallet.h"

AGoBackPallet::AGoBackPallet()
{
	// Scene Component�� �����ϰ� ��Ʈ�� ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component�� �����ϰ� Scene Component�� Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Tick �Լ� �ѱ�
	PrimaryActorTick.bCanEverTick = true;

	// �ȷ�Ʈ ���ǵ�� �ִ� ���� ����
	PalletSpeed = 150.0f;
	PalletMaxRange = 350.0f;

	// �ʱ� ���� ����: ó���� ������ �̵��ϵ��� ����
	bMovingGo = true;
}

void AGoBackPallet::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();  // BeginPlay���� ���� ��ġ ����
}

void AGoBackPallet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector NowLocation = GetActorLocation();  // FVector�� ���� ��ġ ���� ����
    float ElevatorDelta = PalletSpeed * DeltaTime;  // ���������ͼӵ��� DeltaTime�� ���Ͽ� ������ �������� ����.

    // ������ �̵� ��
    if (bMovingGo)
    {
        NowLocation.X += ElevatorDelta; // X ��ġ �� ���ϱ� -> ������ ������
        // �ִ� ���̸� �Ѱų� �����ϸ�
        if (NowLocation.X >= StartLocation.X + PalletMaxRange)
        {
            NowLocation.X = StartLocation.X + PalletMaxRange; // �� ��ġ�� ���߰�
            bMovingGo = false; // ���� �����Ӻ��ʹ� �ڷΰ�
        }
    }
    // �ڷ� �̵� ��
    else
    {
        NowLocation.X -= ElevatorDelta; // X ��ġ �� ���̱� -> �ڷ� ������
        // ���� ��ġ���� �ڷ� ����
        if (NowLocation.X <= StartLocation.X)
        {
            NowLocation.X = StartLocation.X; // ���� ��ġ�� ����
            bMovingGo = true; // ���� �����Ӻ��ʹ� �շ� �ö�
        }
    }

    SetActorLocation(NowLocation); // ���� ��ġ�� ���� �̵�
}