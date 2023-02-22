# Problem Set 2, hangman.py
# Name:
# Collaborators:
# Time spent:

import random
import string

# -----------------------------------
# HELPER CODE
# -----------------------------------

WORDLIST_FILENAME = "words.txt"

def load_words():
    """
    returns: list, a list of valid words. Words are strings of lowercase letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print(" ", len(wordlist), "words loaded.")
    return wordlist

def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)

    returns: a word from wordlist at random
    """
    return random.choice(wordlist)

# -----------------------------------
# END OF HELPER CODE
# -----------------------------------


# Load the list of words to be accessed from anywhere in the program
wordlist = load_words()

def has_player_won(secret_word, letters_guessed):
    """
    secret_word: string, the lowercase word the user is guessing
    letters_guessed: list (of lowercase letters), the letters that have been
        guessed so far

    returns: boolean, True if all the letters of secret_word are in letters_guessed,
        False otherwise
    """
    if secret_word == get_word_progress(secret_word, letters_guessed):
      return True
    else:
      return False
    
    #All the letters have been guessed, player wins!
    


def get_word_progress(secret_word, letters_guessed):
  
    """
    secret_word: string, the lowercase word the user is guessing
    letters_guessed: list (of lowercase letters), the letters that have been
        guessed so far

    returns: string, comprised of letters and asterisks (*) that represents
        which letters in secret_word have not been guessed so far
    """
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    word_progress = []

    for i in secret_word:
      if i in letters_guessed:
        word_progress.append(i)
      else:
        word_progress.append('*')
    
    word_string = ''

    #put the characters in the list into the string
    for x in word_progress:
      word_string += x

    return word_string

    


def get_available_letters(letters_guessed):
    my_string = string.ascii_lowercase
    
    for char in letters_guessed:
      if char in my_string:
        my_string = my_string.replace(char, '')

    return my_string
    """
    letters_guessed: list (of lowercase letters), the letters that have been
        guessed so far

    returns: string, comprised of letters that represents which
      letters have not yet been guessed. The letters should be returned in
      alphabetical order
    """



def hangman(secret_word, with_help):

    letters_guessed = []
    guesses = 10
    vowels = ['a', 'e', 'i', 'o', 'u']
    avail_letters = 'abcdefghijklmnopqrstuvwxyz$' 

    #with help
    if with_help:
      guesses = 10
      print("Your word has ", len(secret_word), " letters")
      
      
      while guesses > 0:
        print("You have ", guesses, " guesses")
        print("Available letters: ", get_available_letters(letters_guessed))
        new_guess = input("Please guess a letter: ")

        if new_guess in letters_guessed:
          print("Oops! You already guessed that letter: ", get_word_progress(secret_word, letters_guessed), "----------")

        #if the guess is too long or not a valid letter
        if len(new_guess) > 1 or new_guess not in avail_letters:
          print("Oops! That is not a valid letter. Please input a letter from the alphabet: ", get_word_progress(secret_word, letters_guessed), "----------")


        #if the user asks for a hint
        elif new_guess == '$':
          random_letter = random.choice(secret_word)
        
          #if the random letter selected has been guessed, 
          #keep picking random letters 
          while random_letter in letters_guessed:
            random_letter = random.choice(secret_word)
      
          #now add the guessed letter to the letters guessed
          letters_guessed.append(random_letter)
        
          print("Letter revealed: ", random_letter, "\n", get_word_progress(secret_word, letters_guessed), "----------")
          guesses -= 3
          if has_player_won(secret_word, letters_guessed):
            print("Yay! You win! \nThe word was: ", get_word_progress(secret_word, letters_guessed))
            break
          
          
        else:

          letters_guessed.append(new_guess)

          #if the guess is incorrect
          if letters_guessed[-1] not in secret_word:
            print("Oops! That letter is not in my word: ", get_word_progress(secret_word, letters_guessed))
            if letters_guessed[-1] in vowels:
              guesses -= 2
              print("You have ", guesses, " guesses\n")
              print("----------")
            else:
              guesses -= 1
              print("You have ", guesses, " guesses\n")
              print("----------")

        #if the guess is in the word!
          else:
            print("Correct guess: ", get_word_progress(secret_word, letters_guessed))
            print("You have ", guesses, " guesses\n")
            print("----------")
            if has_player_won(secret_word, letters_guessed):
              print("Yay! You win! \nThe word was: ", get_word_progress(secret_word, letters_guessed))
              break
            
      if has_player_won(secret_word, letters_guessed) != True:
        print("oops, you lost, the word was: ", secret_word)  
      


    #without help
    else:
      guesses = 10
      print("Your word has ", len(secret_word), " letters")
      

      #while the player has used all their guesses yet
      while guesses > 0 or has_player_won(secret_word, letters_guessed) == True:
        
        print("You have, ", guesses, " guesses")
        print("Available letters: ", get_available_letters(letters_guessed))
        new_guess = input("Please guess a letter: ")

        #if the guess is too long or not a valid letter
        if len(new_guess) > 1 or new_guess not in string.ascii_lowercase:
         print("Oops! That is not a valid letter. Please input a letter from the alphabet: ", get_word_progress(secret_word, letters_guessed))
         print("----------")

        if new_guess in letters_guessed:
          print("Oops! You already guessed that letter: ", get_word_progress(secret_word, letters_guessed))
          print("----------")
          

        else:
          letters_guessed.append(new_guess)

          #if the guess is incorrect
        if letters_guessed[-1] not in secret_word:
            print("Oops! That letter is not in my word: ", get_word_progress(secret_word, letters_guessed))
            if letters_guessed[-1] in vowels:
              guesses -= 2
              print("----------")
            else:
              guesses -= 1
              print("----------")

        #if the guess is in the word!
        else:
            print("Good guess: ", get_word_progress(secret_word, letters_guessed))
            print("----------")
      
      if(has_player_won(secret_word, letters_guessed)):
        print("Yay! You guessed it: ", get_word_progress(secret_word, letters_guessed))

      else:
        print("Oops! Not enough guesses left: ", get_word_progress(secret_word, letters_guessed))
        print("The word was: ", secret_word)


    """
    secret_word: string, the secret word to guess.
    with_help: boolean, this enables help functionality if true.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many
      letters the secret_word contains and how many guesses they start with.

    * The user should start with 10 guesses.

    * Before each round, you should display to the user how many guesses
      they have left and the letters that the user has not yet guessed.

    * Ask the user to supply one guess per round. Remember to make
      sure that the user puts in a single letter (or help character '$'
      for with_help functionality)

    * If the user inputs an incorrect consonant, then the user loses ONE guess,
      while if the user inputs an incorrect vowel (a, e, i, o, u),
      then the user loses TWO guesses.

    * The user should receive feedback immediately after each guess
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the
      partially guessed word so far.

    -----------------------------------
    with_help functionality
    -----------------------------------
    * If the guess is the symbol $, you should reveal to the user one of the
      letters missing from the word at the cost of 3 guesses. If the user does
      not have 3 guesses remaining, print a warning message. Otherwise, add
      this letter to their guessed word and continue playing normally.

    Follows the other limitations detailed in the problem write-up.
    """



# When you've completed your hangman function, scroll down to the bottom
# of the file and uncomment the lines to test

if __name__ == "__main__":
    # To test your game, uncomment the following three lines.

    secret_word = choose_word(wordlist)
    with_help = True
    hangman(secret_word, with_help)

    # After you complete with_help functionality, change with_help to True
    # and try entering "$" as a guess!

    ###############

    # SUBMISSION INSTRUCTIONS
    # -----------------------
    # It doesn't matter if the lines above are commented in or not
    # when you submit your pset. However, please run test_ps2_student.py
    # one more time before submitting to make sure all the tests pass.
    pass

