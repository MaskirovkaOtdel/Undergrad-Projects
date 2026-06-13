<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Salary Calculator</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>

    <div class="container">
        <h2>Salary Calculator</h2>

        <form method="post" action="salary_result.php">
            
            <div class="input-group">
                <label for="name"><strong>Username:</strong></label>
                <input type="text" name="name" id="name" placeholder="Enter your name" required>
            </div>
			
			<div class="input-group">
                <label for="sname"><strong>Surname:</strong></label>
                <input type="text" name="sname" id="sname" placeholder="Enter your surname" required></textarea>
            </div>

            <div class="input-group">
                <label for="salary"><strong>Salary:</strong></label>
                <input type="number" name="salary" id="salary" placeholder="Enter your salary" step="0.1" required>
            </div>
			
			<div class="input-group">
                <label for="children"><strong>Children:</strong></label>
                <input type="number" name="children" id="children" placeholder="Number of children" step="0.1" required>
            </div>

            <div class="button-group">
                <button type="submit" name="execute">Submit</button>
                <button type="reset" class="reset-btn">Reset</button>
            </div>

        </form>
    </div>

</body>
</html>