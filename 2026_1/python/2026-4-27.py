with open("sign.csv", "r", encoding='utf-8') as f:
    content = f.readlines()

checked = input("Input the user you want check: ")

total = 0
found = False

for i in content[1:]:
    total += 1
    stu = i.strip().split(",")
    stu_num = stu[0].replace("=", "").replace("\"", "")
    stu_name = stu[1].replace("\"", "").replace("=", "")
    if stu_num == checked:
        print(stu_num + " " + stu_name + " 已完成签到")
        found = True
if not found:
    print("未找到" + checked + "的签到信息")
print("共有" + str(total) + "人签到")
