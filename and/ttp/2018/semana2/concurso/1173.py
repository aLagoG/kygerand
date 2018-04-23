#!/usr/bin/env python2
while True:
    try:
        line = raw_input()
    except:
        break
    while line.find('BUG') != -1:
        line = line.replace('BUG', '')
    print line