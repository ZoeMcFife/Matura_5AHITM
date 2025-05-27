navigator.geolocation.getCurrentPosition(success, failure);

function success(pos)
{
    document.getElementById("coordinates").innerText = pos.coords.latitude + " " + pos.coords.longitude;
    console.log(pos.coords)
}

function failure()
{
    document.getElementById("coordinates").innerText = "Failure";
}

