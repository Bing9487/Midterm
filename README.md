# Midterm
Chap 4 (50%) 轉板
Add more and more tasks into Chap 4 example by mixing all sub projects functions, features
• Try it and see if you are right,
ex. add x+1 LEDS mapped to x+1 tasks with different priority and STACK size, processing and loading, and 
How many tasks you could create via your RP2040 now? 
Check its boundaries before system failure, 
POC, prove of your concept if system crash 
Chap 5 (50%) 
Counting Semaphore Question
What would happen if in LimitWorker we had four BlinkWorkers but only two tokens
Try it and see if you are right.

Submitting via extension board and
0. PDF file only + ID photo
snapshots  (50%) x 2 chapter 
add each README.txt of each chapter with Q&A, daily, modifications, SOP, comments...etc (50%) x 2 chapter 
Update your chapter in GitHub regularly for FINAL EXAM  (50%)
In Question 1, it can blink 26+1 LEDs，I use GPIO Pin 0~22、26~28 and let those LEDs blink. And I try >28 LEDs but didn’t work. So the maximum of the LEDs is 26+1LEDs.
In Question 2, the first two tasks will run concurrently, each acquiring a token. The remaining two tasks will block and wait for a token. Once one of the running tasks finishes and releases a token, one of the blocked tasks will acquire it and start running. This means only two tasks can run at a time, and the other two will wait until a token is available.
