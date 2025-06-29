---
aliases:
context:
- "[[HTML]]"
- "[[JavaScript]]"
---

# Form validation

Client-side form validation ensures that user inputs meet specified criteria before submission, enhancing user experience and reducing server load. HTML5 provides built-in validation features, and JavaScript can be used for more customized control.

---

### Client-side form validation
The form data needs to be validated before it is sent to the server.
When the user is on a website and starts entering data in the input fields, if the data is not in the expected format, or doesn't meet the requirements, usually the user is presented with a text explaining what is wrong - this is called *form validation*.

Validation done in the browser is called *client-side validation*.
##### Two types of validation:
- HTML
- JS

When an element is valid the element matches the :valid CSS pseudo-class, which lets you apply a specific style to valid elements.
If the user tries to send invalid data, the browser will block the form submission and display an error message. 

 ### Built-In HTML Validation Features
1.Required Fields: Use the required attribute to make fields mandatory.
2.Input Types: Utilize types like email, number, and url to enforce input formats.
3.Constraints: Apply attributes such as min, max, step, maxlength, and pattern to define acceptable input ranges and formats.
4.Datalist: Offer predefined options using the <datalist> element for inputs.
5.Styling Invalid Inputs: CSS pseudo-classes like :invalid and :valid allow visual cues for input validity.


### JavaScript Validation Enhancements
For more control over validation:
Custom Error Messages: Use the Constraint Validation API's setCustomValidity() method to define custom error messages.

``` javascript
	const emailInput = document.querySelector('#email');
	emailInput.addEventListener('input', () => {
	  if (emailInput.validity.typeMismatch) {
	    emailInput.setCustomValidity('Please enter a valid email address.');
	  } else {
	    emailInput.setCustomValidity('');
	  }
	});
```
Real-Time Validation: Listen to events like input or blur to validate fields as the user interacts with them.