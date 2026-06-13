<?php
$str = "Bruh";
$word = "welcome";


$str .= "Bruh what da hell is dis shit you're welcome";

$position = strpos($str, $word);

if ($position !== false) {
    echo "The word '$word' is found at position: $position";
} else {
    echo "The word '$word' was not found.";
}


?>
