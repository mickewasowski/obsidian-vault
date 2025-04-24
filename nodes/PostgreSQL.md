---
aliases:
context:
- "[[Relational Database]]"
- "[[SQL]]"
---

#wip

# PostgreSQL

ad

---

# How to setup Postgres on Windows

1. Download the Postgres installer from the official site
	1.1.  You'll be asked to set a password for the super user (postgres)
	1.2. You can also set a custom port or use the default one

2. Start a Postgres server
	2.1. start psql (command line tool for connecting to your db)
	2.2. it will ask you to provide an IP address for the server (you can leave it empty which will set it as localhost)
	2.3. then it will ask you for the name of the db you want to connect to (postgres is the default name)
	2.4. then it will ask you for the port it is running on (the default one is 5432)
	2.5. then it will ask you for the username (default is postgres)
	2.6. then it will ask you for the password which you set upon installing it
	2.7. after successful connection the prompt will type out the name of the db you've connected to

> [!info] the default IP address for localhost is 127.0.0.1 

> [!tip] You can setup a psql command for the Command prompt so that when you type it it will launch the psql terminal. This is useful so that you dont have to look for the psql manually every time. 
> 1.Go to C:/Program files/PostgresSQL/{version number}/bin
> the above should be the actual path for the psql terminal
> 2. then search for env in your Windows search
> 3. then open Environment variables and under System variables look for Path, select it and click edit, then select new and paste the above path and then click okay
> 4. then close any other command prompts if you had any open and then open a new one
> 5. type psql and if you get a prompt asking for password then you succeeded

<br/>

# PSQL commands

Every psql command starts with \

> \? 
> this lists the different commands that you have available

> \l 
> lists all of the dbs you have in your instance

> CREATE DATABASE DB_NAME; 
> this creates a new database

> \c db_name 
> this connects you to the provided db

> ``` sql
> CREATE TABLE table_name (
> 		id INT,
> 		name VARCHAR(char_limit),
> 		on_sale boolean
> );
> ```
>  this creates a new table with the provided columns and their types

> \d
> lists all the tables

> \d table_name 
> lists all the table's columns and their types

> ALTER TABLE table_name ADD COLUMN column_name column_type; 
> this adds a new column to the specified table

> ALTER TABLE table_name DROP COLUMN column_name; 
> this deletes the column from the table

> DROP TABLE table_name;
> deletes the table

> DROP DATABASE db_name;
> deletes the database

All commands can be found here:
https://neon.tech/postgresql/tutorial