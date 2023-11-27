const curtain = document.querySelector('.curtain');
const lamp = document.querySelector('.lamp');
const hang = document.querySelector('.hang');
const content = document.querySelector('.content');
const rabbit = document.querySelector('.rabbit');
const pigeon = document.querySelector('.pigeon');

curtain.addEventListener('click', () => {
  curtain.classList.toggle('active');
});

lamp.addEventListener('mousedown', () => {
  hang.style.transform = `translateY(5px)`;
});

lamp.addEventListener('mouseup', () => {
  hang.style.transform = `translateY(0px)`;
});

lamp.addEventListener('click', () => {
  content.classList.toggle('hidden');
});

function changeAnimals()
{
  rabbit.classList.toggle('putInHat');
  rabbit.classList.toggle('pullOutOfHat');
  pigeon.classList.toggle('putInHat');
  pigeon.classList.toggle('pullOutOfHat');
}

rabbit.addEventListener('click', changeAnimals);

pigeon.addEventListener('click', changeAnimals);

