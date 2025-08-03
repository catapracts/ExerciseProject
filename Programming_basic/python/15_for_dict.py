fighter = {"name":"F-22 Raptor","type":"fighter","engine":"F119-PW-100 Turbofan"}

#1
for data in fighter:
    #print(data) #dict의 key가 출력됨
    print(f"{data} : {fighter[data]}")

#2
for data in fighter.items():
    print(f"{data[0]} : {data[1]}")


