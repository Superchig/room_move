# Stories
As a player

I want to move between rooms with a textual interface

so that I can actually achieve movement

# Scenarios

Given the player is in a room where he can move to another one,

When he types "north",

Then ensure the player moves into the northern room

And ensure this movement is shown.

=======

Given a room with an exit to another room.

And the player is in the first room.

When the player moves to the second room.

Then all references with weak\_ptrs and shared\_ptrs are updated.
