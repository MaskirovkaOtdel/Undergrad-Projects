<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $fullname = htmlspecialchars($_POST['fullname']);
    $age = intval($_POST['age']);
    $plate = htmlspecialchars($_POST['plate']);
    $cc = intval($_POST['cc']);

    $theme = [
    "xamilo" => ["#1b1b1b", "#d4af37", "linear-gradient(145deg, #2e2e2e, #1b1b1b)", "box-shadow: 0px 0px 10px rgba(212, 175, 55, 0.4)"],
	"ypsilo" => ["#382002", "#ffcc66", "linear-gradient(145deg, #5a3c02, #382002)", "box-shadow: 0px 0px 20px rgba(255, 204, 102, 0.7)"],
	"xrewkopia" => ["#341f00", "#ffcc00", "linear-gradient(145deg, #8b5e00, #341f00)", "box-shadow: 0px 0px 30px rgba(255, 204, 0, 1)"]
	];
	
	
    if ($cc <= 1000) {
		list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["xamilo"];
        $fees = 170;
    } elseif ($cc <= 2000) {
		list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["ypsilo"];
        $fees = 230;
    } else {
        $fees = 350;
		list($bgcolor, $textcolor, $gradient, $boxShadow) = $theme["xrewkopia"];
    }

    
    $surcharge = 0;
    if ($age <= 20) {
        $surcharge = 50;
    }

    $total = $fees + $fees * 0.24 + $surcharge;
}
?>

<!DOCTYPE html>
<html lang="el">
<head>
  <meta charset="UTF-8">
  <title>Αποτέλεσμα Τελών</title>
  <link rel="stylesheet" href="styles.css">
<style>
  body {
    background: <?php echo $gradient; ?>;
  }

  .result-box {
    background-color: <?php echo $bgcolor; ?>;
    color: <?php echo $textcolor; ?>;
    <?php echo $boxShadow; ?>;
    padding: 40px;
    border-radius: 12px;
    max-width: 600px;
    margin: auto;
    margin-top: 50px;
  }

  .result-box a {
    display: inline-block;
    margin-top: 20px;
    padding: 10px 15px;
    background-color: <?php echo $textcolor; ?>;
    color: <?php echo $bgcolor; ?>;
    text-decoration: none;
    border-radius: 6px;
    font-weight: bold;
    transition: 0.3s;
  }

  .result-box a:hover {
    opacity: 0.8;
  }
</style>
<body>
  <div class="result-box">
    <h2>Ειδοποιητήριο Πληρωμής Ασφαλίστρου</h2>
    <p><strong>Ονοματεπώνυμο:</strong> <?php echo $fullname; ?></p>
    <p><strong>Ηλικία:</strong> <?php echo $age; ?></p>
    <p><strong>Πινακίδα:</strong> <?php echo $plate; ?></p>
    <p><strong>Κυβικά:</strong> <?php echo $cc; ?></p>
    <p><strong>Τέλη Κυκλοφορίας:</strong> <?php echo $fees; ?> €</p>
    <p><strong>Επιπλέον Επιβάρυνση:</strong> <?php echo $surcharge; ?> €</p>
    <p><strong>Συνολικό Ποσό:</strong> <?php echo $total; ?> €</p>
	
	<a href="form.php" class="back-btn">Επιστροφή</a>
  </div>
</body>
</html>
