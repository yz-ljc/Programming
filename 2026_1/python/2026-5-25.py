import csv

student_list = []

with open("data/total.csv", "r", encoding="utf-8") as csvfile:
    reader = csv.reader(csvfile)
    for i in reader:
        print(i)
        student_list.append(i)
student_list = student_list[1:]

print(len(student_list))