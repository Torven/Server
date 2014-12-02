/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2002 EQEMu Development Team (http://eqemu.org)

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

#ifndef CORPSE_H
#define CORPSE_H

#include "mob.h"

class Client;
class EQApplicationPacket;
class Group;
class ItemInst;
class NPC;
class Raid;

struct ExtraAttackOptions;
struct NPCType;

#define MAX_LOOTERS 72

class Corpse : public Mob {
	public:

	static void SendEndLootErrorPacket(Client* client);
	static void SendLootReqErrorPacket(Client* client, uint8 response = 2);

	Corpse(NPC* in_npc, ItemList* in_itemlist, uint32 in_npctypeid, const NPCType** in_npctypedata, uint32 in_decaytime = 600000);
	Corpse(Client* client, int32 in_rezexp, uint8 killedby = 0);
	Corpse(uint32 in_corpseid, uint32 in_charid, const char* in_charname, ItemList* in_itemlist, uint32 in_copper, uint32 in_silver, uint32 in_gold, uint32 in_plat, float in_x, float in_y, float in_z, float in_heading, float in_size, uint8 in_gender, uint16 in_race, uint8 in_class, uint8 in_deity, uint8 in_level, uint8 in_texture, uint8 in_helmtexture, uint32 in_rezexp, uint32 in_gmrezexp, uint8 in_killedby, bool wasAtGraveyard = false);
	~Corpse();
	static Corpse* LoadCharacterCorpseEntity(uint32 in_dbid, uint32 in_charid, std::string in_charname, const xyz_heading& position, std::string time_of_death, bool rezzed, bool was_at_graveyard);

	/* Corpse: General */
	virtual bool	Death(Mob* killerMob, int32 damage, uint16 spell_id, SkillUseTypes attack_skill, uint8 killedby = 0) { return true; }
	virtual void	Damage(Mob* from, int32 damage, uint16 spell_id, SkillUseTypes attack_skill, bool avoidable = true, int8 buffslot = -1, bool iBuffTic = false) { return; }
	virtual bool	Attack(Mob* other, int Hand = MainPrimary, bool FromRiposte = false,
		bool			IsStrikethrough = true, bool IsFromSpell = false, ExtraAttackOptions *opts = nullptr) {
		return false;
	}
	virtual bool	HasRaid()			{ return false; }
	virtual bool	HasGroup()			{ return false; }
	virtual Raid*	GetRaid()			{ return 0; }
	virtual Group*	GetGroup()			{ return 0; }
	inline uint32	GetCorpseDBID()		{ return corpse_db_id; }
	inline char*	GetOwnerName()		{ return corpse_name; }
	bool			IsEmpty() const;
	bool			IsCorpse()			const { return true; }
	bool			IsPlayerCorpse()	const { return is_player_corpse; }
	bool			IsNPCCorpse()		const { return !is_player_corpse; }
	bool			IsBecomeNPCCorpse() const { return become_npc; }
	virtual void	DepopNPCCorpse();
	virtual void	DepopPlayerCorpse();
	bool			Process();
	bool			Save();
	uint32			GetCharID()					{ return char_id; }
	uint32			SetCharID(uint32 iCharID)	{ if (IsPlayerCorpse()) { return (char_id = iCharID); } return 0xFFFFFFFF; };
	uint32			GetDecayTime()				{ if (!corpse_decay_timer.Enabled()) return 0xFFFFFFFF; else return corpse_decay_timer.GetRemainingTime(); }
	uint32			GetRezTime()				{ if (!corpse_rez_timer.Enabled()) return 0; else return corpse_rez_timer.GetRemainingTime(); }
	void			SetDecayTimer(uint32 decay_time);
	
	void			Delete();
	void			Bury();
	void			CalcCorpseName();
	void			LoadPlayerCorpseDecayTime(uint32 dbid, bool empty);

	/* Corpse: Items */
	uint32					GetWornItem(int16 equipSlot) const;
	ServerLootItem_Struct*	GetItem(uint16 lootslot, ServerLootItem_Struct** bag_item_data = 0); 
	void	SetPlayerKillItemID(int32 pk_item_id) { player_kill_item = pk_item_id; }
	int32	GetPlayerKillItem() { return player_kill_item; } 
	void	RemoveItem(uint16 lootslot);
	void	RemoveItem(ServerLootItem_Struct* item_data);
	void	AddItem(uint32 itemnum, uint16 charges, int16 slot = 0, uint32 aug1 = 0, uint32 aug2 = 0, uint32 aug3 = 0, uint32 aug4 = 0, uint32 aug5 = 0);
	
	/* Corpse: Coin */
	void	SetCash(uint32 in_copper, uint32 in_silver, uint32 in_gold, uint32 in_platinum);
	void	RemoveCash();
	uint32	GetCopper()		{ return copper; }
	uint32	GetSilver()		{ return silver; }
	uint32	GetGold()		{ return gold; }
	uint32	GetPlatinum()	{ return platinum; }

	/* Corpse: Resurrection */
	bool	IsRezzed() { return rez; }
	void	IsRezzed(bool in_rez) { rez = in_rez; }
	void	CastRezz(uint16 spellid, Mob* Caster);
	void	CompleteResurrection();

	/* Corpse: Loot */
	void	QueryLoot(Client* to);
	void	LootItem(Client* client, const EQApplicationPacket* app);
	void	EndLoot(Client* client, const EQApplicationPacket* app);
	void	MakeLootRequestPackets(Client* client, const EQApplicationPacket* app);
	void	AllowPlayerLoot(Mob *them, uint8 slot);
	void	AddLooter(Mob *who);
	uint32	CountItems();
	bool	CanPlayerLoot(int charid);

	inline void	Lock()				{ is_locked = true; }
	inline void	UnLock()			{ is_locked = false; }
	inline bool	IsLocked()			{ return is_locked; }
	inline void	ResetLooter()		{ being_looted_by = 0xFFFFFFFF; }
	inline bool	IsBeingLooted()		{ return (being_looted_by != 0xFFFFFFFF); }

	/* Mob */
	void FillSpawnStruct(NewSpawn_Struct* ns, Mob* ForWho);
	bool Summon(Client* client, bool spell, bool CheckDistance);
	void Spawn();

	char		corpse_name[64]; 
	uint32		GetEquipment(uint8 material_slot) const;
	uint32		GetEquipmentColor(uint8 material_slot) const;
	inline int	GetRezExp() { return rez_experience; } 
	inline int	GetGMRezExp() { return gm_rez_experience; } 
	uint8		GetKilledBy() { return killedby; }

protected:
	std::list<uint32> MoveItemToCorpse(Client *client, ItemInst *item, int16 equipslot);

private:
	bool		is_player_corpse;
	bool		is_corpse_changed;
	bool		is_locked;
	int32		player_kill_item;
	uint32		corpse_db_id;
	uint32		char_id;
	ItemList	itemlist;
	uint32		copper;
	uint32		silver;
	uint32		gold;
	uint32		platinum;
	bool		player_corpse_depop; /* Sets up Corpse::Process to depop the player corpse */
	uint32		being_looted_by; /* Determines what the corpse is being looted by internally for logic */
	uint32		rez_experience; /* Amount of experience that the corpse would rez for */
	uint32		gm_rez_experience; /* Amount of experience that the corpse would rez for from a GM*/
	bool		rez; /*Sets if a corpse has been rezzed or not to determine if XP should be given or not */
	bool		can_corpse_be_rezzed; /* Bool declaring whether or not a corpse can be rezzed. Shouldn't be used as corpses can always be rezzed.*/
	bool		become_npc;
	int			allowed_looters[MAX_LOOTERS]; // People allowed to loot the corpse, character id
	Timer		corpse_decay_timer; /* The amount of time in millseconds in which a corpse will take to decay (Depop/Poof) */
	Timer		corpse_rez_timer; /* The amount of time in millseconds in which a corpse can be rezzed */
	Timer		corpse_delay_timer;
	Timer		corpse_graveyard_timer;
	Timer		loot_cooldown_timer; /* Delay between loot actions on the corpse entity */
	uint8		killedby;
	Color_Struct item_tint[9];

};

#endif
