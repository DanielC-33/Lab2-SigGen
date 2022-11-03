import math
import string
f = open("sinerom.mem","w") #The "w" means write, there are many other modes for this function
for i in range(256):
    v = int(math.cos(2*3.1416*i/256)*127+127) #the period is 256 discrete points, amplitude*127, shifted up by 127 so range is 0-127
    if (i+1)%16 == 0: #if i+1 is divisible by 16
        s = "{hex:2X}\n"
    else:
        s = "{hex:2X} "
    f.write(s.format(hex=v)) #this is the .format() method. hex is placeholder, X is format type (hex), 2 means more space

f.close()
