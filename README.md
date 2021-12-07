# angina

Steps to run:

- Go to `build` folder
- `cmake ..`
- `make`
- `./chess`

Features:

- movement of all pieces
- king check (works most of the time)
- king castle (available just to the human player)
- start screen - new game, continue, quit
- quit game while playing
- computer opponent
- 1 minute timer for each player
- en passant
- checkmate
- stalemate (should be working but never reproduced)
- winner animation
- log moves
- save and load game

Known issues:

- Sometimes when the human player is in check, they can still move on attacked piece
- Castle does not account for attacked king
- code is shit
