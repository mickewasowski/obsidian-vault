---
aliases:
context:
- "[[Web Development]]"
---

# C#

---

### How to create an app

*`dotnet new list`* will list all the templates in the cli

For a Backend API:
```bash
dotnet new webapi -> scafolds a basic api project with one endpoint

dotnet run -> starts the server

dotnet add package Newtonsoft.Json -> adds package
```


### Configuring database

1. Create a Models folder - here we create a class for each table we want to create in the database. In this class we describe all the columns and their types and restrictions. Think of this like a template.
2. Create a `AppDbContext` class which inherits the `DbContext` from `Microsoft.EntityFrameworkCore`. In this file we also create a constructor for initiallization, and all the `DbSet`s we want (actually describe the tables we want to create);
3. In `Program.cs` we initialize the db conntection.
4. `dotnet ef migrations add InitialCreate` - run this in the terminal in order to create the database. This generates a migrations folder with a snapshot and a timestamped file describing what was created/modified.
5. `dotnet ef database update` - it will execute the last migration file. It also generates a `.db` file.


### Configure Controller files

1. Create a Controllers folder. Create a Controller file for each DB table you'd like to access/modify.
2. Create all the endpoints in each Controller file.
