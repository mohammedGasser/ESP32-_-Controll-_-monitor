//this IP will be changed every place its local ip for your esp 
// you must check every time //
 
const canvas=document.getElementById("canvas");
const ctx=canvas.getContext("2d");

function draw(){
 
ctx.clearRect(0,0,canvas.width,canvas.height);

let bars=50;

for(let i=0;i<bars;i++){

let h=Math.random()*180;

ctx.fillStyle=`rgb(${50+i*4},255,255)`;

ctx.fillRect(
i*20+8,
220-h,
14,
h
);

}

requestAnimationFrame(draw);

}

draw();

// setInterval(draw, 100); 

const ESP_IP = "http://192.168.1.3";
// var frequency = 0;
// var amplitude = 0;
// var status = "Waiting";

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
            console.log(this.responseText);
            const data = JSON.parse(this.responseText)
            document.getElementById("value").innerHTML = data.value;
            document.getElementById("frequency").innerHTML = data.frequency;
            document.getElementById("amplitude").innerHTML = data.amplitude;
            document.getElementById("status").innerHTML = data.status;
        }

    };

    xhttp.open("GET",ESP_IP+ "/Dashboard1", true);

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
