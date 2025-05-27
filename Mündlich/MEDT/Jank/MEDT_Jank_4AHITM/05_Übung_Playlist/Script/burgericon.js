document.addEventListener("DOMContentLoaded", () =>
{
  const nav = document.querySelector('nav');
  const burgerIcon = document.getElementById('Burger-icon');
  const main = document.getElementsByTagName("main")[0];

  const toggleMenu = () =>
  {
    burgerIcon.classList.toggle('open');
    nav.classList.toggle('open');
    main.classList.toggle('blur');

  };

  burgerIcon.addEventListener('click', toggleMenu);
});
