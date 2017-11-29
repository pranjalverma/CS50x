<?php
    
    // require configs
    require(__DIR__ . "/../includes/config.php");
    
    // numerically indexed array of places
    $places = [];
    
    // database search
    // handling postal code
    if (is_numeric($_GET["geo"]))
    {
        $places = CS50::query("SELECT * FROM places WHERE postal_code LIKE ?", $_GET["geo"] . "%");
    }
    else
    {   
        // handling state code
        if (strlen($_GET["geo"]) == 2)
        {
            $places = CS50::query("SELECT * FROM places WHERE admin_code1 LIKE ?", strtoupper($_GET["geo"]));
        }
        // handling place name
        if (empty($places))
        {
            $places = CS50::query("SELECT * FROM places WHERE place_name LIKE ?", $_GET["geo"] . "%");
            
            // handling state name
            if (empty($places))
            {
                $places = CS50::query("SELECT * FROM places WHERE admin_name1 LIKE ?", $_GET["geo"] . "%");
                
                // query must contain punc.
                // handling results using fulltext search
                if (empty($places))
                {
                    $geo = $_GET["geo"];
                    $geo = str_replace(",", " ", $geo);
                    
                    $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name, admin_name1, admin_code1) AGAINST (?)", $geo);
                }
            }
        }
    }
    
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>