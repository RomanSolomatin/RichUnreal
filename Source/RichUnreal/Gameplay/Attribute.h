// Copyright 2017 Evgeny Osmet.

#pragma once

#include "CoreMinimal.h"

#include "Attribute.generated.h"

UENUM(/*BlueprintType*/)
enum class EValueSignState : uint8
{
	BECAME_ZERO_NEGATIVE,
	BECAME_POSITIVE,
	SAME_SIGN,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnValueChangedSignature, int32, DeltaValue, EValueSignState, ValueSignState);

USTRUCT(/*BlueprintType*/)
struct FAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Properties)
	bool bCanGrowUp = false;

	UPROPERTY(EditAnywhere, Category = Properties)
	bool bCanGrowDown = false;

	UPROPERTY(EditAnywhere, Category = Properties)
	bool bValueChangedOnZeroDelta = false;

	//UPROPERTY(BlueprintAssignable, Category = Properties)
	FOnValueChangedSignature OnValueChanged;

	int32 GetMaxValue() const;

	int32 GetMinValue() const;

	int32 GetValue();// const;

	void SetValue(int32 NewValue);

	void AddValue(int32 Value);

	int GetRemainingUpValue() const;
	int GetRemainingDownValue() const;


	void ZeroOut();

private:
	UPROPERTY(EditAnywhere, Category = Properties, meta = (AllowPrivateAccess = true/*, ClampMin = 0, ClampMax = 2147483647, UIMin = 0, UIMax = 2147483647*/))
	int32 MaxValue = 2147483647;
	UPROPERTY(EditAnywhere, Category = Properties, meta = (AllowPrivateAccess = true))
	int32 MinValue = -2147483647 - 1;

	UPROPERTY(EditAnywhere/*, BlueprintReadOnly*/, Category = Properties, meta = (AllowPrivateAccess = true))
	int32 Value;

	void CheckBounds();
};

