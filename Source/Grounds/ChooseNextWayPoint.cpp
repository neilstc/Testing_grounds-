// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWayPoint :: ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory){
    
    
    auto BlackboardComp  = OwnerComp.GetBlackboardComponent();
    auto index = BlackboardComp->GetValueAsInt(indexKey.SelectedKeyName);
    UE_LOG(LogTemp, Warning, TEXT("Waypoint %i"), index);
     return  EBTNodeResult::Succeeded;
}


