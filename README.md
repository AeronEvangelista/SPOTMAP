# :school:SPOTMAP:world_map:

### Prepared By:
### _Abril, Danielle Ziac R._
### _Evangelista, Aeron M._
### _Sumang, Vex Ivan C._
---


With over a hundred rooms and offices, Spot Map will help you navigate your designated locations faster and easier. Not only that, we plan to make this guide a front to newcomers and serve as the showpiece that can also help promote the school as a futuristic learning environment. This innovation will show Spartans’ capability of ensuring warmth in welcoming newcomers into their home.

The clickable buildings as the main menu will serve as a navigating planimetric map of the campus. To search for certain rooms, click the search menu and the list of rooms is displayed alphabetically. Timely campus events can also be announced through the updates in the event window. To download the planimetric map, the button in the upper left corner of the main display contains the qr code that will give access to the map image. This will become an opportunity to further encourage and captivate not only the hearts of new spartans, but also visitors in our school.

Vision: Our vision is to implement a technology-advanced learning environment in all campuses to also promote the connection as the Philippine’s National
Engineering University.

Mission: Our mission aims to be part of the advancement of our school as tech-savvy students who are leaders of sustainable development of innovations.

Future Plans: If given the chance to update and implement the current program, our objective is to make our interface more functionable by adding more convenient features such as the search engine. More animation and visually attractive design will also help the program be more user-friendly especially to visitors. Not only that, we plan to make it more accessible not only in a single school monitor, but also into one of the most innovative technologies, our phones.

---
Breaking Down of Codes
---
---
[Mouse hovering (maps and buttons)]
---
- Get position of the mouse in the window
- Get the coordinates of the parameter
- If mouse is in the parameter, change load file / set string
- Same goes with mouse is pressed and released
---
(Manual Coordinates)
---
- Use variables dependent on the width and height of the user’s
desktop using the formula: w * x/w, h* y/h (Automatic Coordinates)
- button.getGlobalBounds
---
[Animation (skies and clouds)]
---
- Create a boolean loop where images move horizontally
- When position == max position, set bool to false
- When position == min position, set bool to true
- The bool expression serves as the left & right direction of the movement
---
[Calling functions (buttons and windows)]
---
- Every void renders a window and has a game loop
- When another window is called, the previous window is closed
---
[Page loops (floorplan pages)]
---
- Designated certain image(set string) for each value
- When right button is pressed page ++;
- When left button is pressed page–;
- When page < minvalue, page = maxvalue;
- When page > maxvalue, page = minvalue;
---
[Debugging (Console & Terminal Displays)]
---
- Left button was pressed; get mouse position (coordinates)
- If (!image.loadfromfile(“”)) cout << “image cannot be found”<< endl;
- Cout and endl for readable debugs
---
  Platforms Used	IDE:
---
-	Visual Studio, and Visual Code Library:
-	(SFML) Simple and Fast Multimedia Library Design:
-	Pixilart and Canva
---
FLOWCHART: [SpotMap_Flowchart](https://github.com/AeronEvangelista/SPOTMAP/blob/main/FLOWCHART.pdf)

---
#### Acknowledgement: A special appreciation to Ma’am Lanie Palad, our course facilitator and Engr. Oliver S. Dimalig, the Head of PFMO Alangilan, for providing access to essential information - the floor plans.
---

