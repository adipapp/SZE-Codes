window.onkeyup = function () {
    var postcode = document.getElementById("postcode").value;
    var select = document.getElementById("select");
    while (select.firstChild) {
        select.removeChild(select.firstChild);
    }
    if (postcode.length == 4) {
        for (var i in irsz) {
            if (irsz[i][0] == parseInt(postcode)) {
                var option = document.createElement("option");
                option.text = irsz[i][1];
                select.add(option);
            }
        }
    }
}
