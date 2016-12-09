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

[1] - To list all the computer scientists, computers or relations

[2] - To add a computer scientist, computer or a relation

[3] - To find a computer scientist, computer or relation

[4] - This will edit a computer scientist, computer or relation

[5] - To delete a relation

[6] - this will clear the screen

[7] - This will quit the program

(if the user inputs "1" from main menu)

list:

Enter one of the following commands:

[1] - to list scientists  //Offers you various ways to sort the computer scientists listed

[2] - to list computers //Offers you various ways to sort the list of the computers listed

[3] - to list relations //Offers you various ways to sort the list of relations listed

(if the user inputs "1" from the list menu)

List => Scientists

[1] - Alphabetical order //Lists the computer scientists in alphabetical order

[2] - Gender order //Lists the computer scientists in order of gender

[3] - Year of birth order //Lists the computer scientists in order of Year of birth

[4] - Still alive order(those who are still alive appear first) //Lists the computer scientists based on if they're still alive or not

[5] - No particular sorting //Lists the computer scientists by the order they were input in. 

(if the user inputs "add" from the menu)

add:

(input options)

Enter the name: John Doe ("John Doe" is a sample input)

Enter the gender: M ('M' is a sample input, non-case sensitive, expects a single char input 'M'/'F')

Enter the year of birth: 555 ("555" is a sample input, expects a number from 0 to 2016) 

Are they alive (y/n)? n ('n' is a  sample input, expects a single char 'y' or 'n')

Enter the year of death: 777 ("777" is a sample input, expects a number between 0 and 2016)

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
