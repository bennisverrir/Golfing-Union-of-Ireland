# DreamTeamExtreme

## Helgi, Benni, Elvar, Sara, Þorfinnur, Kolbeinn

A team of extreme dreams

This project is a collective work of 6 people, individual commits can have been moderated and/or monitored by 2 or more people. It is a layered structure of database handling.

Presentation layer - ConsoleUI, handles all cin and cout logic, translates user input commands and sends them forward to the business logic layer.

Business logic layer - LegendService and Legend, takes in the translated user input commands from the Presentation layer and sends further instructions to the Data Access layer.

Data access layer - DataAccess, handles the opening, reading and writing requests to the source of data.

Data (source) - External source of information.

This program is a database that keeps basic information about famous computer scientists. In the program the user has the options of listing all the computer scientists in different kind of sorts. The user can add new famous computer scientists and delete existing scientists. The user can search in the list of famous computer scientists and can also clear the screen of the program. If the user wants to know the answer to life, the universe and everything, type 42 in the commands menu.

Availible commands:


Menu (from start):

list   - This will list all the computer scientists (goes into sorting options)

add    - This will add a computer scientists (goes into input mode, will validate if name is already input)

find   - This will find a computer scientists from the list (goes into find options)

delete - This will delete a computer scientists from the list (goes into delete options)

clear  - this will clear the screen

quit   - This will quit the program

the answer to life - (hidden) (displays the meaning of life)

(if the user inputs "list" from menu)

list:

(sorting options)

a - Alphabetical order

n - No particular sorting

g - Gender order

b - Year of birth order

l - Still alive order(those who are still alive appear first)

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
