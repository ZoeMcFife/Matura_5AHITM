
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Winzer</title>
    <link href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css" rel="stylesheet">
</head>
<body class="bg-gray-100">
<div class="container mx-auto p-4">
    <h2 class="text-2xl font-bold mb-4">Winzer</h2>
    <table class="table-auto w-full bg-white border border-gray-300">
        <thead>
        <tr class="bg-gray-200">
            <th class="px-4 py-2 text-left">ID</th>
            <th class="px-4 py-2 text-left">Name</th>
            <th class="px-4 py-2 text-left" colspan="2">Adresse</th>
            <th class="px-4 py-2 text-left">Telefon</th>
            <th class="px-4 py-2 text-left">Action</th>
        </tr>
        </thead>
        <tbody>
        @foreach ($winemakers as $index => $winemaker)
            <tr class="{{ $index % 2 == 0 ? 'bg-gray-100' : 'bg-white' }}">
                <td class="px-4 py-2">{{ $winemaker->id }}</td>
                <td class="px-4 py-2">{{ $winemaker->name }}</td>
                <td class="px-4 py-2">{{ $winemaker->street }}</td>
                <td class="px-4 py-2">{{ $winemaker->zipcode }} {{ $winemaker->city }}</td>
                <td class="px-4 py-2">{{ $winemaker->phone }}</td>
                <td class="px-4 py-2">
                    <a href="{{ url("/winemaker/{$winemaker->id}/edit") }}" class="bg-blue-500 hover:bg-blue-700 text-white py-1 px-2 rounded-sm">Bearbeiten</a>
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>

    <div class="mt-4">
        <a href="{{ url('/winemakers/create') }}" class="bg-blue-500 hover:bg-blue-700 text-white py-2 px-4 rounded">Neuer Winzer</a>
    </div>

    @if (session('status'))
        <div class="mt-4 bg-green-100 border border-green-400 text-green-700 px-4 py-3 rounded relative" role="alert">
            <span class="block sm:inline">{{ session('status') }}</span>
        </div>
    @endif
</div>
</body>
</html>
