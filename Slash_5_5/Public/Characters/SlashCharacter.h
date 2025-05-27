// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;

UCLASS()
class SLASH_5_5_API ASlashCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

protected:
	virtual void BeginPlay() override;

	/*
	* Callbacks for functions
	*/
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Jump(); // using ACharacter::Jump instead
	void EKeyPressed();
	void FKeyPressed(); // ˫�ֳֽ�����
	void Dodge();

	/** Combat Related */
	virtual void Attack() override;
	virtual void AttackEnd() override;
	virtual bool CanAttack() override;
	bool CanDisarm();
	bool CanArm();
	void PlayEquipMontage(const FName& SectionName);

	UFUNCTION(BlueprintCallable)
	void Disarm(); // ��AM notify�����ģ����װ����attach mesh socket����

	UFUNCTION(BlueprintCallable)
	void Arm(); // ��AM notify�����ģ�װ���ϵ�attach mesh socket����

	UFUNCTION(BlueprintCallable)
	void FinishEquipping(); // // ��AM notify�����ģ�װ��/��װ������������action state

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();

private:
	/** Character Components */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;

	// �洢��character���ϵ�����overlappingʱ����һ�����߼��ж�
	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	// ��ɫװ��״̬
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE AItem* GetOverlappingItem() {
		return OverlappingItem;
	}

	FORCEINLINE ECharacterState GetCharacterState() const {
		return CharacterState;
	}
};
