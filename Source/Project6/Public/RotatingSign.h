// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingSign.generated.h"	// 반드시 마지막에 위치해야 한다.

UCLASS()
class PROJECT6_API ARotatingSign : public AActor
{
	GENERATED_BODY()

public:
	ARotatingSign();

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
	float RotationSpeed;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};