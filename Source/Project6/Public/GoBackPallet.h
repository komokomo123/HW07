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
	float PalletSpeed;

	// float���� �ȷ�Ʈ �ִ� ���� ����
	// UPROPERTY() �� ���� �����ڸ� �ۼ���, Blueprint ���ټ�, �б�/���� ���� ���� �ڼ��ϰ� ���� ������.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itedm|Properties")
	float PalletMaxRange;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// ���� ��ġ ����
	FVector StartLocation;

	// �ȷ�Ʈ�� ������ �̵� ������ ���θ� �����ϴ� ����
	bool bMovingGo;

};