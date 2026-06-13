<?php
session_start(); 

$host = "localhost";
$user = "root";
$pass = "";
$dbname = "experimental";


$conn = new mysqli($host, $user, $pass);


if ($conn->connect_error) {
    die("Connection Error: " . $conn->connect_error);
}


$dbCheckQuery = "CREATE DATABASE IF NOT EXISTS $dbname";
if ($conn->query($dbCheckQuery) !== TRUE) {
    echo json_encode([
        "success" => false,
        "message" => "Error creating database: " . $conn->error
    ]);
    exit();
}


$conn->select_db($dbname);


$createTableQuery = "CREATE TABLE IF NOT EXISTS users (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(20) NOT NULL,
    surname VARCHAR(25) NOT NULL,
    gender VARCHAR(10),
    department VARCHAR(100)
)";

if ($conn->query($createTableQuery) !== TRUE) {
    echo json_encode([
        "success" => false,
        "message" => "Error creating table: " . $conn->error
    ]);
    exit();
}


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['username'];
    $surname = $_POST['surname'];
    $gender = $_POST['gender'];
    $department = $_POST['department'];

    
    $sql = "INSERT INTO users (username, surname, gender, department) 
            VALUES ('$name', '$surname', '$gender', '$department')";

    if ($conn->query($sql) === TRUE) {
        
        echo json_encode([
            "success" => true,
            "message" => "The registry was successfully completed."
        ]);
    } else {
        
        echo json_encode([
            "success" => false,
            "message" => "Error during registry: " . $conn->error
        ]);
    }

    
    $conn->close();
}
?>
