let check = document.getElementById("check");
let serverInput = document.getElementById("server");
let serverName = document.getElementById("resultName");
let status = document.getElementById("resultStatus");
let resultPlayers = document.getElementById("resultPlayers");
let resultArea = document.getElementById("result");

function Server(name, status, players) {
    this.name = name;
    this.status = status;
    this.players = players;
}

let serverList = [
    new Server("lobby", "在线", 15),
    new Server("mini1A", "在线", 8),
    new Server("mega1A", "维护中", 0),
    new Server("limbo", "离线", 0)
];

function getServerByName(name) {
    return serverList.find(server => server.name === name) || null;
}

check.addEventListener("click", () => {
    let inputName = serverInput.value.trim();

    let serverNameList = serverList.map(server => server.name);

    if (serverNameList.includes(inputName)) {
        let tmpServer = getServerByName(inputName);
        if (tmpServer != null) {
            serverName.innerText = "服务器: " + tmpServer.name;
            status.innerText = "状态: " + tmpServer.status;
            resultPlayers.innerText = tmpServer.players;
            resultArea.style.display = "block";
        } else {
            serverName.innerText = "服务器: " + "无效";
            status.innerText = "状态: " + "无效";
            resultPlayers.innerText = "无效的服务器标识，请重新输入！";
            resultArea.style.display = "block";
        }
    } else {
        serverName.innerText = "服务器: " + "无效";
        status.innerText = "状态: " + "无效";
        resultPlayers.innerText = "无效的服务器标识，请重新输入！";
        resultArea.style.display = "block";
    }
});