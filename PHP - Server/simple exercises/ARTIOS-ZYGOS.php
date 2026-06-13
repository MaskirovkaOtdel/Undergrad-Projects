<!DOCTYPE html>
<html>
<head>
    <title>Odd or Even Checker</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number:</label>
    <input type="number" name="number" required>
    <button type="submit">Check</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $input = $_POST["number"]; 

    
    preg_match_all("/-?\d+/", $input, $matches);

    if (!empty($matches[0])) {
        echo "<p>Extracted numbers and their even/odd status:</p><ul>";
        
        foreach ($matches[0] as $number) {
            $number = (int) $number; 
            $type = ($number % 2 == 0) ? "even" : "odd";
            echo "<li>" . htmlspecialchars($number) . " is $type.</li>";
        }
        
        echo "</ul>";
    } else {
        echo "<p>No valid numbers found in the input.</p>";
    }
}
?>



</body>
</html>
