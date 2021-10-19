# Battleships with Bot & GUI

## Introduction
This program was designed to recreate the traditional board game called battleship. It contains a battle interface GUI that can be interacted with using the command line in the terminal. 
<br />
<br />The README is divided into the following sections:
* The Battle Interface GUI
* The Battleship Bot
* Interacting with the GUI
* Win Conditions


# Battle Interface
<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    |    |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    |    |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>

<br /> This is the interface that each player is presented with. The interface is divided into two sections:
* The left side is where the player deploys their ships and where the bot makes its guesses
* The right side is where the bot deploys its ships and the player makes their guesses

<br /> In the "deployment" stage, a player types in command line input to deploy their ships. To break this down, it is important to note that there are four types of ships that both the player and the bot can deploy:
<br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; oo      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Radar Ship       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (Length: 2)
<br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ooo     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Minor Ship       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (Length: 3)
<br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; oooo    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Destroyer Ship   &nbsp; (Length: 4)
<br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ooooo   &nbsp;&nbsp;&nbsp;             Flagship        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; (Length: 5)

<br /> Each ship has a different length, and each 'o' is placed on a seperate square in the grid. Ships can either be oriented vertically or horizontally, and they cannot overlap. The player has the option to either type in "DEPLOY" to randomly deploy their ships, or alternatively they can manually place each one onto their grid. Deploying manually requires the player to type in the type of ship they want to deploy (either F, D, M, or R), and start and end point coordinates: (ie A1 or F7). So for example, to deploy a flagship on the grid a player would need to type in: FA1A5 - which will deploy a flagship on the grid that occupies squares A1, A2, A3, A4, and A5. 

<br /> The following demonstrates these two types of deployments:

## Typing in: "DEPLOY"
<br /> This will randomly deploy all available ships onto the grid.

<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |  o |    |    |    |    |    |    |    | 
B  |  o |    |    |    |    |    |    |    | 
C  |    |    |    |    |  o |    |    |  o | 
D  |    |    |    |    |  o |    |    |  o | 
E  |    |    |    |    |  o |    |    |  o | 
F  |    |    |    |    |  o |    |    |  o | 
G  |    |    |    |    |    |    |    |  o | 
H  |    |  o |  o | o  |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    |    |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>




## Typing in: "FE3E7"
<br /> This will deploy only the flagship onto the grid from squares A1 to A5.

<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    | o  | o  | o  | o  | o  |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    |    |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>

<br /> As a result it is up to the player how they would like to deploy ships onto the grid.


# The Battleship Bot

The battleship bot is designed to take on the role of the player's opponent. The battleship bot deploys its ships on the right-side grid where the player makes their guesses. Additionally, the battleship bots places its guesses on the left-side grid in order to destroy the player's ships before the player can destroy the bot's. There are three stages of guessing that the bot goes through when playing against the player.
<br />
<br /> 1. The first stage is randomly guessing. The bot will randomly guess where the player's ships could be, attempting to mimic how a human would behave.
<br /> 2. The second stage is when a 'o' has been detected. This occurs when a bot correctly guesses the location of one of a ship's 'o'. The bot will now try to determine the orientation of the ship. It has four directions to choose from: either top, right, down, or left. If another 'o' is detected, the bot will continue to guess in that direction.
<br /> 3. The third stage is destroying the detected ship. The bot will continue guessing in the direction the second 'o' was found. Once it reaches a blank square, it will then return to the original 'o' it had initially guessed and continue guessing from the opposite direction.
<br /> 
<br /> To demonstrate what this all means, consider a ship horizontally oriented on the grid:
<br /> o o o o o 
<br />
<br /> Now, consider that the bot guessed the middle circle so that the following was destroyed: (Stage 1)
<br /> o o x o o
<br />
<br /> The bot will now try to determine the orientation: (Stage 2)
<br /> Let's say that it guesses "right" (as opposed to up, down, or left)
<br /> The ship now looks like this:
<br /> o o x x o
<br />
<br /> Next it will continue guessing in the direction of the second succesful guess such that: (Stage 3)
<br /> o o x x x -
<br />
<br /> It finally reached the end of the ship and guessed on square after it (noted as the "-").
<br /> Now the bot will guess in the opposite direction from the first successful guess, and continue onwards.
<br /> o x x x x -
<br /> x x x x x -
<br /> 
<br /> And that is how the bot destroys a player's ship.

# Interacting with the GUI

Interacting with the GUI is purely command-line based. After deployment. players are first presented with the following layout.

<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |  o |    |    |    |    |    |    |    | 
B  |  o |    |    |    |    |    |    |    | 
C  |    |    |    |    |  o |    |    |  o | 
D  |    |    |    |    |  o |    |    |  o | 
E  |    |    |    |    |  o |    |    |  o | 
F  |    |    |    |    |  o |    |    |  o | 
G  |    |    |    |    |    |    |    |  o | 
H  |    |  o |  o | o  |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    |    |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>
<br /> Input:
<br />
<br /> Players must now guess where the enemy's (bot's) ships are.
<br /> Let's say the player inputs E5.
<br /> Input: E5
<br />
<br /> The terminal updates so that: 

<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |  o |    |    |    |    |    |    |    | 
B  |  o |    | -  |    |    |    |    |    | 
C  |    |    |    |    |  o |    |    |  o | 
D  |    |    |    |    |  o |    |    |  o | 
E  |    |    |    |    |  o |    |    |  o | 
F  |    |    |    |    |  o |    |    |  o | 
G  |    |    |    |    |    |    |    |  o | 
H  |    |  o |  o | o  |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    | -  |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>

<br /> And it's a miss!
<br />
<br /> Notice that the bot also made it's guess instantaneously and the screen has been updated to reflect that. The bot guessed B3, and its guess is shown on the player's side of the grid on the left.
<br />
<br /> The player then guesses H7, and it's a direct hit! The screen updates to reflect this and again, it shows the bot's guess as well.


<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |  o |    |    |    |    |    |    |    | 
B  |  o |    | -  |    |    |    |    |    | 
C  |    |    |    |    |  o |    |    |  o | 
D  |    |    |    |    |  o |    |    |  o | 
E  |    |    |    |    |  o |    |    |  o | 
F  |    |    |    |  - |  o |    |    |  o | 
G  |    |    |    |    |    |    |    |  o | 
H  |    |  o |  o | o  |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    | -  |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    | X  |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>

<br /> And the game continues in this way until either the player or the bot successfully destroys all of their opponent's ships.

# Win Conditions

<br /> There are two different win conditions, either the bot successfully destroyed all the player's ships or the player successfully destroyed all of the bot's ships.

## Player Wins! - GUI Board

<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |  X |  - |    |    |  - |    |    |  - | 
B  |  X |    | -  |    |  - |    |    |    | 
C  |    |    |    |    |  X |    | -  |  o | 
D  |    |    | -  |    |  X |  - |    |  o | -
E  |    |    |    |    |  X |    |    |  o | 
F  | -  |  - |    |  - |  o |    |    |  o | 
G  |    |    |    |    |    |    |    |  o | 
H  | -  |  X |  X | X  | -  |  - |    |    | 
I  |    |    |    |    | -  |    |    |    | 
J  | -  |    |    |-   |    |    |    |    | -

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  | -  |    |    |    |    |    |    |  - | 
B  |    |    |    |  - |    |    |    |    | 
C  |  - |  X |  X |  X | X  | X  |    |    | 
D  |    |    |    |    |    |    |  - |    | 
E  |    | -  |    |    | -  |    | X  | -  | 
F  |    |    |    |    |    |    | X  |    | 
G  |    |  - | X  | X  | X  | -  | X  |    | 
H  |  - |    |    |    |    |    | X  |    | 
I  |  X |    |    | -  |    |    |  - |    | 
J  |  X |  - |    |    |    |    |    |    |   
  </td></tr> </table>




## Bot Wins! - GUI Board

<table>
<tr><th>YOUR SHIPS </th><th>ENEMY SHIPS</th></tr>
<tr><td>

 .  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |  o |    |    |    |    |    |    |    | 
B  |  o |    | -  |    |    |    |    |    | 
C  |    |    |    |    |  o |    |    |  o | 
D  |    |    |    |    |  o |    |    |  o | 
E  |    |    |    |    |  o |    |    |  o | 
F  |    |    |    |  - |  o |    |    |  o | 
G  |    |    |    |    |    |    |    |  o | 
H  |    |  o |  o | o  |    |    |    |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    | 

</td><td>
  
.  | 1  | 2  | 3  | 4  |  5 | 6  | 7  | 8  | 9  |   
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
A  |    |    |    |    |    |    |    |    | 
B  |    |    |    |    |    |    |    |    | 
C  |    |    |    |    |    |    |    |    | 
D  |    |    |    |    |    |    |    |    | 
E  |    |    |    |    | -  |    |    |    | 
F  |    |    |    |    |    |    |    |    | 
G  |    |    |    |    |    |    |    |    | 
H  |    |    |    |    |    |    | X  |    | 
I  |    |    |    |    |    |    |    |    | 
J  |    |    |    |    |    |    |    |    |   
  </td></tr> </table>






