import os
i = int(input("1. for use \n2. for exit\nchoose : "))
while i < 2:
    text = input("enter your text: ")

    if text.isupper():
        text = text.replace("A", "4")
        text = text.replace("B", "8")
        text = text.replace("E", "3")
        text = text.replace("F", "7")
        text = text.replace("J", "7")
        text = text.replace("T", "7")
        text = text.replace("G", "6")
        text = text.replace("I", "1")
        text = text.replace("O", "0")
        text = text.replace("S", "5")
        text = text.replace("Z", "2")
        text = text.replace(" ", "-")
        print(text)
    else:
        print("try again with uppercase\n")
        
    i = int(input("1. for use \n2. for exit\nchoose : "))   