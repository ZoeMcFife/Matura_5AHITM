let xmlhttp = new XMLHttpRequest();
let url = "data/animal.json";

xmlhttp.onreadystatechange = function ()
{
    if (this.readyState === 4 && this.status === 200)
    {
        let myAnimals = JSON.parse(this.responseText);
        displayAnimals(myAnimals.animals);
    }
};

xmlhttp.open("GET", url, true);
xmlhttp.send();


function displayAnimals(myAnimals)
{
    for (let i = 0; i < myAnimals.length; i++)
    {
        appendAnimalToGallery(myAnimals[i])
    }
}

function appendAnimalToGallery(animal)
{
    document.getElementById("gallery").append(createAnimalCard(animal));
}

function openAnimalDetails(animal)
{
    let root = document.getElementsByTagName("body")[0];

    let blur = document.getElementById("blur-div");

    let animalDetailDiv = document.createElement("div");
    animalDetailDiv.setAttribute("class", "animalDetailDiv");

    let closeButton = document.createElement("button");
    closeButton.innerText = "X";
    closeButton.onclick = function ()
    {
        animalDetailDiv.remove();
        blur.removeAttribute("class");
    }

    let img = document.createElement("img");
    img.setAttribute("src", "images/" + animal.img);

    let header = document.createElement("h3");
    header.innerText = animal.name;

    animalDetailDiv.append(closeButton);
    animalDetailDiv.append(img);
    animalDetailDiv.append(header);

    root.append(animalDetailDiv);

    blur.setAttribute("class", "blur");
}

function openPartnerDetails(animal)
{
    let root = document.getElementsByTagName("body")[0];

    let blur = document.getElementById("blur-div");

    let animalDetailDiv = document.createElement("div");
    animalDetailDiv.setAttribute("class", "animalDetailDiv");

    let closeButton = document.createElement("button");
    closeButton.innerText = "X";
    closeButton.onclick = function ()
    {
        animalDetailDiv.remove();
        blur.removeAttribute("class");
    }

    let header = document.createElement("h3");
    header.innerText = animal.name;

    let p = document.createElement("p");

    if (animal.partner !== undefined)
    {
        p.innerText = "I belong to ... " + animal.partner[0].firstname + " "+ animal.partner[0].lastname;
    }

    animalDetailDiv.append(closeButton);
    animalDetailDiv.append(header);
    animalDetailDiv.append(p);

    root.append(animalDetailDiv);

    blur.setAttribute("class", "blur");
}

function createAnimalCard(animal)
{
    let animalContainer = document.createElement("div");
    animalContainer.setAttribute("class", "animalContainer");

    let animalDiv = document.createElement("div");
    animalDiv.setAttribute("class", "animal");

    let img = document.createElement("img");
    img.setAttribute("src", "images/" + animal.img);
    img.onclick = function ()
    {
        openAnimalDetails(animal);
    }

    let header = document.createElement("h3");
    header.innerText = animal.name;

    let description = document.createElement("p");
    description.innerText = animal.description;

    let partner = document.createElement("p");

    if (animal.partner !== undefined)
    {
        partner.setAttribute("class", "partnerHighlight partner");
        partner.innerText = "I have a partner!";
        partner.onclick = function ()
        {
            openPartnerDetails(animal);
        }
    }
    else
    {
        partner.setAttribute("class", "partner");
        partner.innerText = "I don't have a partner!";
    }



    animalDiv.append(img);
    animalDiv.append(header);
    animalDiv.append(description);
    animalDiv.append(partner);
    
    animalContainer.append(animalDiv);

    return animalContainer;
}