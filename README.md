# DreamTeamExtreme

## Helgi, Benni, Elvar, Sara, Þorfinnur, Kolbeinn

Fans of clubs

Link to this repository: https://github.com/bennisverrir/Golfing-Union-of-Ireland/

This project is a collective work of 6 people, individual commits can have been moderated and/or monitored by 2 or more people. It is a layered structure of database handling.

Presentation layer - ConsoleUI, handles all cin and cout logic, translates user input commands and sends them forward to the business logic layer.

Business logic layer - LegendService and Legend, takes in the translated user input commands from the Presentation layer and sends further instructions to the Data Access layer.

Data access layer - DataAccess, handles the opening, reading and writing requests to the source of data.

Data (source) - External source of information.

This program is a database that keeps basic information about famous computer scientists, computers and their relations. The program lists scientists, computers and their relations on startup, and the user can add, and edit scientists, computers and relations and search for a specific entry in the database. The user can also add a small bio or notes about each entry and add a photo to the scientists. 

On startup the user has to choose which language they want to display the program in. Translations for a few languages are available.

Table selection, in the top left corner the user can select which table he wants to view, add to, or edit from.

The table on the left side of the screen the user sees a table from the corresponding database (Scientists/Computers/Relations).

Clicking on entries in the table will select the entire row and enable edit. 

Find bar is located on the bottom of the window, this bar will look for any value in any field of the table, (except the indexes as they may vary throughout find results)

Fields on the right hand side:

In the scientist tab - Scientist name, gender, birth year, death year, add image and bio.

In the computer tab - Computer name, build year and computer type.

In the relations tab - Scientist name, computer name (and a delete button, which deletes the entry highlighted /selected).

The fields are for the user to add or edit a scientist, computer or relation, each of the fields has to be filled out in order to edit or add into their respective tabs. Some fields require no input (Such as death year and build year). Edit only becomes enabled when a row (entry) on the left hand table is highlighted or selected. 

Clear button - The button clears the user selection and the input fields.

Joke - The button opens up a new window and displays a random joke (from library).

Quit - Exits the program, and terminates connection to the SQLite library.
