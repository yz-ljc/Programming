let a = 0;
let b = 'c';
let c = 0;
let d = 1e+43;

function fuc1() {
    console.log("Hello World!");
}

console.log(b, typeof b);
console.log(typeof c);
console.log(typeof d);
console.log(d + 1);

function onClicked() {
    document.getElementById("clicked").innerHTML = "Hello World";
    console.log("Clicked!");
}

for (let i = 0; i < 10; i++) {
    console.log(i);
}
let num = 0;
while (true) {
    num++;
    if (num === 10) break;
    console.log(num);
}