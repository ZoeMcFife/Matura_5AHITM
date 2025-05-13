@extends('layouts.app')

@section('title', 'Edit Invoice')

@section('content')
    <h2>Edit Invoice</h2>

    @if ($errors->any())
        <div style="color: red;">
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif

    <form action="{{ route('invoice.update', $invoice) }}" method="POST">
        @csrf
        @method('PUT')

        <label>Name:</label>
        <input type="text" name="name" value="{{ $invoice->name }}" required><br>

        <label>Net Price:</label>
        <input type="number" step="0.01" name="priceNet" value="{{ $invoice->priceNet }}" required><br>

        <label>Gross Price:</label>
        <input type="number" step="0.01" name="priceGross" value="{{ $invoice->priceGross }}" required><br>

        <label>VAT:</label>
        <input type="number" step="0.01" name="vat" value="{{ $invoice->vat }}" required><br>

        <label>User Clearing:</label>
        <input type="number" step="0.01" name="userClearing" value="{{ $invoice->userClearing }}" required><br>

        <label>Clearing Date:</label>
        <input type="datetime-local" name="clearingDate" value="{{ $invoice->clearingDate }}" required><br>

        <button type="submit">Update Invoice</button>
    </form>

    <!-- Delete Button -->
    <form action="{{ route('invoice.destroy', $invoice) }}" method="POST" onsubmit="return confirm('Are you sure you want to delete this invoice?');" style="margin-top: 10px;">
        @csrf
        @method('DELETE')
        <button type="submit" style="color: red;">Delete Invoice</button>
    </form>

    <a href="{{ route('invoice.index') }}">Back to Invoices</a>
@endsection
