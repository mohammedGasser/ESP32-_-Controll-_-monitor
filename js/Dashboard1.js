function openDashboard(id){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET","/dashboard?id="+id,true);

    xhttp.send();

}

function getSpectrum() {

    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function () {

        if (this.readyState == 4 && this.status == 200) {

            document.getElementById("value").innerHTML = this.responseText;

        }

    };

    xhttp.open("GET", "/spectrum", true);

    xhttp.send();
}

getSpectrum();
// كرر القراءة كل ثانية
setInterval(getSpectrum, 1000);


function sendName() {

    var name = document.getElementById("txt").value;

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/name?user=" + encodeURIComponent(name), true);

    xhttp.send();

}