var beers = [{ name: 'Aladár', part: 0 }, { name: 'Béla', part: 0 }, { name: 'Cili', part: 0 }, { name: 'Dezső', part: 0 }, { name: 'Eleonóra', part: 0 }];
var lastdate;

function addRow() {
    var options = { year: 'numeric', month: 'numeric', day: 'numeric' };
    var lastTr = $('#lastLine');
    var result = $('#result');
    result.empty();
    lastTr.before('<tr></tr>');
    if (lastdate === undefined) lastdate = new Date();
    else lastdate.setDate(lastdate.getDate() + 7);
    lastTr.before('<td>' + lastdate.toLocaleDateString('hu-HU', options) + '</td>');
    for (var i in beers) {
        if ($('.chkbox')[i].checked) {
            beers[i].part++;
            lastTr.before('<td>X</td>');
        }
        else lastTr.before('<td></td>');
        result.html(result.html() + beers[i].name + ':' + Math.floor(beers[i].part / 5) + ' ');
    }
}

$(function () {
    $('#addRow').on('click', addRow);
});