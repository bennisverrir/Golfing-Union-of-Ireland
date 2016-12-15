# DreamTeamExtreme

## Helgi, Benni, Elvar, Sara, Þorfinnur, Kolbeinn

Club of fans

Link to this repository: https://github.com/bennisverrir/Golfing-Union-of-Ireland/

This project is a collective work of 6 people, individual commits can have been moderated and/or monitored by 2 or more people. It is a layered structure of database handling.

Presentation layer - ConsoleUI, handles all cin and cout logic, translates user input commands and sends them forward to the business logic layer.

Business logic layer - LegendService and Legend, takes in the translated user input commands from the Presentation layer and sends further instructions to the Data Access layer.

Data access layer - DataAccess, handles the opening, reading and writing requests to the source of data.

Data (source) - External source of information.

This program is a database that keeps basic information about famous computer scientists, computers and their relations. The program lists scientists, computers and their relations on startup, and the user can add, and edit scientists, computers and relations and search for a specific entry in the database. The user can also add a small bio or notes about each entry and add a photo to the scientists. 


On startup the user is asked which language they want to display the program in. Translations for a few languages are available.

1 - Table selection, in the top left corner the user can select which table he wants to view, add to, or edit from.

2 - The table itself on the left side of the screen the user sees a table from the corresponding database (Scientists/Computers/Relations).

3 - 
