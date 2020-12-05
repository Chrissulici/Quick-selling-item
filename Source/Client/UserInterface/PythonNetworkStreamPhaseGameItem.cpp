//search:
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count)
{
	[...]
}

//add:
#ifdef ENABLE_SELL_ITEM
bool CPythonNetworkStream::SendItemSellPacket(TItemPos pos, DWORD elk)
{
	if (!__CanActMainInstance())
        return true;
	
    TPacketCGItemSell itemSellPacket;
    itemSellPacket.header = HEADER_CG_ITEM_SELL;
    itemSellPacket.pos = pos;
	itemSellPacket.gold = elk;
	
    if (!Send(sizeof(itemSellPacket), &itemSellPacket))
    {
        Tracen("SendItemDestroyPacket Error");
        return false;
    }
	
    return true;	
}
#endif

