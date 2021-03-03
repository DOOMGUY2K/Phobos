#pragma once

#include <CCINIClass.h>
#include <WarheadTypeClass.h>

#include "../_Container.hpp"
#include "../../Phobos.h"

#include "../../Utilities/Debug.h"

#include "../../Utilities/TemplateDef.h"

class WarheadTypeExt
{
public:
	using base_type = WarheadTypeClass;

	class ExtData final : public Extension<WarheadTypeClass>
	{
	public:
		Valueable<bool> SpySat;
		Valueable<bool> BigGap;
		Valueable<int> TransactMoney;
		ValueableVector<AnimTypeClass*> SplashList;
		Valueable<bool> SplashList_PickRandom;
		Valueable<bool> RemoveDisguise;
		Valueable<bool> RemoveDisguise_AffectAllies;
		Valueable<bool> RemoveDisguise_ApplyCellSpread;

		ExtData(WarheadTypeClass* OwnerObject) : Extension<WarheadTypeClass>(OwnerObject),
			SpySat(false),
			BigGap(false),
			TransactMoney(0),
			SplashList(),
			SplashList_PickRandom(false),
			RemoveDisguise(false),
			RemoveDisguise_AffectAllies(false),
			RemoveDisguise_ApplyCellSpread(false)
		{ }

		virtual void LoadFromINIFile(CCINIClass* pINI) override;
		virtual ~ExtData() = default;

		virtual void InvalidatePointer(void* ptr, bool bRemoved) override {}

		virtual void LoadFromStream(IStream* Stm);

		virtual void SaveToStream(IStream* Stm);
	};

	static void ReshroudMapForOpponents(HouseClass* pThisHouse);

	class ExtContainer final : public Container<WarheadTypeExt> {
	public:
		ExtContainer();
		~ExtContainer();
	};

	static ExtContainer ExtMap;
};
