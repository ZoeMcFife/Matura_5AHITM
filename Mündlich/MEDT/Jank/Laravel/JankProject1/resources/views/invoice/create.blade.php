@extends('layouts.app')

@section('title', 'Create Invoice')

@section('content')
    <h2>Create New Invoice</h2>

    @if ($errors->any())
        <div style="color: red;">
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif

    <form action="{{ route('invoice.store') }}" method="POST">
        @csrf
        <label>Name:</label>
        <input type="text" name="name" required><br>

        <label>Net Price:</label>
        <input type="number" step="0.01" name="priceNet" required><br>

        <label>Gross Price:</label>
        <input type="number" step="0.01" name="priceGross" required><br>

        <label>VAT:</label>
        <input type="number" step="0.01" name="vat" required><br>

        <label>User Clearing:</label>
        <input type="number" step="0.01" name="userClearing" required><br>

        <label>Clearing Date:</label>
        <input type="datetime-local" name="clearingDate" required><br>

        <button type="submit">Save Invoice</button>
    </form>

    <a href="{{ route('invoice.index') }}">Back to Invoices</a>
@endsection
