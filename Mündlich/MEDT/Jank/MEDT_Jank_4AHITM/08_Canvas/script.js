let canvas = document.getElementById("canvas");

let context = canvas.getContext("2d");

context.fillStyle = "rgb(200,0,0)";
context.fillRect(10,10,55,50);
context.fillStyle = "rgba(0,0,200,05)";
context.fillRect(30, 30, 55, 50);


let intRed = 255;


function rotateRect()
{
    context.clearRect(0, 0, 40, 40);
    context.rotate((1/8) * Math.PI);
    context.fillStyle = "rgb(" + (intRed - i * 10) + ", 0, 0)";
    context.fillRect(0,0, 40, 40);

    requestAnimationFrame(rotateRect);
}

rotateRect();
requestAnimationFrame(rotateRect);
