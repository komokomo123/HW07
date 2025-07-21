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
	// ��Ʈ ������Ʈ�� ��Ÿ���� Scene Component ������
	// UPROPERTY() �� ���� �����ڸ� �ۼ���, Blueprint ���ټ�, �б�/���� ���� ���� �ڼ��ϰ� ���� ������.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	// Static Mesh Component ������
	// UPROPERTY() �� ���� �����ڸ� �ۼ���, Blueprint ���ټ�, �б�/���� ���� ���� �ڼ��ϰ� ���� ������.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// float ���ñ� �� ���� ����? �ҽ� ���Ͽ��� �� ���� ����
	// UPROPERTY() �� ���� �����ڸ� �ۼ���, Blueprint ���ټ�, �б�/���� ���� ���� �ڼ��ϰ� ���� ������.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float ElevatorSpeed;

	// float���� ������������ �ִ� ���� ����
	// UPROPERTY() �� ���� �����ڸ� �ۼ���, Blueprint ���ټ�, �б�/���� ���� ���� �ڼ��ϰ� ���� ������.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itedm|Properties")
	float ElevatorMaxHigh;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// ���� ��ġ ����
	FVector StartLocation;

	// ���������Ͱ� ���� �̵� ������ ���θ� �����ϴ� ����
	bool bMovingUp;

};