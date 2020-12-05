#search:
	def __UseItem(self, slotIndex):
		ItemVNum = player.GetItemIndex(slotIndex)
		itemCount = player.GetItemCount(slotIndex)
		item.SelectItem(ItemVNum)

#add:
		if app.ENABLE_SELL_ITEM:		
			if app.IsPressed(app.DIK_LCONTROL) and self.IsSellItems(slotIndex):
				self.__SendSellItemPacket(slotIndex)
				return
				
#search:
	def __SendMoveItemPacket(self, srcSlotPos, dstSlotPos, srcItemCount):
		if uiPrivateShopBuilder.IsBuildingPrivateShop():
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.MOVE_ITEM_FAILURE_PRIVATE_SHOP)
			return

		net.SendItemMovePacket(srcSlotPos, dstSlotPos, srcItemCount)

#add:
	if app.ENABLE_SELL_ITEM:
		def IsSellItems(self, slotIndex):
			itemVnum = player.GetItemIndex(slotIndex)
			item.SelectItem(itemVnum)
			itemPrice = item.GetISellItemPrice()
			
			# if item.GetItemType() == item.ITEM_TYPE_WEAPON or item.GetItemType() == item.ITEM_TYPE_ARMOR:
				# return True
				
			if itemPrice > 1:
				return True
				
			return False
			
		def __SendSellItemPacket(self, itemVNum):
			if uiPrivateShopBuilder.IsBuildingPrivateShop():
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.USE_ITEM_FAILURE_PRIVATE_SHOP)
				return
				
			net.SendItemSellPacket(itemVNum)