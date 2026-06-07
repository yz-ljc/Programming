content = []

with open("./data/daily/sign1.csv", "r", encoding="utf-8") as f:
    content.append(f.readlines())
with open("./data/daily/sign2.csv", "r", encoding="utf-8") as f:
    content.append(f.readlines())
with open("./data/daily/sign3.csv", "r", encoding="utf-8") as f:
    content.append(f.readlines())
with open("./data/total.csv", "r", encoding="utf-8") as f:
    total = f.readlines()

total_student = []
total_num = 0
total_unsigned_stu = []
for t in total[1:]:
    total_num += 1
    stu = t.strip().split(",")
    stu_num = stu[1]
    stu_name = stu[2]
    stu_sex = stu[3]
    stu_class = stu[4]
    total_student.append({"id": stu_num, "name": stu_name, "sex": stu_sex, "class": stu_class, "is_sign": False})

times = 0
while times < len(content):
    temp_total_student = []
    for s in total_student:
        temp_total_student.append(s.copy())
    total_signed = 0
    unsigned_stu = []
    for line in content[times][1:]:
        stu = line.strip().split(",")
        stu_num = stu[0].replace("=", "").replace("\"", "")
        stu_name = stu[1].replace("\"", "").replace("=", "")
        for s in temp_total_student:
            is_signed_line = False
            if s["is_sign"]:
                continue
            if stu_num == s["id"]:
                s["is_sign"] = True
                is_signed_line = True
            if stu_name == s["name"]:
                s["is_sign"] = True
                is_signed_line = True

            if is_signed_line:
                total_signed += 1

    for data in temp_total_student:
        if not data['is_sign']:
            unsigned_stu.append(data)

    print(f"第 {times + 1} 实签: {total_signed} 总计: {total_num}")
    print("=======================================")
    print("未签:")
    for data in unsigned_stu:
        print(f"学号: {data['id']}, 姓名: {data['name']}")
    print("=======================================")
    times += 1




