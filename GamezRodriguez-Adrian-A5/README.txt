Assignment 5
For modulus of double:
https://stackoverflow.com/questions/9138790/cant-use-modulus-on-doubles
For random numbers:
https://www.daniweb.com/programming/software-development/threads/1769/c-random-numbers
Notes on code:
• Provide a short description or pseudocode for the game “Bulls and Cows”
	The game "Bulls and Cows" checks the user's guess against the "code" and outputs the information of bulls, which are number that are i
	in the correct position, and information of cows, which is the amount of correct digits not in the rigth position.
	Note that I did not include the option for the random code to print, 
	because I wasn't sure how to do it if the "code" changes.
• Write how you tested your program(s) for correctness and how you used exceptions for
the error handling.
	I used a function to check for double digits and if the input digits were in the correct range.
	I checked for input size but somehow theres a mistake because it only takes five intergers and if you input more than 5, it will take 
	the numbers after the fifth as another input. 
	