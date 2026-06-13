<!DOCTYPE html>
<html>
<head>
    <title>Numbers and Square Roots</title>
    <style>
        body {
            font-family: "Segoe UI", Tahoma, Geneva, Verdana, sans-serif;
            background-color: #f9f9f9;
            color: #333;
            margin: 0;
            padding: 0;
        }

        h2 {
            text-align: center;
            background-color: #005a9c;
            color: white;
            padding: 20px 0;
            margin-bottom: 30px;
            font-size: 24px;
        }

        form {
            text-align: center;
            margin-bottom: 30px;
        }

        label {
            font-size: 18px;
            margin-right: 10px;
        }

        input[type="number"] {
            padding: 8px;
            font-size: 16px;
            width: 120px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }

        input[type="submit"] {
            padding: 8px 16px;
            font-size: 16px;
            background-color: #0078d4;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            margin-left: 10px;
        }

        input[type="submit"]:hover {
            background-color: #005a9c;
        }

        table {
            border-collapse: collapse;
            width: 60%;
            margin: 0 auto 50px auto;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }

        th, td {
            border: 1px solid #ddd;
            padding: 12px 15px;
            font-size: 16px;
        }

        th {
            background-color: #e6f2ff;
            color: #003366;
        }

        tr:nth-child(even) {
            background-color: #f2f9ff;
        }
    </style>
</head>
<body>

<h2>📚 Square Root Learning Tool</h2>

<form method="post" action="">
    <label for="limit">Enter a number:</label>
    <input type="number" id="limit" name="limit" min="1" value="<?php echo isset($_POST['limit']) ? $_POST['limit'] : 20; ?>" required>
    <input type="submit" value="Generate">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['limit'])) {
    $limit = intval($_POST['limit']);

    if ($limit > 0) {
        echo "<table>";
        echo "<tr><th>Number</th><th>Power²</th><th>Square Root</th></tr>";
        for ($i = 1; $i <= $limit; $i++) {
            $sqrt = sqrt($i);
            $power = pow($i, 2);
            echo "<tr><td>$i</td><td>" . $power . "</td><td>" . number_format($sqrt, 2) .  "</td></tr>";
        }
        echo "</table>";
    } else {
        echo "<p style='text-align:center;color:red;'>Please enter a positive number.</p>";
    }
}
?>

</body>
</html>
