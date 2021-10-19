# Battleships with Bot & GUI

## Introduction
This program was designed to recreate the traditional board game called battleship. It contains a battle interface GUI that can be interacted with using the command line in the terminal. 
<br />
<br />The README is divided into the following sections:
* The battle interface GUI
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







