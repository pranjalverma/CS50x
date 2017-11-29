<div>
    <h5>Hi, <?= htmlspecialchars($username) ?>. Here's your current portfolio!</h5>
</div>
<br/>
<div>
    <table class="container">
        
        <tr>
            <td><h4>Symbol</h4></td>
            <td><h4>Shares</h4></td>
            <td><h4>Price</h4></td>
            <td><h4>Current Value</h4></td>
        </tr>
        
        <?php foreach ($positions as $position): ?>
    
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td>$<?= $position["price"] ?></td>
            <td>$<?= number_format($position["shares"] * $position["price"], 2, ".", ",") ?></td>
        </tr>
    
        <?php endforeach ?>
        
    </table>
    <br/>
    <p>Current Balance: $<?= $cash ?></p>
</div>
