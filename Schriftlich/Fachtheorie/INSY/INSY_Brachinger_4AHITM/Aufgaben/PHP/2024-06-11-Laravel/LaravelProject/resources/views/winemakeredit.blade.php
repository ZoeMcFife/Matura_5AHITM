<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Winzer bearbeiten</title>
    <link href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css" rel="stylesheet">
</head>
<body class="bg-gray-100">

<div class="container mx-auto p-4">

    <h2 class="text-2xl mb-4">Winzer bearbeiten</h2>

    <form method="post" action="{{ url("/winemaker/{$winemaker->id}") }}">
        @csrf
        @method("put")

        <div class="mb-4">
            <label for="name" class="block mb-1">Name</label>
            <input id="name" name="name" type="text" placeholder="Name ..." class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                   value="{{ $winemaker->name }}">
        </div>
        <div class="mb-4">
            <label for="street" class="block mb-1">Straße</label>
            <input id="street" name="street" type="text" placeholder="Straße Hausnummer ..." class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                   value="{{ $winemaker->street }}">
        </div>
        <div class="mb-4">
            <label for="zipcode" class="block mb-1">Postleitzahl</label>
            <input id="zipcode" name="zipcode" type="text" placeholder="Postleitzahl ..." class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                   value="{{ $winemaker->zipcode }}">
        </div>
        <div class="mb-4">
            <label for="city" class="block mb-1">Ort</label>
            <input id="city" name="city" type="text" placeholder="Ort ..." class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                   value="{{ $winemaker->city }}">
        </div>
        <div class="mb-4">
            <label for="phone" class="block mb-1">Telefon</label>
            <input id="phone" name="phone" type="text" placeholder="Telefonnummer ..." class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                   value="{{ $winemaker->phone }}">
        </div>
        <div class="mb-4">
            <button type="submit" class="bg-blue-500 hover:bg-blue-700 text-white py-2 px-4 rounded">Speichern</button>
        </div>

    </form>

    <form method="post" action="{{ url("/winemaker/{$winemaker->id}") }}">
        @csrf
        @method("delete")

        <button type="submit" class="bg-red-500 hover:bg-red-700 text-white py-2 px-4 rounded">Löschen</button>

    </form>

    @if ($errors->any())
        <div class="alert alert-danger col-md-8">
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif

</div>

</body>
</html>
