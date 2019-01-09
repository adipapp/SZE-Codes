var lista = [];

function kattint() {
    var rendszam = $('#rendszam').val();
    var pattern = /[A-Z]{3}[0-9]{3}/;
    if (!pattern.test(rendszam)) {
        window.alert("Helytelen a rendszám formátuma!");
        return;
    }
    var i = lista.indexOf(rendszam);
    if (i < 0) {
        if (lista.length < 10) lista.push(rendszam);
        else window.alert("Tele a parkoló! :(");
    }
    else lista.splice(i, 1);
    $('#szabad').val(10 - lista.length);
    var content = '';    
    for (var j in lista) {
        content += lista[j];
        content += '<br/>';
    }
    $('#eddigi').html(content);
}

$(function () {
    $('#ok').on('click', kattint);
});