// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/*
 helps ai choose the next waypoint in patrol
 */

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()
    
public:
    TArray<AActor*> getPatrolPoints() const;
    
private:
    UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
    TArray<AActor*> PatrolPoints;
};
