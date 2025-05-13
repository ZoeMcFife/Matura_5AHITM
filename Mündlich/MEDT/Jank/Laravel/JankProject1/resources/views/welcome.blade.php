{{-- Welcome Page --}}
@extends('layouts/app')

@section('title', 'Welcome')

@section('content')
    <h2>Welcome to My Laravel Site</h2>
    <p>We are glad to have you here. Explore our content and enjoy your stay!</p>

    <p><a href="{{ route('invoice.index') }}">View Invoices</a></p>
@endsection
