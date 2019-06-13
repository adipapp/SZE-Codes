<?php declare (strict_types=1); ?>
<!DOCTYPE html>
<html>
    <title>Munkatársak</title>
    <head>
        <link rel="stylesheet" type="text/css" href="style.css">
        <meta charset="utf-8">
    </head>
<body>
    <h1> Munkatársak </h1>   

<?php
$munkatarsak = [
    $bp = [
    "Név" => "Dr. Baranyi Péter Zoltán",
    "Beosztás" => "egyetemi tanár",
    "Szobaszám" => "A604",
    "E-mail cím" => "baranyi.peter@sze.hu",
    "Telefonszám" => array("+36 (96) 613-521", "3521")
    ],

    $csa = [
        "Név" => "Dr. Csapó Ádám Balázs",
        "Beosztás" => "egyetemi docens",
        "Szobaszám" => "A605",
        "E-mail cím" => "csapo.adam@sze.hu",
        "Telefonszám" => array("+36 (96) 613-617", "3617")
        ],
    
    $ea = [
        "Név" => "Dr. Edelmayer András ",
        "Beosztás" => "kutató professzor",
        "Szobaszám" => "A605",
        "E-mail cím" => "andras.edelmayer@sze.hu",
        "Telefonszám" => array("+36 (96) 613-518", "3581")
        ]
];

function  tablazat(array $munkatarsak){
    foreach ($munkatarsak as $mnktrs) {
        echo "<table>\n";
        foreach ($mnktrs as $kulcs => $ertek) {
            echo "<tr><td class=\"bal\">$kulcs</td><td class=\"jobb\">";
            if(gettype($ertek)=="string"){
                echo $ertek;
            }
            else {
                echo "<ul>\n";
                foreach ($ertek as $elem) {
                    echo "<li>$elem</li>\n";
                }
                echo "</ul>\n";
            }
            echo "</td></tr>\n";
        }
        echo "</table>\n<p/>";
    }
}

tablazat($munkatarsak);

?>

</body>
</html>