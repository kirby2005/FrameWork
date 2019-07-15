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

	//lua_State *L = luaL_newstate();
	//luaL_openlibs(L);

	//lua_pushcfunction(L, LuaStatic::Print);
	//lua_setfield(L, LUA_GLOBALSINDEX, "print");
	//lua_pushcfunction(L, LuaStatic::Dofile);
	//lua_setfield(L, LUA_GLOBALSINDEX, "dofile");

	//lua_getfield(L, LUA_GLOBALSINDEX, "package"); // table
	//lua_getfield(L, -1, "loaders"); // table, table
	//int count = lua_objlen(L, -1); // table, table, number

	//for (int i = count; i > 0; --i)
	//{
	//	lua_rawgeti(L, -1, i); // table, table, func
	//	lua_rawseti(L, -2, i + 1); // table, table
	//}

	//lua_pushcfunction(L, LuaStatic::Loader); // table, table, func
	//lua_rawseti(L, -2, 1); // table, table
	//lua_pop(L, 2);


	//luaL_dostring(L, "require [[preload]]");
	//luaL_dostring(L, "require [[Main.test]]");
	//luaL_dostring(L, "print(1, 2, 3)");
	//luaL_dostring(L, "dofile([[Main/EntryPoint.lua]])");
}

// Called every frame
void AEntryPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

