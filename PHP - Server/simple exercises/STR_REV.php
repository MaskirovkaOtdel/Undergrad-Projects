<?php

$str = "WhatDaHellBoy";

$wordCount = str_word_count($str);
echo "The number of words is: " . $wordCount . "\n";

$charCount = strrev($str);
echo "The number of characters is: " . $charCount;

?>