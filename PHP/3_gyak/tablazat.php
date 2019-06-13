<html>
<head>
<meta charset="UTF-8">
<title>Jólviselkedők</title>
<link rel="stylesheet" href="style.css"/>
</head>
<body>

<?php

include 'kozoskod.php';

echo "<table><thead><tr><td>Személy neve</td><td>Ajándék neve</td><td>Személy jósága</td><td>Ajándék jósága</td></head><tbody>";
for($i = 0; $i < count($szemelyek); $i++){
    echo "<tr><td>".$szemelyek[$i][0]."</td><td>".$ajandekok[$i][0]."</td><td>".$szemelyek[$i][1]."</td><td>".$ajandekok[$i][1]."</td>";
}
echo "</tbody></table>";

echo "<a href=\"index.php\">Vissza az eredi listához</a>"

?>
</body>
</html>