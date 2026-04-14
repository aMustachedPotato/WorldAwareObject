// Copyright 2026 aMustachedPotato. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WAO.generated.h"

/**
 * World Aware Object (WAO) is a UObject that implements GetWorld()
 * allowing for gameplay code to be written in a lightweight object
 */
UCLASS(Blueprintable, BlueprintType)
class WORLDAWAREOBJECT_API UWAO : public UObject
{
	GENERATED_BODY()

public:

	UWAO();

	/** Function to create a World Aware Object (WAO) */
	UFUNCTION(BlueprintCallable, Category = "World Aware Object", meta = (WorldContext = "WC"))
	static UWAO* CreateWorldAwareObject(UObject* WC, const TSubclassOf<UWAO> Class);

	/** Used to remove this object */
	UFUNCTION(BlueprintCallable, Category = "World Aware Object", meta = (KeyWords = "Destroy, Release, Remove"))
	void Destroy();


	// C++ Only Functions //

	FORCEINLINE void Init(UWorld* World) { SetWorldPtr(World); OnCreated(); }

	FORCEINLINE void SetWorldPtr(UWorld* World) { WorldRef = World; }

protected:

	virtual UWorld* GetWorld() const override;

	/** Event when this object is created */
	UFUNCTION(BlueprintNativeEvent, Category = "World Aware Object")
	void OnCreated();

	virtual void OnCreated_Implementation(){}

	/** Event when this object is destroyed */
	UFUNCTION(BlueprintNativeEvent, Category = "World Aware Object")
	void OnDestroy();

	virtual void OnDestroy_Implementation(){}

private:

	TWeakObjectPtr<UWorld> WorldRef;
};
