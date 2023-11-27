document.addEventListener('DOMContentLoaded', function() {
    var inputDiv = document.querySelector('.InputDiv');
    var inputLine = document.querySelector('.InputLine');
    var saveButton = document.getElementsByName('save')[0];
    var addElementButton = document.getElementsByName('add')[0];

    addElementButton.addEventListener('click', function(){
        var newElement = inputLine.cloneNode(true);
        var inputs = newElement.querySelectorAll('input[type="text"]');
        inputs.forEach(function(input) {
            input.value = '';
        });
        inputDiv.appendChild(newElement);
    });

    saveButton.addEventListener('click', function() {
        var inputs = document.querySelectorAll('.InputLine');
		var data = "{";
        inputs.forEach(function(input) {
            var keys = input.querySelectorAll('input[type="text"]');
			console.log(keys[0]);
			data += '"'+keys[0].value+'"'+':'+'"'+keys[1].value+'"'+',';
        });
		data = data.slice(0,-1);
		data += "}";
        console.log(data);
        var div = document.createElement("div");
        div.innerHTML = data;
        document.body.appendChild(div);
    });

    inputDiv.addEventListener('click', function(e) {
        if (e.target.name === 'up') {
            var inputClassDiv = e.target.parentNode;
            var previousSibling = inputClassDiv.previousElementSibling;
            if (previousSibling) {
                inputDiv.insertBefore(inputClassDiv, previousSibling);
            }
        } else if (e.target.name === 'down') {
            var inputClassDiv = e.target.parentNode;
            var nextSibling = inputClassDiv.nextElementSibling;
            if (nextSibling) {
                inputDiv.insertBefore(nextSibling, inputClassDiv);
            }
        } else if (e.target.name === 'delete') {
            var inputClassDiv = e.target.parentNode;
            inputDiv.removeChild(inputClassDiv);
        }
    });
});