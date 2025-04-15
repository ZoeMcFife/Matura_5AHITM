<?php

use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/hello1', function ()
{
   return 'Hello World!';
});

Route::get('/hello2/{abc}', function ($abc)
{
    return "Hello $abc!";
});

Route::get('/hello3/{abc?}', function ($abc='Kitty')
{
    return "Hello $abc!";
});

Route::get('dbtest', function ()
{
    if (DB::connection()->getDatabaseName())
    {
        echo 'Connected successfully to db ' . DB::connection()->getDatabaseName();
    }
});

Route::get('winemaker1', function ()
{
    $winemakers=\App\Models\Winemaker::all();

    echo '<pre>';
    print_r($winemakers);
    echo '</pre>';
});

Route::get('winemaker2', [App\Http\Controllers\WinemakerController::class, 'index2']);

Route::get('winemaker3', [App\Http\Controllers\WinemakerController::class, 'index3']);

Route::get('winemaker4', [App\Http\Controllers\WinemakerController::class, 'index4']);

Route::get('winemaker5', [App\Http\Controllers\WinemakerController::class, 'index5']);

Route::resource('winemaker', 'App\Http\Controllers\WinemakerController');
