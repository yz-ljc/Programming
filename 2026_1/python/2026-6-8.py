import os

dir = "./data/daily"
sign_files = [f for f in os.listdir(dir) if f.endswith(".csv")]

content = []
for file in sign_files:
    with open(os.path.join(dir, file), "r", encoding="utf-8") as f:
        content.append(f.readlines())

with open("./data/total.csv", "r", encoding="utf-8") as f:
    total = f.readlines()

total_student = []
for t in total[1:]:
    stu = t.strip().split(",")
    total_student.append({
        "id": stu[1],
        "name": stu[2],
        "sex": stu[3],
        "class": stu[4],
        "unsigned_times": 0
    })

for day, day_content in enumerate(content):
    signed_ids = set()

    for line in day_content[1:]:  # 跳过标题行
        line = line.strip()
        if not line:
            continue
        stu = line.split(",")
        if len(stu) < 2:
            continue

        stu_num = stu[0].replace("=", "").replace("\"", "").strip()
        signed_ids.add(stu_num)

    unsigned_stu = []
    for student in total_student:
        if student["id"] not in signed_ids:
            student["unsigned_times"] += 1
            unsigned_stu.append(student)

    print(f"第 {day + 1} 天 实签: {len(signed_ids)} 总计: {len(total_student)}")
    print("=======================================")
    if unsigned_stu:
        print("未签:")
        for data in unsigned_stu:
            print(f"学号: {data['id']}, 姓名: {data['name']}")
    else:
        print("全员签到！")
    print("=======================================")

print("\n缺勤统计：")
print("=======================================")
for student in total_student:
    if student["unsigned_times"] > 0:
        print(f"学号: {student['id']}, 姓名: {student['name']}, 缺勤次数: {student['unsigned_times']}")