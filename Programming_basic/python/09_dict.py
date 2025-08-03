# Dictionary {key:value}
# key, value 둘 다 어떤 형태든 사용 가능
# key는 반드시 1개여야만 함 = unique
fighter = {"name":"F-22 Raptor","type":"fighter","engine":"F119-PW-100 Turbofan"}
print(fighter["name"])
print(fighter["type"])
print(fighter["engine"])
print(fighter)
fighter["maiden flight"] = 19970907
print(fighter)
del fighter["maiden flight"]
print(fighter)

#key만 뽑아서 list화
keys_list = fighter.keys()
print(keys_list)
print(type(keys_list))
keys_list = list(keys_list)
print(keys_list)
print(type(keys_list))

#value만 뽑아서 list화
value_list = fighter.values()
print(value_list)
print(type(value_list))
value_list = list(value_list)
print(value_list)
print(type(value_list))

#key, value 동시에 list화
item_list = fighter.items()
item_list = list(item_list)
print(item_list)
print(type(item_list))
print(item_list[0])
print(type(item_list[0]))
