let playlist_column_container = document.getElementById("playlist-column-container");
let blur_top = document.getElementById("blur-top");
let blur_bottom = document.getElementById("blur-bottom")

playlist_column_container.addEventListener('scroll', function () {
    const scrollTop = playlist_column_container.scrollTop;
    const scrollHeight = playlist_column_container.scrollHeight - playlist_column_container.clientHeight;

    // Calculate scroll position as a percentage
    const scrollPercentage = (scrollTop / scrollHeight) * 100;

    if (scrollPercentage === 0)
        blur_top.classList.remove("blur-playlist-on-scroll-top");
    else
        blur_top.classList.add("blur-playlist-on-scroll-top");

    if (scrollPercentage === 100)
        blur_bottom.classList.remove("blur-playlist-on-scroll-bottom");
    else
        blur_bottom.classList.add("blur-playlist-on-scroll-bottom");

});