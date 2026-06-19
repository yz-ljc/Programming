// JavaScript脚本

// 登录验证
function checkLogin() {
    let user = document.getElementById('username').value;
    let pass = document.getElementById('password').value;
    let userError = document.getElementById('user-error');
    let passError = document.getElementById('pass-error');
    let ok = true;

    if (user.length < 3) {
        userError.innerHTML = '用户名不能少于3个字符';
        userError.className = 'error';
        ok = false;
    } else if (user.length > 20) {
        userError.innerHTML = '用户名不能超过20个字符';
        userError.className = 'error';
        ok = false;
    } else {
        userError.innerHTML = '格式正确';
        userError.className = 'success';
    }

    if (pass.length < 6) {
        passError.innerHTML = '密码不能少于6个字符';
        passError.className = 'error';
        ok = false;
    } else {
        passError.innerHTML = '格式正确';
        passError.className = 'success';
    }

    if (ok) {
        alert('登录成功！');
    }
    return false;
}

// 注册验证
function checkRegister() {
    let user = document.getElementById('reg-username').value;
    let email = document.getElementById('reg-email').value;
    let pass = document.getElementById('reg-password').value;
    let pass2 = document.getElementById('reg-password2').value;
    let ok = true;

    let ue = document.getElementById('reg-user-error');
    if (user.length < 3) {
        ue.innerHTML = '用户名不能少于3个字符';
        ue.className = 'error';
        ok = false;
    } else {
        ue.innerHTML = '格式正确';
        ue.className = 'success';
    }

    let ee = document.getElementById('reg-email-error');
    if (email.indexOf('@') === -1 || email.indexOf('.') === -1) {
        ee.innerHTML = '邮箱格式不正确';
        ee.className = 'error';
        ok = false;
    } else {
        ee.innerHTML = '格式正确';
        ee.className = 'success';
    }

    let pe = document.getElementById('reg-pass-error');
    if (pass.length < 6) {
        pe.innerHTML = '密码不能少于6个字符';
        pe.className = 'error';
        ok = false;
    } else {
        pe.innerHTML = '格式正确';
        pe.className = 'success';
    }

    let p2e = document.getElementById('reg-pass2-error');
    if (pass !== pass2) {
        p2e.innerHTML = '两次密码不一致';
        p2e.className = 'error';
        ok = false;
    } else {
        p2e.innerHTML = '密码一致';
        p2e.className = 'success';
    }

    if (ok) {
        alert('注册成功！');
    }
    return false;
}

// 切换登录和注册
function showLogin() {
    document.getElementById('login-form').style.display = 'block';
    document.getElementById('register-form').style.display = 'none';
    document.getElementById('tab-login').className = 'active-tab';
    document.getElementById('tab-register').className = '';
}

function showRegister() {
    document.getElementById('login-form').style.display = 'none';
    document.getElementById('register-form').style.display = 'block';
    document.getElementById('tab-login').className = '';
    document.getElementById('tab-register').className = 'active-tab';
}

// 展开和收起内容
function toggleContent(id) {
    let el = document.getElementById(id);
    if (el.style.display === 'none' || el.style.display === '') {
        el.style.display = 'block';
    } else {
        el.style.display = 'none';
    }
}

// 页面加载
window.onload = function() {
    const welcome = document.getElementById('welcome-msg');
    if (welcome) {
        let hour = new Date().getHours();
        let msg = '';
        if (hour < 9) {
            msg = '早上好！';
        } else if (hour < 12) {
            msg = '上午好！';
        } else if (hour < 14) {
            msg = '中午好！';
        } else if (hour < 18) {
            msg = '下午好！';
        } else {
            msg = '晚上好！';
        }
        welcome.innerHTML = msg + ' 欢迎浏览旅游推荐网';
    }
};

// banner文字切换
let i = 0;
const texts = ['探索世界之美', '畅游天下名胜', '背上行囊去远方', '每一段旅程都值得'];

function changeBanner() {
    const b = document.getElementById('banner-text');
    if (b) {
        i = (i + 1) % texts.length;
        b.innerHTML = texts[i];
    }
}

setInterval(changeBanner, 3000);

// 表格行点击高亮
function highlightRow(row) {
    const rows = document.getElementsByTagName('tr');
    for (let j = 0; j < rows.length; j++) {
        rows[j].classList.remove('row-highlight');
    }
    row.classList.add('row-highlight');
}

// 点赞
let likeCount = 0;

function addLike() {
    likeCount++;
    document.getElementById('like-count').innerHTML = likeCount;
}
