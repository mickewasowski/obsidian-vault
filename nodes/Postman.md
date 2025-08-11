---
aliases:
context:
- "[[Web]]"
---

#wip

# Postman

HTTP request, Socket requests, and more

---
### Pre-request scripts
Requirements:
1. Runs before your request is sent. Its job is to generate data (like a timestamp, a random number, or a calculated value) and store it in a Postman variable.
2. In the Body tab you use Postman's varuable syntax `{{variable_name}}` as a placeholder where you want the dynamic data to be inserted.

``` json
// Body tab
{
	"username": "{{dynamic_username}}",
	"role": "user",
}
```

``` json
//Pre-request script tab
// Generate a dynamic value. In this case, a username with a random number.
let randomNumber = Math.floor(Math.random() * 1000);
let username = `user_${randomNumber}`;

// Set a temporary "local" variable that Postman will use for this request.
// The first argument is the variable name (must match the placeholder in the body).
// The second argument is the value to assign.
pm.variables.set("dynamic_username", username);

// (Optional) You can log the value to the Postman Console to debug.
console.log("Set dynamic username to: " + pm.variables.get("dynamic_username"));
```

