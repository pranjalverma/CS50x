<?php
    
    // require configs
    require("../includes/config.php");
    
    // if both inputs match, proceed; else apologize
    if ($_POST["newpass"] == $_POST["confirm"])
    {
        // update user's hash entry in database and render display page
        CS50::query("UPDATE users SET hash = ?", password_hash($_POST["newpass"], PASSWORD_DEFAULT));
        render("pass_display.php", ["title" => "Success"]);
    }
    else
        apologize("Both entries are not identical, try again!");

?>
