<?php
    
    // require configs
    require("../includes/config.php");
    
    // select entire history database
    $rows = CS50::query("SELECT * FROM history");
    
    // render history display for user 
    render("history_display.php", ["title" => "History", "rows" => $rows]);
    
?>