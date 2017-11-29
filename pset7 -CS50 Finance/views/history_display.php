<div>
    <table class="container">
        <tr>
            <td><h5>Transaction</h5></td>
            <td><h5>Symbol</h5></td>
            <td><h5>Shares</h5></td>
            <td><h5>Price</h5></td>
            <td><h5>Date/Time</h5></td>
        </tr>
        
        <?php foreach($rows as $row): ?>
        
        <tr>
            <td><?= $row["transaction"] ?></td>
            <td><?= $row["symbol"] ?></td>
            <td><?= $row["shares"] ?></td>
            <td><?= $row["price"] ?></td>
            <td><?= $row["datetime"] ?></td>
        </tr>
        
        <?php endforeach ?>
    </table>
</div>