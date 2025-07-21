// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingSign.h"

ARotatingSign::ARotatingSign()
{
	// Scene Component를 생성하고 루트로 설정
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Tick 함수 켜기
	PrimaryActorTick.bCanEverTick = true;

	// 기본 회전 속도 (1초에 90.0f)
	RotationSpeed = 90.0f;
}

void ARotatingSign::BeginPlay()
{
	Super::BeginPlay();

}

void ARotatingSign::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// RotationSpeed가 0이 아니라면 회전 처리
	// IsNearlyZero : 부동 소수점 비교에서 안전하게 0에 가까운지 확인해주는 함수
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		// 초당 RotationSpeed가 0이 아니라면 회전 처리
		// 언리얼엔진은 피치, 요, 롤 순으로 표현하기 때문에 괄호 내 순서는 X, Z, Y 기준이다.
		// AddActorLocalRotation : 초당 RotationSpeed만큼, 한 프레임당 (RotationSpeed * DeltaTime)만큼 회전
		AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, 0.0f, 0.0f));
	}

}