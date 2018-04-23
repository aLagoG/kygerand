#!/usr/bin/env python2
from datetime import datetime, timedelta

start = datetime(2011,11,11,11,11)
d,h,m = [int(x) for x in raw_input().split()]
end = datetime(2011,11,d,h,m)
d = int((end-start).total_seconds()//60)
print(max(d,-1))