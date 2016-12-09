# DreamTeamExtreme

## Helgi, Benni, Elvar, Sara, Þorfinnur, Kolbeinn

Club of fans

Link to this repository: https://github.com/bennisverrir/GucciManeFanclub

This project is a collective work of 6 people, individual commits can have been moderated and/or monitored by 2 or more people. It is a layered structure of database handling.

Presentation layer - ConsoleUI, handles all cin and cout logic, translates user input commands and sends them forward to the business logic layer.

Business logic layer - LegendService and Legend, takes in the translated user input commands from the Presentation layer and sends further instructions to the Data Access layer.

Data access layer - DataAccess, handles the opening, reading and writing requests to the source of data.

Data (source) - External source of information.

This program is a database that keeps basic information about famous computer scientists, computers and their relations. In the program the user has the options of listing any of the 3 lists (Scientists/Computers/Relations) with various different sorting. The user can add, and edit scientists, computers and relations and search for a specific entry in the database. If the user wants to know the answer to life, the universe and everything, type 42 in the commands menu.

Availible commands:

Menu (from start):

|--------------------------------------------------------------|
|Please enter one of the following numbers:                    |
|[1] - To list all the computer scientists or computers        |
|[2] - To add a computer scientist or a computer               |
|[3] - To find a computer scientist from the list or a computer|
|[4] - This will edit a computer scientists from the list      |
|[5] - To delete a relation                                    |
|[6] - this will clear the screen                              |
|[7] - This will quit the program                              |
|--------------------------------------------------------------|

(if the user inputs "1" from main menu)

List:

|--------------------------------------------------------------|
|Enter one of the following commands:                          |
|[1] - to list scientists                                      |  //Offers ways to sort the list of scientists
|[2] - to list computers                                       |  //Offers ways to sort the list of computers
|[3] - to list relations                                       |  //Offers ways to sort the list of relations
|--------------------------------------------------------------|

(if the user inputs "1" from the list menu)

List => Scientists:

|---------------------------------------------------------------|
|How do you want to sort                                        |
|[1] - Alphabetical order                                       | //Lists scientists, sorted in alphabetical order
|[2] - Gender order                                             | //Lists scientists, sorted in order by gender
|[3] - Year of birth order                                      | //Lists scientists, sorted by birth year
|[4] - Still alive order(those who are still alive appear first)| //Lists scientists, sorted by still alive (bool value)
|[5] - No particular sorting                                    | //Lists scientists, sorted by the order of insertions
|---------------------------------------------------------------|

(if the user inputs "2" from the list menu)

List => Computers:

|--------------------------------------------------------------|
|How do you want to sort                                       |
|[1] - Alphabetical order                                      |  //Lists computers, sorted in alphabetical order
|[2] - Built year order                                        |  //Lists computers, sorted in order by year built
|[3] - Was built                                               |  //Lists computers, sorted by was built (bool value)
|[4] - Type of computer order                                  |  //Lists computers, sorted by computer type
|[5] - No particular sorting                                   |  //Lists computers, sorted by the order of insertions
|--------------------------------------------------------------|

(if the user inputs "3" from the list menu)

Lists => Relations:

|--------------------------------------------------------------|
|How do you want to sort                                       |
|[1] - By scientist name                                       |  //Lists relations, sorted in alphabetical order of scientists
|[2] - By computer name                                        |  //Lists computers, sorted in alphabetical order of computers
|--------------------------------------------------------------|

(if the user inputs "2" from the main menu)

Add:

|--------------------------------------------------------------|
|Enter one of the following commands:                          |
|[1] - to add scientists                                       |
|[2] - to add computers                                        |
|[3] - to add relations                                        |
|--------------------------------------------------------------|

(if the user inputs "1" from the add menu)

Add => Scientists:

Input options:

Enter the name: John Doe ("John Doe" is a sample input - expects a string of undefined length)

Enter the gender (M/F): M ('M' is a sample input, non-case sensitive - expects a char of either 'm' or 'f')

Enter the year of birth (up to 4 digits): 1750 ("1750" is a sample input - expects a numeric value between 0 and current year)

Are they alive (y/n)? n ('n' is a sample input - expects a char value of either 'y' or 'n' (if y then the user is prompted with a followup question of death year))

Enter the year of death (up to 4 digits): 1800 ('1800' is a sample input - expects a numeric value between born and current year)

(if the user inputs "2" from the add menu)

Add => Computers:

Input options:

Enter the name: MeanMachine42 ("MeanMachine42" is a sample input - expects a string value name)

Was it built (y/n)? y ('y' is a sample input - expects a char value of either 'y' or 'n' (if y then the user is prompted with a followup question of build year))

Year of build (4 digits): 2015 ("2015" is a sample input - expects a numeric value of 0 to current year)

No.    Type
----------------------------------------
1      Mechanical
2      Electrical
3      Transistor
4      Electromechanical
5      Abstract machine
6      Add a computerType
Enter Computer Type(0-6): 5

(if the user inputs "find" from menu)

find:

(find options)

n - Name

g - Gender

b - Born (year)

d - Died (year)

(if the user inputs "delete" from menu)

delete

(delete options)


Who do you want to delete? John Doe ("John Doe" is a sample input, expects a string (name), empty string displays full list)

No.    Name                          Gender     Born       Died      
--------------------------------------------------------------------------------
1      John Doe                      M          555        777       Died 111 years old

What number do you want to delete? 1 ('1' is a sample input, expects a number based on search results 0-list size)

The line has been deleted

quit:

Press <RETURN> to close this window...
