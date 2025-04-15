<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class WineMakerSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        DB::table('wine_makers')->delete();

        DB::table('wine_makers')->insert([
            'name' => 'Lackner Tinnacher',
            'street' => 'Steinback 8',
            'zipcode' => 4567,
            'city' => 'Gamlitz',
            'phone' => '1234567'
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Weingut Prager',
            'street' => 'Weissenkirchen 48',
            'zipcode' => 3610,
            'city' => 'Weissenkirchen',
            'phone' => '1234567'
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Weingut Emmerich Knoll',
            'street' => 'Unterloiben 10',
            'zipcode' => 3601,
            'city' => 'Unterloiben',
            'phone' => '1234456'
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Weingut F.X.Pichler',
            'street' => 'Unterloiben 27',
            'zipcode' => 3601,
            'city' => 'Unterloiben',
            'phone' => '11122233'
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Weingut Spätlese',
            'street' => 'Weintalstraße 23',
            'zipcode' => 1136,
            'city' => 'Wien',
            'phone' => null
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Freie Weingärten Wachau',
            'street' => 'Kremstalstraße 23',
            'zipcode' => 3600,
            'city' => 'Krems',
            'phone' => '2304002'
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Stiftskellerei',
            'street' => null,
            'zipcode' => null,
            'city' => null,
            'phone' => null
        ]);
        DB::table('wine_makers')->insert([
            'name' => 'Weingut Biegler',
            'street' => 'Wienerstraße 88',
            'zipcode' => 2352,
            'city' => 'Gumpoldskirchen',
            'phone' => '54564565'
        ]);
    }
}
