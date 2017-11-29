<?php
    
    // require configs
    require("../includes/config.php");
    
    // show from for GET request
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("pass_form-0.php", ["title" => "Change Password"]); 
    }
    // handle input from form for POST request
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // select user's hashed password
        $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        
        // render password change provisions only if entered password is correct; else apologize 
        if (password_verify($_POST["curpass"], $rows[0]["hash"]))
            render("pass_form-1.php", ["title" => "Change Password"]);
        else
            apologize("Sorry! Incorrect password.");
    }

?>
