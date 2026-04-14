// Copyright 2026 aMustachedPotato. All rights reserved


#include "WAO.h"

UWAO::UWAO()
{
	WorldRef = nullptr;
}

UWAO* UWAO::CreateWorldAwareObject(UObject* WC, const TSubclassOf<UWAO> Class)
{
	if (!Class || !WC) return nullptr;

	UWAO* Obj = NewObject<UWAO>(WC, Class);
	Obj->Init(WC->GetWorld());

	return Obj;
}

void UWAO::Destroy()
{
	OnDestroy();
	WorldRef = nullptr;

	ConditionalBeginDestroy();
}

UWorld* UWAO::GetWorld() const
{
	return WorldRef.Get();
}
