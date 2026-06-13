<?php
$bgcolor = "white"; 

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["execute"])) {
    $gender = strtolower($_POST["gender"] ?? ""); 
    $grade = $_POST["grade"] ?? null;  

    
    if (!is_numeric($grade)) {
        echo "<div style='color:red;'>Error: Please enter a valid grade.</div>";
    } else {
        
        if ($gender == "female") {
            $bgcolor = "pink";
        } elseif ($gender == "male") {
            $bgcolor = "blue";
        } else {
            $bgcolor = "beige"; 
        }

        
        echo "<div style='font-size:20px; margin-top:20px;'>Gender: " . ucfirst(htmlspecialchars($gender)) . "</div>";
        echo "<div style='font-size:20px;'>Grade: " . htmlspecialchars($grade) . "</div>";
    }
}
?>
