student_list = [
    ["2026001", "张三"],
    ["2026002", "李四"],
    ["2026003", "王五"],
    ["2026004", "赵六"],
    ["2026005", "孙七"]
]

attend1 = [
    ["2026001", "2026-06-01", "正常出勤"],
    ["2026002", "2026-06-01", "迟到"],
    ["2026003", "2026-06-01", "缺勤"],
    ["2026001", "2026-06-01", "正常出勤"],
    ["2026004", "2026-06-01", "正常出勤"],
    ["2026005", "2026-06-01", "请假"]
]

attend2 = [
    ["2026001", "2026-06-02", "正常出勤"],
    ["2026002", "2026-06-02", "正常出勤"],
    ["2026003", "2026-06-02", "迟到"],
    ["2026004", "2026-06-02", "缺勤"],
    ["2026002", "2026-06-02", "正常出勤"]
]

attend3 = [
    ["2026001", "2026-06-03", "迟到"],
    ["2026002", "2026-06-03", "缺勤"],
    ["2026003", "2026-06-03", "正常出勤"],
    ["2026005", "2026-06-03", "正常出勤"],
    ["2026004", "2026-06-03", "迟到"]
]

list_students_data = {}


for v in student_list:
    if v[0] is not None:
        list_students_data[v[0]] = {
            "uin": v[0],
            "name": v[1],
            "appended_times": 0,
            "absent_times": 0,
            "late_times": 0,
            "leave_times": 0
        }

attends = attend1 + attend2 + attend3

recorded = set()

for v in attends:
    t_uin = v[0]
    t_date = v[1]
    t_status = v[2]

    key = (t_uin, t_date)
    if key in recorded:
        continue

    if t_uin in list_students_data:
        if t_status == "正常出勤":
            list_students_data[t_uin]["appended_times"] += 1
        elif t_status == "迟到":
            list_students_data[t_uin]["late_times"] += 1
        elif t_status == "缺勤":
            list_students_data[t_uin]["absent_times"] += 1
        elif t_status == "请假":
            list_students_data[t_uin]["leave_times"] += 1
    recorded.add(key)

list_final_data = list(list_students_data.values())

print("-" * 60)
print("学号\t\t\t姓名\t出勤\t缺勤\t迟到\t请假\t出勤率\t考勤次数")

for v in list_final_data:
	print(f"{v["uin"]}\t\t{v["name"]}\t{v["appended_times"]}\t{v["absent_times"]}\t{v["late_times"]}\t{v["leave_times"]}\t{(v["appended_times"] / (v["appended_times"] + v["leave_times"] + v["absent_times"] + v["late_times"])) * 100:.2f}%\t{v["appended_times"] + v["leave_times"] + v["absent_times"] + v["late_times"]}")