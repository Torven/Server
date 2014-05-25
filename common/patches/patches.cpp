
#include "../debug.h"
#include "patches.h"

#include "Client62.h"
#include "Titanium.h"
#include "Underfoot.h"
#include "SoF.h"
#include "SoD.h"
#include "Mac.h"
#include "Evolution.h"

void RegisterAllPatches(EQStreamIdentifier &into) {
	Client62::Register(into);
	Titanium::Register(into);
	SoF::Register(into);
	SoD::Register(into);
	Underfoot::Register(into);
	Mac::Register(into);
	Evolution::Register(into);

}

void ReloadAllPatches() {
	Client62::Reload();
	Titanium::Reload();
	SoF::Reload();
	SoD::Reload();
	Underfoot::Reload();
	Mac::Reload();
	Evolution::Reload();
}

