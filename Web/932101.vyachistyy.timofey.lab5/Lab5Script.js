var n1 = document.querySelectorAll('.popupDiv')[0];
var n2 = document.querySelectorAll('.popupDiv')[1];
var n3 = document.querySelectorAll('.popupDiv')[2];
var white = document.querySelector('#white');
function showNews1()
{
	white.style.display = 'block';
	n1.style.display = 'block';
}
function showNews2()
{
	white.style.display = 'block';
	n2.style.display = 'block';
}
function showNews3()
{
	white.style.display = 'block';
	n3.style.display = 'block';
}
function closeNews()
{
	white.style.display = 'none';
	n1.style.display = 'none';
	n2.style.display = 'none';
	n3.style.display = 'none';
}