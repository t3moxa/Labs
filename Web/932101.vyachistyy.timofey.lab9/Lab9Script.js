const result = document.querySelector('#result');
var i;

function IsSpecial(s){
	if ((s == ".") || (s == "*") || (s== "/") || (s == "+") || (s == "-"))
		return 1;
	else
		return 0;
}

function Calc(){
	var array = result.value;
	for (i = 1; i < array.length; i++) {
		if (IsSpecial(array[i]) && IsSpecial(array[i-1])){
			alert("Выражение составлено неправильно!");
			return 0;
		}
	}
	result.value = eval(result.value)
}