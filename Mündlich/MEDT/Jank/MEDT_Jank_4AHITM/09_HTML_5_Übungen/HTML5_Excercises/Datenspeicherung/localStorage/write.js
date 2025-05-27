function writeToLocalStorage()
{
    let input = document.getElementById("input");

    localStorage.setItem("dog", input.value);

    input.value = "";
}

