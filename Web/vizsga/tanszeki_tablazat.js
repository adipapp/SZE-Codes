$(function () {
    var szamok = window.prompt("Adjon meg néhány nemnegatív egész számot szóközökkel tagolva!").split(' ');
    for (var i in szamok) {
        if (!isNaN(szamok[i]) && parseFloat(szamok[i]) % 1 == 0 && parseInt(szamok[i])>=0) szamok[i] = parseInt(szamok[i]);
        else {
            $('#szamok').html('Hibás input!!!');
            return;
        }
    }
    $('#szamok').html(szamok.sort(function (a, b) { return parseInt(a) - parseInt(b); }).join(' '));
});