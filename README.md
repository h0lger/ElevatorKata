ElevatorKata
-------------

Specifications:

Floors tot: 20 (0-19)
Direction: up/down
Elevator calls: smarter than FIFO

Q = Requested calls in queue.
Elevator @ N = current floor.
N(up/down) = requested floor (direction if outside call).
→ Requested call.

Test cases:

Inside calls:
1: Request to go from 1 to 19
2: Request to go from 19 to 10

Outside calls:
3: Elevator @ 10 → 1(up) Q: 5(down) Ex: 5, 1
4: Elevator @ 10 →  5(up) Q:1(up) Ex: 1, 5
5: Elevator @ 10 → 1(up) Q: 3(down), 5(down) Ex: 5, 3, 1
6: Elevator @ 10 → 5(up) Q: 3(up), 1(up) Ex: 3, 1, 5
6.1: Elevator @ 3 → 8 Q: 1(up), 5(up)  Ex: 5, 8, 1
7: Elevator @ 19 → 18(up) Q:1(down) Ex: 1, 18

Mixed calls:
8: Elevator @ 5 → 3 Q:1(up)
9: Elevator @ 5 → 15 Q: 7, 8(down), 10
