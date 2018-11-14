import sys
import struct

def convertFloat (number):
    number_i = struct.unpack('I', struct.pack('f', number))[0]
    sign = (number_i & 0x80000000) >> 31
    exp =  (number_i & 0x7f800000) >> 23
    mantissa = (number_i & 0x007fffff)
    toString = '(' + str(sign) + "," + str(exp) + "," + str(mantissa) + ')'
    return toString 

def nextFloat (number):
    number_i = struct.unpack('I', struct.pack('f', number))[0]
    num = number_i + 1
    return (struct.unpack('f', struct.pack('I', num)))[0]

def countBetween (lower, upper):
    lower = struct.unpack('I', struct.pack('f', lower))[0]
    upper = struct.unpack('I', struct.pack('f', upper))[0]
    return (upper - lower)

print("i. Floating point number converter.")
print(convertFloat(3.14159265358979))

print("\nii. Floating point number enumeration.")
fp = 0.0
i = 0
while fp < 1.4E-44:
    i = i + 1
    fp = nextFloat(fp)
    print (str(i), "th number: ", str(fp))

print("\niii. Floating point number counting")
zeroToMaxFloat = countBetween(0.0, sys.float_info.max)
zeroToOneFloat = countBetween(0.0, 1.0)
print("Number of positive floating point numbers:", str(zeroToMaxFloat))
print("Number of floating point numbers between 0 and 1:", str(zeroToOneFloat))
print("Proportion (# of 0~1) / (# of positive):", str(float(zeroToOneFloat) / float(zeroToMaxFloat) * 100.0), "%")