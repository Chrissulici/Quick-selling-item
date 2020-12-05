#search:
	def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
		[...]
		
		self.AddItemData(itemVnum, metinSlot, attrSlot, 0, 0, window_type, slotIndex)

#replace:
		self.AddItemData(itemVnum, metinSlot, attrSlot, 0, 0, window_type, slotIndex, 1)

#search:
	def AddItemData(self, itemVnum, metinSlot, attrSlot = 0, flags = 0, unbindTime = 0, window_type = player.INVENTORY, slotIndex = -1):

#replace or adapt , window_open = 0:
	def AddItemData(self, itemVnum, metinSlot, attrSlot = 0, flags = 0, unbindTime = 0, window_type = player.INVENTORY, slotIndex = -1, window_open = 0):

#search:
		for i in xrange(item.LIMIT_MAX_NUM):
			(limitType, limitValue) = item.GetLimit(i)

			if item.LIMIT_REAL_TIME_START_FIRST_USE == limitType:
				self.AppendRealTimeStartFirstUseLastTime(item, metinSlot, i)
			elif item.LIMIT_TIMER_BASED_ON_WEAR == limitType:
				self.AppendTimerBasedOnWearLastTime(metinSlot)

#add:
		itemPrice = item.GetISellItemPrice()
		itemCount = player.GetItemCount(window_type, slotIndex)
		itemPriceCount = itemPrice * itemCount

		if window_open != 0:
			if app.ENABLE_SELL_ITEM:
				if self.IsSellItems(itemVnum, itemPrice):
					self.AppendSpace(5)
					self.AppendTextLine(localeInfo.EMOJI_SELL_ITEMS, self.CAN_LEVEL_UP_COLOR)
					self.AppendSpace(5)
					self.AppendTextLine(localeInfo.SELL_PRICE_INFO, self.SPECIAL_TITLE_COLOR)
					
					if itemCount > 1:
						self.AppendTextLine(localeInfo.SELL_PRICE_INFO_PCS % localeInfo.NumberToMoneyString(itemPrice), self.SPECIAL_TITLE_COLOR)
						self.AppendTextLine(localeInfo.SELL_PRICE_INFO_ALL % localeInfo.NumberToMoneyString(itemPriceCount), self.SPECIAL_TITLE_COLOR)
					else:
						self.AppendTextLine(localeInfo.NumberToMoneyString(itemPrice), self.SPECIAL_TITLE_COLOR)

#search:
	def __DragonSoulInfoString (self, dwVnum):

#add before:
	if app.ENABLE_SELL_ITEM:
		def IsSellItems(self, itemVnum, itemPrice):
			item.SelectItem(itemVnum)
			
			# if item.GetItemType() == item.ITEM_TYPE_WEAPON or item.GetItemType() == item.ITEM_TYPE_ARMOR:
				# return True
				
			if itemPrice > 1:
				return True
				
			return False