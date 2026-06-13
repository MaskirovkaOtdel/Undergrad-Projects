<?php

// Integer
$akeraios_x = 5;
$akeraios_y = 10;
$akeraios_sum = $akeraios_x + $akeraios_y;

echo sprintf("The value of variant x is %d<br>", $akeraios_x);
echo sprintf("The value of variant y is %d<br>", $akeraios_y);
echo sprintf("The value of sum is %d<br>", $akeraios_sum);
echo "The type of variant x is ";
var_dump($akeraios_x);
echo "<br>";

// String
$YourName = "Theodore";
echo "The username is " . $YourName . "<br>";
echo "The type of variant is "; var_dump($YourName);
echo "<br>";

// Float
$float_x = 10.365;
echo "The value of x is " . $float_x . "<br>";
echo "The type of variant is "; var_dump($float_x);
echo "<br>";

// Boolean
$is_logged_in = true;
echo "The value of is_logged_in is " . ($is_logged_in ? 'true' : 'false') . "<br>";
echo "The type of variant is "; var_dump($is_logged_in);
echo "<br>";

// Array
$fruits = array("apple", "banana", "cherry");
echo "The value of fruits is ";
print_r($fruits);
echo "<br>";
echo "The type of variant is "; var_dump($fruits);
echo "<br>";

// Object
class Person {
    public $name;
    public $age;

    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }

    public function __toString() {
        return "Name: $this->name, Age: $this->age";
    }

    
    public function introduce() {
        return "Hello, my name is $this->name and I am $this->age years old.";
    }
}

$person = new Person("John", 30);
echo "The value of person is " . $person . "<br>";
echo "The type of variant is "; var_dump($person);
echo "<br>";
echo $person->introduce() . "<br>"; 

// NULL
$no_value = NULL;
echo "The value of no_value is " . ($no_value ? $no_value : "NULL value") . "<br>";
echo "The type of variant is "; var_dump($no_value);
echo "<br>";

// Resource (e.g., database connection or file pointer)
$filePath = "sample.txt";
if (file_exists($filePath)) {
    $resource = fopen($filePath, "r");
    if ($resource) {
        echo "Resource opened successfully<br>";
        fclose($resource); 
    } else {
        echo "Failed to open resource<br>";
    }
} else {
    echo "The file does not exist.<br>";
}
echo "The type of variant is "; var_dump($resource);
echo "<br>";

// Callable (a function name as a variable)
function greet($name) {
    return "Hello, " . $name;
}

$callable_example = "greet";

// Use the callable function
echo "The value of callable_example is "; var_dump($callable_example);
echo "<br>";
echo "The type of variant is "; var_dump($callable_example);
echo "<br>";

echo $callable_example("Theodore") . "<br>";

// Iterable (can be used with `foreach`)
$iterable_example = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
echo "The value of iterable_example is ";
foreach ($iterable_example as $value) {
    echo $value . " ";
}
echo "<br>";
echo "The type of variant is "; var_dump($iterable_example);
echo "<br>";

// Closure (Anonymous function)
$closure_example = function($name) {
    return "Hello, " . strtoupper($name);
};

echo $closure_example("theodore") . "<br>";  

// Math Functions - Arithmetic calculations
$a = 10;
$b = 3;
echo "Modulo: " . ($a % $b) . "<br>";
echo "Addition: " . ($a + $b) . "<br>";
echo "Subtraction: " . ($a - $b) . "<br>";
echo "Multiplication: " . ($a * $b) . "<br>";
echo "Division: " . ($a / $b) . "<br>";
echo "Power (a^b): " . pow($a, $b) . "<br>";  
echo "Square Root of a: " . sqrt($a) . "<br>"; 
echo "Round b to nearest integer: " . round($b, 1) . "<br>"; 

// Date functions
echo "Today's date is: " . date("Y-m-d") . "<br>";
echo "The timestamp is: " . time() . "<br>";
echo "The date after 10 days: " . date("Y-m-d", strtotime("+10 days")) . "<br>";  
echo "The day of the week: " . date("l") . "<br>";  

// Array functions
$numbers = [1, 2, 3, 4, 5, 6];
$mapped_numbers = array_map(function($n) { return $n * 2; }, $numbers);
echo "Mapped numbers (multiplied by 2): ";
print_r($mapped_numbers);
echo "<br>";

$filtered_numbers = array_filter($numbers, function($n) { return $n % 2 == 0; });
echo "Filtered numbers (even only): ";
print_r($filtered_numbers);
echo "<br>";

// Explicit casting to other types
$casted_string_to_int = (int) "123";
$casted_float_to_string = (string) 10.25;
$casted_bool_to_int = (int) true;

echo "Casted string '123' to int: $casted_string_to_int<br>";
echo "Casted float 10.25 to string: $casted_float_to_string<br>";
echo "Casted bool true to int: $casted_bool_to_int<br>";


// casting (new)
$a = 5;
$b = 2;

$new2 = $a * 10 + $b;

var_dump($new2);
echo "<br>";

$new2++;
echo ($new2);

echo "<br>";

$new2--;
echo ($new2);

echo "<br>";
echo ++$new2;
echo "<br>";
echo --$new2 ;
echo "<br>";

//idon't know what's this

$name = "Digger \n";
$surname = "Chigger";
$name.=$surname;
echo $name;

echo "<br>";

$name2 = "Biggus \n";
$surname2 = "Dickus";
$name2.=$surname2;
echo $name2;

// Comparison


?>



