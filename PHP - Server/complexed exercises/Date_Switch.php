<?php

$year = date("Y");
$day = date("d");
$month = date("m");

echo $year;
echo $day;
echo $month;

switch((int)$month) {
    case 1:
        echo "January";
        break;
    case 2:
        echo "February";
        break;    
    case 3:
        echo "March";
        break;        
    case 4:
        echo "April";
        break;
    case 5:
        echo "May";
        break;
    case 6:
        echo "June";
        break;
    case 7:
        echo "July";
        break;
    case 8:
        echo "August";
        break;
    case 9:
        echo "September";
        break;
    case 10:
        echo "October";
        break;        
    case 11:
        echo "November";
        break;    
    case 12:
        echo "December";
        break;
    default:
        echo "Not a month";
}

echo "<br>Date example with switch in PHP - Copyright 2025, $year,$month,$day";

?>