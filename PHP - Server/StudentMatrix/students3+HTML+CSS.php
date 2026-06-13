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

        
        .student-list {
            margin: 20px 0;
            padding-left: 0;
            list-style-position: inside;
            line-height: 1.8;
        }

        .numbered-list {
            list-style-type: decimal;
            padding-left: 20px;
        }

        .dot-list {
            list-style-type: disc;
            padding-left: 20px;
        }

        
        .student-list li {
            padding: 10px;
            background-color: #f9f9f9;
            border-radius: 5px;
            margin-bottom: 8px;
            transition: background-color 0.3s, transform 0.2s;
        }

        .student-list li:hover {
            background-color: #e7f7e7;
            transform: translateX(5px);
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
            <h2>Students and Their Positions (Numbered List):</h2>
            <ol class="student-list numbered-list">
                <?php
                foreach ($students as $index => $student) {
                    $position = getOrdinal($index + 1);  
                    echo "<li>$position: " . $student[0] . "</li>";
                }
                ?>
            </ol>
        </div>

        
        <div class="students-container">
            <h2>Students and Their Positions (Bulleted List):</h2>
            <ul class="student-list dot-list">
                <?php
                foreach ($students as $index => $student) {
                    $position = getOrdinal($index + 1);  
                    echo "<li>" . $student[0] . "</li>";
                }
                ?>
            </ul>
        </div>
    </div>

</body>
</html>
