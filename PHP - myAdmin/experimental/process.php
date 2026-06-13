<?php
	$host ='localhost';
	$user ='root';
	$pass ="";
	$dbname = "phpmyadmin";
	
	$conn = new mysqli($host, $user, $pass, $dbname);
	
	if ($conn->connect_error) {
    die("Connection Error: " . $conn->connect_error);
	}
	
	
	
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$name = $_POST['username'];
		$surname = $_POST['surname'];
		$gender = $_POST['gender'];
		$department = $_POST['department'];
		
	$sql = "INSERT INTO users (username, surname, gender, department) 
		    VALUES ('$name', '$surname', '$gender', '$department')";
	
	
	if ($conn->query($sql) === TRUE) {
		echo "The registry sucessfully completed";
	} else {
		echo "Error during registry: " . $conn->error;
	}
	
	$conn->close();
	}
?>