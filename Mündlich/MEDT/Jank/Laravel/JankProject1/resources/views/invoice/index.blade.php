@extends('layouts.app')

@section('title', 'Invoices')

@section('content')

    <div class="container mb-5 mt-5">
       <h2>Invoices</h2>
       <a href="{{ route('invoice.create') }}" class="btn btn-primary">Create New Invoice</a>

       @if(session('success'))
           <p style="color: green;">{{ session('success') }}</p>
       @endif
    </div>

    <div class="container mt-5">
        <h3>Really Fancy Datatable oooooo</h3>
        <table class="table table-bordered" id="laravel_datatable">
            <thead>
            <tr>
                <th>Name</th>
                <th>Net Price</th>
                <th>Gross Price</th>
                <th>VAT</th>
                <th>User Clearing</th>
                <th>Clearing Date</th>
            </tr>
            </thead>
        </table>
    </div>
    </table>
@endsection

<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script src="https://cdn.datatables.net/1.10.21/js/jquery.dataTables.min.js"></script>


<script>
    $(document).ready(function () {
        $('#laravel_datatable').DataTable({
            processing: true,
            serverSide: true,
            ajax: "{{ url('invoice-list') }}",
            pageLength: 5,
            language: {
                processing: '<div class="spinner"></div>'
            },
            columns: [
                {
                    data: 'name',
                    name: 'name',
                    render: function(data, type, row) {
                        // Format invoice number as a link to the edit page (adjust the URL as needed)
                        return '<a href="/invoice/' + row.id + '/edit">' + data + '</a>';
                    }
                },
                { data: 'priceNet', name: 'priceNet' },
                { data: 'priceGross', name: 'priceGross' },
                { data: 'vat', name: 'vat' },
                { data: 'userClearing', name: 'userClearing' },
                {
                    data: 'clearingDate',
                    name: 'clearingDate',
                    render: function(data, type, row) {
                        // Format the date as dd.mm.yyyy
                        if (data) {
                            var date = new Date(data);
                            var day = ("0" + date.getDate()).slice(-2);
                            var month = ("0" + (date.getMonth() + 1)).slice(-2);
                            var year = date.getFullYear();
                            return day + "." + month + "." + year;
                        }
                        return data;
                    }
                }
            ],
            columnDefs: [
                {
                    targets: 4, // Index for userClearing column
                    createdCell: function (td, cellData, rowData, row, col) {
                        if (typeof cellData === 'string' && cellData.trim() === '') {
                            $(td).css('background-color', 'LightCoral');
                        } else if (cellData) {
                            $(td).css('background-color', 'LightGreen');
                        } else {
                            $(td).css('background-color', 'LightCoral');
                        }
                    }
                }
            ]
        });
    });

</script>
