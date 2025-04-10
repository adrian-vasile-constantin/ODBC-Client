# ODBC Client
ODBC client and tools

The project is still in developement and not really usable as of now. See the other repository [ODBC-GUI-Client](https://github.com/adrian-vasile-constantin/ODBC-GUI-Client) for a working prototype.

The intent is to develop 3 components for working with ODBC:
  - a C++ client library: `odbc++`
  - a command line interpretter: `dbcmd`
  - a graphical client: `odbc-client`

The client library `odbc++` should simply translate the standard SQL/CLI (or [ODBC](https://learn.microsoft.com/en-us/sql/odbc/reference/syntax/odbc-api-reference?view=sql-server-ver16)) application programming interrface into C++ classes.

The command line interpretter `dbcmd` should be usable as a mini-shell that directly allows running SQL statements and provides dot-commands (like .time) for connecting to a data source and for utility commands.

The grafical client `odbc-client` should allow end-users access to everything ODBC has to offer, like connecting to any data source or with any connection string, saving a new data source or a file DSN, running SQL queries on a connection, and browsing existing SQL functions, tables, views...
