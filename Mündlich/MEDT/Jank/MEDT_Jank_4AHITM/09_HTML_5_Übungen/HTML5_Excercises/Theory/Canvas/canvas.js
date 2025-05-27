let canvas = document.getElementById("canvas");

let ctx = canvas.getContext("2d");

ctx.fillStyle = "rgb(200,0,0)";
ctx.fillStyle =  "rgba(0, 0, 200, 0.5)";
ctx.fillStyle = "rgba(0,0,200, 0.5)";
ctx.fillRect(30, 30, 55, 50);

let intRed = 255;

for (let i = 1; i <= 16; i++)
{
    ctx.rotate( (1/8) * Math.PI);
    ctx.fillStyle = "rgb(" + (intRed - i * 10) + ", 0, 0)";
    ctx.fillRect(0, 0, 40, 40);
}


function draw()
{
    let ctx = document.getElementById('canvas').getContext('2d');
    ctx.fillRect(0, 0, 300, 300);

    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            ctx.save();
            ctx.strokeStyle = "#9CFF00";
            ctx.translate(50 + j * 100, 50 + i * 100);
            drawSpirograph(ctx, 20 * (j + 2) / (j + 1), -8 * (i + 3) / (i + 1), 10);
            ctx.restore();
        }
    }
}

function drawSpirograph(ctx, R, r, o) {
    var x1 = R - o;
    var y1 = 0;
    var i = 1;
    ctx.beginPath();
    ctx.moveTo(x1, y1);

    do {
        if (i > 20000) break;

        var x2 = (R + r) * Math.cos(i * Math.PI / 72) - (r + o) * Math.cos(((R + r) / r) * (i * Math.PI / 72));
        var y2 = (R + r) * Math.sin(i * Math.PI / 72) - (r + o) * Math.sin(((R + r) / r) * (i * Math.PI / 72));

        ctx.lineTo(x2, y2);

        x1 = x2;
        y1 = y2;

        i++;
    } while (x2 !== R - o || y2 !== 0);

    ctx.stroke();
}


draw()