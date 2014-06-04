#!/usr/bin/env python
from sys import argv as a
f = open(a[1]).read().split(a[2]) if len(a) > 2 else ["USAGE:\tpython.py fname key\n\n\tprints key(count) from file."]
print ("".join(["%s%s(%s)"%(f[i],a[2],str(i)) for i in range(len(f)) if i<(len(f)-1)]) if len(f) > 1 else f.pop())
