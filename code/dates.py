import datetime

jdate = 17330
date = datetime.datetime.strptime(str(jdate), '%y%j').date()
# date is (date.day, date.month, date.year)

date = datetime.date(2017, 11, 26)

jdate = int( date.strftime('%y%j') )

