#include "Elevator.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h" 
#include "Materials/Material.h"

AElevator::AElevator()
{
	// Scene Component�� �����ϰ� ��Ʈ�� ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component�� �����ϰ� Scene Component�� Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Tick �Լ� �ѱ�
	PrimaryActorTick.bCanEverTick = true;

    // ���������� ���ǵ�� �ִ� ���� ����
	ElevatorSpeed = 90.0f;
	ElevatorMaxHigh = 250.0f;

	// �ʱ� ���� ����: ó���� ���� �ö󰡵��� ����
	bMovingUp = true;
}

void AElevator::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();  // BeginPlay���� ���� ��ġ ����
}

void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NowLocation = GetActorLocation();  // FVector�� ���� ��ġ ���� ����
	float ElevatorDelta = ElevatorSpeed * DeltaTime;  // ���������ͼӵ��� DeltaTime�� ���Ͽ� ������ �������� ����.

    // ���� �̵� ��
    if (bMovingUp)
    {
        NowLocation.Z += ElevatorDelta; // Z ��ġ �� ���ϱ� -> ���� ������
        // �ִ� ���̸� �Ѱų� �����ϸ�
        if (NowLocation.Z >= StartLocation.Z + ElevatorMaxHigh)
        {
            NowLocation.Z = StartLocation.Z + ElevatorMaxHigh; // �� ��ġ�� ���߰�
            bMovingUp = false; // ���� �����Ӻ��ʹ� ������
        }
    }
    // �Ʒ��� �̵� ��
    else
    {
        NowLocation.Z -= ElevatorDelta; // Z ��ġ �� ���̱� -> �Ʒ��� ������
        // ���� ��ġ���� ��������
        if (NowLocation.Z <= StartLocation.Z)
        {
            NowLocation.Z = StartLocation.Z; // ���� ��ġ�� ����
            bMovingUp = true; // ���� �����Ӻ��ʹ� ���� �ö�
        }
    }

    SetActorLocation(NowLocation); // ���� ��ġ�� ���� �̵�
}