function Book(name, author, price, date, category) {
    this.name = name;
    this.author = author;
    this.price = price;
    this.date = date;
    this.category = category;
}

const books = [
    new Book('三体：黑暗森林', '刘慈欣', 68.00, 2008, '科幻'),
    new Book('人类群星闪耀时', '斯蒂芬·茨威格', 52.00, 2019, '历史'),
    new Book('深度学习入门', '斋藤康毅', 89.00, 2021, '科技'),
    new Book('百年孤独', '加西亚·马尔克斯', 55.00, 1967, '文学'),
    new Book('人工智能导论', '周志华', 79.00, 2020, '科技'),
    new Book('活着', '余华', 45.00, 1993, '文学'),
    new Book('碳中和时代', '王毅', 98.00, 2022, '科学'),
    new Book('人类简史', '尤瓦尔·赫拉利', 68.00, 2014, '历史'),
    new Book('Python编程入门', '埃里克·马瑟斯', 72.00, 2021, '科技'),
    new Book('红楼梦', '曹雪芹', 89.00, 1791, '文学')
];

function getBooksByYear(year) {
    let arr = [];
    books.forEach(book => {
        if (book.date >= year) {
            arr.push(book);
        }
    })
    return arr;
}

function getBooksByCategory() {
    let amount = {};
    books.forEach(book => {
        if (Object.keys(amount).includes(book.category)) {
            amount[book.category]++;
        } else {
            amount[book.category] = 1;
        }
    })
    console.log("各类别图书数量如下: ");
    for (let i of Object.keys(amount)) {
        console.log("类别 " + i + " 的图书数量为: " + amount[i]);
    }
}

function getPrice() {
    books.sort(function (a, b) {
        return a.price - b.price;
    })
    console.log("按价格从低到高排序的图书如下: ");
    console.log("最低价: " + books[0].name + " " + books[0].price);
    console.log("最高价: " + books[books.length - 1].name + " " + books[books.length - 1].price);
}

let booksList = getBooksByYear(2020);
console.log("按年份筛选后如下: ");
for (let i = 0; i < booksList.length; i++) {
    console.log(booksList[i].name + " " + booksList[i].date);
}
getBooksByCategory();
getPrice();