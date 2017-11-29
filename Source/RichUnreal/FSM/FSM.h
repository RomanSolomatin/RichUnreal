// Copyright 2017 Evgeny Osmet.

#pragma once

#include "CoreMinimal.h"
#include "FSMState.h"
#include <typeinfo>
#include "../Utils/any.hpp"

/**
 * 
 */

template <class C>
class TFSM
{
private:
	TIFSMState<C>* CurrentState;
	C* Context;
public:
	TFSM(C* Context, TIFSMState<C>* BeginState, bool ApplyOnEnter = false)
		: Context(Context), CurrentState(BeginState)
	{
		if (ApplyOnEnter)
		{
			CurrentState->OnEnter(Context, CurrentState);
		}
	}

	virtual ~TFSM() = 0;

	void Tick(float DeltaTime)
	{
		CurrentState->Tick(Context, DeltaTime);
	}
	void SetState(TIFSMState<C>* NewState, linb::any* Parameter = nullptr)
	{
		auto OldState = CurrentState;
		CurrentState->OnExit(Context, NewState, Parameter);
		CurrentState = NewState;
		CurrentState->OnEnter(Context, OldState, Parameter);
	}

	virtual TIFSMState<C>* GetCurrentState() const
	{
		return CurrentState;
	}

	C* GetContext() const
	{
		return Context;
	}

};

template<class C>
FORCEINLINE TFSM<C>::~TFSM()
{
}
