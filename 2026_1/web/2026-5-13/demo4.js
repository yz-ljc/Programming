function getGPA(score) {
    if (score >= 90) return 4.0;
    else if (score >= 85) return 3.5;
    else if (score >= 80) return 3.0;
    else if (score >= 75) return 2.5;
    else if (score >= 70) return 2.0;
    else if (score >= 65) return 1.5;
    else if (score >= 60) return 1.0;
    else return 0.0;
}

console.log("成绩为95分，绩点为" + getGPA(95));
console.log("成绩为82分，绩点为" + getGPA(82));
console.log("成绩为76分，绩点为" + getGPA(76));
console.log("成绩为68分，绩点为" + getGPA(68));
console.log("成绩为59分，绩点为" + getGPA(59));