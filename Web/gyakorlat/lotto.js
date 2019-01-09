function sorsol() {
    var szamok = [];
    var i = 0;

    while (i != 5) {
        var voltmar = false;
        var temp = (1 + Math.random() * 90).toFixed();
        for (var j = 0; j < szamok.length && !voltmar; j++) {
            if (szamok[j] == temp) voltmar = true;
        }
        if (!voltmar) {
            szamok[i] = parseInt(temp);
            i++;
        }
    }
    document.getElementById("szamok").innerHTML = szamok.sort(function (a, b) {
        var aa = +a;
        var bb = +b;
        return a - b;
    });
}
