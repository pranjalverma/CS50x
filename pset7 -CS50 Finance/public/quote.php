<?php
    
    // require configs
    require("../includes/config.php");
    
    // show form for GET request
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("quote_form.php", ["title" => "Find Quote"]);
    }
    // handle input for POST request
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup symbol and proceed only if it's valid; else apologize
        $stock = lookup($_POST["symbol"]);
        if ($stock != false)
        {
            // format quote and render display for user
            $quote = number_format($stock["price"], 2, ".", ",");
            render("quote_display.php", ["title" => "Quote", "quote" => $quote]);
        }
        else
            apologize("Invalid symbol!");
    }
    
?>