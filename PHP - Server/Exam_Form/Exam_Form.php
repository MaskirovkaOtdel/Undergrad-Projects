<?php 
$bgcolor = "white"; 
$textcolor = "black";

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["execute"])) {
    
    $gender = strtolower(trim($_POST["gender"] ?? ""));
    $grade = $_POST["grade"] ?? null;

    if (!in_array($gender, ["male", "female"])) {
        $gender = "other"; 
    }

    if (empty($grade) || !is_numeric($grade)) {
        echo "<div class='error'>Error: Please enter a valid grade.</div>";
    } else {
        
        if ($gender == "female") {
            $bgcolor = "pink";
            $textcolor = "white"; 
        } elseif ($gender == "male") {
            $bgcolor = "blue";
            $textcolor = "white"; 
        } else {
            $bgcolor = "beige";
            $textcolor = "black"; 
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exam Form</title>
    <style>
        body {
            background-color: <?php echo $bgcolor; ?>;
            color: <?php echo $textcolor; ?>;
            font-family: Arial, sans-serif;
            transition: background-color 0.5s ease, color 0.5s ease;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        .container {
            text-align: center;
            background-color: rgba(255, 255, 255, 0.8);
            padding: 35px;
            border-radius: 10px;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.2);
            width: 350px;
        }

        h2 {
            font-size: 36px;
            margin-bottom: 20px;
        }

        form {
            margin-bottom: 20px;
        }

        input[type="text"], input[type="number"] {
            width: auto;
            padding: 12px;
            margin: 10px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
            font-size: 16px;
        }

        button {
            width: 80%;
            padding: 12px;
            background-color: #4CAF50;
            color: white;
            font-size: 18px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }

        button:hover {
            background-color: #45a049;
        }

        .result {
            margin-top: 20px;
            font-size: 18px;
			color: black;
        }

        .error {
            color: red;
            margin-top: 20px;
            font-size: 16px;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>Exam Form</h2>

        <form method="post" action="">
            <input type="text" name="gender" placeholder="male/female" required>
            <input type="number" name="grade" placeholder="Enter grade" step="any" required>

            <br><button type="submit" name="execute">Submit</button>
        </form>

        <?php 
        if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["execute"])) {
            if (!empty($grade) && is_numeric($grade)) {
                echo "<div class='result'>Gender: " . ucfirst(htmlspecialchars($gender)) . "</div>";
                echo "<div class='result'>Grade: " . htmlspecialchars($grade) . "</div>";
            } else {
                echo "<div class='error'>Error: Please enter a valid grade.</div>";
            }
        }
        ?>
    </div>

</body>
</html>
