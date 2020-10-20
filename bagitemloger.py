from datetime import datetime
# tampung waktu sekarang di now
now = datetime.now()
item=[]
choice=0
#append file
file=open("bag-inventory.txt","a")
#write waktu ke file
file.write(str(now))
while choice!=4:
    #menu
    print("welcome to bag item log!")
    print("1. input item")
    print("2. remove item")
    print("3. show all item")
    print("4. exit")
    choice=int(input("choose: "))
    if choice==1:
        # pilihan 1 masukin item
        inputItem=input("what item do you put in?\ninput: ")
        while inputItem!="nothing":
            item.append(inputItem)
            inputItem=input("what else?\nif nothing more type nothing!\ninput: ")
    elif choice==2:
        # pilihan 2, validasi & buang item
        if not item:
            print("can't remove item because bag is empty!")
            print("")
        else:
            print(item)
            removeItem=input("enter item you want to remove! ")
            item.remove(removeItem)
            print("done!")
    elif choice==3:
        # pilihan 3, validasi & tampilin item
        if not item:
            print("nothing here currently...")
        else:
            print("here you go!\n")
            for i in item:
                print(i)
        print("")
    elif choice==4:
        # tulis file item
        with open("bag-inventory.txt", "a") as file:
            for i in item:
                file.writelines("\n%s" % i)
            file.write("\n")
        print("thanks!")
        file.close()