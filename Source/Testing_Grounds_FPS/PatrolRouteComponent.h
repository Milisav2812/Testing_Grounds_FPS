// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTING_GROUNDS_FPS_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }

protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route CPP")
	TArray<AActor*> PatrolPoints;
		
};
