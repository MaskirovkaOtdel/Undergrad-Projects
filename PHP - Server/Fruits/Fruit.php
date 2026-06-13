<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Fruit Table</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f9f9f9;
            padding: 50px;
            text-align: center;
        }
        table {
            margin: 0 auto;
            border-collapse: collapse;
            width: 60%;
            background-color: #ffffff;
            box-shadow: 0 4px 8px rgba(0,0,0,0.1);
        }
        th, td {
            padding: 15px;
            border-bottom: 1px solid #ddd;
        }
        th {
            background-color: #4CAF50;
            color: white;
        }
        tr:hover {
            background-color: #f1f1f1;
        }
        caption {
            font-size: 24px;
            margin-bottom: 10px;
            font-weight: bold;
        }
    </style>
</head>
<body>

<?php

$allFruits = ["Apple", "Banana", "Cherry", "Mango", "Pineapple", "Erdberry", "Watermelon", "Myrtile", "Dragonfruit", "Orange"];
$fruits = [];

for ($i = 0; $i < 10; $i++) {
    $fruits[] = $allFruits[$i];
}
?>

<table>
    <caption>Fruit List</caption>
    <tr>
        <th>#</th>
        <th>Fruit Name</th>
    </tr>
    <?php
    $counter = 1;
    foreach ($fruits as $fruit) {
        echo "<tr>
                <td>{$counter}</td>
                <td>{$fruit}</td>
              </tr>";
        $counter++;
    }
    ?>
</table>

</body>
</html>
