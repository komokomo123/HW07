// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingSign.h"

ARotatingSign::ARotatingSign()
{
	// Scene Component�� �����ϰ� ��Ʈ�� ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component�� �����ϰ� Scene Component�� Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Tick �Լ� �ѱ�
	PrimaryActorTick.bCanEverTick = true;

	// �⺻ ȸ�� �ӵ� (1�ʿ� 90.0f)
	RotationSpeed = 90.0f;
}

void ARotatingSign::BeginPlay()
{
	Super::BeginPlay();

}

void ARotatingSign::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// RotationSpeed�� 0�� �ƴ϶�� ȸ�� ó��
	// IsNearlyZero : �ε� �Ҽ��� �񱳿��� �����ϰ� 0�� ������� Ȯ�����ִ� �Լ�
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		// �ʴ� RotationSpeed�� 0�� �ƴ϶�� ȸ�� ó��
		// �𸮾����� ��ġ, ��, �� ������ ǥ���ϱ� ������ ��ȣ �� ������ X, Z, Y �����̴�.
		// AddActorLocalRotation : �ʴ� RotationSpeed��ŭ, �� �����Ӵ� (RotationSpeed * DeltaTime)��ŭ ȸ��
		AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, 0.0f, 0.0f));
	}

}