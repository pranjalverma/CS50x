<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // error checking: ensure o fields are left empty
        if (empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["email"]) || empty($_POST["confirmation"]))
            apologize("Please ensure no fields are left empty!");
        // ensure both entries of password match
        else if ($_POST["password"] != $_POST["confirmation"])
            apologize("Both entries of password must be identical!");
        
        // insert row in users' database
        $check = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
        // check for valid insert to proceed; else apologize
        if ($check == 0)
            apologize("Username already exists, please choose a different one!");
        else
        {
            // select id of last row in users
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            
            // set this id as current session id
            $_SESSION["id"] = $id;
            
            // log user in automatically
            redirect("/");
        }
        
    }

?>