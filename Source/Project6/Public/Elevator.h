#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class PROJECT6_API AElevator : public AActor
{
	GENERATED_BODY()
	
public:
	AElevator();

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
	float ElevatorSpeed;

	// float으로 엘리베이터의 최대 높이 선언
	// UPROPERTY() 에 여러 지정자를 작성해, Blueprint 접근성, 읽기/쓰기 권한 등을 자세하게 설정 가능함.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itedm|Properties")
	float ElevatorMaxHigh;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// 시작 위치 저장
	FVector StartLocation;

	// 엘리베이터가 위로 이동 중인지 여부를 저장하는 변수
	bool bMovingUp;

};