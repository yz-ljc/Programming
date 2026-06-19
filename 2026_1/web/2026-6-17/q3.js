function Good(name, price, amount, category) {
    this.name = name;
    this.price = price;
    this.amount = amount;
    this.category = category;
}

let goods = [
    new Good("苹果", 6.5, 50, "食品类"),
    new Good("面包", 12.8, 30, "食品类"),
    new Good("牛奶", 15.0, 40, "食品类"),
    new Good("方便面", 4.5, 100, "食品类"),
    new Good("Java编程思想", 99.0, 15, "图书类"),
    new Good("三体", 68.0, 25, "图书类"),
    new Good("新华字典", 39.9, 10, "图书类"),
    new Good("笔记本", 22.5, 60, "其他类"),
    new Good("保温杯", 89.0, 20, "其他类"),
    new Good("充电宝", 129.0, 18, "其他类")
];

function calcMoney() {
    console.log("====== 消费情况 ======")
    goods.forEach(item => {
        let money = item.price * item.amount;
        console.log(item.amount + ": " + money);
    })
}

function discount() {
    goods.forEach(item => {
        switch (item.type) {
            case "食品类" :
                item.price = item.price * 0.9;
                break;
            case "图书类":
                item.price = item.price * 0.85;
                break;
            default:
                break;
        }
    })
}

function discountAll(money) {
    return money * 0.9;
}

function checkout() {
    let total = 0;
    goods.forEach(item => {
        total += item.price * item.amount;
    })

    if (total > 1000) {
        total = discountAll(total);
    }
    console.log("总消费: " + total);
}

calcMoney();
discount();
checkout();
