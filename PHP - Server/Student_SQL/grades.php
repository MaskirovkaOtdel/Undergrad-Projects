<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Grade Results</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Grade Results</h1>
        <?php
        
        function calculateAverage($grades) {
            $sum = array_sum($grades);
            return $sum / count($grades);
        }

       
        function getClosestValidValues($grade) {
            $lower = floor($grade * 100) / 100; 
            $upper = ceil($grade * 100) / 100; 

            
            return [$lower, $upper];
        }

        
        function isValidGrade($grade) {
            return is_numeric($grade) && $grade >= 1 && $grade <= 10 && preg_match('/^\d+(\.\d{1,2})?$/', $grade);
        }

        
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            
            $grades = $_POST['grades'];
            $validGrades = [];
            $invalidGrades = [];
            $suggestions = [];

            
            foreach ($grades as $grade) {
                if (isValidGrade($grade)) {
                    $validGrades[] = (float)$grade; 
                } else {
                    $invalidGrades[] = $grade;
                    
                    $suggestions[] = getClosestValidValues($grade);
                }
            }

            
            if (empty($invalidGrades)) {
                $average = calculateAverage($validGrades);
                echo "<div class='result'>Average Grade: " . number_format($average, 2) . "</div>";

                echo "<table class='result-table'>
                        <thead>
                            <tr>
                                <th>Grade</th>
                                <th>Status</th>
                            </tr>
                        </thead>
                        <tbody>";
                
                foreach ($validGrades as $index => $grade) {
                    $grade = number_format($grade, 2, '.', '');
                    $status = $grade < 5 ? "Fail" : "Pass";
                    $statusClass = $grade < 5 ? "fail" : "pass";
                    echo "<tr>
                            <td>Grade " . ($index + 1) . ": " . $grade . "</td>
                            <td class='$statusClass'>$status</td>
                          </tr>";
                }
                echo "</tbody></table>";
            } else {
                
                echo "<div class='error-message'>Some of the grades are invalid. Please enter grades between 1.00 and 10.00 with up to two decimal places.</div>";
                echo "<div class='suggestion-message'>Suggestions for invalid grades: " . implode(", ", array_map(function($sug) {
                    return "[" . implode(", ", $sug) . "]";
                }, $suggestions)) . ".</div>";
            }
        }
        ?>
        <div class="back-link">
            <a href="Student.html" class="back-btn">Back to Form</a>
        </div>
    </div>
</body>
</html>
