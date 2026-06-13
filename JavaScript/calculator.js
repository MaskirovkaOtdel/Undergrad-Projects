// Attach event listener to the form submission
document.getElementById('calcForm').addEventListener('submit', function(e) {
  e.preventDefault(); // Prevent form from reloading the page

  let resultsDiv = document.getElementById('results');
  resultsDiv.innerHTML = ''; // Clear previous results

  // Process Unary Operations
  let numberUnary = parseFloat(document.getElementById('numberUnary').value);
  let unaryOps = document.querySelectorAll('input[name="unaryOp"]:checked');
  if (!isNaN(numberUnary) && unaryOps.length > 0) {
    let unaryResults = '<h3>Unary Operations Results:</h3><ul>';
    unaryOps.forEach(function(op) {
      let operation = op.value;
      let result;
      switch(operation) {
        case 'sqrt':
          result = (numberUnary < 0 ? 'NaN' : Math.sqrt(numberUnary));
          unaryResults += '<li>Square Root of ' + numberUnary + ': ' + result + '</li>';
          break;
        case 'square':
          result = Math.pow(numberUnary, 2);
          unaryResults += '<li>' + numberUnary + ' squared: ' + result + '</li>';
          break;
        case 'cube':
          result = Math.pow(numberUnary, 3);
          unaryResults += '<li>' + numberUnary + ' cubed: ' + result + '</li>';
          break;
        case 'sin':
          result = Math.sin(numberUnary);
          unaryResults += '<li>Sine of ' + numberUnary + ': ' + result + '</li>';
          break;
        case 'cos':
          result = Math.cos(numberUnary);
          unaryResults += '<li>Cosine of ' + numberUnary + ': ' + result + '</li>';
          break;
        case 'tan':
          result = Math.tan(numberUnary);
          unaryResults += '<li>Tangent of ' + numberUnary + ': ' + result + '</li>';
          break;
        case 'log':
          result = (numberUnary <= 0 ? 'NaN' : Math.log(numberUnary));
          unaryResults += '<li>Natural Logarithm of ' + numberUnary + ': ' + result + '</li>';
          break;
        case 'exp':
          result = Math.exp(numberUnary);
          unaryResults += '<li>Exponential of ' + numberUnary + ': ' + result + '</li>';
          break;
        case 'factorial':
          if (numberUnary < 0 || numberUnary % 1 !== 0) {
            result = 'Invalid input for factorial';
          } else {
            result = factorial(numberUnary);
          }
          unaryResults += '<li>Factorial of ' + numberUnary + ': ' + result + '</li>';
          break;
        default:
          break;
      }
    });
    unaryResults += '</ul>';
    resultsDiv.innerHTML += unaryResults;
  }

  // Process Binary Operations
  let number1 = parseFloat(document.getElementById('number1').value);
  let number2 = parseFloat(document.getElementById('number2').value);
  let binaryOps = document.querySelectorAll('input[name="binaryOp"]:checked');
  if (!isNaN(number1) && !isNaN(number2) && binaryOps.length > 0) {
    let binaryResults = '<h3>Binary Operations Results:</h3><ul>';
    binaryOps.forEach(function(op) {
      let operation = op.value;
      let result;
      switch(operation) {
        case 'add':
          result = number1 + number2;
          binaryResults += '<li>' + number1 + ' + ' + number2 + ' = ' + result + '</li>';
          break;
        case 'subtract':
          result = number1 - number2;
          binaryResults += '<li>' + number1 + ' - ' + number2 + ' = ' + result + '</li>';
          break;
        case 'multiply':
          result = number1 * number2;
          binaryResults += '<li>' + number1 + ' * ' + number2 + ' = ' + result + '</li>';
          break;
        case 'divide':
          result = (number2 === 0 ? 'Division by zero error' : number1 / number2);
          binaryResults += '<li>' + number1 + ' / ' + number2 + ' = ' + result + '</li>';
          break;
        case 'power':
          result = Math.pow(number1, number2);
          binaryResults += '<li>' + number1 + ' raised to ' + number2 + ' = ' + result + '</li>';
          break;
        default:
          break;
      }
    });
    binaryResults += '</ul>';
    resultsDiv.innerHTML += binaryResults;
  }
});

// A simple factorial function (iterative approach)
function factorial(n) {
  if (n === 0 || n === 1) return 1;
  let fact = 1;
  for (let i = 2; i <= n; i++) {
    fact *= i;
  }
  return fact;
}