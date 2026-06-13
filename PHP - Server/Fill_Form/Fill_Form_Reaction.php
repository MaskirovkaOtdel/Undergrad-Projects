<?php

if (isset($_POST['name']) && isset($_POST['sname']) && isset($_POST['age'])) {
    
    $firstName = htmlspecialchars($_POST['name']);
    $surname = htmlspecialchars($_POST['sname']);
    $age = htmlspecialchars($_POST['age']);
    
    echo "Welcome back, " . $firstName . " " . $surname . "!";
    echo "<br>";
    echo "Your age is: " . $age . "!";
} else {
    echo "Please fill in both your first name, surname, and age.";
}
?>
