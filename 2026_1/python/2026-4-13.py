import calendar
def dateToNum(date):
    year = int(date.split('-')[0])
    month = int(date.split('-')[1])
    day = int(date.split('-')[2])
    monthDays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    num = 0
    if calendar.isleap(year):
        monthDays[month - 1] = 29
    if month > 1:
        num = num + sum(monthDays[:month - 1]) + day
    else:
        num += day
    return year,num

date = input("Enter a date: ")
year,num = dateToNum(date)
print(year,num)