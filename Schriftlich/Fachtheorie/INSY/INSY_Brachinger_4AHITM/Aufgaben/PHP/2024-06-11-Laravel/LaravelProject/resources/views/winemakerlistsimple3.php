<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Winzer</title>
</head>
<body>

<table>
    <?php foreach ($winemakers as $winemaker) : ?>
        <tr>
            <td><?php echo $winemaker->id; ?></td>
            <td><?php echo $winemaker->name; ?></td>
            <td><?php echo $winemaker->street; ?></td>
            <td><?php echo $winemaker->zipcode; ?> <?php echo $winemaker->city; ?></td>
            <td><?php echo $winemaker->phone; ?></td>
        </tr>
    <?php endforeach; ?>
</table>

</body>
</html>
