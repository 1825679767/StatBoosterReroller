#include "StatBoosterReroller.h"

bool StatBoosterRerollPlayerScript::CanCastItemUseSpell(Player* player, Item* item, SpellCastTargets const& targets, uint8 /*cast_count*/, uint32 /*glyphIndex*/)
{
    if (!item)
    {
        return true;
    }

    auto itemTemplate = item->GetTemplate();
    if (!itemTemplate)
    {
        return true;
    }

    if (itemTemplate->ItemId != 41605)
    {
        return true;
    }

    if (!sConfigMgr->GetOption<bool>("StatBoostReroll.Enable", false))
    {
        ChatHandler(player->GetSession()).SendSysMessage("此项目已禁用.");
        return false;
    }

    auto targetItem = targets.GetItemTarget();
    if (!targetItem)
    {
        return false;
    }

    if (sConfigMgr->GetOption<bool>("StatBoostReroll.AllowOwnedItemsOnly", true) &&
        targetItem->GetOwner()->GetGUID() != player->GetGUID())
    {
        ChatHandler(player->GetSession()).SendSysMessage("你不能重置别人的物品.");
        return false;
    }

    if (StatBoostMgr::BoostItem(player, targetItem, 100))
    {
        player->DestroyItemCount(itemTemplate->ItemId, 1, true);

        uint32 visualId = sConfigMgr->GetOption<uint32>("StatBoostReroll.VisualId", 62015);
        player->CastSpell(player, visualId);
        //player->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
    }
    else
    {
        ChatHandler(player->GetSession()).SendSysMessage("你不能重置这件物品.");
    }

    return false;
}

void AddStatBoostRerollScripts()
{
    new StatBoosterRerollPlayerScript();
}
