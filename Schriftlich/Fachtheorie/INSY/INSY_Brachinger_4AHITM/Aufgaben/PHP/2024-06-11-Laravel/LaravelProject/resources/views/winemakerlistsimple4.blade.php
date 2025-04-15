<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <title>Winzer</title>
</head>
<body>
<div class="container">
    <h2>Winzer</h2>
    <table class="table table-striped table-bordered">
        <thead>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th colspan="2">Adresse</th>
            <th>Telefon</th>
        </tr>
        </thead>
        <tbody>
        @foreach ($winemakers as $winemaker)
            <tr>
                <td>{{ $winemaker->id }}</td>
                <td>{{ $winemaker->name }}</td>
                <td>{{ $winemaker->street }} </td>
                <td>{{ $winemaker->zipcode }} {{ $winemaker->city }}</td>
                <td>{{ $winemaker->phone }}</td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
