import random,string
lowercase = "abcdefghijklmnopqrstuvwxyz"
uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
number = "1234567890"
special_char="!@#%&*?"
all = lowercase + uppercase + number + special_char

password=""
print("Welcome to simple string randomizer(password generator)")
print("=======================================================")
print("1. use lowercase only")
print("2. use upercase only")
print("3. use number only")
print("4. use lowercase and upercase")
print("5. use lowercase and number")
print("6. use lowercase and special character")
print("7. use uppercase and number")
print("8. use uppercase and special character")
print("9. use lowercase, uppercase, and number")
print("10. use lowercase, number, and special character")
print("11. use lowercase, uppercase, and special character")
print("12. use uppercase, number, and special character")
print("13. use all")

ans=input("input your choice: ")
ans=int(ans)
print("")
if(ans<14 and ans>0):
	length = input("password length: ")
	length = int(length)
	print("")
	print("enjoy your new password!")

if(ans==1):
	for c in range(length):
		password+=random.choice(lowercase)
	print(password)
elif(ans==2):
	for c in range(length):
                password+=random.choice(uppercase)
        print(password)
elif(ans==3):
	for c in range(length):
                password+=random.choice(number)
        print(password)
elif(ans==4):
        for c in range(length):
                password+=random.choice(uppercase + lowercase)
        print(password)
elif(ans==5):
        for c in range(length):
                password+=random.choice(lowercase + number)
        print(password)
elif(ans==6):
        for c in range(length):
                password+=random.choice(lowercase + special_char)
        print(password)
elif(ans==7):
        for c in range(length):
                password+=random.choice(uppercase + number)
        print(password)
elif(ans==8):
        for c in range(length):
                password+=random.choice(uppercase + special_char)
        print(password)
elif(ans==9):
        for c in range(length):
                password+=random.choice(lowercase + uppercase + number)
        print(password)
elif(ans==10):
        for c in range(length):
                password+=random.choice(lowercase + number + special_char)
        print(password)
elif(ans==11):
        for c in range(length):
                password+=random.choice(lowercase + uppercase +special_char)
        print(password)
elif(ans==12):
        for c in range(length):
                password+=random.choice(uppercase + number + special_char)
        print(password)
elif(ans==13):
	for c in range(length):
                password+=random.choice(all)
        print(password)
else:
	print("Goodbye!")


