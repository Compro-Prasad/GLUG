#!/usr/bin/python3

newf = open("newf.txt", "w")
f = open("/etc/passwd", "r")

line = f.readline()
while line:
    fields = line.split(":")
    newf.write("%s\t%s\t%s" % (fields[0], fields[-2], fields[-1]))
    line = f.readline()

f.close()
newf.close()
