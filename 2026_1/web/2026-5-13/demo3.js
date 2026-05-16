function calEvenNum(arr) {
    let total = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] % 2 === 0) {
            total++;
        }
    }
    return total;
}

let result = calEvenNum([2, 3, 13, 24, 8, 17, 40]);

console.log("共有" + result + "个偶数");