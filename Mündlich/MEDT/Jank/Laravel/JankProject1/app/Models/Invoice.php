<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Invoice extends Model
{
    protected $table = "invoice";
    protected $fillable = ['name', 'priceNet', 'priceGross', 'vat', 'userClearing', 'clearingDate'];
}
