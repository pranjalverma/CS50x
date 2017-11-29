<form action="sell.php" method="post">
    <div>
        <table class="container">
            <tr>
                <td><h5>Symbol</h5></td>
                <td><h5>Shares</h5></td>
                <td><h5>Sell</h5></td>
            </tr>
            <?php foreach ($rows as $row): ?>
                
                <tr>
                    <td><?= $row["symbol"] ?></td>
                    <td><?= $row["shares"] ?></td>
                    <td><input type="checkbox" name="symbol" value="set"></td>
                </tr>
                
            <?php endforeach ?>
        </table>
    </div>
    <br/>
    <div>
        <button class="btn btn-default" type="submit">
            Sell
        </button>
    </div>
</form>