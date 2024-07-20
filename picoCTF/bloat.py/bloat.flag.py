import sys
a = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ "

def arg133(arg432):
  if arg432 == "happychance":
    return True
  else:
    print("That password is incorrect")
    sys.exit(0)
    return False

def getEncFlag():
  return open('flag.txt.enc', 'rb').read()

def arg122(arg432, arg423):
    arg433 = arg423
    i = 0
    while len(arg433) < len(arg432):
        arg433 = arg433 + arg423[i]
        i = (i + 1) % len(arg423)        
    return "".join([chr(ord(arg422) ^ ord(arg442)) for (arg422,arg442) in zip(arg432,arg433)])

encFlag = getEncFlag()
arg133(input("Please enter correct password for flag: "))
print("Welcome back... your flag, user:")
print(arg122(encFlag.decode(), "rapscallion"))
sys.exit(0)
