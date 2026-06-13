<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart Calculator</title>
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

    <h2>Smart Calculator</h2>

    <form method="post" class="calculator" action="calc_result.php">
        <input type="number" name="num1" placeholder="Enter first number" required step="any">
        <input type="number" name="num2" placeholder="Enter second number (if needed)" step="any">

        <select name="operation">
            <option value="add">Addition (+)</option>
            <option value="subtract">Subtraction (-)</option>
            <option value="multiply">Multiplication (×)</option>
            <option value="divide">Division (÷)</option>
            <option value="modulus">Modulus (%)</option>
            <option value="power">Exponentiation (^)</option>
            <option value="sqrt">Square Root (√)</option>
            <option value="factorial">Factorial (!)</option>
            <option value="log">Logarithm (log)</option>
            <option value="sin">Sine (sin)</option>
            <option value="cos">Cosine (cos)</option>
            <option value="tan">Tangent (tan)</option>
        </select>

        <button type="submit" name="calculate">Calculate</button>
    </form>

</body>
</html>
