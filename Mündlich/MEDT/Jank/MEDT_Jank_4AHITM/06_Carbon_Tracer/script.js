class Location
{
    constructor(latitude, longitude, name)
    {
        this.latitude = latitude;
        this.longitude = longitude;
        this.name = name;
    }
}

class Route
{
    constructor(bbox, waypoints)
    {
        this.bbox = bbox;
        this.waypoints = waypoints;
    }
}

let currentRoutes = Array();
let routeIndex = -1;

const apiURLBase = "https://api.carbontracer.uni-graz.at";

const APICallType =
    {
        LOCATION: "location",
        ROUTE: "routing"
    }

const apiKey = "Q2d8Jdq7C76WqTvQ2a29w2xQwwzwJfTratFrkVQj";

const VehicleType=
    {
        CAR: "car",
        E_CAR: "e-car",
        BUS: "bus",
        E_BUS: "e-bus",
        TRAIN: "train"
    };

function createLocationRequestString(location)
{
    return apiURLBase + "/" + APICallType.LOCATION + "/" + apiKey + "/" + location;
}

function createRouteRequestString(vehicleType, start, destination)
{
    return apiURLBase + "/" + APICallType.ROUTE + "/" + apiKey + "/" + vehicleType + "/" + start.name + "/" + destination.name + "/options=waypoints,bbox";
}

async function getLocations()
{
    let startLocation = await getLocationCoordinates(document.getElementById('startPosition').value)
    let endLocation = await getLocationCoordinates(document.getElementById('endPosition').value)

    let locations = Array();
    locations[0] = startLocation;
    locations[1] = endLocation;

    return locations;
}

async function calculateRoute()
{
    let locations = await getLocations();

    currentRoutes = Array();

    let tbody = document.getElementById("table-body");
    tbody.replaceChildren();
    
    for (let type in VehicleType)
    {
        if (VehicleType.hasOwnProperty(type))
        {
            let value = VehicleType[type];

            let data = await getRouteData(value, locations)

            let bbox = new Array(2);
            bbox[0] = new Location(data.bbox[1], data.bbox[0], "bbox");
            bbox[1] = new Location(data.bbox[3], data.bbox[2], "bbox");

            let waypoints = Array();

            /* Waypoints are delivered differently for trains for some god forsaken reason */
            if (type === "TRAIN")
            {
                for (let point of data.wayPoints)
                {
                    if (point[1] === undefined || point[0] === undefined)
                    {
                        continue;
                    }

                    for (let p of point)
                    {
                        waypoints.push(new Location(p[1], p[0], "Waypoint"));
                    }
                }
            }
            else
            {
                for (let point of data.wayPoints[0])
                {
                    waypoints.push(new Location(point[1], point[0], "Waypoint"));
                }
            }



            let route = new Route(bbox, waypoints);
            
            currentRoutes.push(route);

            appendValuesToTable(type, data.distanceRoute, data.co2eq);
        }
    }
}

async function getRouteData(type, locations)
{
    let url = createRouteRequestString(type, locations[0], locations[1]);

    let response = await fetch(url,
        {
            headers: {
                'Accept': 'application/json'
            }
        });

    return (await response.json()).response.data;
}

function appendValuesToTable(vehicleType, distance, co2)
{
    let tbody = document.getElementById("table-body");

    const newRow = document.createElement("tr");

    const cell1 = document.createElement("td");
    cell1.textContent = vehicleType;
    newRow.appendChild(cell1);

    const cell2 = document.createElement("td");
    cell2.textContent = distance + " km";
    newRow.appendChild(cell2);

    const cell3 = document.createElement("td");
    cell3.textContent = co2 + " kg";
    newRow.appendChild(cell3);

    newRow.onclick = function () {
        switch (vehicleType) {
            case "CAR":
                routeIndex = 0;
                break;
            case "E_CAR":
                routeIndex = 1;
                break;
            case "BUS":
                routeIndex = 2;
                break;
            case "E_BUS":
                routeIndex = 3;
                break;
            case "TRAIN":
                routeIndex = 4;
                break;
        }

        initGoogleMap();
    };

    // Add the new-row class and append the row
    newRow.classList.add("new-row");
    tbody.appendChild(newRow);

    setTimeout(function ()
    {
        newRow.classList.add("new-row");
    }, 10);

    setTimeout(function ()
    {
        newRow.classList.remove("new-row");
    }, 500);
}

async function getLocationCoordinates(location)
{
    let url = createLocationRequestString(location);

    let response = await fetch(url,
        {
            headers: {
                'Accept': 'application/json'
            }
        });

    let data = (await response.json()).response.data;

    return new Location(data.latitude, data.longitude, location);
}


function initGoogleMap()
{
    initMap();
}


function initMap()
{
    const map = new google.maps.Map(document.getElementById("map"), {
        zoom: 10,
        center: { lat: (currentRoutes[routeIndex].bbox[0].latitude + currentRoutes[0].bbox[1].latitude) / 2, lng: (currentRoutes[routeIndex].bbox[0].longitude + currentRoutes[0].bbox[1].longitude) / 2 },
    });

    setMarkers(map);
}

function setMarkers(map)
{
    const image =
        {
        url: "red.png",
        // This marker is 20 pixels wide by 32 pixels high.
        size: new google.maps.Size(20, 20),
        // The origin for this image is (0, 0).
        origin: new google.maps.Point(0, 0),
        // The anchor for this image is the base of the flagpole at (0, 32).
        anchor: new google.maps.Point(0, 20),
    };
// Shapes define the clickable region of the icon. The type defines an HTML
// <area> element 'poly' which traces out a polygon as a series of X,Y points.
// The final coordinate closes the poly by connecting to the first coordinate.
    const shape =
        {
        coords: [1, 1, 1, 20, 18, 20, 18, 1],
        type: "poly",
    };

    for (let point of currentRoutes[routeIndex].waypoints)
    {
        new google.maps.Marker({
            position: { lat: point.latitude, lng: point.longitude },
            map,
            icon: image,
            shape: shape,
            title: "",
            zIndex: 500,
        });
    }
}

window.initMap = initMap;
