<!DOCTYPE html>
<html>
<head>
    <title>Fill Form</title>
    <style>
		* {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Times New Roman', Arial, sans-serif;
        }

        body {
            background: #666666;
            color: #333;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            padding: 20px;
        }
        .container {
            background: white;
            padding: 50px;
            border-radius: 15px;
            box-shadow: 0 15px 30px rgba(0, 0, 0, 0.1);
            width: 100%;
            max-width: 600px;
            text-align: center;
            transform: scale(1);
            transition: all 0.3s ease-in-out;
        }
		    .container:hover {
            transform: scale(1.05);
            box-shadow: 0 15px 60px rgba(0, 0, 0, 0.2);
        }
        h2 {
            font-size: 2.5rem;
            color: #333;
            margin-bottom: 30px;
            font-weight: 700;
            letter-spacing: 1px;
            text-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        label {
            font-size: 1.1rem;
            margin-bottom: 10px;
            color: #555;
            display: block;
            text-align: left;
        }
		
        input[type="text"] {
            width: 100%;
            padding: 15px;
            margin: 15px 0 25px;
            border: 2px solid #6666660;
            border-radius: 10px;
            font-size: 1.1rem;
            color: #333;
            background-color: #f9f9f9;
            transition: all 0.3s ease;
        }

        input[type="text"]:focus {
            border-color: #666666;
            outline: none;
            background-color: #fff7e6;
        }
		    input[type="number"] {
            width: 100%;
            padding: 15px;
            margin: 15px 0 25px;
            border: 2px solid #6666660;
            border-radius: 10px;
            font-size: 1.1rem;
            color: #333;
            background-color: #f9f9f9;
            transition: all 0.3s ease;
        }

        input[type="number"]:focus {
            border-color: #666666;
            outline: none;
            background-color: #fff7e6;
        }

        input[type="submit"] {
            background-color: #666666;
            color: white;
            border: none;
            padding: 15px 30px;
            font-size: 1.1rem;
            font-weight: 600;
            border-radius: 8px;
            cursor: pointer;
            transition: background-color 0.3s ease, transform 0.3s ease;
        }

        input[type="submit"]:hover {
            background-color: #666666;
            transform: translateY(-3px);
        }
    </style>
</head>
<body>
<div class="container">
    <h2>Welcome Form</h2>
    <form method="post" action="Fill_Form_Reaction.php">
        <label for="Name">Name: </label>
        <input type="text" id="fname" name="name" required>
        <br><br>
        <label for="Surname">Surname: </label>
        <input type="text" id="sname" name="sname" required>
		<label for="Age">Age: </label>
        <input type="number" id="age" name="age" required>
        <br><br>
        <input type="submit">
    </form>
</div>
</body>
</html>
