// Fill out your copyright notice in the Description page of Project Settings.

#include "EntryPoint.h"
#include "lua.hpp"
#include "LuaStatic.h"

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

	lua_State *L = luaL_newstate();

	lua_pushcfunction(L, LuaStatic::Print);
	lua_setfield(L, LUA_GLOBALSINDEX, "print");
	

	luaL_dostring(L, "print(1, 2, 3)");
}

// Called every frame
void AEntryPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

