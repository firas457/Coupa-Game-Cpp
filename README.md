# Coupa Game
## Coupa is a board game with 2-6 players playing against each other, the one who lasts to the end is the winner of the game,  each player draws a card from the pile. Each card describes a role that the player can fulfill. In the center of the table is a box of coins. Each player in turn according to the role he belongs to (the details of the roles below) can take coins accordingly. The goal is to carry out "coups" and remove other players from their positions. The last player left holding a role wins , Every player has their own name. In each round, a player can, regardless of his role, perform one of the following actions:. Salary - income - take a coin from the pile. This operation has no cost, no actions against it, and the player earns a single coin. Double salary - foreign_aid - take two coins from the pile. This operation has no cost, and it entitles the player to two coins. But there's a role in the game that can block this operation. If the player is blocked while trying to take double pay, his turn ends. Coup-coup-- to remove an opponent from his position and thus take him out of the game.. The cost of this operation is 7 coins, has no replay, and ends with the player to whom the action is being played is removed and finished. Each action must update the number of coins the player holds accordingly. If the operation is invalid, an appropriate exception must be thrown. In addition, the following methods must be implemented: Role - a function that returns the role of the player (see the list of roles below) for display. Coins the method returns how many coins the player has, Rules to play: <br/>
#### Doakes - Duke: Can take a three-quarters-high tax from the register without any player being able to stop it. In addition, the Dox can block a double-wage operation. The blocked player returns the two coins to the cash register.

#### Assassin - assassin: The player can be removed from the position with only 3 coins (instead of 7). However, there is a role that can prevent this action from the assassin. If an assassin is blocked, the player who was voted out after the assassination returns to the game.

#### Ambassador - Ambassador: A coin can be transferred from one player to another player, and the ambassador can prevent further theft.

#### Captain - Captain: Could steal 2 coins from another player. This action can be blocked by an ambassador or another captain. (Captain can also block theft, like the ambassador).

#### Countess - Contessa: Could block the assassination operation.
#### Notes:
#### There can be two or more players who have the same role - nothing special happens in this situation.
#### If a player holds 10 coins at the beginning of his turn, he must perform a coup in that line
#### Blocking operations should not wait for the blocking player's turn and do not waste an appointment but are performed "in real time." In our game, we will not #### #### exercise "real-time" responses, so we will come up with the following solution:
#### A player who has performed a blocked action can be blocked until it is his turn to play again.
#### Example:
#### Player 1 took double pay and player 3 has the Doakes card. Player 3 doesn't have to wait his turn to block player 1, but if it's player 1 again, player 3 can't ask #### him to return the coins to the register.
