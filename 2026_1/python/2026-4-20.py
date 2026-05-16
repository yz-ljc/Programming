import calendar

def get_date(date):
    year = int(date.split('-')[0])
    month = int(date.split('-')[1])
    day = int(date.split('-')[2])

    days_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    total_days = 0

    if calendar.isleap(year):
        days_of_month[1] = 29

    if month > 2:
        total_days = total_days + sum(days_of_month[:month - 1]) + day
    else:
        total_days += day
    return total_days

date = input('Enter a date: ')
days_sum = get_date(date)
print("输入的日期距今有: " + str(days_sum) + "天")


