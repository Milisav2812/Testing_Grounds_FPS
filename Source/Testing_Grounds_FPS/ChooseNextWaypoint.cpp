// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.h"
#include "AIController.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get NextWaypointIndex from Blackboard
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto NextWaypointIndex = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	
	// Get PatrolPoints Form 3PC
	auto ThirdPersonChar = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	auto PatrolPoints = ThirdPersonChar->GetPatrolPoints();

	// If Array is empty, return Failed
	if (PatrolPoints.Num() <= 0)
	{
		// UE_LOG(LogTemp, Warning, TEXT("UChooseNextWaypoint Failed on %s"), *ThirdPersonChar->GetName());
		return EBTNodeResult::Failed;
	}

	// Set NextWaypoint
	BlackboardComponent->SetValueAsObject(NextWaypointKey.SelectedKeyName, PatrolPoints[NextWaypointIndex]);

	// Increment the Index
	NextWaypointIndex++;
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, (NextWaypointIndex % PatrolPoints.Num()) );

	return EBTNodeResult::Succeeded;
}