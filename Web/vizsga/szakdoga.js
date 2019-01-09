function jegyHataroz(osszpont, bukta) {
    var jegy = "";
    if (bukta || osszpont <= 25) jegy = "elégtelen (1)";
    else if (osszpont >= 26 && osszpont <= 30) jegy = "elégséges (2)";
    else if (osszpont >= 31 && osszpont <= 37) jegy = "közepes (3)";
    else if (osszpont >= 38 && osszpont <= 44) jegy = "jó (4)";
    else jegy = "jeles (5)";
    $('#jegy').text(jegy);
}

function pontSzamol() {
    var pontok = $("input[type=number]");
    var osszpont = 0;
    var bukta = false;
    for (var i = 0; i < pontok.length; i++) {
        osszpont += parseInt(pontok[i].value);
        if (pontok[i].value == 0) bukta = true;
    }
    $('#osszpont').text(osszpont);
    jegyHataroz(osszpont, bukta);
}

$(function () {
    $("input[type=number]").on('change', pontSzamol);
    pontSzamol();
});