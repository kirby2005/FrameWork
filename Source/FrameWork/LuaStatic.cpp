#include "LuaStatic.h"
#include "CoreMinimal.h"
#include "lua.hpp"


LuaStatic::LuaStatic()
{
}


LuaStatic::~LuaStatic()
{
}


int LuaStatic::Print(lua_State *L)
{
	FString output;

	int n = lua_gettop(L);  /* number of arguments */
	int i;
	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; i++) {
		const char *s;
		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		s = lua_tostring(L, -1);  /* get result */
		if (s == NULL)
			return luaL_error(L, LUA_QL("tostring") " must return a string to "
				LUA_QL("print"));
		//if (i > 1) fputs("\t", stdout);
		if (i > 1) output += "\t";
		//fputs(s, stdout);
		output += s;
		lua_pop(L, 1);  /* pop result */
	}
	UE_LOG(LogTemp, Log, TEXT("%s"), *output);
	return 0;
}
