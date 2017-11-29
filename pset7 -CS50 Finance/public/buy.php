<?php
    
    // require configs
    require("../includes/config.php");
    
    // show form for GET request (href used GET)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
    // handle input from form for POST request
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup symbol, only if it exists
        $lookup = lookup($_POST["symbol"]);
        if ($lookup != false)
        {
            // ensure shares are positive ints
            if (preg_match("/^\d+$/", $_POST["shares"]))
            {
                // calculate proceeds of user and get current balance
                $proceeds = $lookup["price"] * $_POST["shares"];
                $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
                
                // check if user can affort shares
                if ($proceeds <= $rows[0]["cash"])
                {
                    // query portfolio
                    CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"],
                                strtoupper($_POST["symbol"]), $_POST["shares"]);
                                
                    // update cash in user's database
                    CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $proceeds, $_SESSION["id"]);
                    
                    // select new cash
                    $new = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
                    
                    // log transaction
                    CS50::query("INSERT INTO history (transaction, symbol, shares, price, datetime) VALUES('BUY', ?, ?, ?, NOW())", strtoupper($_POST["symbol"]), $_POST["shares"], 
                                number_format($lookup["price"], 2, ".", ","));
                                
                    // render display page, showing new cash balance
                    render("buy_display.php", ["title" => "Bought!", "cash" => $new[0]["cash"]]);
                }
                else
                {
                    apologize("This is all fake and you still can't afford this. Wow.");
                }
            }
            else
            {
                apologize("Invalid entry for Shares; can't be fractional or non-numeric!");
            }
        }
        else
        {
            apologize("Invalid Symbol!");
        }
    }
    
?>