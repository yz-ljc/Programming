let sales: number = 123_456_789;
let course: string = "TypeScript";
let is_published: boolean = true;
function render(document: any) {

}
let numbers: Array<number> = [1, 2, 3, 4, 5];
let numbers_2: number[] = [1, 2, 3, 4, 5];
numbers_2.forEach(t => console.log(t.toString()));

let nums: [string, number, number] = ["1", 2, 3];

// const small = 1;
// const medium = 2;
// const large = 3;

enum Size {
    Small, Medium, Large,
}

let mySize: Size = Size.Medium;
console.log(mySize);

function calc(income: number): number {
    return 0;
}