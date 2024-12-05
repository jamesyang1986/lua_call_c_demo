-- package.cpath = "/home/james/c_code/test/src/?.so"
print("-----module test-----")

local mylib = require "mylib"
print(mylib.mysin(3.14))