#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnLevel.generated.h"

class ABaseLevel;

UCLASS()
class ENDLESSRUNGAME_API ASpawnLevel : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void SpawnLevel(bool isFirst);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void DelayedSpawnLevel();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Level")
	TSubclassOf<ABaseLevel> Level1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Level")
	TSubclassOf<ABaseLevel> Level2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Level")
	TSubclassOf<ABaseLevel> Level3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Level")
	TSubclassOf<ABaseLevel> Level4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Level")
	TSubclassOf<ABaseLevel> Level5;

	TArray<ABaseLevel*> LevelList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn Level")
	bool bCanSpawnLevel;

private:
	APawn* Player;
	FVector SpawnLocation;
	FRotator SpawnRotation;
	FActorSpawnParameters SpawnInfo;
	FTimerHandle SpawnLevelTimerHandle;

public:
	int RandomLevel;
};