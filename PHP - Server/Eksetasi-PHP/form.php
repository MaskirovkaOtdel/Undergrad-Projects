<!DOCTYPE html>
<html lang="el">
<head>
  <meta charset="UTF-8">
  <meta  name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Φόρμα Τελών Κυκλοφορίας</title>
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <div class="form-container">
    <h2>Υπολογισμός Τελών Κυκλοφορίας</h2>
    <form action="teli.php" method="post">
	  <div class="input-group">
      <input type="text" name="fullname" placeholder="Ονοματεπώνυμο" required>
	  </div>
	  
	  <div class="input-group">
      <input type="number" name="age" placeholder="Ηλικία" required>
	  </div>
	  
	  <div class="input-group">
      <input type="text" name="plate" placeholder="Αριθμός Πινακίδας" required>
	  </div>
	  
	  <div class="input-group">
      <input type="number" name="cc" placeholder="Κυβικά (cc)" required>
	  </div>
	  
      <div class="buttons">
        <button type="submit" class="submit-btn">Υπολογισμός</button>
        <button type="reset" class="reset-btn">Απαλοιφή</button>
      </div>
    </form>
  </div>
</body>
</html>