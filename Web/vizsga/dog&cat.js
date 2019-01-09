var cats = 0;

$(function () {
    $('#image').on('mouseenter', function () {
        this.src = "cat.png";
        $('#cats').html('Macskák száma: ' + ++cats);
    });
    $('#image').on('mouseleave', function () {
        this.src = "dog.jpg";
    });
});