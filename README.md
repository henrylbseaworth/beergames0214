beergames0214
=============

Week of June 2, 2014 beer games.

Due: Monday, June 9 as close to 4:35 pm MST as possible.

Challenge
-----
Develop a program that takes two inputs, a text file and a key (the key can be any ascii string but the text file could be any text encoding). The program searches the text file for the key. If the key is found the program inserts the number of occurrences of the key up to that point in the document next to that key. The changes will be made in-place for simplicity of checking.

Example
-----
Given the following text file

    hi my name is bacon and this email is getting longer than expected. have you ever thought about bacon ^ bacon && bacon?

and our key is "bacon", then the resulting text file could be:

    hi my name is bacon(1) and this email is getting longer than expected. have you ever thought about bacon(2) ^ bacon(3) && bacon(4)?

You can use any languages/libraries/hax. Whoever completes the program is invited to a bar to drink beer. Whoever "wins" the challenge chooses the bar

## Beer Games Rules (Preliminary)

### Programs
Contestants can enter any number of programs. Programs can use any language, libraries, or dependencies. The programs will be evaluated on ONE agreed upon machine. 

###Metrics
Challenges should include details such as the due date and specifics of how to win the challenge. Usually an auto-checker will be provided to provide logical validation and possibly some benchmark if applicable. 

### Rewards
By tradition, the winner of the challenge picks a celebration venue (bar). All contestants that complete the challenge are invited to the celebration and are not obligated to buy the winner anything. 

### Submissions
Make a folder in the root directory of the repository. The name of this folder is your handle. Put all your submissions in this folder, you may organize them as you see fit.

E.g. if I wanted to submit my program called SortingIPAs.sh I could use the following procedure:

```shell
git clone https://github.com/henrylbseaworth/beergames0214.git
cd beergames0214
mkdir -p baconsWinningSubmissions   #my folder/handle
cp <path_to_my_submission>/SortingIPAs.sh ./baconsWinningSubmissions/   #copy in my submission
git add baconsWinningSubmissions/SortingIPAs.sh #add my submission to be tracked 
git commit -m "added my submission yay!"    #commit this change to the stage
git push -u orign master    #push my changes to the repository

```
