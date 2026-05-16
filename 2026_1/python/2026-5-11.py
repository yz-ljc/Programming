class Student:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def get_score(self):
        return self.score

    def display_stu(self):
        print(self.name + " " + str(self.score))

stu1 = Student("AAA", 1)
stu1.display_stu()

stu2 = Student("BBB", 2)
stu2.display_stu()