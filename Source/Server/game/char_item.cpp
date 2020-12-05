//search:
bool CHARACTER::DropItem(TItemPos Cell, WORD bCount)
{
	[...]
}

//add:
#ifdef ENABLE_SELL_ITEM
bool CHARACTER::SellItem(TItemPos Cell)
{	
	LPITEM item = NULL;
	
	if (!CanHandleItem())
	{
		if (NULL != DragonSoul_RefineWindow_GetOpener())
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("#4 <Unknown translate> Report GM"));
		return false;
	}
	
#ifdef __INVENTORY_PROTECT_SYSTEM__
	if (GetQuestFlag("abs.INVENTORY_LOCK") == 1)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Your inventory is locked."));
		return false;
	}
#endif

#ifdef __ATTR_TRANSFER_SYSTEM__
	if (IsAttrTransferOpen())
		return false;
#endif

	if (IsDead())
		return false;
	
	if (!IsValidItemPosition(Cell) || !(item = GetItem(Cell)))
		return false;
	
	if (item->IsExchanging() || item->IsEquipped())
		return false;
	
	if (true == item->isLocked())
		return false;
	
	if (IS_SET(item->GetAntiFlag(), ITEM_ANTIFLAG_SELL))
		return false;

    if (quest::CQuestManager::instance().GetPCForce(GetPlayerID())->IsRunning() == true)
        return false;
	
    if (item->GetCount() <= 0)
        return false;
	
	long long dwPrice = item->GetShopBuyPrice();
	dwPrice *= item->GetCount();
	
	const long long nTotalMoney = static_cast<long long>(GetGold()) + static_cast<long long>(dwPrice);

	if (GOLD_MAX <= nTotalMoney)
	{
		sys_err("[OVERFLOW_GOLD] OriGold %lld AddedGold %lld id %u Name %s ", GetGold(), dwPrice, GetPlayerID(), GetName());
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You have reached the maximum limit of yang."));
		return false;
	}
	
	item->SetCount(item->GetCount() - item->GetCount());
	PointChange(POINT_GOLD, dwPrice, false);
	
	char buf[1024];
	char itemlink[256];
	int len;
	len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x", item->GetVnum(), item->GetFlag());

	for (int i = 0; i < ITEM_SOCKET_MAX_NUM; ++i)
		len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x", item->GetSocket(i));
		
	for (int i = 0; i < ITEM_ATTRIBUTE_MAX_NUM; ++i)
		if (item->GetAttributeType(i) != 0)
			len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x:%d", item->GetAttributeType(i), item->GetAttributeValue(i));
	
	snprintf(buf, sizeof(buf), "|cffffc700|H%s|h[%s]|h|r", itemlink, item->GetName());
	ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You succesfully sell %s."), buf);
    return true;
}
#endif

