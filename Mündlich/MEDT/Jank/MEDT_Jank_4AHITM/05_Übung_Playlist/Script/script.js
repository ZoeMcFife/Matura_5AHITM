document.addEventListener("DOMContentLoaded", () =>
{
    let xmlhttp = new XMLHttpRequest();
    let url = "Data/JSON/playlists.json";

    xmlhttp.onreadystatechange = function ()
    {
        if (this.readyState === 4 && this.status === 200)
        {
            let playlist = JSON.parse(this.responseText);
            displayPlaylists(playlist);
        }
    };

    xmlhttp.open("GET", url, true);
    xmlhttp.send();

    function displayPlaylists(data)
    {
        const container = document.querySelector(".playlist-column");

        data.playlists.forEach(playlist =>
        {
            const cell = document.createElement("div");
            cell.classList.add("playlist");

            const img = document.createElement("img");
            img.setAttribute("src", `Data/Images/${playlist.cover}`);
            img.setAttribute("alt", `${playlist.name} cover image`);

            const name = document.createElement("p");
            name.textContent = `${playlist.name}`;

            cell.appendChild(img);
            cell.appendChild(name);
            container.appendChild(cell);
        });
    }
});