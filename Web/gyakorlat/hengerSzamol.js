function szamol() {
    var r = parseFloat(document.getElementById("radius").value);
    var h = parseFloat(document.getElementById("height").value);
    var A = 2 * r * Math.PI * (h + r);
    var V = Math.pow(r, 2) * Math.PI * h;
    document.getElementById("surface").value = A;
    document.getElementById("volume").value = V;
    return false;
}

function init() {
    var urlap = document.getElementById("urlap");
    urlap.onsubmit = szamol;
}

window.onload = init;