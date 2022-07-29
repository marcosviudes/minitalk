# Minitalk

Minitalk is a project that generates a couple of programs that work as a client and a server.

Client and server comunicate using only two Unix signals: SIGUSR1 and SIGUSR2.

NO standard protocol used, it sends the strings bit by bit.

## How to run it
  * Use ``make`` to generate the two programs
  
  * Run ``./server`` with no arguments. the server will print its PID
  
  * Use ``./client [PID] [MESSAGE]`` and send a MESSAGE to the server
   
  
  To simplify you can use ``$(pgrep -x server)`` that returns the server PID
  
  Example: ``./client $(pgrep -x server) "$(cat ./test.txt)"``

## Makefile
   
  ``clean``: remove objects
  
  ``fclean``: remove binaries
  
  ``re``: generate all again
  
