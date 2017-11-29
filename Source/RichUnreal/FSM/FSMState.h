// Copyright 2017 Evgeny Osmet.

#pragma once

#include "CoreMinimal.h"
#include "../Utils/any.hpp"


/**
 * 
 */

template <class C>
class TIFSMState
{
public:
	virtual ~TIFSMState() = 0;

	virtual void Tick(C* Context, float DeltaTime)
	{

	}

	virtual void OnEnter(C* Context, TIFSMState<C>* PrevState, linb::any* Parameter = nullptr)
	{

	}

	virtual void OnExit(C* Context, TIFSMState<C>* NextState, linb::any* Parameter = nullptr)
	{

	}


};

template<class C>
FORCEINLINE TIFSMState<C>::~TIFSMState()
{
}
