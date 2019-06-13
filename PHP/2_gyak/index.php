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
function readFromCSV($filename){
    $handle = fopen($filename, "r"); // if(($fajl = fopen("fajl.csv", 0, )) !== FALSE)
    while (!feof($handle)){
        $data[] = fgetcsv($handle, 0, ";");
    }
    tablazat($data);
    fclose($handle);
}

function  tablazat(array $munkatarsak){
    
    for($i = 1; $i < count($munkatarsak); $i++){
        echo "<table>\n";
        for($j = 0; $j < count($munkatarsak[$i])-1; $j++){
            echo "<tr>\n<td class=\"bal\">".$munkatarsak[0][$j]."</td><td class=\"jobb\">".$munkatarsak[$i][$j]."</td></tr>\n</td></tr>\n";
        }
        echo "</table>\n<p/>";
    }
}

readFromCSV("munkatarsak.csv");

?>

</body>
</html>