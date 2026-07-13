function signIn() {

    const name = document.getElementById("username").value.trim();

    if(name === "")
    {
        alert("Please enter your name");
        return;
    }

    document.getElementById("welcome").innerHTML = "Hi, " + name + " 👋";

}
window.onload = function(){

    const name = localStorage.getItem("username");

    if(name)
    {
        document.getElementById("welcome").innerHTML = "Hi, " + name + " 👋";
    }

}
