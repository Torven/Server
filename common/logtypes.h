/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2006 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef LOG_CATEGORY
#define LOG_CATEGORY(name)
#endif
#ifndef LOG_TYPE
#define LOG_TYPE(cat, type, default_value)
#endif
#ifndef ENABLED
#define ENABLED true
#endif
#ifndef DISABLED
#define DISABLED false
#endif


LOG_CATEGORY( CHAT )
LOG_TYPE( CHAT, SAY, DISABLED )
LOG_TYPE( CHAT, EMOTE, DISABLED )
LOG_TYPE( CHAT, OOC, DISABLED )
LOG_TYPE( CHAT, GROUP, DISABLED )
LOG_TYPE( CHAT, GUILD, DISABLED )

LOG_CATEGORY( MAIL )
LOG_TYPE( MAIL, INIT, ENABLED )
LOG_TYPE( MAIL, ERROR, ENABLED )
LOG_TYPE( MAIL, CLIENT, DISABLED )
LOG_TYPE( MAIL, TRACE, DISABLED )
LOG_TYPE( MAIL, PACKETS, DISABLED)

LOG_CATEGORY( CHANNELS )
LOG_TYPE( CHANNELS, INIT, ENABLED )
LOG_TYPE( CHANNELS, ERROR, ENABLED )
LOG_TYPE( CHANNELS, CLIENT, DISABLED )
LOG_TYPE( CHANNELS, TRACE, DISABLED )
LOG_TYPE( CHANNELS, PACKETS, DISABLED)

LOG_CATEGORY( UCS )
LOG_TYPE( UCS, INIT, ENABLED )
LOG_TYPE( UCS, ERROR, ENABLED )
LOG_TYPE( UCS, CLIENT, DISABLED )
LOG_TYPE( UCS, TRACE, DISABLED )
LOG_TYPE( UCS, PACKETS, DISABLED)

LOG_CATEGORY( QUERYSERV )
LOG_TYPE( QUERYSERV, INIT, ENABLED )
LOG_TYPE( QUERYSERV, ERROR, ENABLED )
LOG_TYPE( QUERYSERV, CLIENT, DISABLED )
LOG_TYPE( QUERYSERV, TRACE, DISABLED )
LOG_TYPE( QUERYSERV, PACKETS, DISABLED)

LOG_CATEGORY( SPAWNS )
LOG_TYPE( SPAWNS, MAIN, DISABLED )
LOG_TYPE( SPAWNS, CONDITIONS, DISABLED )
LOG_TYPE( SPAWNS, LIMITS, DISABLED )

LOG_CATEGORY( AI )
LOG_TYPE( AI, ERROR, ENABLED )
LOG_TYPE( AI, WAYPOINTS, DISABLED )
LOG_TYPE( AI, BUFFS, DISABLED )
LOG_TYPE( AI, SPELLS, DISABLED )

LOG_CATEGORY( PATHING)
LOG_TYPE( PATHING, DEBUG, DISABLED )

LOG_CATEGORY( QUESTS )
LOG_TYPE( QUESTS, PATHING, DISABLED )

LOG_CATEGORY( SPELLS )
LOG_TYPE( SPELLS, LOAD, DISABLED )
LOG_TYPE( SPELLS, LOAD_ERR, DISABLED )
LOG_TYPE( SPELLS, CASTING_ERR, DISABLED )
LOG_TYPE( SPELLS, CASTING, DISABLED )
LOG_TYPE( SPELLS, EFFECT_VALUES, DISABLED )
LOG_TYPE( SPELLS, RESISTS, DISABLED )
LOG_TYPE( SPELLS, STACKING, DISABLED )
LOG_TYPE( SPELLS, BARDS, DISABLED )
LOG_TYPE( SPELLS, BUFFS, DISABLED )
LOG_TYPE( SPELLS, PROCS, DISABLED )
LOG_TYPE( SPELLS, MODIFIERS, DISABLED )
LOG_TYPE( SPELLS, CRITS, DISABLED )
LOG_TYPE( SPELLS, REZ, DISABLED )

LOG_CATEGORY( FACTION )

LOG_CATEGORY( ZONE )
LOG_TYPE( ZONE, GROUND_SPAWNS, DISABLED )
LOG_TYPE( ZONE, INIT, ENABLED )
LOG_TYPE( ZONE, INIT_ERR, ENABLED )
LOG_TYPE( ZONE, WORLD, ENABLED )
LOG_TYPE( ZONE, WORLD_ERR, ENABLED )
LOG_TYPE( ZONE, WORLD_TRACE, DISABLED )

LOG_CATEGORY( TASKS )
LOG_TYPE( TASKS, GLOBALLOAD, DISABLED )
LOG_TYPE( TASKS, CLIENTLOAD, DISABLED )
LOG_TYPE( TASKS, UPDATE, DISABLED )
LOG_TYPE( TASKS, CLIENTSAVE, DISABLED )
LOG_TYPE( TASKS, PACKETS, DISABLED )
LOG_TYPE( TASKS, PROXIMITY, DISABLED )


LOG_CATEGORY( TRADING )
LOG_TYPE( TRADING, ERROR, ENABLED )
LOG_TYPE( TRADING, CLIENT, DISABLED )
LOG_TYPE( TRADING, NPC, DISABLED )
LOG_TYPE( TRADING, HOLDER, DISABLED )
LOG_TYPE( TRADING, BARTER, DISABLED )
LOG_TYPE( TRADING, PACKETS, DISABLED )

LOG_CATEGORY( INVENTORY )
LOG_TYPE( INVENTORY, ERROR, ENABLED )
LOG_TYPE( INVENTORY, SLOTS, ENABLED )
LOG_TYPE( INVENTORY, BANDOLIER, ENABLED )

LOG_CATEGORY( TRADESKILLS )
LOG_TYPE( TRADESKILLS, IN, DISABLED )
LOG_TYPE( TRADESKILLS, OUT, DISABLED )
LOG_TYPE( TRADESKILLS, SQL, DISABLED )
LOG_TYPE( TRADESKILLS, TRACE, DISABLED )

LOG_CATEGORY( AA )
LOG_TYPE( AA, ERROR, ENABLED )
LOG_TYPE( AA, MESSAGE, DISABLED )
LOG_TYPE( AA, IN, DISABLED )
LOG_TYPE( AA, OUT, DISABLED )
LOG_TYPE( AA, BONUSES, DISABLED )


LOG_CATEGORY( DOORS )
LOG_TYPE( DOORS, INFO, DISABLED )

LOG_CATEGORY( PETS )
LOG_TYPE( PETS, AGGRO, DISABLED )

LOG_CATEGORY( COMBAT )
LOG_TYPE( COMBAT, ATTACKS, DISABLED )
LOG_TYPE( COMBAT, TOHIT, DISABLED )
LOG_TYPE( COMBAT, MISSES, DISABLED )
LOG_TYPE( COMBAT, DAMAGE, DISABLED )
LOG_TYPE( COMBAT, HITS, DISABLED )
LOG_TYPE( COMBAT, RANGED, DISABLED )
LOG_TYPE( COMBAT, SPECIAL_ATTACKS, DISABLED )
LOG_TYPE( COMBAT, PROCS, DISABLED )

LOG_CATEGORY( GUILDS )
LOG_TYPE( GUILDS, ERROR, ENABLED )
LOG_TYPE( GUILDS, ACTIONS, ENABLED )
LOG_TYPE( GUILDS, DB, DISABLED )
LOG_TYPE( GUILDS, PERMISSIONS, DISABLED )
LOG_TYPE( GUILDS, REFRESH, DISABLED )	//inter-zone refresh comm
LOG_TYPE( GUILDS, IN_PACKETS, DISABLED )
LOG_TYPE( GUILDS, OUT_PACKETS, DISABLED )
LOG_TYPE( GUILDS, IN_PACKET_TRACE, DISABLED )	//hex dumps
LOG_TYPE( GUILDS, OUT_PACKET_TRACE, DISABLED )	//hex dumps
LOG_TYPE( GUILDS, BANK_ERROR, ENABLED )

LOG_CATEGORY( CLIENT )
LOG_TYPE( CLIENT, ERROR, ENABLED )
LOG_TYPE( CLIENT, DUELING, DISABLED )
LOG_TYPE( CLIENT, SPELLS, DISABLED )
LOG_TYPE( CLIENT, NET_ERR, ENABLED )
LOG_TYPE( CLIENT, NET_IN_TRACE, DISABLED )
LOG_TYPE( CLIENT, EXP, DISABLED )

LOG_CATEGORY( SKILLS )
LOG_TYPE( SKILLS, GAIN, DISABLED )

LOG_CATEGORY( RULES )
LOG_TYPE( RULES, ERROR, DISABLED )
LOG_TYPE( RULES, CHANGE, DISABLED )

LOG_CATEGORY( NET )
LOG_TYPE( NET, WORLD, ENABLED )
LOG_TYPE( NET, OPCODES, ENABLED )
LOG_TYPE( NET, IDENTIFY, ENABLED )
LOG_TYPE( NET, IDENT_TRACE, ENABLED )
LOG_TYPE( NET, STRUCTS, ENABLED )
LOG_TYPE( NET, STRUCT_HEX, ENABLED )
LOG_TYPE( NET, ERROR, ENABLED )
LOG_TYPE( NET, DEBUG, DISABLED )
LOG_TYPE( NET, APP_TRACE, DISABLED )
LOG_TYPE( NET, APP_CREATE, DISABLED )
LOG_TYPE( NET, APP_CREATE_HEX, DISABLED )
LOG_TYPE( NET, NET_TRACE, DISABLED )
LOG_TYPE( NET, NET_COMBINE, DISABLED )
LOG_TYPE( NET, FRAGMENT, DISABLED )
LOG_TYPE( NET, FRAGMENT_HEX, DISABLED )
LOG_TYPE( NET, NET_CREATE, DISABLED )
LOG_TYPE( NET, NET_CREATE_HEX, DISABLED )
LOG_TYPE( NET, NET_ACKS, DISABLED )
LOG_TYPE( NET, RATES, DISABLED )

LOG_CATEGORY( DATABASE )

LOG_CATEGORY( COMMON )
LOG_TYPE( COMMON, ERROR, ENABLED )
LOG_TYPE( COMMON, THREADS, ENABLED )

LOG_CATEGORY( LAUNCHER )
LOG_TYPE( LAUNCHER, ERROR, ENABLED )
LOG_TYPE( LAUNCHER, INIT, ENABLED )
LOG_TYPE( LAUNCHER, STATUS, ENABLED )
LOG_TYPE( LAUNCHER, NET, ENABLED )
LOG_TYPE( LAUNCHER, WORLD, ENABLED )

LOG_CATEGORY( WORLD )
LOG_TYPE( WORLD, CONFIG, ENABLED )
LOG_TYPE( WORLD, INIT, ENABLED )
LOG_TYPE( WORLD, INIT_ERR, ENABLED )
LOG_TYPE( WORLD, CLIENT, ENABLED )
LOG_TYPE( WORLD, ZONE, ENABLED )
LOG_TYPE( WORLD, LS, ENABLED )
LOG_TYPE( WORLD, CLIENT_ERR, ENABLED )
LOG_TYPE( WORLD, ZONE_ERR, ENABLED )
LOG_TYPE( WORLD, LS_ERR, ENABLED )
LOG_TYPE( WORLD, SHUTDOWN, ENABLED )
LOG_TYPE( WORLD, CLIENTLIST, DISABLED )
LOG_TYPE( WORLD, CLIENTLIST_ERR, ENABLED )
LOG_TYPE( WORLD, ZONELIST, ENABLED )
LOG_TYPE( WORLD, ZONELIST_ERR, ENABLED )
LOG_TYPE( WORLD, CLIENT_TRACE, DISABLED )
LOG_TYPE( WORLD, ZONE_TRACE, DISABLED )
LOG_TYPE( WORLD, LS_TRACE, DISABLED )
LOG_TYPE( WORLD, CONSOLE, ENABLED )
LOG_TYPE( WORLD, HTTP, ENABLED )
LOG_TYPE( WORLD, HTTP_ERR, ENABLED )
LOG_TYPE( WORLD, PERL, ENABLED )
LOG_TYPE( WORLD, PERL_ERR, ENABLED )
LOG_TYPE( WORLD, EQW, ENABLED )
LOG_TYPE( WORLD, LAUNCH, ENABLED )
LOG_TYPE( WORLD, LAUNCH_ERR, ENABLED )
LOG_TYPE( WORLD, LAUNCH_TRACE, ENABLED )

LOG_CATEGORY( EQMAC )
LOG_TYPE( EQMAC, LOG, ENABLED )

#undef LOG_TYPE
#undef LOG_CATEGORY

