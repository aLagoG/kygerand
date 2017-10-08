#!/usr/bin/env python
notes = ['DO', 'DO#', 'RE', 'RE#', 'MI', 'FA', 'FA#', 'SOL', 'SOL#',
         'LA', 'LA#', 'SI']
s, note = input().split()
s = int(s)
print(notes[notes.index(note) - s])
