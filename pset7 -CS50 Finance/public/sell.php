<?php
    
    // require configs
    require("../includes/config.php"); 
    
    // select symbol and shares from portfolio for current user
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    // show form for GET request
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("sell_form.php", ["title" => "Sell", "rows" => $rows]);
    }
    // handle input for POST request
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // iterate over $rows
        foreach ($rows as $row)
        {
            // check if symbol is checked
            if (isset($_POST["symbol"]))
            {
                // lookup symbol and calculate proceeds
                $lookup = lookup($row["symbol"]);
                $proceeds = $lookup["price"] * $row["shares"];
                
                // update user's cash balance
                CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $proceeds, $_SESSION["id"]);
                
                // delete this share's entry from user's portfolio
                CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $row["symbol"]);
                
                // log transaction 
                CS50::query("INSERT INTO history (transaction, symbol, shares, price, datetime) VALUES('SELL', ?, ?, ?, NOW())", strtoupper($row["symbol"]), $row["shares"], 
                            number_format($lookup["price"], 2, ".", ","));
            }
        }
        
        // select user's new cash balance
        $balance = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        // render display showing user their new balance
        render("sell_display.php", ["title" => "Sold!", "balance" => $balance]);
    }
    
?>