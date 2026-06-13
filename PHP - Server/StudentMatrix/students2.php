<?php


$students = array(
    array("John"),
    array("Mary"),
    array("George"),
    array("Irene")
);


$first_student = $students[0][0];  
$last_student = $students[count($students) - 1][0];  


echo "First Student: $first_student\n";
echo "<br>";
echo "Last Student: $last_student\n";
echo "<br><br>";

echo "Students and their positions:\n" ."<br><br>";
foreach ($students as $index => $student) {
    echo "no." . ($index + 1) . " Student " . ": " . $student[0] . "\n" ."<br>";
}


echo "<br>Students and their positions:\n" ."<br><br>";
foreach ($students as $index => $student) {
    echo "• " . $student[0] . "\n" ."<br>";
}
?>
