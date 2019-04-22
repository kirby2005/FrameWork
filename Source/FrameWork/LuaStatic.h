#pragma once
struct lua_State;

class LuaStatic
{
public:
	LuaStatic();
	~LuaStatic();

	static int Print(lua_State *L);
	static int Dofile(lua_State *L);
	static int Loader(lua_State *L);
};

