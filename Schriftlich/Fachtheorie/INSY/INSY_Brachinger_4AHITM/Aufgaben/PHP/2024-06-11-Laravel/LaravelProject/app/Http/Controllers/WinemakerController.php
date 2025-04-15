<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class WinemakerController extends Controller
{
    public function index()
    {
        $winemakers=\App\Models\Winemaker::all();
        return view('winemakerlist', ['winemakers'=>$winemakers]);
        //
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {

        $validatedData = $request->validate([
            'name' => 'required',
            'street' => 'nullable',
            'zipcode' => 'nullable',
            'city' => 'nullable',
            'phone' => 'nullable'
        ]);

        $winemaker = new \App\Models\Winemaker();
        $winemaker->name = $validatedData['name'];
        $winemaker->street = $validatedData['street'];
        $winemaker->zipcode = $validatedData['zipcode'];
        $winemaker->city = $validatedData['city'];
        $winemaker->phone = $validatedData['phone'];
        $winemaker->save();

        return redirect('/winemaker')->with('status', "Winzer {$winemaker->name} hinzugefügt.");

    }

    /**
     * Display the specified resource.
     */
    public function show(string $id)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(string $id)
    {
        $winemaker = \App\Models\Winemaker::find($id);

        return view('winemakeredit')->with('winemaker', $winemaker);
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, string $id)
    {
        $winemaker = \App\Models\Winemaker::find($id);

        $validatedData = $request->validate([
            'name' => 'required',
            'street' => 'nullable',
            'zipcode' => 'nullable',
            'city' => 'nullable',
            'phone' => 'nullable'
        ]);

        $winemaker->name = $validatedData['name'];
        $winemaker->street = $validatedData['street'];
        $winemaker->zipcode = $validatedData['zipcode'];
        $winemaker->city = $validatedData['city'];
        $winemaker->phone = $validatedData['phone'];

        $winemaker->save();

        //echo "Winzer {$winemaker->name} geändert.";
        return redirect('/winemaker')->with('status', "Winzer {$winemaker->name} geändert.");
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(string $id)
    {
        //
    }


    public function index2(): void
    {
        $winemakers=\App\Models\Winemaker::all();
        echo '<pre>';
        print_r($winemakers);
        echo '</pre>';
    }

    public function index3()
    {
        $winemakers=\App\Models\Winemaker::all();
        return view('winemakerlistsimple3', ['winemakers'=>$winemakers]);
    }

    public function index4()
    {
        $winemakers=\App\Models\Winemaker::all();
        return view('winemakerlistsimple4', ['winemakers'=>$winemakers]);
    }

    public function index5()
    {
        $winemakers=\App\Models\Winemaker::all();
        return view('winemakerlistsimple5', ['winemakers'=>$winemakers]);
    }
}
