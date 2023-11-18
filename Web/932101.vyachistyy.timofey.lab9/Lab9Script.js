const result = document.getElementById('result');
function Equal(){
	console.log(result.value);
	result.value = eval(result.value);
	console.log(result.value);
}
