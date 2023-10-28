var left = document.querySelector('#leftDiv');
var leftImg = document.querySelector('#leftDiv img');
var right = document.querySelector('#rightDiv');
var rightImg = document.querySelector('#rightDiv img');
function showLeft()
{
	leftImg.style.display = 'block';
	rightImg.style.display = 'none';
	left.style.width = '650px';
	right.style.width = '22px';
	right.style.right = '-650px';
	leftImg.style.width = '75%';
}
function showBoth()
{
	rightImg.style.display = 'block';
	leftImg.style.display = 'block';
	leftImg.style.width = '100%';
	rightImg.style.width = '100%';
	right.style.width = 'calc(224px * 1.5)';
	left.style.width = 'calc(224px * 1.5)';
	right.style.right = '-336px';
}
function showRight()
{
	rightImg.style.display = 'block';
	leftImg.style.display = 'none';
	right.style.width = '650px';
	left.style.width = '22px';
	right.style.right = '-22px';
	rightImg.style.width = '75%';
}