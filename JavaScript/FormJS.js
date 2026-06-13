// Activate form submission
const form = document.getElementById('MyForm');
const outputDiv = document.getElementById('output');

// Event listener for form submission
form.addEventListener('submit', function (event) {
    event.preventDefault(); // Prevent the form from refreshing the page

    // Grab information from the form
    let name = document.getElementById('name').value;
    let email = document.getElementById('email').value;
    let age = document.getElementById('age').value;

    // Show user the input data in a table format
    outputDiv.innerHTML = `
        <h2>Submitted Information:</h2>
        <table>
            <tr>
                <td><b>Name:</b></td>
                <td>${name}</td>
            </tr>
            <tr>
                <td><b>Email Address:</b></td>
                <td>${email}</td>
            </tr>
            <tr>
                <td><b>Age:</b></td>
                <td>${age}</td>
            </tr>
        </table>
    `;
});
