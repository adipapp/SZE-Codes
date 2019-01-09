function modifyResults() {
    var zh1 = parseInt($(this).find('.zh1').val());
    var zh1p = parseInt($(this).find('.zh1p').val());
    var zh2 = parseInt($(this).find('.zh2').val());
    var zh2p = parseInt($(this).find('.zh2p').val());
    var sumPoints = zh1 > zh1p ? zh1 : zh1p;
    $(this).find('.ossz').html(sumPoints += zh2 > zh2p ? zh2 : zh2p);
    if (sumPoints >= 6) {
        $(this).find('.alairas').html('aláírva');
        $(this).find('.alairas').attr('class', 'alairas green');
    }
    else {
        $(this).find('.alairas').html('megtagadva');
        $(this).find('.alairas').attr('class', 'alairas red');
    }
    switch (sumPoints) {
        case 11:
        case 12:
            $(this).find('.megajanlott').html(4);
            $(this).find('.megajanlott').attr('class', 'megajanlott green');
            break;
        case 13:
        case 14:
            $(this).find('.megajanlott').html(5);
            $(this).find('.megajanlott').attr('class', 'megajanlott green');
            break;
        default:
            $(this).find('.megajanlott').html('-');
            $(this).find('.megajanlott').attr('class', 'megajanlott red');
            break;
    }
}

function addRow() {
    var newObj = $('tr:last').clone();
    newObj.find('input[type="text"]').val("");
    newObj.find('input[type="number"]').val(0);
    newObj.find('.ossz, .alairas, .megajanlott').html("");
    newObj.on('change', modifyResults);
    $('tbody').append(newObj);
}

$(function () {
    $('tr').on('change', modifyResults);
    $('#add').on('click', addRow);
});