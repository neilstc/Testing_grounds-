// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWayPoint :: ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory){
    
    //this block will get the patrol points
    auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn(); // getting the ai components
    auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
    
    // if the patrol route is empty
    if(!ensure(PatrolRoute)){
        EBTNodeResult::Failed;
    }
    
    auto PatrolPoints = PatrolRoute->getPatrolPoints(); // after that we getting acces to the patrol points;
    
    //warning if the patrol route is empty
    if(PatrolPoints.Num() == 0){
        UE_LOG(LogTemp, Warning, TEXT("a guard missing patrol points. "));
        return EBTNodeResult::Failed;
    }
    
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


