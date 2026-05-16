function isYear(year) {
    return year % 400 === 0 || (year % 4 === 0 && year % 100 !== 0);
}

function display(year) {
    if (isYear(year)) {
        console.log(year + "是闰年");
    } else {
        console.log(year + "不是闰年");
    }
}

display(2000);
display(2024);
display(2025);
display(2026);