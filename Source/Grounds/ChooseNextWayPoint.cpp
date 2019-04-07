// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"


EBTNodeResult::Type UChooseNextWayPoint :: ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory){
    
    //this block will get the patrol points
    auto AIController = OwnerComp.GetAIOwner(); // getting the ai components
    auto ControlledPawn = AIController->GetPawn();
    auto PatrollingGuard = Cast <APatrollingGuard> (ControlledPawn); // here we want to do the cast we did in the blueprint
    auto PatrolPoints = PatrollingGuard ->patrolPointsCPP; // after that we getting acces to the patrol points;
    
    
    //this block will be the "set next waypoint" function
    auto BlackboardComp  = OwnerComp.GetBlackboardComponent();
    auto index = BlackboardComp->GetValueAsInt(indexKey.SelectedKeyName);
    BlackboardComp->SetValueAsObject(waypointKey.SelectedKeyName, PatrolPoints[index]);
    
    
    //cycle next index
    auto nextIndex = (index+1)%PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(indexKey.SelectedKeyName, nextIndex);
     return  EBTNodeResult::Succeeded;
    //TODO protect against empty patrol points;
}


