<?php
$bgcolor = "#ffffff";
$textcolor = "#000000";
$error = "";
$message = "";

$name = trim($_POST["name"] ?? "");
$sname = trim($_POST["sname"] ?? "");
$salary = $_POST["salary"] ?? "";
$children = $_POST["children"] ?? 0;

// Validate salary input
if (!is_numeric($salary) || $salary === "") {
    $error = "Error: Please enter a valid salary.";
} else {
    $salary = floatval($salary);
    $children = intval($children);

    if ($salary < 0) {
        $error = "Error: Salary cannot be negative.";
    } else {
        // Tax Calculation
        $tax = 0;
        $originalSalary = $salary;

        if ($salary > 40000) {
            $tax += ($salary - 40000) * 0.44;
            $salary = 40000;
        }
        if ($salary > 30000) {
            $tax += ($salary - 30000) * 0.36;
            $salary = 30000;
        }
        if ($salary > 20000) {
            $tax += ($salary - 20000) * 0.28;
            $salary = 20000;
        }
        if ($salary > 10000) {
            $tax += ($salary - 10000) * 0.22;
            $salary = 10000;
        }
        $tax += $salary * 0.09;

        // Tax Discount based on the number of children
        $discount = match ($children) {
            0 => 777,
            1 => 810,
            2 => 900,
            default => 1120, // 3 or more children
        };

        // Reduce discount if salary exceeds €12,000
        $extraSalary = $originalSalary - 12000;
        if ($extraSalary > 0) {
            $reduction = floor($extraSalary / 1000) * 20;
            $discount = max($discount - $reduction, 0);
        }

        // Final tax calculation
        $finalTax = max($tax - $discount, 0);
        $netSalary = $originalSalary - $finalTax;

        $message = "
            <p>📌 <b>Total Tax:</b> €" . number_format($finalTax, 2) . "</p>
            <p>💵 <b>Net Annual Salary:</b> €" . number_format($netSalary, 2) . "</p>
            <p>📆 <b>Net Monthly Salary:</b> €" . number_format($netSalary / 12, 2) . "</p>
        ";
    }
}


$theme = [
    "low" => ["#1b1b1b", "#d4af37", "linear-gradient(145deg, #2e2e2e, #1b1b1b)", "box-shadow: 0px 0px 10px rgba(212, 175, 55, 0.4)"],    
    "medium" => ["#2c1a02", "#e0b23d", "linear-gradient(145deg, #4a2f02, #2c1a02)", "box-shadow: 0px 0px 15px rgba(224, 178, 61, 0.6)"], 
    "high" => ["#382002", "#ffcc66", "linear-gradient(145deg, #5a3c02, #382002)", "box-shadow: 0px 0px 20px rgba(255, 204, 102, 0.7)"], 
    "upper-high" => ["#482700", "#ffd700", "linear-gradient(145deg, #754a00, #482700)", "box-shadow: 0px 0px 25px rgba(255, 215, 0, 0.8)"],
    "borgeoise" => ["#341f00", "#ffcc00", "linear-gradient(145deg, #8b5e00, #341f00)", "box-shadow: 0px 0px 30px rgba(255, 204, 0, 1)"]
];

if (empty($error)) {
    if ($originalSalary < 10000) {
        list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["low"];
    } elseif ($originalSalary < 20000) {
        list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["medium"];
    } elseif ($originalSalary < 30000) {
        list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["high"];
    } elseif ($originalSalary < 40000) {
        list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["upper-high"];
    } else {
        list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["borgeoise"];
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Salary Tax Calculator</title>
    <link rel="stylesheet" href="styles.css">
    <style>
    body {
        background: <?= $gradient ?>;
        color: <?= $textcolor ?>;
    }
    h2 {
        color: <?= $textcolor ?>;
        text-shadow: 2px 2px 10px rgba(255, 215, 0, 0.5);
    }
    .result {
        background: rgba(0, 0, 0, 0.3);
        color: <?= $textcolor ?>;
        padding: 15px;
        border-radius: 10px;
        <?= $boxShadow ?>;
    }
    .error {
        background: rgba(255, 0, 0, 0.2);
        color: white;
        padding: 15px;
        border-radius: 10px;
    }
    .back-btn {
        background-color: <?= $textcolor ?>;
        color: <?= $bgcolor ?>;
        font-weight: bold;
        border-radius: 8px;
        padding: 10px 15px;
        display: inline-block;
        text-decoration: none;
        transition: all 0.3s ease-in-out;
        <?= $boxShadow ?>;
    }
    .back-btn:hover {
        background-color: gold;
        color: black;
        box-shadow: 0px 0px 20px rgba(255, 215, 0, 1);
    }
    </style>
</head>
<body>

    <div class="container">
        <h2>Salary Tax Calculator</h2>

        <?php if ($error): ?>
            <div class="error"><?= htmlspecialchars($error) ?></div>
        <?php else: ?>
            <div class="result"><strong>Name:</strong> <?= htmlspecialchars($name) ?></div>
            <div class="result"><strong>Surname:</strong> <?= htmlspecialchars($sname) ?></div>
            <div class="result"><strong>Salary:</strong> €<?= number_format($originalSalary, 2) ?></div>
            <div class="result"><strong>Children:</strong> <?= htmlspecialchars($children) ?></div>
            <div class="result"><?= $message ?></div>
        <?php endif; ?>

        <a href="Salary_Form.php" class="back-btn">Go Back</a>
    </div>

</body>
</html>
