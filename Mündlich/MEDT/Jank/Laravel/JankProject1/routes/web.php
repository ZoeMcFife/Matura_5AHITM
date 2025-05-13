<?php

use App\Http\Controllers\InvoiceController;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});


Route::get('test', function() {
    return "test!";
});

Route::resource('/invoice', InvoiceController::class);

Route::get('invoice-list', [InvoiceController::class, 'invoiceList']);
