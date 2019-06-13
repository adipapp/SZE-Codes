<html>
<head>
<meta charset="UTF-8">
<title>Jólviselkedők</title>
</head>
<body>
<?php

include 'kozoskod.php';

echo "<ol>";
for($i = 0; $i < count($szemelyek); $i++){
    echo "<li>".$szemelyek[$i][0]." - ".$ajandekok[$i][0]."</li>";
}
echo "</ol>";

echo "<a href=\"tablazat.php\">A teljes táblázat megtekintése</a>"

?>
</body>
</html>
