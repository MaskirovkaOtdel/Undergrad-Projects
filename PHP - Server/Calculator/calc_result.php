<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculation Result</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            margin: 50px;
            background-color: #121212;
            color: white;
        }
        .calculator {
            display: inline-block;
            padding: 20px;
            border-radius: 8px;
            background: #1e1e1e;
            box-shadow: 0 0 10px rgba(255, 255, 255, 0.2);
        }
        input, select, button {
            margin: 10px;
            padding: 10px;
            font-size: 16px;
            border-radius: 5px;
            border: none;
        }
        input, select {
            background: #333;
            color: white;
        }
        button {
            background: #007bff;
            color: white;
            cursor: pointer;
        }
        button:hover {
            background: #0056b3;
        }
        .result {
            margin-top: 20px;
            font-size: 20px;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <h2>Calculation Result</h2>

    <div class="calculator">
<?php
if (isset($_POST["calculate"])) {
    $num1 = $_POST["num1"] ?? null;
    $num2 = $_POST["num2"] ?? null;
    $operation = $_POST["operation"];
    $result = "";

    if (!is_numeric($num1) && !in_array($operation, ["sqrt", "factorial", "log", "sin", "cos", "tan"])) {
        echo "<div class='result'>Error: Please enter a valid number.</div>";
    } else {
        switch ($operation) {
            case "add":
                $result = $num1 + $num2;
                break;
            case "subtract":
                $result = $num1 - $num2;
                break;
            case "multiply":
                $result = $num1 * $num2;
                break;
            case "divide":
                $result = ($num2 != 0) ? $num1 / $num2 : "Error: Division by zero!";
                break;
            case "modulus":
                $result = ($num2 != 0) ? $num1 % $num2 : "Error: Modulus by zero!";
                break;
            case "power":
                $result = pow($num1, $num2);
                break;
            
           
            case "sqrt":
                $res1 = ($num1 >= 0) ? sqrt($num1) : "Error: Cannot calculate square root of a negative number!";
                $res2 = ($num2 >= 0) ? sqrt($num2) : "Error: Cannot calculate square root of a negative number!";
                $result = "Sqrt($num1) = $res1 <br> Sqrt($num2) = $res2";
                break;

			case "factorial":
				function factorial($n) {
				if ($n < 0) return "Error: Factorial requires a non-negative integer!";
				if ($n == 0 || $n == 1) return 1;
				$fact = 1;
				for ($i = 2; $i <= $n; $i++) {
				$fact *= $i;
				}
				return $fact;
				}

				$res1 = ($num1 >= 0 && floor($num1) == $num1) ? factorial($num1) : "Error: Factorial requires a non-negative integer!";
				$res2 = ($num2 >= 0 && floor($num2) == $num2) ? factorial($num2) : "Error: Factorial requires a non-negative integer!";
				$result = "Factorial($num1) = $res1 <br> Factorial($num2) = $res2";
				break;

            case "log":
                $res1 = ($num1 > 0) ? log($num1) : "Error: Log undefined for zero or negative values!";
                $res2 = ($num2 > 0) ? log($num2) : "Error: Log undefined for zero or negative values!";
                $result = "Log($num1) = $res1 <br> Log($num2) = $res2";
                break;

			case "sin":
				$result = "Sin({$num1}°) = " . sin(deg2rad($num1)) . "<br> Sin({$num2}°) = " . sin(deg2rad($num2));
				break;

			case "cos":
				$result = "Cos({$num1}°) = " . cos(deg2rad($num1)) . "<br> Cos({$num2}°) = " . cos(deg2rad($num2));
				break;

			case "tan":
				$result = "Tan({$num1}°) = " . tan(deg2rad($num1)) . "<br> Tan({$num2}°) = " . tan(deg2rad($num2));
				break;


            default:
                $result = "Invalid operation.";
        }
        echo "<div class='result'>Result: <br>$result</div>";
    }
}
?>
        <br>
        <a href="Calculator_Test.php">
            <button>Back to Calculator</button>
        </a>
    </div>

</body>
</html>