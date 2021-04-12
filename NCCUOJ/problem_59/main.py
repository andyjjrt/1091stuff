print("馬德",end="")
i = 0
while(1):
    try:
        string = input()
        if i > 0:
            print("")
        print(string,end="")
        i+=1
    except:
        break
print("!!",end="")