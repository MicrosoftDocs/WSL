---
title: Add or connect a database with WSL
description: Learn how to set up MySQL MongoDB, PostgreSQL, SQLite, Microsoft SQL Server, or Redis on the Windows Subsystem for Linux.
ms.date: 03/04/2022
ms.topic: article
---

# Get started with databases on Windows Subsystem for Linux

This step-by-step guide will help you get started connecting your project in WSL to a database. Get started with MySQL, PostgreSQL, MongoDB, Redis, Microsoft SQL Server, or SQLite.

## Prerequisites

- Running Windows 10, [updated to version 2004](ms-settings:windowsupdate), **Build 19041** or later.
- [Install WSL and create a user name and password for the Linux distribution](../install.md).
- Linux distribution [running in WSL 2 mode](../basic-commands.md#set-wsl-version-to-1-or-2).

## Differences between database systems

The most [popular choices](https://insights.stackoverflow.com/survey/2019#technology-_-databases) for a database system include:

- [MySQL](https://www.mysql.com/why-mysql/) (SQL)
- [PostgreSQL](https://www.postgresql.org/about/) (SQL)
- [Microsoft SQL Server](/sql) (SQL)
- [SQLite](https://www.sqlite.org/about.html) (SQL)
- [MongoDB](https://www.mongodb.com/what-is-mongodb) (NoSQL)
- [Redis](https://redis.io/topics/introduction) (NoSQL)

**MySQL** is an open-source SQL relational database, organizing data into one or more tables in which data types may be related to each other. It is vertically scalable, which means one ultimate machine will do the work for you. It is currently the most widely used of the four database systems.

**PostgreSQL** (sometimes referred to as Postgres) is also an open-source SQL relational database with an emphasis on extensibility and standards compliance. It can handle JSON now too, but it is generally better for structured data, vertical scaling, and ACID-compliant needs like eCommerce and financial transactions.

**Microsoft SQL Server** includes SQL Server on Windows, SQL Server on Linux, and SQL on Azure. These are also relational database management systems set up on servers with primary function of storing and retrieving data as requested by software applications.

**SQLite** is an open-source self-contained, file-based, “serverless” database, known for its portability, reliability, and good performance even in low-memory environments.

**MongoDB** is an open-source NoSQL document database designed to work with JSON and store schema-free data. It is horizontally scalable, which means multiple smaller machines will do the work for you. It's good for flexibility and unstructured data, and caching real-time analytics.

**Redis** is is an open-source NoSQL in-memory data structure store. It uses key-value pairs for storage instead of documents. Redis is known for its flexibility, performance, and wide language support. It’s flexible enough to be used as a cache or message broker and can use data structures like lists, sets, and hashes.

The sort of database you choose should depend on the type of application you will be using the database with. We recommend that you look up the advantages and disadvantages of structured and unstructured databases and choose based on your use case.

## Install MySQL

To install MySQL on WSL (ie. Ubuntu):

1. Open your WSL terminal (ie. Ubuntu).
2. Update your Ubuntu packages: `sudo apt update`
3. Once the packages have updated, install MySQL with: `sudo apt install mysql-server`
4. Confirm installation and get the version number: `mysql --version`

You may also want to run the included security script. This changes some of the less secure default options for things like remote root logins and sample users. To run the security script:

1. Start a MySQL server: `sudo /etc/init.d/mysql start`
2. Start the security script prompts: `sudo mysql_secure_installation`
3. The first prompt will ask whether you’d like to set up the Validate Password Plugin, which can be used to test the strength of your MySQL password. You will then set a password for the MySQL root user, decide whether or not to remove anonymous users, decide whether to allow the root user to login both locally and remotely, decide whether to remove the test database, and, lastly, decide whether to reload the privilege tables immediately.

To open the MySQL prompt, enter: `sudo mysql`

To see what databases you have available, in the MySQL prompt, enter: `SHOW DATABASES;`

To create a new database, enter: `CREATE DATABASE database_name;`

To delete a database, enter: ` DROP DATABASE database_name;`

For more about working with MySQL databases, see the [MySQL docs](https://dev.mysql.com/doc/mysql-getting-started/en/).

To work with with MySQL databases in VS Code, try the [MySQL extension](https://marketplace.visualstudio.com/items?itemName=cweijan.vscode-mysql-client2).

## Install PostgreSQL

To install PostgreSQL on WSL (ie. Ubuntu):

1. Open your WSL terminal (ie. Ubuntu).
2. Update your Ubuntu packages: `sudo apt update`
3. Once the packages have updated, install PostgreSQL (and the -contrib package which has some helpful utilities) with: `sudo apt install postgresql postgresql-contrib`
4. Confirm installation and get the version number: `psql --version`

There are 3 commands you need to know once PostgreSQL is installed:

- `sudo service postgresql status` for checking the status of your database.
- `sudo service postgresql start`  to start running your database.
- `sudo service postgresql stop` to stop running your database.

The default admin user, `postgres`, needs a password assigned in order to connect to a database. To set a password:

1. Enter the command: `sudo passwd postgres`
2. You will get a prompt to enter your new password.
3. Close and reopen your terminal.

To run PostgreSQL with [psql](https://www.postgresql.org/docs/10/app-psql.html) shell:

1. Start your postgres service: `sudo service postgresql start`
2. Connect to the postgres service and open the psql shell: `sudo -u postgres psql`

Once you have successfully entered the psql shell, you will see your command line change to look like this: `postgres=#`

> [!NOTE]
> Alternatively, you can open the psql shell by switching to the postgres user with: `su - postgres` and then entering the command: `psql`.

To exit postgres=# enter: `\q` or use the shortcut key: Ctrl+D

To see what user accounts have been created on your PostgreSQL installation, use from your WSL terminal: `psql -c "\du"` ...or just `\du` if you have the psql shell open. This command will display columns: Account User Name, List of Roles Attributes, and Member of role group(s). To exit back to the command line, enter: `q`.

For more about working with PostgreSQL databases, see the [PostgreSQL docs](https://www.postgresql.org/docs/13/tutorial-createdb.html).

To work with with PostgreSQL databases in VS Code, try the [PostgreSQL extension](https://marketplace.visualstudio.com/items?itemName=ms-ossdata.vscode-postgresql).

## Install MongoDB

To install MongoDB (version 5.0) on WSL (Ubuntu 20.04):

1. Open your WSL terminal (ie. Ubuntu) and go to your home directory: `cd ~`
2. Update your Ubuntu packages: `sudo apt update`
3. Import the public key used by the MongoDB package management system: `wget -qO - https://www.mongodb.org/static/pgp/server-5.0.asc | sudo apt-key add -`
4. Create a list file for MongoDB: `echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/5.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-5.0.list`
5. Reload local package database: `sudo apt-get update`
6. Install MongoDB packages: `sudo apt-get install -y mongodb-org`
7. Confirm installation and get the version number: `mongod --version`
8. Make a directory to store data: `mkdir -p ~/data/db`
9. Run a Mongo instance: `sudo mongod --dbpath ~/data/db`
10. Check to see that your MongoDB instance is running with: `ps -e | grep 'mongod'`
11. To exit the MongoDB Shell, use the shortcut keys: Ctrl + C

> [!TIP]
> Installing MongoDB may require slightly different steps depending on the Linux distribution being used for installation. See the [MongoDB installation tutorials](https://docs.mongodb.com/manual/installation/#mongodb-installation-tutorials). Also note that MongoDB installation may differ depending on the version # that you are aiming to install. Use the version drop-down list in the top-left corner of the MongoDB documentation to select the version that aligns with your goal.

### MongoDB init system differences

In the example above we ran MongoDB directly. Other tutorials may start MongoDB using the operating system's built-in init system. You might see the command `sudo systemctl status mongodb` used in tutorials or articles. Currently WSL does not have support for `systemd` (a service management system in Linux).

You shouldn't notice a difference, but if a tutorial recommends using `sudo systemctl`, instead use: `sudo /etc/init.d/`. For example, `sudo systemctl status docker`, for WSL would be `sudo /etc/init.d/docker status` ...or you can also use `sudo service docker status`.

### Add the init script to start MongoDB as a service

The installation instructions above install a version of MongoDB that doesn't include a script automatically in `/etc/init.d/`. If you would like to use the service commands, you can download the init.d script for mongodb [from this source](https://github.com/mongodb/mongo/blob/master/debian/init.d), place that manually as a file at this path: `/etc/init.d/mongodb` and then you can start Mongo as a service using `sudo service mongodb start`.

1. Download the init.d script for MongoDB: `curl https://raw.githubusercontent.com/mongodb/mongo/master/debian/init.d | sudo tee /etc/init.d/mongodb >/dev/null`
2. Assign that script executable permissions: `sudo chmod +x /etc/init.d/mongodb`
3. Now you can use MongoDB service commands:
    - `sudo service mongodb status` for checking the status of your database. You should see a [Fail] response if no database is running.
    - `sudo service mongodb start`  to start running your database. You should see a [Ok] response.
    - `sudo service mongodb stop` to stop running your database.
4. Verify that you are connected to the database server with the diagnostic command: `mongo --eval 'db.runCommand({ connectionStatus: 1 })'` This will output the current database version, the server address and port, and the output of the status command. A value of `1` for the "ok" field in the response indicates that the server is working.

> [!NOTE]
> MongoDB has several default parameters, including storing data in /data/db and running on port 27017. Also, `mongod` is the daemon (host process for the database) and `mongo` is the command-line shell that connects to a specific instance of `mongod`.

VS Code supports working with MongoDB databases via the [Azure CosmosDB extension](https://marketplace.visualstudio.com/items?itemName=ms-azuretools.vscode-cosmosdb), you can create, manage and query MongoDB databases from within VS Code. To learn more, visit the VS Code docs: [Working with MongoDB](https://code.visualstudio.com/docs/azure/mongodb).

Learn more in the MongoDB docs:

- [Introduction to using MongoDB](https://docs.mongodb.com/manual/introduction/)
- [Create users](https://docs.mongodb.com/manual/tutorial/create-users/)
- [Connect to a MongoDB instance on a remote host](https://docs.mongodb.com/manual/mongo/#mongodb-instance-on-a-remote-host)
- [CRUD: Create, Read, Update, Delete](https://docs.mongodb.com/manual/crud/)
- [Reference Docs](https://docs.mongodb.com/manual/reference/)

## Install Microsoft SQL Server

To install SQL Server on WSL (ie. Ubuntu), follow this quickstart: [Install SQL Server and create a database on Ubuntu](/sql/linux/quickstart-install-connect-ubuntu).

> [!NOTE]
> Although it is possible to install and configure SQL Server on WSL, it is not a supported configuration. Additionally, SQL Server on Linux requires **systemd**, which is not included on WSL.

To work with Microsoft SQL Server databases in VS Code, try the [MSSQL extension](https://marketplace.visualstudio.com/items?itemName=ms-mssql.mssql).

## Install SQLite

To install SQLite on WSL (ie. Ubuntu):

1. Open your WSL terminal (ie. Ubuntu).
2. Update your Ubuntu packages: `sudo apt update`
3. Once the packages have updated, install SQLite3 with: `sudo apt install sqlite3`
4. Confirm installation and get the version number: `sqlite3 --version`

To create a test database, called "example.db", enter: `sqlite3 example.db`

To see a list of your SQLite databases, enter: `.databases`

To see the status of your database, enter: `.dbinfo ?DB?`

Database will be empty after creation. You can create a new table for your database with `CREATE TABLE empty (kol INTEGER);`.

Now entering the `.dbinfo ?DB?` will show the database you have created.

To exit the SQLite prompt, enter: `.exit`

For more information about working with a SQLite database, see the [SQLite docs](https://www.sqlite.org/quickstart.html).

To work with SQLite databases in VS Code, try the [SQLite extension](https://marketplace.visualstudio.com/items?itemName=mtxr.sqltools).

## Install Redis

To install Redis on WSL (ie. Ubuntu):

1. Open your WSL terminal (ie. Ubuntu).
2. Update your Ubuntu packages: `sudo apt update`
3. Once the packages have updated, install Redis with: `sudo apt install redis-server`
4. Confirm installation and get the version number: `redis-server --version`

To start running your Redis server: `sudo service redis-server start`

Check to see if redis is working (redis-cli is the command line interface utility to talk with Redis): `redis-cli ping` this should return a reply of "PONG".

To stop running your Redis server: `sudo service redis-server stop`

For more information about working with a Redis database, see the [Redis docs](https://redis.io/topics/quickstart).

To work with Redis databases in VS Code, try the [Redis extension](https://marketplace.visualstudio.com/items?itemName=cweijan.vscode-redis-client).

## See services running and set up profile aliases

To see the services that you currently have running on your WSL distribution, enter: `service --status-all`

Typing out `sudo service mongodb start` or `sudo service postgres start` and `sudo -u postgrest psql` can get tedious.  However, you could consider setting up aliases in your `.profile` file on WSL to make these commands quicker to use and easier to remember.

To set up your own custom alias, or shortcut, for executing these commands:

1. Open your WSL terminal and enter `cd ~` to be sure you're in the root directory.
2. Open the `.profile` file, which controls the settings for your terminal, with the terminal text editor, Nano: `sudo nano .profile`
3. At the bottom of the file (don't change the `# set PATH` settings), add the following:

    ```bash
    # My Aliases
    alias start-pg='sudo service postgresql start'
    alias run-pg='sudo -u postgres psql'
    ```

    This will allow you to enter `start-pg` to start running the postgresql service and `run-pg` to open the psql shell. You can change `start-pg` and `run-pg` to whatever names you want, just be careful not to overwrite a command that postgres already uses!

4. Once you've added your new aliases, exit the Nano text editor using **Ctrl+X** -- select `Y` (Yes) when prompted to save and Enter (leaving the file name as `.profile`).
5. Close and re-open your WSL terminal, then try your new alias commands.

## Troubleshooting

### Error: directory-sync fdatasync Invalid argument

Ensure that you are running your Linux distribution in WSL 2 mode. For help switching from WSL 1 to WSL 2, see [Set your distribution version to WSL 1 or WSL 2](../basic-commands.md).

## Additional resources

- [Setting up your development environment on Windows](/windows/dev-environment/)
