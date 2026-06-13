<?php
echo "\nFor Loop:\n";
for ($i = 1; $i <= 5; $i++) {
    echo $i . " ";
}
echo "\n\n";




echo "\nWhile Loop:\n";
$j = 5;
while ($j > 0) {
    echo $j . " ";
    $j--;
}
echo "\n\n";




echo "\nDo-While Loop:\n";
$k = 1;
do {
    echo $k . " ";
    $k++;
} while ($k <= 3);
echo "\n\n";




echo "\nForeach Loop:\n";
$fruits = array("Apple", "Banana", "Cherry");
foreach ($fruits as $fruit) {
    echo $fruit . " ";
}
echo "\n";
?>
