<?php

$students = array(
    array("John"),
    array("Mary"),
    array("George"),
    array("Irene")
);

$first_student = $students[0][0];  
$last_student = $students[count($students) - 1][0];  

function getOrdinal($num) {
    $suffix = ['th', 'st', 'nd', 'rd', 'th', 'th', 'th', 'st', 'nd', 'rd'];
    $last_digit = $num % 10;
    $last_two_digits = $num % 100;
    if ($last_two_digits >= 11 && $last_two_digits <= 13) {
        return $num . 'th';
    }
    return $num . $suffix[$last_digit] . " place";
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Students List</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: #f4f7fa;
            color: #333;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            text-align: center;
        }

        .container {
            background-color: white;
            padding: 30px;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            width: 80%;
            max-width: 600px;
            margin: 20px;
        }

        h2 {
            color: #4CAF50;
            font-size: 24px;
            margin-bottom: 20px;
            text-transform: uppercase;
            letter-spacing: 1px;
        }

        .student-info {
            font-size: 1.1em;
            color: #555;
            margin-bottom: 20px;
        }

        .student-info span {
            font-weight: bold;
            color: #4CAF50;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
        }

        table, th, td {
            border: 2px solid #ddd;
        }

        th, td {
            padding: 12px;
            text-align: left;
        }

        th {
            background-color: #4CAF50;
            color: white;
        }

        tr:nth-child(even) {
            background-color: #f9f9f9;
        }

        tr:hover {
            background-color: #f1f1f1;
        }

        @media (max-width: 768px) {
            .container {
                padding: 20px;
            }
            h2 {
                font-size: 20px;
            }
        }
    </style>
</head>
<body>

    <div class="container">
        
        <div class="student-info">
            <p><span>First Student:</span> <?php echo $first_student; ?></p>
            <p><span>Last Student:</span> <?php echo $last_student; ?></p>
        </div>

        
        <div class="students-container">
            <h2>Students and Their Positions:</h2>
            <table>
                <thead>
                    <tr>
                        <th>Position</th>
                        <th>Student Name</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    foreach ($students as $index => $student) {
                        $position = getOrdinal($index + 1);
                        echo "<tr><td>$position</td><td>" . $student[0] . "</td></tr>";
                    }
                    ?>
                </tbody>
            </table>
        </div>

    </div>

</body>
</html>
