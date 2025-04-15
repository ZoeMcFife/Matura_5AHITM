<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Winzer</title>
    <link href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css" rel="stylesheet">
</head>
<body>
<div class="container mx-auto p-4">
    <h2 class="text-2xl font-semibold mb-4">Winzer</h2>
    <table class="min-w-full bg-white border border-gray-300">
        <thead>
        <tr>
            <th class="px-4 py-2 border-b text-left">ID</th>
            <th class="px-4 py-2 border-b text-left">Name</th>
            <th class="px-4 py-2 border-b text-left" colspan="2">Adresse</th>
            <th class="px-4 py-2 border-b text-left">Telefon</th>
        </tr>
        </thead>
        <tbody>
        @foreach ($winemakers as $winemaker)
            <tr class="border-t {{ $loop->odd ? 'bg-gray-100' : '' }}">
                <td class="px-4 py-2">{{ $winemaker->id }}</td>
                <td class="px-4 py-2">{{ $winemaker->name }}</td>
                <td class="px-4 py-2">{{ $winemaker->street }}</td>
                <td class="px-4 py-2">{{ $winemaker->zipcode }} {{ $winemaker->city }}</td>
                <td class="px-4 py-2">{{ $winemaker->phone }}</td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
</body>
</html>
