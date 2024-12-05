#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

/* 所有注册给Lua的C函数具有
 * "typedef int (*lua_CFunction) (lua_State *L);"的原型。
 */
static int l_sin(lua_State *L)
{   
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(d));  /* push result */
    return 1;  /* number of results */
}

static const struct luaL_Reg mylib[] = {
    {"mysin", l_sin},
    {NULL, NULL}
};


int luaopen_mylib(lua_State* L)
{
    /* void luaL_newlib (lua_State *L, const luaL_Reg l[]);
     * 创建一个新的"table"，并将"l"中所列出的函数注册为"table"的域。
     */ 
    //luaL_newlib(L, mylib);

    luaL_register(L, "cc", mylib);

    return 1;
}
