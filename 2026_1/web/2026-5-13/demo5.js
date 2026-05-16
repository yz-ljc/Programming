function getPrime(num1, num2) {
    for (let i = num1; i <= num2; i++) {
        let str = isPrime(i) ? "是" : "不是";
        console.log(i + str + "素数");
    }
}

function isPrime(num) {
    if (num === 1) return false;
    if (num === 2) return true;
    if (num % 2 === 0) return false;
    if (num <= 0) return false;
    for (let i = 3; i < num; i += 2) {
        if (num % i === 0) return false;
    }
    return true;
}

getPrime(1, 100);