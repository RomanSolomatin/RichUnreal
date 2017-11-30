// Copyright 2017 Evgeny Osmet.

#pragma once

#include "CoreMinimal.h"

template<class T>
T* FindComponentByName(const AActor* Actor, const FString& ComponentName)
{
	static_assert(TPointerIsConvertibleFromTo<T, const UActorComponent>::Value, "'T' template parameter to FindComponentByName must be derived from UActorComponent");

	auto Components = Actor->GetComponentsByClass(T::StaticClass());

    UActorComponent* FoundComponent  = nullptr;

    for (auto Component : Components)
	{
		if (Component->GetName() == ComponentName)
		{
			FoundComponent = Component;
			break;
		}
	}
        
    return (T*) FoundComponent;
}