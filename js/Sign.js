function signIn() {
    const name = document.getElementById("username").value.trim();

    if (name === "") {
        alert("Please enter your name");
        return;
    }

    localStorage.setItem("username", name);
    document.getElementById("welcome").innerHTML = "Hi, " + name + " 👋";
}

function sendName() {
    const text = document.getElementById("txt").value;

    console.log(text);

    // هنا هتبعت القيمة للـ ESP32
    // fetch("/send?msg=" + text);
}
