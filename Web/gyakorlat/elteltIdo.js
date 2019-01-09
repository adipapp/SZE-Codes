function elteltIdo() {
    var hour = parseInt(document.getElementById("hour").value);
    var min = parseInt(document.getElementById("minute").value);
    
    var actHour = new Date().getHours();
    var actMin = new Date().getMinutes();

    var elapsed = (hour * 60 + min) - (actHour * 60 + actMin);
    var elapsedHour = parseInt(elapsed / 60);
    var elapsedMin = parseInt(elapsed) % 60;
    var towrite = elapsedMin >= 10 ? elapsedMin.toString() : ('0' + elapsedMin.toString());
    document.getElementById("result").value = elapsed < 0 ? 'Kesobbi datumot!' : (elapsedHour.toString() + ':' + towrite);
}

function init() {
    document.getElementById("calculate").onclick = elteltIdo;
}

window.onload = init();