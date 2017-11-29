<?php

    // configuration
    require("../includes/config.php"); 
    
    // select symbols and shares from user's portfolio database
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    // construct hashtable 
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    // select cash and username of user
    $user = CS50::query("SELECT cash, username FROM users WHERE id = ?", $_SESSION["id"]);
    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "cash" => number_format($user[0]["cash"], 2, ".", ","), "username" => $user[0]["username"]]);

?>
