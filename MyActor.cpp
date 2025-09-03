// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CurrentPosition = FVector2D(0.0f, 0.0f);
	StepCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Start : (%.0f, %.0f)"), CurrentPosition.X, CurrentPosition.Y);

	for (int i = 1; i <= 10; i++) {
		MoveOnce();
		UE_LOG(LogTemp, Warning, TEXT("Move %d Location : (%.0f, %.0f)"), i, CurrentPosition.X, CurrentPosition.Y);

	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AMyActor::Step() {
	return FMath::RandRange(0, 1);
}

void AMyActor::MoveOnce() {
	int stepX = Step();
	int stepY = Step();
	CurrentPosition.X += stepX;
	CurrentPosition.Y += stepY;
}