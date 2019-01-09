function clickLink() {
    $('#username').val($(this).html());
    return false;
}

function makeError() {
    var pattern = /^[a-zA-Z]+$/;
    var lastname = $('#lastname').val();
    var firstname = $('#firstname').val();
    $('.error').remove();
    $('#userlinks').remove();
    $('#username').val("");
    var lok = false, fok = false;
    if (!pattern.test(lastname)) {
        $('#lastname_div').css({ 'background-color': 'red' });
        $('#lastname_div').append('<p class="error"> Csak az angol abc betűit lehet használni!</p>');
    }
    else {
        $('#lastname_div').css({ 'background-color': 'lightgray' });
        lok = true;
    }
    if (!pattern.test(firstname)) {
        $('#firstname_div').css({ 'background-color': 'red' });
        $('#firstname_div').append('<p class="error"> Csak az angol abc betűit lehet használni!</p>');
    }
    else {
        $('#firstname_div').css({ 'background-color': 'lightgray' });
        fok = true;
    }
    if (lok && fok) {
        $('#username_div').append('<p id="userlinks"></p>');
        var advices = [firstname + lastname, firstname[0] + lastname, firstname[0] + lastname[0]];
        for (var i in advices) {
            $('#userlinks').append('<a class="userlink" href="">' + advices[i] + '</a>, ');
        }
        $('.userlink').on('click', clickLink);
    }
}

$(function () {
    $(document).on('keyup', makeError);
});