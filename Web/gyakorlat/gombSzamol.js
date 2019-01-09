function szamol() {
    var r = parseFloat(document.getElementById("radius").value);
    var A = 4 * Math.pow(r, 2) * Math.PI;
    var V = A * r / 3;
    document.getElementById("surface").value = A;
    document.getElementById("volume").value = V;
    return false;
}

function init() {
    var urlap = document.getElementById("urlap");
    urlap.onsubmit = szamol;
}

window.onload = init;