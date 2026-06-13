<?php
session_start();


if (!isset($_SESSION['form_data'])) {
    echo "<h2>Δεν υπάρχουν καταχωρημένα στοιχεία.</h2>";
    exit();
}

$data = $_SESSION['form_data'];
?>

<!DOCTYPE html>
<html lang="el">
<head>
    <meta charset="UTF-8">
    <title>Επιβεβαίωση Καταχώρησης</title>
    <style>
        body {
            font-family: 'Roboto', sans-serif;
            background-color: #121212;
            color: #e0e0e0;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 20px;
        }

        .result-box {
            background-color: #1f1f1f;
            padding: 40px;
            border-radius: 12px;
            box-shadow: 0 8px 16px rgba(0,0,0,0.3);
            border: 1px solid #444;
            max-width: 500px;
            width: 100%;
        }

        h2 {
            color: #ffcc00;
            margin-bottom: 20px;
        }

        p {
            font-size: 18px;
            margin-bottom: 10px;
            color: #ddd;
        }

        .highlight {
            color: #ffd700;
            font-weight: bold;
        }

        a {
            display: inline-block;
            margin-top: 20px;
            padding: 10px 20px;
            background-color: #ffd700;
            color: #121212;
            text-decoration: none;
            border-radius: 6px;
            font-weight: bold;
        }

        a:hover {
            background-color: #ffcc00;
        }
    </style>
</head>
<body>
    <div class="result-box">
        <h2>Καταχώρηση Επιτυχής</h2>
        <p>Όνομα: <span class="highlight"><?php echo htmlspecialchars($data['username']); ?></span></p>
        <p>Επώνυμο: <span class="highlight"><?php echo htmlspecialchars($data['surname']); ?></span></p>
        <p>Φύλο: <span class="highlight"><?php echo htmlspecialchars($data['gender']); ?></span></p>
        <p>Τμήμα: <span class="highlight"><?php echo htmlspecialchars($data['department']); ?></span></p>

        <a href="index.html">Επιστροφή στην αρχική</a>
    </div>
</body>
</html>