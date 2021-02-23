// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindPressurePlate() const;
	void FindAudioComponent();

private:

	float InitialYaw;
	float CurrentYaw;

	// Tracks whether the sound has been played.
	bool OpenDoorSound = false;
	bool CloseDoorSound = true;

	UPROPERTY(EditAnyWhere)
	float DoorOpenAngle = -45.f;

	UPROPERTY(EditAnyWhere)
	ATriggerVolume* PressurePlate = nullptr;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.1f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 2.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 2.f;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoors = 15.f;

	UPROPERTY()
	UAudioComponent * AudioComponent = nullptr;

};
