let button = document.getElementById("button");
let container = document.querySelector(".container");
let mast = document.querySelector(".mast");
let sails = document.querySelectorAll(".sail");

document.getElementById("button").addEventListener("click", () => {
    button.classList.add("transformed");

    button.textContent = "Плывём";

    setTimeout(() => {
    mast.style.opacity = "1";
    mast.style.transform = "translateX(-50%) rotate(0deg)";
    }, 1000);

    setTimeout(() => {
    sails.forEach((sail) => {
        sail.style.opacity = "1";
        sail.style.transform = "translate(0, 0) scale(1)";
    });
    }, 2000);

    setTimeout(() => {
    container.classList.add("moving");
    }, 3000);
});
