---
title: Add or connect a database with WSL
description: Learn how to set up MySQL MongoDB, PostgreSQL, SQLite, Microsoft SQL Server, or Redis on the Windows Subsystem for Linux.
ms.date: 09/18/2023
ms.topic: article
---

# Get started with databases on Windows Subsystem for Linux

This step-by-step guide will help you get started connecting your project in WSL to a database. Get started with MySQL, PostgreSQL, MongoDB, Redis, Microsoft SQL Server, or SQLite.

## Prerequisites

- Running Windows 11 or Windows 10, [updated to version 2004](ms-settings:windowsupdate), **Build 19041** or later.
- [Install a Linux distribution using WSL and create a Linux user name and password](../install.md).

## Differences between database systems

Some [popular choices](https://survey.stackoverflow.co/2024/technology#most-popular-technologies-database) for a database system include:

- [MySQL](https://www.mysql.com/why-mysql/) (SQL)
- [PostgreSQL](https://www.postgresql.org/about/) (SQL)
- [Microsoft SQL Server](/sql) (SQL)
- [SQLite](https://www.sqlite.org/about.html) (SQL)
- [MongoDB](https://www.mongodb.com/what-is-mongodb) (NoSQL)
- [Redis](https://redis.io/topics/introduction) (NoSQL)

**MySQL** is an open-source SQL relational database, organizing data into one or more tables in which data types may be related to each other. It is vertically scalable, which means one ultimate machine will do the work for you. It is currently the most widely used of the four database systems.

**PostgreSQL** (sometimes referred to as Postgres) is also an open-source SQL relational database with an emphasis on extensibility and standards compliance. It can handle JSON now too, but it is generally better for structured data, vertical scaling, and ACID-compliant needs like eCommerce and financial transactions.

**Microsoft SQL Server** includes SQL Server on Windows, SQL Server on Linux, and SQL on Azure. These are also relational database management systems set up on servers with primary function of storing and retrieving data as requested by software applications.

**SQLite** is an open-source self-contained, file-based, "serverless" database, known for its portability, reliability, and good performance even in low-memory environments.

**MongoDB** is an open-source NoSQL document database designed to work with JSON and store schema-free data. It is horizontally scalable, which means multiple smaller machines will do the work for you. It's good for flexibility and unstructured data, and caching real-time analytics.

**Redis** is an open-source NoSQL in-memory data structure store. It uses key-value pairs for storage instead of documents.

## Install MySQL

To install MySQL on a Linux distribution running on WSL, just follow the [Installing MySQL on Linux](https://dev.mysql.com/doc/refman/en/linux-installation.html) instructions in the MySQL docs. You may need to first [enable systemd support](../systemd.md#how-to-enable-systemd) in your `wsl.conf` configuration file.

Example using the Ubuntu distribution:

1. Open your Ubuntu command line and update the packages available:

    ```bash
    sudo apt update
    ```

1. Once the packages have updated, install MySQL with:

    ```bash
    sudo apt install mysql-server
    ```

1. Confirm installation and get the version number:

    ```bash
    mysql --version
    ```

1. Start MySQL Server / check status:

    ```bash
    systemctl status mysql
    ```

1. To open the MySQL prompt, enter:

    ```bash
    sudo mysql
    ```

1. To see what databases you have available, in the MySQL prompt, enter:

    ```bash
    SHOW DATABASES;
    ```

1. To create a new database, enter:

    ```bash
    CREATE DATABASE database_name;
    ```

1. To delete a database, enter:

    ```bash
    DROP DATABASE database_name;
    ```

For more about working with MySQL databases, see the [MySQL docs](https://dev.mysql.com/doc/mysql-getting-started/en/).

To work with MySQL databases in VS Code, try the [MySQL extension](https://marketplace.visualstudio.com/items?itemName=cweijan.vscode-mysql-client2).

You may also want to run the included security script. This changes some of the less secure default options for things like remote root logins and sample users. This script also includes steps to change password for MySQL root user. To run the security script:

1. Start a MySQL server:

    ```bash
    sudo service mysql start
    ```

1. Start the security script prompts:

    ```bash
    sudo mysql_secure_installation
    ```

1. The first prompt will ask whether you’d like to set up the VALIDATE PASSWORD COMPONENT, which can be used to test the strength of your MySQL password. If you want to set some simple password, you should not set this component.
1. You will then set/change password for the MySQL root user, decide whether or not to remove anonymous users, decide whether to allow the root user to login both locally and remotely, decide whether to remove the test database, and, lastly, decide whether to reload the privilege tables immediately.

## Install PostgreSQL

To install PostgreSQL on WSL (ie. Ubuntu):

1. Open your WSL terminal (ie. Ubuntu).
1. Update your Ubuntu packages:

    ```bash
    sudo apt update
    ```

1. Once the packages have updated, install PostgreSQL (and the PostgreSQL Contrib package which has some helpful utilities) with:

    ```bash
    sudo apt install postgresql postgresql-contrib
    ```

1. Confirm installation and get the version number:

    ```bash
    psql --version
    ```

There are 3 commands you need to know once PostgreSQL is installed:

- Check the database status

  ```bash
  sudo service postgresql status
  ```

- Start the database

  ```bash
  sudo service postgresql start
  ```

- Stop the database

  ```bash
  sudo service postgresql stop
  ```

The default admin user, `postgres`, needs a password assigned in order to connect to a database. To set a password:

1. Enter the command:

    ```bash
    sudo passwd postgres
    ```

1. You will get a prompt to enter your new password.
1. Close and reopen your terminal.

To run PostgreSQL with [`psql`](https://www.postgresql.org/docs/current/app-psql.html) shell:

1. Start your postgres service:

    ```bash
    sudo service postgresql start
    ```

1. Connect to the postgres service and open the psql shell:

    ```bash
    sudo -u postgres psql
    ```

Once you have successfully entered the psql shell, you will see your command line change to look like this:

```psqlshell
postgres=#
```

> [!NOTE]
> Alternatively, you can open the psql shell by switching to the postgres user with: `su - postgres` and then entering the command: `psql`.

To exit psql shell enter: `\q` or use the shortcut key: Ctrl+D

To see what user accounts have been created on your PostgreSQL installation, use from your WSL terminal:

```bash
psql --command="\du"
```

...or just `\du` if you have the psql shell open. This command will display columns: Account User Name, List of Roles Attributes, and Member of role group(s). To exit back to the command line, enter: `q`.

For more about working with PostgreSQL databases, see the [PostgreSQL docs](https://www.postgresql.org/docs/current/tutorial-createdb.html).

To work with PostgreSQL databases in VS Code, try the [PostgreSQL extension](https://marketplace.visualstudio.com/items?itemName=ms-ossdata.vscode-postgresql).

## Install MongoDB

To install MongoDB, see the Mongodb docs: [Install MongoDB Community Edition on Linux](https://www.mongodb.com/docs/manual/administration/install-on-linux/)

Installing MongoDB may require slightly different steps depending on the Linux distribution being used for installation. Also note that MongoDB installation may differ depending on the version # that you are aiming to install. Use the version drop-down list in the top-left corner of the MongoDB documentation to select the version that aligns with your goal. Lastly, you may need to [enable systemd support](../systemd.md#how-to-enable-systemd) in the `wsl.conf` configuration file of the Linux distribution that you are using with WSL. The `systemctl` command is a part of the systemd init system and may not work if your distribution is using systemv.

VS Code supports working with MongoDB databases via the [Azure CosmosDB extension](https://marketplace.visualstudio.com/items?itemName=ms-azuretools.vscode-cosmosdb), you can create, manage and query MongoDB databases from within VS Code. To learn more, visit the VS Code docs: [Working with MongoDB](https://code.visualstudio.com/docs/azure/mongodb).

Learn more in the MongoDB docs:

- [Introduction to using MongoDB](https://www.mongodb.com/docs/manual/introduction/)
- [Create users](https://www.mongodb.com/docs/manual/tutorial/create-users/)
- [CRUD: Create, Read, Update, Delete](https://www.mongodb.com/docs/manual/crud/)
- [Reference Docs](https://www.mongodb.com/docs/manual/reference/)

## Install Microsoft SQL Server

[Quickstart: Install SQL Server and create a database on Windows Subsystem for Linux (WSL 2)](/sql/linux/quickstart-install-connect-wsl-2).

## Install SQLite

To install SQLite on WSL (ie. Ubuntu):

1. Open your WSL terminal (ie. Ubuntu).
1. Update your Ubuntu packages:

    ```bash
    sudo apt update
    ```

1. Once the packages have updated, install SQLite3 with:

    ```bash
    sudo apt install sqlite3
    ```

1. Confirm installation and get the version number:

    ```bash
    sqlite3 --version
    ```

To create a test database, called "example.db", enter:

```bash
sqlite3 example.db
```

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
1. Update your Ubuntu packages:

    ```bash
    sudo apt update
    ```

1. Once the packages have updated, install Redis with:

    ```bash
    sudo apt install redis-server
    ```

1. Confirm installation and get the version number:

    ```bash
    redis-server --version
    ```

To start running your Redis server:

```bash
sudo service redis-server start
```

Check to see if redis is working (redis-cli is the command line interface utility to talk with Redis):

```bahs
redis-cli ping
```

This should return a reply of "PONG".

To stop running your Redis server:

```bash
sudo service redis-server stop
```

For more information about working with a Redis database, see the [Redis docs](https://redis.io/docs/develop/get-started/).

To work with Redis databases in VS Code, try the [Redis extension](https://marketplace.visualstudio.com/items?itemName=cweijan.vscode-redis-client).

## See services running and set up profile aliases

To see the services that you currently have running on your WSL distribution, enter:

```bash
service --status-all
```

Typing out `sudo service mongodb start` or `sudo service postgres start` and `sudo -u postgrest psql` can get tedious.  However, you could consider setting up aliases in your `.profile` file on WSL to make these commands quicker to use and easier to remember.

To set up your own custom alias, or shortcut, for executing these commands:

1. Open your WSL terminal and enter `cd ~` to be sure you're in the root directory.
1. Open the `.profile` file, which controls the settings for your terminal, with the terminal text editor, Nano:

    ```bash
    sudo nano .profile
    ```

1. At the bottom of the file (don't change the `# set PATH` settings), add the following:

    ```bash
    # My Aliases
    alias start-pg='sudo service postgresql start'
    alias run-pg='sudo -u postgres psql'
    ```

    This will allow you to enter `start-pg` to start running the postgresql service and `run-pg` to open the psql shell. You can change `start-pg` and `run-pg` to whatever names you want, just be careful not to overwrite a command that postgres already uses!

1. Once you've added your new aliases, exit the Nano text editor using **Ctrl+X** -- select `Y` (Yes) when prompted to save and Enter (leaving the file name as `.profile`).
1. Close and re-open your WSL terminal, then try your new alias commands.

## Troubleshooting

### Error: directory-sync fdatasync Invalid argument

Ensure that you are running your Linux distribution in WSL 2 mode. For help switching from WSL 1 to WSL 2, see [Set your distribution version to WSL 1 or WSL 2](../basic-commands.md).

## Additional resources

- [Setting up your development environment on Windows](/windows/dev-environment/)
