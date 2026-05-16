function getNums(arr) {
    let max = arr[0];
    let min = arr[0];
    let total = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        total += arr[i];
    }
    console.log("最大数值为" + max);
    console.log("最小数值为" + min);
    console.log("平均数为" + total / arr.length);
}

getNums([12, 5, 99, 34, 1, 67]);
