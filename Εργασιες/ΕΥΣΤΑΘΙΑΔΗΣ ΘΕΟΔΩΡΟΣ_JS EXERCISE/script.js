let output = document.getElementById('output');

function appendNumber(num) {
    output.value += num;
}

function appendOperator(operator) {
    output.value += ` ${operator} `;
}

function appendDot() {
    if (!output.value.endsWith('.')) {
        output.value += '.';
    }
}

function appendBrackets() {
    let countOpen = (output.value.match(/\(/g) || []).length;
    let countClose = (output.value.match(/\)/g) || []).length;
    output.value += countOpen > countClose ? ')' : '(';
}

function toggleSign() {
    if (output.value) {
        output.value = eval(`-(${output.value})`);
    }
}

function deleteLast() {
    output.value = output.value.slice(0, -1);
}

function clearOutput() {
    output.value = '';
}

function power() {
    output.value += ' ** ';
}

function squareRoot() {
    let num = parseFloat(output.value);
    if (num < 0) {
        alert('Σφάλμα: Δεν μπορεί να υπολογιστεί η ρίζα αρνητικού αριθμού.');
        return;
    }
    output.value = Math.sqrt(num);
}

function factorial() {
    let num = parseInt(output.value);
    if (num < 0 || num > 452) {
        alert('Σφάλμα: Παραγοντικό μόνο για αριθμούς 0-452.');
        return;
    }
    let fact = 1;
    for (let i = 2; i <= num; i++) {
        fact *= i;
    }
    output.value = fact;
}

function randomNumber() {
    output.value = Math.floor(Math.random() * 101);
}

function calculate() {
    try {
        if (output.value.includes('/ 0')) {
            throw new Error('Διαίρεση με το μηδέν δεν επιτρέπεται!');
        }
        output.value = new Function('return ' + output.value)();
    } catch (error) {
        alert('Σφάλμα: Μη έγκυρη πράξη.');
        output.value = '';
    }
}
