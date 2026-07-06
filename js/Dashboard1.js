//this IP will be changed every place its local ip for your esp 
// you must check every time //
const ESP_IP=""
var frequency = 0;
var amplitude = 0;
var status = "Waiting";

function openDashboard(id){
 
 
    window.location.href = "Dashboard" + id + ".html";

    // var xhttp = new XMLHttpRequest();
    // xhttp.open("GET","/Dashboard?id="+id,true);
    // xhttp.send();

}

function getSpectrum() {

    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function () {
     // Check that the request is complete and the server responded successfully

        if (this.readyState == 4 && this.status == 200) {

            document.getElementById("value").innerHTML = this.responseText;
            document.getElementById("frequency").innerHTML = frequency;
            document.getElementById("amplitude").innerHTML = amplitude;
            document.getElementById("status").innerHTML = status;
        }

    };

    xhttp.open("GET",ESP_IP+ "/spectrum", true);

    xhttp.send();
}

getSpectrum();
// كرر القراءة كل ثانية
setInterval(getSpectrum, 1000);


function sendName() {

    var name = document.getElementById("txt").value;

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", ESP_IP+"/name?user=" + encodeURIComponent(name), true);

    xhttp.send();

}
