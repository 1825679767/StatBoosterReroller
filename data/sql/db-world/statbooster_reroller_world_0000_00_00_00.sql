UPDATE item_template SET name = "属性重置器", AllowableClass = -1, ItemLevel = 1, RequiredLevel = 1, RequiredSkill = 0, RequiredSkillRank = 0, spellid_1 = 10694, spelltrigger_1 = 0, description = "|cff00ff00Use: 为物品添加或重新掷出一个额外属性。|n|n|cffff0000WARNING: 这将会用新的属性替换任何额外的属性。" WHERE entry = 41605;
UPDATE item_template_locale SET name = '属性重置器' WHERE ID = 41605 AND locale = 'zhCN';