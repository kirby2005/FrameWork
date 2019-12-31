// Fill out your copyright notice in the Description page of Project Settings.

#include "EntryPoint.h"

// Sets default values
AEntryPoint::AEntryPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEntryPoint::BeginPlay()
{
	Super::BeginPlay();

	L = NS_SLUA::LuaState::get();
	FString path = FPaths::ProjectDir();
	L->doFile("Lua.Main.EntryPoint");
	L->call("EntryPoint");
}

// Called every frame
void AEntryPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	L->call("Tick", DeltaTime);
}

