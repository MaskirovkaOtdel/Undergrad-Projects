<?php
session_start();

header('Content-Type: application/json');


$host = "localhost";
$user = "root";
$pass = "";
$dbname = "experimental";


$conn = new mysqli($host, $user, $pass);
if ($conn->connect_error) {
    echo json_encode([
        "success" => false,
        "message" => "Σφάλμα σύνδεσης: " . $conn->connect_error
    ]);
    exit();
}


$dbCheckQuery = "CREATE DATABASE IF NOT EXISTS $dbname";
if (!$conn->query($dbCheckQuery)) {
    echo json_encode([
        "success" => false,
        "message" => "Σφάλμα δημιουργίας βάσης: " . $conn->error
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
if (!$conn->query($createTableQuery)) {
    echo json_encode([
        "success" => false,
        "message" => "Σφάλμα δημιουργίας πίνακα: " . $conn->error
    ]);
    exit();
}


if ($_SERVER["REQUEST_METHOD"] === "POST") {
    
    
    $username = trim($_POST['username'] ?? '');
    $surname = trim($_POST['surname'] ?? '');
    $gender = $_POST['gender'] ?? '';
    $department = $_POST['department'] ?? '';

    
    $stmt = $conn->prepare("INSERT INTO users (username, surname, gender, department) VALUES (?, ?, ?, ?)");
    $stmt->bind_param("ssss", $username, $surname, $gender, $department);

    if ($stmt->execute()) {
        
        $_SESSION['form_data'] = [
            'username' => $username,
            'surname' => $surname,
            'gender' => $gender,
            'department' => $department
        ];

        echo json_encode([
            "success" => true,
            "message" => "Η καταχώρηση ήταν επιτυχής!",
            "redirect" => "secondpage.php"
        ]);
    } else {
        echo json_encode([
            "success" => false,
            "message" => "Σφάλμα κατά την καταχώρηση: " . $stmt->error
        ]);
    }

    $stmt->close();
    $conn->close();
}
?>
