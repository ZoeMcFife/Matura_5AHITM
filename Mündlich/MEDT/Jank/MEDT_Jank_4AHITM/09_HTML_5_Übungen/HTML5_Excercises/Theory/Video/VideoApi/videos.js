document.addEventListener('DOMContentLoaded', (event) =>
{
    let videoElement = document.getElementById('video-api');
    let videoSources = ["collie.mp4", "starman.mp4", "bulk.mp4"];
    let currentVideoIndex = 0;

    videoElement.muted = true

    videoElement.src = videoSources[currentVideoIndex];
    videoElement.play();

    videoElement.addEventListener('ended', function()
    {
        currentVideoIndex++;

        if (currentVideoIndex < videoSources.length)
        {
            videoElement.src = videoSources[currentVideoIndex];
            videoElement.play();
        }
    });
});

function unmute()
{
    let videoElement = document.getElementById('video-api');
    videoElement.muted = false;
}
