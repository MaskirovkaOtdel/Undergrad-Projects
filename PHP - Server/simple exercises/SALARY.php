<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wage Calculation</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Times New Roman', Arial, sans-serif;
        }

        body {
            background: linear-gradient(to right, #666666, #333333);
            color: #333;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            padding: 20px;
        }

        .container {
            background: white;
            padding: 50px;
            border-radius: 15px;
            box-shadow: 0 15px 30px rgba(0, 0, 0, 0.1);
            width: 100%;
            max-width: 600px;
            text-align: center;
            transform: scale(1);
            transition: all 0.3s ease-in-out;
        }

        .container:hover {
            transform: scale(1.05);
            box-shadow: 0 15px 60px rgba(0, 0, 0, 0.2);
        }

        h2 {
            font-size: 2.5rem;
            color: #333;
            margin-bottom: 30px;
            font-weight: 700;
            letter-spacing: 1px;
            text-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }

        label {
            font-size: 1.1rem;
            margin-bottom: 10px;
            color: #555;
            display: block;
            text-align: left;
        }

        input[type="number"] {
            width: 100%;
            padding: 15px;
            margin: 15px 0 25px;
            border: 2px solid #ccac00;
            border-radius: 10px;
            font-size: 1.1rem;
            color: #333;
            background-color: #f9f9f9;
            transition: all 0.3s ease;
        }

        input[type="number"]:focus {
            border-color: #ccac00;
            outline: none;
            background-color: #fff7e6;
        }

        input[type="submit"] {
            background-color: #ccac00;
            color: white;
            border: none;
            padding: 15px 30px;
            font-size: 1.1rem;
            font-weight: 600;
            border-radius: 8px;
            cursor: pointer;
            transition: background-color 0.3s ease, transform 0.3s ease;
        }

        input[type="submit"]:hover {
            background-color: #ccac00;
            transform: translateY(-3px);
        }

        p {
            font-size: 1.2rem;
            color: #333;
            margin-top: 25px;
            font-weight: 500;
            transition: all 0.3s ease;
        }

        .error {
            color: #e74c3c;
            font-weight: bold;
			font-family: Arial, sans-serif;
        }

        .success {
            color: #27ae60;
            font-weight: bold;
			font-family: Arial, sans-serif;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Wage Calculation</h2>
        <form method="post" action="">
            <label for="salary">Enter earned wage:</label>
            <input type="number" id="salary" name="salary" required>
            <input type="submit" value="Υπολογισμός">
        </form>
        
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $salary = floatval($_POST["salary"]);
        if ($salary >= 0 && $salary < 900) {
            echo "<p class='success'>Χαμηλόμισθος</p>";
        } elseif ($salary >= 900 && $salary < 1600) {
            echo "<p class='success'>Μεσαία Αμοιβόμενος</p>";
        } elseif ($salary >= 1600) {
            echo "<p class='success'>Υψηλόμισθος</p>";
        } else {
            echo "<p class='error'>Παρακαλώ εισάγετε έγκυρο ποσό μισθού</p>";
        }
    }
?>

    </div>
</body>
</html>
