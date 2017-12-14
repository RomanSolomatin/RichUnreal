// Copyright 2017 Evgeny Osmet.

#include "Attribute.h"

int32 FAttribute::GetMaxValue() const
{
	return MaxValue;
}

int32 FAttribute::GetMinValue() const
{
	return MinValue;
}

int32 FAttribute::GetValue()// const
{
	CheckBounds();
	return Value;
}

void FAttribute::SetValue(int32 NewValue)
{
	int32 OldValue = Value;
	Value = NewValue;
	CheckBounds();
	int32 DeltaValue = Value - OldValue;

	if (DeltaValue != 0 || bValueChangedOnZeroDelta)
	{
		EValueSignState ValueSignState(EValueSignState::SAME_SIGN);
		if (OldValue > 0 && Value <= 0)
		{
			ValueSignState = EValueSignState::BECAME_ZERO_NEGATIVE;
		}
		else if (OldValue < 1 && Value >= 1)
		{
			ValueSignState = EValueSignState::BECAME_POSITIVE;
		}
		OnValueChanged.Broadcast(DeltaValue, ValueSignState);
	}
}


void FAttribute::AddValue(int32 Value)
{
	SetValue(this->Value + Value);
}

int FAttribute::GetRemainingUpValue() const
{
	return MaxValue - Value;
}

int FAttribute::GetRemainingDownValue() const
{
	return Value - MinValue;
}

void FAttribute::ZeroOut()
{
	AddValue(-Value);
}

void FAttribute::CheckBounds()
{
	if (Value < MinValue)
	{
		if (!bCanGrowDown)
		{
			Value = MinValue;
		}
		else
		{
			MinValue = Value;
		}
	}
	else if (Value > MaxValue)
	{
		if (!bCanGrowUp)
		{
			Value = MaxValue;
		}
		else
		{
			MaxValue = Value;
		}
	}
}
