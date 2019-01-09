function jelszo() {
    var password = document.getElementById("password").value;
    var lowerLetter = 0, upperLetter = 0, number = 0, other = 0;
    for (var i = 0; i < password.length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') lowerLetter++;
        else if (password[i] >= 'A' && password[i] <= 'Z') upperLetter++;
        else if (password[i] >= '0' && password[i] <= '9') number++;
        else other++;
    }
    var sum = (lowerLetter == 0 ? 0 : (lowerLetter + 5)) + (upperLetter == 0 ? 0 : (upperLetter + 5)) + 
        (number == 0 ? 0 : (number + 5)) + (other == 0 ? 0 : (other + 5));
    var value = "";
    if (sum < 10 && sum > 0) value = "Gyenge";
    else if (sum >= 11 && sum < 20) value = "Közepes";
    else if (sum >= 20) value = "Erõs";
    else value = "Hiba";
    document.getElementById("strength").innerHTML = value;
}

function init() {
    document.getElementById("password").onchange = jelszo;
}

window.onload = init;