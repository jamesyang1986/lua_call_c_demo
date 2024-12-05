#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int luaadd(lua_State* L, int x, int y)
{
    int sum;
    lua_getglobal(L,"add");
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);
    lua_call(L, 2, 1);
    sum = (int)lua_tonumber(L, -1);
    lua_pop(L,1);
    return sum;
}

int main(int argc, char *argv[]){
    printf("test c demo code....");
    if(argc > 1){
        printf("the config file path is %s\n", argv[1]);
    }

    int sum;

    lua_State* L = luaL_newstate();  
    luaL_openlibs(L);
    luaL_dofile(L, "add.lua");
    sum = luaadd(L, 99, 10);
    printf("The sum is %d \n",sum);

    lua_close(L);

    L = luaL_newstate();  
    luaL_openlibs(L);
    if (luaL_loadfile(L, "a.lua") || lua_pcall(L, 0, 0, 0)) {
        printf("%s", lua_tostring(L, -1));
    }
    lua_close(L);
    return 0;
}