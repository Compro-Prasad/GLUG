let c = document.getElementById("test");
let canvas = document.createElement('canvas');
h = canvas.height = 200;
w = canvas.width = 650;
c.appendChild(canvas);
let ctx = canvas.getContext("2d");

ctx.fillStyle = "#222";
ctx.fillRect(0, 0, w, h);
function createCircle(height, width, radius = 10, fillColor = "yellow",
                      strokeColor = "yellow", fill = true, stroke = true) {
    ctx.beginPath();
    ctx.arc(width, height, radius, 0, 2*3.14159, false);
    if (fill) {
        ctx.fillStyle = fillColor;
        ctx.fill();
    }
    if (stroke) {
        ctx.strokeStyle = strokeColor;
        ctx.lineWidth = 2;
        ctx.stroke();
    }
}

function createIsoscelesTriangle(x, y, height, width, angle, color) {
    let midx = x + height * Math.cos(angle);
    let midy = y + height * Math.sin(-angle);
    let x1 = midx + width / 2 * Math.cos(angle + Math.PI / 2);
    let y1 = midy + width / 2 * Math.sin(angle - Math.PI / 2);
    let x2 = midx + width / 2 * Math.cos(angle - Math.PI / 2);
    let y2 = midy + width / 2 * Math.sin(angle + Math.PI / 2);
    ctx.beginPath();
    ctx.fillStyle = color;
    ctx.strokeStyle = "yellow";
    ctx.lineWidth = 2;
    ctx.moveTo(x, y);
    ctx.lineTo(x1, y1);
    ctx.lineTo(x2, y2);
    ctx.lineTo(x, y);
    ctx.closePath();
    ctx.fill();
}

// createIsoscelesTriangle(50, 50, 15, 8, Math.PI/180 * 39, "yellow");
function createArrow(x1, y1, x2, y2) {
    createIsoscelesTriangle(x2, y2, 10, 8,
                            Math.atan((y2 - y1) / (x2 - x1)), "lightblue");
    ctx.beginPath();
    ctx.strokeStyle = "lightblue";
    ctx.lineWidth = 1;
    ctx.moveTo(x1, y1);
    ctx.lineTo(x2, y2);
    ctx.stroke();
}

for (let i = 0; i < 9; i++) {
    createCircle(100, 40 + i * 70, 11);
}

for (let i = 1; i < 9; i++) {
    createArrow(30 + i * 70, 100, 50 + (i - 1) * 70, 100);
}
