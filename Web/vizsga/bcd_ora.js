$(function () {
    setInterval(function () {
        var time = new Date();
        var hours = time.getHours();
        var minuntes = time.getMinutes();
        var seconds = time.getSeconds();
        $('#ora').html((hours < 10 ? '0' + hours : hours) + ':' +
            (minuntes < 10 ? '0' + minuntes : minuntes) + ':' + (seconds < 10 ? '0' + seconds : seconds));
        var pieces = [Math.floor(hours / 10), Math.floor(hours % 10), Math.floor(minuntes / 10),
            Math.floor(minuntes % 10), Math.floor(seconds / 10), Math.floor(seconds % 10)];
        var tbody = $('tbody');
        tbody.empty();
        for (var i = 8; i > 0; i = Math.floor(i / 2)) {
            tbody.append('<tr></tr>');
            for (var j = 0; j < 6; j++) {
                if (Math.floor(pieces[j] / i) > 0) {
                    tbody.append('<td style="background-color:red">1</td>');
                    pieces[j] -= i;
                }
                else tbody.append('<td>0</td>');
            }
        }
        
    }, 1000);
});