function Employee(name, salary, department) {
    this.name = name;
    this.salary = salary;
    this.department = department;
}

let employees = [
    new Employee("John", 8000, "IT"),
    new Employee("John", 6000, "HR"),
    new Employee("Alice", 5500, "Finance"),
    new Employee("Bob", 4800, "IT"),
    new Employee("Charlie", 6500, "Marketing"),
    new Employee("Diana", 7200, "HR"),
    new Employee("Eve", 10000, "Finance"),
    new Employee("Frank", 12000, "IT"),
    new Employee("Ivy", 19000, "Finance"),
    new Employee("Jack", 5800, "Marketing")
];

function showSalaryLevel() {
    console.log("======== 员工工资等级 ========")
    employees.forEach(employee => {
        let level
        if (employee.salary >= 15000) {
            level = "高薪"
        } else if (employee.salary >= 10000) {
            level = "中等"
        } else if (employee.salary >= 6000) {
            level = "普通"
        } else {
            level = "偏低"
        }
        console.log("员工 " + employee.name + " 的工资等级为" + level + "，工资为：" + employee.salary.toFixed(0))
    })
}

function addSalary() {
    employees.forEach(employee => {
        employee.salary = employee.salary * 1.1;
        if (employee.salary > 20000) {
            employee.salary = 20000
        }
    })
}

function calculateAverageSalary() {
    let total = 0;
    employees.forEach(employee => {
        total += employee.salary;
    })
    console.log("员工的平均工资为：" + (total / employees.length).toFixed(2));
}

function calculateDepartments() {
    let departments = {};
    employees.forEach(employee => {
        let department = employee.department;
        if (Object.keys(departments).includes(department)) {
            departments[department]++;
        } else {
            departments[department] = 1;
        }
    })
    console.log("各部门情况如下: ")
    for (const i of Object.keys(departments)) {
        console.log("部门" + i + "的人数为: " + departments[i])
    }
}

showSalaryLevel();

addSalary();

showSalaryLevel();

calculateAverageSalary();

calculateDepartments();
