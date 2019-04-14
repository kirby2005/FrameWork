#pragma once
struct lua_State;

class LuaStatic
{
public:
	LuaStatic();
	~LuaStatic();

	static int Print(lua_State *L);
};

