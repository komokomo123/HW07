// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoBackPallet.generated.h"

UCLASS()
class PROJECT6_API AGoBackPallet : public AActor
{
	GENERATED_BODY()
	
public:	
	AGoBackPallet();

protected:
	// 루트 컴포넌트를 나타내는 Scene Component 포인터
	// UPROPERTY() 에 여러 지정자를 작성해, Blueprint 접근성, 읽기/쓰기 권한 등을 자세하게 설정 가능함.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	// Static Mesh Component 포인터
	// UPROPERTY() 에 여러 지정자를 작성해, Blueprint 접근성, 읽기/쓰기 권한 등을 자세하게 설정 가능함.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// float 뭐시기 는 변수 선언? 소스 파일에서 값 설정 가능
	// UPROPERTY() 에 여러 지정자를 작성해, Blueprint 접근성, 읽기/쓰기 권한 등을 자세하게 설정 가능함.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float PalletSpeed;

	// float으로 팔레트 최대 길이 선언
	// UPROPERTY() 에 여러 지정자를 작성해, Blueprint 접근성, 읽기/쓰기 권한 등을 자세하게 설정 가능함.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itedm|Properties")
	float PalletMaxRange;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// 시작 위치 저장
	FVector StartLocation;

	// 팔레트가 앞으로 이동 중인지 여부를 저장하는 변수
	bool bMovingGo;

};