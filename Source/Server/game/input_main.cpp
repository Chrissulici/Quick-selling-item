//search:
void CInputMain::ItemDrop2(LPCHARACTER ch, const char * data)
{
	[...]
}

//add:
#ifdef ENABLE_SELL_ITEM
void CInputMain::ItemSell(LPCHARACTER ch, const char * data)
{
	TPacketCGItemSell * pinfo = (TPacketCGItemSell *) data;
	
	if (!ch)
		return;

	if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->SellItem(pinfo->Cell);
}
#endif

//search:
		case HEADER_CG_ITEM_MOVE:
			if (!ch->IsObserverMode())
				ItemMove(ch, c_pData);
			break;

//add:
#ifdef ENABLE_SELL_ITEM
		case HEADER_CG_ITEM_SELL:
            if (!ch->IsObserverMode())
                ItemSell(ch, c_pData);
			break;
#endif

