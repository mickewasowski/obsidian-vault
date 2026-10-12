---
aliases:
context:
  - "[[C#]]"
---

# C# create project

Initial scaffolding and some basic setup

---

### Install dotnet

```bash
sudo apt-get update  => refreshes the packages list

sudo apt-get install -y dotnet-sdk-10.0

dotnet --info => verifies the installation
```

### Create project

```bash

dotnet new gitignore

dotnet new web -n PeopleApi -f net10.0 -o .
```

- `web` - selects the empty template
- `-n PeopleApi` - names the project
- `-f net10.0` - targets .net 10
- `-o .` - puts the files in the current directory

| File                           | Purpose                                                                                     |
| ------------------------------ | ------------------------------------------------------------------------------------------- |
| PeopleApi.csproj               | Defines the target .NET version, compiler settings, and eventually our package dependencies |
| Program.cs                     | Starts the application and defines its endpoints                                            |
| appsettings.json               | Holds application configuration, initially including logging settings                       |
| appsettings.Development.json   | Overrides configuration when running in the Development environment                         |
| Properties/launchSettings.json | Holds local launch settings, such as the environment and listening address                  |


### Start the project

```bash
dotnet run  => in the root folder

dotnet run --project ProjectName

```


### Install and start Postgres

```bash
sudo apt-get update
sudo apt-get install -y postgresql postgresql-client
sudo systemctl start postgresql
pg_isready -h localhost -p 5432  => this should produce localhost:5432 - accepting connections


sudo -u postgres psql  -> opens the postgres-cli 

CREATE ROLE people_api WITH LOGIN;  => creates the user credentials

people_api -> both username and pass

CREATE DATABASE people_db OWNER people_api;  => creates the database

\q  => exit postgresql


psql -h localhost -p 5432 -U people_api -d people_db -W  => test the db login

SELECT current_database(), current_user;
SHOW server_version
==> shows the db and the version
```

| Argument | Purpose |
|---|---|
| -h localhost | Connect to PostgreSQL on this machine using TCP |
| -p 5432 | Use port 5432 |
| -U people_api | Connect as the API’s role |
| -d people_db | Open our database |
| -W | Prompt for the password |
