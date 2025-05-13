@extends('layouts.app')

@section('title', 'Invoice Details')

@section('content')
    <h2>Invoice Details</h2>

    <p><strong>Name:</strong> {{ $invoice->name }}</p>
    <p><strong>Net Price:</strong> {{ $invoice->priceNet }}</p>
    <p><strong>Gross Price:</strong> {{ $invoice->priceGross }}</p>
    <p><strong>VAT:</strong> {{ $invoice->vat }}</p>
    <p><strong>User Clearing:</strong> {{ $invoice->userClearing }}</p>
    <p><strong>Clearing Date:</strong> {{ $invoice->clearingDate }}</p>

    <a href="{{ route('invoice.edit', $invoice) }}">Edit Invoice</a> |
    <a href="{{ route('invoice.index') }}">Back to List</a>

    <form action="{{ route('invoice.destroy', $invoice) }}" method="POST" style="display:inline;">
        @csrf
        @method('DELETE')
        <button type="submit" onclick="return confirm('Are you sure?')">Delete</button>
    </form>
@endsection
