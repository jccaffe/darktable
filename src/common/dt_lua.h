/*
    This file is part of darktable,
    copyright (c) 2012 Jeremy Rosen

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef DT_LUA_H
#define DT_LUA_H
#include <lualib.h>
#include <lua.h>
#include <lauxlib.h>

/** initialize lua stuff at DT start time */
void dt_lua_init();
/** runs a command in the DT lua environement, command in any valid lua string */
void dt_lua_dostring(const char* command);


/**
  define an OO type to create, will be used as a submodule of the darktable module
  */
typedef struct {
	const char *name; /// the recommanded name for the module (modname)
	lua_CFunction load; /// follows the loader convention, i.e returns a table, nil, or object that can be maped to name
	lua_CFunction clean; /// to be called when a DT lua run is finished to release locks etc... WARNING : this is not a GC, only for locks
} dt_lua_type;

/** helper to build types
  push on the stach a CFunction that can be used as __pair in metadata base on the list
  */
void dt_lua_push_generic_pair(lua_State* L, const char ** list);

#endif
// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.sh
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-space on;