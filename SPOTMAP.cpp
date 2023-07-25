#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
void MAIN_WINDOW();
void CICS_WINDOW();
void CEAFA_WINDOW();
void ACES_WINDOW();
void CIT_WINDOW();
void SSO_WINDOW();
void BSU_WINDOW();
void MENU_PAGE_1_WINDOW();
void MENU_PAGE_2_WINDOW();
void MENU_PAGE_3_WINDOW();
void MENU_PAGE_4_WINDOW();
void MENU_PAGE_5_WINDOW();
void MENU_PAGE_6_WINDOW();
void MENU_PAGE_7_WINDOW();
void BUTTON_WINDOW(int x);
void EVENTS_WINDOW();
void LOGO_WINDOW();

using namespace sf;
using namespace std;

int main()
{
    //PLAY BACKGROUND MUSIC
    Music music;
    music.openFromFile("resources/CottonCandy.ogg");
    music.play();
    music.setLoop(true);

    MAIN_WINDOW();


    return EXIT_SUCCESS;
}

void MAIN_WINDOW()
{
    // Fullscreen WINDOW (3360,2100)
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    window.setFramerateLimit(60);

    // PLANIMETRIC MAP
    float xPos = w / static_cast<float>(2);
    float yPos = h / static_cast<float>(2);

    RectangleShape map(Vector2f(w, h));
    map.setPosition(xPos, yPos);
    map.setOrigin(xPos, yPos);
    string mapImage = "resources/map.png";

    // CLOUD 1
    RectangleShape cloud1(Vector2f(w, h));
    Texture cloud1Texture;
    cloud1Texture.loadFromFile("resources/cloud-1.png");
    cloud1.setTexture(&cloud1Texture);
    cloud1.setOrigin(xPos + 15, yPos);

    // CLOUD 2
    RectangleShape cloud2(Vector2f(w, h));
    Texture cloud2Texture;
    cloud2Texture.loadFromFile("resources/cloud-2.png");
    cloud2.setTexture(&cloud2Texture);
    cloud2.setOrigin(xPos - 15, yPos);

    // MOVING CLOUDS
    bool cloud1direction = true;
    bool cloud2direction = false;

    float move = 0.50;
    float cloudmaxMove = 15;
    float cloud1maxPos = xPos + cloudmaxMove;
    float cloud1minPos = xPos - cloudmaxMove;
    float cloud2maxPos = xPos + cloudmaxMove;
    float cloud2minPos = xPos - cloudmaxMove;

    Vector2f cloud1Position(xPos, yPos);
    cloud1.setPosition(cloud1Position);

    Vector2f cloud2Position(xPos, yPos);
    cloud2.setPosition(cloud2Position);

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(window).x;
    mp.y = Mouse::getPosition(window).y;


    //TEXT DECLARATION/VARIABLES-------------------------------------------------------------------------------------------------------
    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(Color::Blue);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.83f, h * 0.89f);

    // TEXTBOX
    RectangleShape textbox(Vector2f(w * 0.20, h * 0.10)); // size and pos not finalized
    textbox.setPosition(w * 0.78, h * 0.87);
    Texture textboxtexture;
    textboxtexture.loadFromFile("resources/textbox.png");
    textbox.setTexture(&textboxtexture);

    // WELCOME
    RectangleShape welcome(Vector2f(w * 0.20, h * 0.1)); // size and pos not finalized
    welcome.setPosition(w * 0.78, h * 0.76);
    Texture welcometexture;
    welcometexture.loadFromFile("resources/welcome.png");
    welcome.setTexture(&welcometexture);

    // BUTTON: SEARCH MENU
    RectangleShape menu(Vector2f(w * 0.31, h * 0.07));
    menu.setPosition(w * 0.68, h * 0.03);
    string menuImage = "resources/menu.png";

    // BUTTON: EVENTS
    RectangleShape events(Vector2f(w * 0.21, h * 0.07));
    events.setPosition(w * 0.78, h * 0.12);
    Texture eventstexture;
    string EventsImage = "resources/events.png";

    // BUTTON: BSU LOGO
    RectangleShape bsu(Vector2f(w * 0.16, h * 0.32));
    bsu.setPosition(w * 0.03, h * 0.0);
    Texture bsutexture;
    string BSUImage = "resources/bsu.png";

    // BUTTON: SPOTMAP LOGO
    RectangleShape logo(Vector2f(w * 0.31, h * 0.37));
    logo.setPosition(w * 0.08, h * 0.58);
    string LogoImage = "resources/logo.png";



    //GAME LOOP
    while (window.isOpen())
    {
        Event ev;
        // FOR HOVERING (MANUAL COORDINATES)
        //Mouse mp;
        //Vector2i mo;
        //mo.y = mp.getPosition(window).y;
        //mo.x = mp.getPosition(window).x;

        // FOR AUTOMATED COORDINATES
        Vector2i mp = Mouse::getPosition(window);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        //EVENTS
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (ev.key.code == Keyboard::Escape)
                    window.close();
                break;
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                    cout << "the left button was pressed" << endl;
                cout << "mouse x: " << ev.mouseButton.x << endl;
                cout << "mouse y: " << ev.mouseButton.y << endl;
                break;
            Fullscreen:
                break;
            }
        }

        // BUTTON SENSOR: SEARCH MENU
        //if (mo.x > w * 0.68 && mo.x < w * 0.99 && mo.y > h * 0.03 && mo.y < h * 0.10) {
        if (menu.getGlobalBounds().contains(mo))
        {
            cout << "You clicked Menu" << endl;
            menuImage = "resources/menu2.png";
            if (menu.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                menuImage = "resources/menu3.png";
                window.close();
                MENU_PAGE_1_WINDOW();
            }
        }
        else
            menuImage = "resources/menu.png";

        // BUTTON SENSOR: EVENTS
        //if (mo.x > w * 0.78 && mo.x < w * 0.99 && mo.y > h * 0.12 && mo.y < h * 0.19) {
        if (events.getGlobalBounds().contains(mo))
        {
            cout << "You clicked Events" << endl;
            EventsImage = "resources/events2.png";
            if (events.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                EventsImage = "resources/events3.png";
                window.close();
                EVENTS_WINDOW();
            }
        }
        else
            EventsImage = "resources/events.png";

        //BUTTON SENSOR: BSU LOGO
        //if (mo.x > w * 0.03 && mo.x < w * 0.19 && mo.y > h * 0 && mo.y < h * 0.32) {
        if (bsu.getGlobalBounds().contains(mo))
        {
            cout << "You clicked the BSU LOGO" << endl;

            BSUImage = "resources/bsu2.png";

            if (bsu.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                BSUImage = "resources/bsu3.png";
                BSU_WINDOW();
                window.close();
            }
        }
        else
            BSUImage = "resources/bsu.png";

        // BUTTON SENSOR: SPOTMAP LOGO
        //if (mo.x > w * 0.08 && mo.x < w * 0.39 && mo.y > h * 0.56 && mo.y < h * 0.94) {
        if (logo.getGlobalBounds().contains(mo))
        {
            cout << "You clicked the SpotMap Logo" << endl;

            LogoImage = "resources/logo2.png";
            if (logo.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                LogoImage = "resources/logo3.png";
                LOGO_WINDOW();
                window.close();
            }
        }
        else
            LogoImage = "resources/logo.png";

        // CLICKABLE BUILDINGS

         // ACES
        if (mo.x > w * 0.46 && mo.x < w * 0.54 && mo.y > h * 0.08 && mo.y < h * 0.14)
        {
            cout << "You clicked the ACES BUILDING" << endl;
            mapImage = "resources/B.ACES.png";
            text.setString("ACES");
            text.setCharacterSize(h * 0.05);
            text.setPosition(w * 0.84f, h * 0.89f);
            if (mo.x > w * 0.46 && mo.x < w * 0.54 && mo.y > h * 0.08 && mo.y < h * 0.14 && Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
                ACES_WINDOW();
            }
        }

        // CICS
        else if (mo.x > w * 0.55 && mo.x < w * 0.59 && mo.y > h * 0.04 && mo.y < h * 0.34)
        {
            cout << "You clicked the CICS BUILDING" << endl;
            mapImage = "resources/B.CICS.png";
            text.setString("CICS");
            text.setCharacterSize(h * 0.05);
            text.setPosition(w * 0.84f, h * 0.89f);
            if (mo.x > w * 0.55 && mo.x < w * 0.59 && mo.y > h * 0.04 && mo.y < h * 0.34 && Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
                CICS_WINDOW();
            }
        }

        // CEAFA
        else if (mo.x > w * 0.28 && mo.x < w * 0.42 && mo.y > h * 0.22 && mo.y < h * 0.50)
        {
            cout << "You clicked the CEAFA BUILDING" << endl;
            mapImage = "resources/B.CEAFA.png";
            text.setString("CEAFA");
            text.setCharacterSize(h * 0.05);
            text.setPosition(w * 0.83f, h * 0.89f);
            if (mo.x > w * 0.28 && mo.x < w * 0.42 && mo.y > h * 0.22 && mo.y < h * 0.50 && Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
                CEAFA_WINDOW();
            }
        }

        // CENTER FOR STUDENT SERVICES CENTER
        else if (mo.x > w * 0.52 && mo.x < w * 0.55 && mo.y > h * 0.71 && mo.y < h * 0.84)
        {
            cout << "You clicked the CFT BUILDING" << endl;
            mapImage = "resources/B.Center_for_Technopreneurship.png";
            text.setString("          CENTER FOR \nTECHNOPRENEURSHIP");
            text.setCharacterSize(h * 0.02);
            text.setPosition(w * 0.81f, h * 0.89f);
            if (mo.x > w * 0.52 && mo.x < w * 0.55 && mo.y > h * 0.71 && mo.y < h * 0.84 && Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
                SSO_WINDOW();
            }
        }

        // CIT
        else if (mo.x > w * 0.63 && mo.x < w * 0.66 && mo.y > h * 0.72 && mo.y < h * 0.93)
        {
            cout << "You clicked the CIT BUILDING" << endl;
            mapImage = "resources/B.CIT.png";
            text.setString("CIT");
            text.setCharacterSize(h * 0.05);
            text.setPosition(w * 0.85f, h * 0.89f);
            if (mo.x > w * 0.63 && mo.x < w * 0.66 && mo.y > h * 0.72 && mo.y < h * 0.93 && Mouse::isButtonPressed(Mouse::Left))
            {
                window.close();
                CIT_WINDOW();
            }
        }

        // COVERED WALKWAY
        else if (mo.x > w * 0.43 && mo.x < w * 0.50 && mo.y > h * 0.47 && mo.y < h * 0.93)
        {
            cout << "You clicked the B.Covered_walkway1" << endl;
            mapImage = "resources/B.Covered_walkway1.png";
            text.setString("Long Covered-Walkway");
            text.setCharacterSize(h * 0.02);
            text.setPosition(w * 0.81f, h * 0.905f);
        }

        // COVERED WALKWAY 2
        else if (mo.x > w * 0.52 && mo.x < w * 0.62 && mo.y > h * 0.69 && mo.y < h * 0.71)
        {
            cout << "You clicked the B_CWW BUILDING" << endl;
            mapImage = "resources/B.Covered_walkway2.png";
            text.setString("Short Covered-Walkway");
            text.setCharacterSize(h * 0.02);
            text.setPosition(w * 0.807f, h * 0.907f);
        }

        // FOOD INNOVATION
        else if (mo.x > w * 0.30 && mo.x < w * 0.33 && mo.y > h * 0.14 && mo.y < h * 0.22)
        {
            cout << "You clicked the FOOD INNOVATION BUILDING" << endl;
            mapImage = "resources/B.Food_Innovation_Center.png";
            text.setString("Food Innovation");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.80f, h * 0.90f);
        }

        // FOUNTAIN
        else if (mo.x > w * 0.42 && mo.x < w * 0.50 && mo.y > h * 0.25 && mo.y < h * 0.46)
        {
            cout << "You clicked the FOUNTAIN" << endl;
            mapImage = "resources/B.Fountain_Area.png";
            text.setString("Fountain");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.83f, h * 0.897f);
        }

        // GATE 3
        else if (mo.x > w * 0.67 && mo.x < w * 0.71 && mo.y > h * 0.93 && mo.y < h * 0.95)
        {
            cout << "You clicked the GATE 3" << endl;
            mapImage = "resources/B.Gate3.png";
            text.setString("Gate 3");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.838f, h * 0.897f);
        }

        // GATE 2
        else if (mo.x > w * 0.49 && mo.x < w * 0.52 && mo.y > h * 0.94 && mo.y < h * 0.95)
        {
            cout << "You clicked the GATE 2" << endl;
            mapImage = "resources/B.Gate2.png";
            text.setString("Gate 2");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.838f, h * 0.897f);
        }

        // GYMNASIUM
        else if (mo.x > w * 0.52 && mo.x < w * 0.68 && mo.y > h * 0.35 && mo.y < h * 0.52)
        {
            cout << "You clicked the GYM BUILDING" << endl;
            mapImage = "resources/B.Gym.png";
            text.setString("GYMNASIUM");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.820f, h * 0.897f);
        }

        // MAIN GATE
        else if (mo.x > w * 0.52 && mo.x < w * 0.62 && mo.y > h * 0.92 && mo.y < h * 0.95)
        {
            cout << "You clicked the MAIN GATE" << endl;
            mapImage = "resources/B.Main_Gate.png";
            text.setString("MAIN GATE");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.828f, h * 0.897f);
        }

        // PARKING LOT
        else if (mo.x > w * 0.57 && mo.x < w * 0.62 && mo.y > h * 0.54 && mo.y < h * 0.66)
        {
            cout << "You clicked the PARKING LOT " << endl;
            mapImage = "resources/B.Parking_Lot.png";
            text.setString("Parking Lot");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.820f, h * 0.90f);
        }

        // PARKING LOT 2
        else if (mo.x > w * 0.34 && mo.x < w * 0.42 && mo.y > h * 0.11 && mo.y < h * 0.21)
        {
            cout << "You clicked the PARKING LOT2 " << endl;
            mapImage = "resources/B.Parking_Lot2.png";
            text.setString("Parking Lot 2");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.812f, h * 0.90f);
        }

        // PARKING LOT 3
        else if (mo.x > w * 0.46 && mo.x < w * 0.55 && mo.y > h * 0.14 && mo.y < h * 0.19)
        {
            cout << "You clicked the PARKING LOT3" << endl;
            mapImage = "resources/B.Parking_Lot3.png";
            text.setString("Parking Lot 3");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.812f, h * 0.90f);
        }

        // STEER HUB
        else if (mo.x > w * 0.62 && mo.x < w * 0.71 && mo.y > h * 0.48 && mo.y < h * 0.67)
        {
            cout << "You clicked the STEER HUB BUILDING" << endl;
            mapImage = "resources/B.Research_Steer_Hub.png";
            text.setString("STEER HUB");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.822f, h * 0.90f);
        }

        // ROTONDA
        else if (mo.x > w * 0.48 && mo.x < w * 0.53 && mo.y > h * 0.20 && mo.y < h * 0.27)
        {
            cout << "You clicked the ROTONDA" << endl;
            mapImage = "resources/B.Rotonda.png";
            text.setString("ROTONDA");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.827f, h * 0.90f);
        }

        // STUDY AREA
        else if (mo.x > w * 0.53 && mo.x < w * 0.55 && mo.y > h * 0.19 && mo.y < h * 0.30)
        {
            cout << "You clicked the STUDY AREA" << endl;
            mapImage = "resources/B.Study_Area.png";
            text.setString("STUDY AREA");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.818f, h * 0.90f);
        }

        // STUDY AREA 2
        else if (mo.x > w * 0.52 && mo.x < w * 0.57 && mo.y > h * 0.54 && mo.y < h * 0.66)
        {
            cout << "You clicked the STUDY AREA2" << endl;
            mapImage = "resources/B.Study_Area2.png";
            text.setString("STUDY AREA 2");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.812f, h * 0.90f);
        }

        // WALK WAY
        else if (mo.x > w * 0.60 && mo.x < w * 0.62 && mo.y > h * 0.72 && mo.y < h * 0.92)
        {
            cout << "You clicked the WALK WAY" << endl;
            mapImage = "resources/B.Walkway.png";
            text.setString("WALK WAY");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.826f, h * 0.90f);
        }

        // WALK WAY 2
        else if (mo.x > w * 0.7 && mo.x < w * 0.71 && mo.y > h * 0.72 && mo.y < h * 0.93)
        {
            cout << "You clicked the WALK WAY2" << endl;
            mapImage = "resources/B.Walkway3.png";
            text.setString("WALK WAY 2");
            text.setCharacterSize(h * 0.03);
            text.setPosition(w * 0.819f, h * 0.90f);
        }

        else {
            mapImage = "resources/map.png";
            text.setString("Explore!");
            text.setCharacterSize(h * 0.04);
            text.setPosition(w * 0.83f, h * 0.89f);
        }

        // MOVING CLOUDS 1
        if (cloud1Position.x == cloud1maxPos) {
            cloud1direction = false;
        }

        if (cloud1Position.x == cloud1minPos) {
            cloud1direction = true;
        }

        if (cloud1direction == true) {
            cloud1Position.x += move;
        }
        else if (cloud1direction == false) {
            cloud1Position.x -= move;
        }

        cloud1.setPosition(cloud1Position);

        // MOVING CLOUDS 2
        if (cloud2Position.x == cloud2maxPos) {
            cloud2direction = false;
        }

        if (cloud2Position.x == cloud2minPos) {
            cloud2direction = true;
        }

        if (cloud2direction == true) {
            cloud2Position.x += move;
        }
        else if (cloud2direction == false) {
            cloud2Position.x -= move;
        }

        cloud2.setPosition(cloud2Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture mapTexture;
        mapTexture.loadFromFile(mapImage);
        map.setTexture(&mapTexture);

        Texture bsutexture;
        bsutexture.loadFromFile(BSUImage);
        bsu.setTexture(&bsutexture);

        Texture logotexture;
        logotexture.loadFromFile(LogoImage);
        logo.setTexture(&logotexture);

        Texture menutexture;
        menutexture.loadFromFile(menuImage);
        menu.setTexture(&menutexture);

        Texture eventstexture;
        eventstexture.loadFromFile(EventsImage);
        events.setTexture(&eventstexture);

        //RENDER DISPLAY
        window.clear();

        window.draw(map);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(textbox);
        window.draw(welcome);
        window.draw(menu);
        window.draw(events);
        window.draw(bsu);
        window.draw(logo);
        window.draw(text);
        window.display();

    }

}

void CICS_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow CICSwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    CICSwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    // CICS BOARDER
    RectangleShape CICS(Vector2f(w, h));
    CICS.setPosition(xPos * 0.98, yPos * 1.1);
    Texture CICSTexture;
    CICSTexture.loadFromFile("resources/CICS.png");
    CICS.setTexture(&CICSTexture);
    CICS.setOrigin(xPos, yPos);

    // BACK BUTTON
    RectangleShape CICSBack(Vector2f(w * 0.15, h * 0.08));
    CICSBack.setPosition(w * 0.01, h * 0.02);
    string CICSBackImage = "resources/back.png";

    // RIGHT BUTTON
    RectangleShape CICSRight(Vector2f(w * 0.09, h * 0.1));
    CICSRight.setPosition(w * 0.7, h * 0.85);
    string CICSRightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape CICSLeft(Vector2f(w * 0.09, h * 0.1));
    CICSLeft.setPosition(w * 0.2, h * 0.85);
    string CICSLeftImage = "resources/left.png";

    // FLOOR LEVELS
    RectangleShape CICSFloor(Vector2f(w * 0.35, h * 0.1));
    CICSFloor.setPosition(w * 0.33, h * 0.85);
    string CICSFloorImage = "resources/floor-1.png";

    // FLOOR PLAN
    RectangleShape FLOOR_PLAN(Vector2f(w * 0.73, h * 0.40));
    FLOOR_PLAN.setPosition(w * 0.13, h * 0.37);
    string PLAN_IMAGE = "resources/CICS-1.png";

    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(CICSwindow).x;
    mp.y = Mouse::getPosition(CICSwindow).y;

    int FloorLevel = 1;


    // GAME LOOP
    while (CICSwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(CICSwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        int maxFloor = 5;

        //EVENTS
        while (CICSwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                CICSwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    CICSwindow.close();

                // BUTTONS
            case Event::MouseButtonReleased:
                CICSRightImage = "resources/right.png";
                CICSLeftImage = "resources/left.png";

            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    cout << "CICSwindow; the left button was pressed" << endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;

                //BUTTON SENSOR: RIGHT
                if (CICSRight.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel++;
                    CICSRightImage = "resources/right2.png";

                    if (FloorLevel > maxFloor)
                    {
                        FloorLevel = 1;
                    }
                }
                //BUTTON SENSOR: LEFT
                if (CICSLeft.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel--;
                    CICSLeftImage = "resources/left2.png";

                    if (FloorLevel < 1)
                    {
                        FloorLevel = 5;
                    }
                }

            Fullscreen:
                break;
            }
        }
        //BUTTONS HOVERED
        //if (mo.x > w * 0.01 && mo.x < w * 0.15 && mo.y > h * 0.02 && mo.y < h * 0.10) {
        if (CICSBack.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            CICSBackImage = "resources/back2.png";
            if (CICSBack.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                CICSBackImage = "resources/back3.png";
                MAIN_WINDOW();
                CICSwindow.close();

            }
        }
        else
        {
            CICSBackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture CICSBackTexture;
        CICSBackTexture.loadFromFile(CICSBackImage);
        CICSBack.setTexture(&CICSBackTexture);

        Texture CICSRightTexture;
        CICSRightTexture.loadFromFile(CICSRightImage);
        CICSRight.setTexture(&CICSRightTexture);

        Texture CICSLeftTexture;
        CICSLeftTexture.loadFromFile(CICSLeftImage);
        CICSLeft.setTexture(&CICSLeftTexture);

        Texture CICSFloorTexture;
        CICSFloorImage = "resources/floor-" + to_string(FloorLevel) + ".png";
        CICSFloorTexture.loadFromFile(CICSFloorImage);
        CICSFloor.setTexture(&CICSFloorTexture);

        Texture PlanTexture;
        PLAN_IMAGE = "resources/CICS-" + to_string(FloorLevel) + ".png";
        PlanTexture.loadFromFile(PLAN_IMAGE);
        FLOOR_PLAN.setTexture(&PlanTexture);

        //RENDER DISPLAY
        CICSwindow.clear();

        CICSwindow.draw(skies1);
        CICSwindow.draw(skies2);
        CICSwindow.draw(cloud3);
        CICSwindow.draw(CICS);
        CICSwindow.draw(CICSRight);
        CICSwindow.draw(CICSLeft);
        CICSwindow.draw(CICSFloor);
        CICSwindow.draw(CICSBack);
        CICSwindow.draw(FLOOR_PLAN);
        CICSwindow.display();

    }

}

void CEAFA_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow CEAFAwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    CEAFAwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    // CEAFA BOARDER
    RectangleShape CEAFA(Vector2f(w, h));
    CEAFA.setPosition(xPos * 0.98, yPos * 1.1);
    Texture CEAFATexture;
    CEAFATexture.loadFromFile("resources/CEAFA.png");
    CEAFA.setTexture(&CEAFATexture);
    CEAFA.setOrigin(xPos, yPos);

    // BACK BUTTON
    RectangleShape CEAFABack(Vector2f(w * 0.15, h * 0.08));
    CEAFABack.setPosition(w * 0.01, h * 0.02);
    string CEAFABackImage = "resources/back.png";

    // RIGHT BUTTON
    RectangleShape CEAFARight(Vector2f(w * 0.08, h * 0.1));
    CEAFARight.setPosition(w * 0.905, h * 0.70);
    string CEAFARightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape CEAFALeft(Vector2f(w * 0.08, h * 0.1));
    CEAFALeft.setPosition(w * 0.565, h * 0.70);
    string CEAFALeftImage = "resources/left.png";

    // FLOOR LEVELS
    RectangleShape CEAFAFloor(Vector2f(w * 0.25, h * 0.09));
    CEAFAFloor.setPosition(w * 0.65, h * 0.70);
    string CEAFAFloorImage = "resources/floor-1.png";

    // FLOOR PLAN
    RectangleShape FLOOR_PLAN(Vector2f(w * 0.463, h * 0.767));
    FLOOR_PLAN.setPosition(w * 0.048, h * 0.16);
    string PLAN_IMAGE = "resources/CEAFA-1.png";

    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(CEAFAwindow).x;
    mp.y = Mouse::getPosition(CEAFAwindow).y;

    int FloorLevel = 1;


    // GAME LOOP
    while (CEAFAwindow.isOpen())
    {
        Event ev2;
        Vector2i mp = Mouse::getPosition(CEAFAwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        int maxFloor = 5;

        //EVENTS
        while (CEAFAwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                CEAFAwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    CEAFAwindow.close();

                // BUTTONS
            case Event::MouseButtonReleased:
                CEAFARightImage = "resources/right.png";
                CEAFALeftImage = "resources/left.png";
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    cout << "CEAFAwindow; the left button was pressed" << endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;

                //BUTTON SENSOR: RIGHT
                if (CEAFARight.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel++;
                    CEAFARightImage = "resources/right2.png";

                    if (FloorLevel > maxFloor)
                    {
                        FloorLevel = 1;
                    }
                }
                //BUTTON SENSOR: LEFT
                if (CEAFALeft.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel--;
                    CEAFALeftImage = "resources/left2.png";

                    if (FloorLevel < 1)
                    {
                        FloorLevel = 5;
                    }
                }

            Fullscreen:
                break;
            }
        }
        //BUTTONS HOVERED
        //if (mo.x > w * 0.01 && mo.x < w * 0.15 && mo.y > h * 0.02 && mo.y < h * 0.10) {
        if (CEAFABack.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            CEAFABackImage = "resources/back2.png";
            if (CEAFABack.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                CEAFABackImage = "resources/back3.png";
                MAIN_WINDOW();
                CEAFAwindow.close();

            }
        }
        else
        {
            CEAFABackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture CEAFABackTexture;
        CEAFABackTexture.loadFromFile(CEAFABackImage);
        CEAFABack.setTexture(&CEAFABackTexture);

        Texture CEAFARightTexture;
        CEAFARightTexture.loadFromFile(CEAFARightImage);
        CEAFARight.setTexture(&CEAFARightTexture);

        Texture CEAFALeftTexture;
        CEAFALeftTexture.loadFromFile(CEAFALeftImage);
        CEAFALeft.setTexture(&CEAFALeftTexture);

        Texture CEAFAFloorTexture;
        CEAFAFloorImage = "resources/floor-" + to_string(FloorLevel) + ".png";
        CEAFAFloorTexture.loadFromFile(CEAFAFloorImage);
        CEAFAFloor.setTexture(&CEAFAFloorTexture);

        Texture PlanTexture;
        PLAN_IMAGE = "resources/CEAFA-" + to_string(FloorLevel) + ".png";
        PlanTexture.loadFromFile(PLAN_IMAGE);
        FLOOR_PLAN.setTexture(&PlanTexture);

        //RENDER DISPLAY
        CEAFAwindow.clear();

        CEAFAwindow.draw(skies1);
        CEAFAwindow.draw(skies2);
        CEAFAwindow.draw(cloud3);
        CEAFAwindow.draw(CEAFA);
        CEAFAwindow.draw(CEAFARight);
        CEAFAwindow.draw(CEAFALeft);
        CEAFAwindow.draw(CEAFAFloor);
        CEAFAwindow.draw(CEAFABack);
        CEAFAwindow.draw(FLOOR_PLAN);
        CEAFAwindow.display();

    }

}

void ACES_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow ACESwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    ACESwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    // ACES BOARDER
    RectangleShape ACES(Vector2f(w, h));
    ACES.setPosition(xPos * 0.98, yPos * 1.1);
    Texture ACESTexture;
    ACESTexture.loadFromFile("resources/ACES.png");
    ACES.setTexture(&ACESTexture);
    ACES.setOrigin(xPos, yPos);

    // BACK BUTTON
    RectangleShape Back(Vector2f(w * 0.15, h * 0.08));
    Back.setPosition(w * 0.01, h * 0.02);
    string BackImage = "resources/back.png";

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.09, h * 0.1));
    Right.setPosition(w * 0.7, h * 0.85);
    string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.09, h * 0.1));
    Left.setPosition(w * 0.2, h * 0.85);
    string LeftImage = "resources/left.png";

    // FLOOR LEVELS
    RectangleShape Floor(Vector2f(w * 0.35, h * 0.1));
    Floor.setPosition(w * 0.33, h * 0.85);
    string FloorImage = "resources/floor-1.png";

    // FLOOR PLAN
    RectangleShape FLOOR_PLAN(Vector2f(w * 0.73, h * 0.40));
    FLOOR_PLAN.setPosition(w * 0.13, h * 0.37);
    string PLAN_IMAGE = "resources/ACES-1.png";

    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(ACESwindow).x;
    mp.y = Mouse::getPosition(ACESwindow).y;

    int FloorLevel = 1;


    // GAME LOOP
    while (ACESwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(ACESwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        int maxFloor = 3;

        //EVENTS
        while (ACESwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                ACESwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    ACESwindow.close();

                // BUTTONS
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    cout << "ACESwindow; the left button was pressed" << endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;

                //BUTTON SENSOR: RIGHT
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel++;
                    RightImage = "resources/right2.png";

                    if (FloorLevel > maxFloor)
                    {
                        FloorLevel = 1;
                    }
                }
                //BUTTON SENSOR: LEFT
                if (Left.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel--;
                    LeftImage = "resources/left2.png";

                    if (FloorLevel < 1)
                    {
                        FloorLevel = 3;
                    }
                }

            Fullscreen:
                break;
            }
        }
        //BUTTONS HOVERED
        //if (mo.x > w * 0.01 && mo.x < w * 0.15 && mo.y > h * 0.02 && mo.y < h * 0.10) {
        if (Back.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            BackImage = "resources/back2.png";
            if (Back.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                BackImage = "resources/back3.png";
                MAIN_WINDOW();
                ACESwindow.close();

            }
        }
        else
        {
            BackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture BackTexture;
        BackTexture.loadFromFile(BackImage);
        Back.setTexture(&BackTexture);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        Texture FloorTexture;
        FloorImage = "resources/floor-" + to_string(FloorLevel) + ".png";
        FloorTexture.loadFromFile(FloorImage);
        Floor.setTexture(&FloorTexture);

        Texture PlanTexture;
        PLAN_IMAGE = "resources/ACES-" + to_string(FloorLevel) + ".png";
        PlanTexture.loadFromFile(PLAN_IMAGE);
        FLOOR_PLAN.setTexture(&PlanTexture);

        //RENDER DISPLAY
        ACESwindow.clear();

        ACESwindow.draw(skies1);
        ACESwindow.draw(skies2);
        ACESwindow.draw(cloud3);
        ACESwindow.draw(ACES);
        ACESwindow.draw(Right);
        ACESwindow.draw(Left);
        ACESwindow.draw(Floor);
        ACESwindow.draw(Back);
        ACESwindow.draw(FLOOR_PLAN);
        ACESwindow.display();

    }

}

void CIT_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow CITwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    CITwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    // CIT BOARDER
    RectangleShape CIT(Vector2f(w, h));
    CIT.setPosition(xPos * 0.98, yPos * 1.1);
    Texture CITTexture;
    CITTexture.loadFromFile("resources/CIT.png");
    CIT.setTexture(&CITTexture);
    CIT.setOrigin(xPos, yPos);

    // BACK BUTTON
    RectangleShape Back(Vector2f(w * 0.15, h * 0.08));
    Back.setPosition(w * 0.01, h * 0.02);
    string BackImage = "resources/back.png";

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.09, h * 0.1));
    Right.setPosition(w * 0.7, h * 0.85);
    string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.09, h * 0.1));
    Left.setPosition(w * 0.2, h * 0.85);
    string LeftImage = "resources/left.png";

    // FLOOR LEVELS
    RectangleShape Floor(Vector2f(w * 0.35, h * 0.1));
    Floor.setPosition(w * 0.33, h * 0.85);
    string FloorImage = "resources/floor-1.png";

    // FLOOR PLAN
    RectangleShape FLOOR_PLAN(Vector2f(w * 0.73, h * 0.40));
    FLOOR_PLAN.setPosition(w * 0.13, h * 0.37);
    string PLAN_IMAGE = "resources/CIT-1.png";



    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(CITwindow).x;
    mp.y = Mouse::getPosition(CITwindow).y;

    int FloorLevel = 1;

    // GAME LOOP
    while (CITwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(CITwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        int maxFloor = 5;

        //EVENTS
        while (CITwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                CITwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    CITwindow.close();

                // BUTTONS
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    cout << "CITwindow; the left button was pressed" << endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;

                //BUTTON SENSOR: RIGHT
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel++;
                    RightImage = "resources/right2.png";

                    if (FloorLevel > maxFloor)
                    {
                        FloorLevel = 1;
                    }
                }
                //BUTTON SENSOR: LEFT
                if (Left.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel--;
                    LeftImage = "resources/left2.png";

                    if (FloorLevel < 1)
                    {
                        FloorLevel = 5;
                    }
                }

            Fullscreen:
                break;
            }
        }
        //BUTTONS HOVERED
        //if (mo.x > w * 0.01 && mo.x < w * 0.15 && mo.y > h * 0.02 && mo.y < h * 0.10) {
        if (Back.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            BackImage = "resources/back2.png";
            if (Back.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                BackImage = "resources/back3.png";
                MAIN_WINDOW();
                CITwindow.close();

            }
        }
        else
        {
            BackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture BackTexture;
        BackTexture.loadFromFile(BackImage);
        Back.setTexture(&BackTexture);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        Texture FloorTexture;
        FloorImage = "resources/floor-" + to_string(FloorLevel) + ".png";
        FloorTexture.loadFromFile(FloorImage);
        Floor.setTexture(&FloorTexture);

        Texture PlanTexture;
        PLAN_IMAGE = "resources/CIT-" + to_string(FloorLevel) + ".png";
        PlanTexture.loadFromFile(PLAN_IMAGE);
        FLOOR_PLAN.setTexture(&PlanTexture);


        //RENDER DISPLAY
        CITwindow.clear();

        CITwindow.draw(skies1);
        CITwindow.draw(skies2);
        CITwindow.draw(cloud3);
        CITwindow.draw(CIT);
        CITwindow.draw(Right);
        CITwindow.draw(Left);
        CITwindow.draw(Floor);
        CITwindow.draw(Back);
        CITwindow.draw(FLOOR_PLAN);
        CITwindow.display();

    }

}




void SSO_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow SSOwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    SSOwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    // SSO BOARDER
    RectangleShape SSO(Vector2f(w, h));
    SSO.setPosition(xPos * 0.98, yPos * 1.1);
    Texture SSOTexture;
    SSOTexture.loadFromFile("resources/SSO.png");
    SSO.setTexture(&SSOTexture);
    SSO.setOrigin(xPos, yPos);

    // BACK BUTTON
    RectangleShape Back(Vector2f(w * 0.15, h * 0.08));
    Back.setPosition(w * 0.01, h * 0.02);
    string BackImage = "resources/back.png";

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.09, h * 0.1));
    Right.setPosition(w * 0.7, h * 0.85);
    string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.09, h * 0.1));
    Left.setPosition(w * 0.2, h * 0.85);
    string LeftImage = "resources/left.png";

    // FLOOR LEVELS
    RectangleShape Floor(Vector2f(w * 0.35, h * 0.1));
    Floor.setPosition(w * 0.33, h * 0.85);
    string FloorImage = "resources/floor-1.png";

    // FLOOR PLAN
    RectangleShape FLOOR_PLAN(Vector2f(w * 0.73, h * 0.40));
    FLOOR_PLAN.setPosition(w * 0.13, h * 0.37);
    string PLAN_IMAGE = "resources/SSC-1.png";

    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(SSOwindow).x;
    mp.y = Mouse::getPosition(SSOwindow).y;

    int FloorLevel = 1;


    // GAME LOOP
    while (SSOwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(SSOwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        int maxFloor = 3;

        //EVENTS
        while (SSOwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                SSOwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    SSOwindow.close();

                // BUTTONS
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    cout << "SSOwindow; the left button was pressed" << endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;

                //BUTTON SENSOR: RIGHT
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel++;
                    RightImage = "resources/right2.png";

                    if (FloorLevel > maxFloor)
                    {
                        FloorLevel = 1;
                    }
                }
                //BUTTON SENSOR: LEFT
                if (Left.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    FloorLevel--;
                    LeftImage = "resources/left2.png";

                    if (FloorLevel < 1)
                    {
                        FloorLevel = 3;
                    }
                }

            Fullscreen:
                break;
            }
        }
        //BUTTONS HOVERED
        //if (mo.x > w * 0.01 && mo.x < w * 0.15 && mo.y > h * 0.02 && mo.y < h * 0.10) {
        if (Back.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            BackImage = "resources/back2.png";
            if (Back.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                BackImage = "resources/back3.png";
                MAIN_WINDOW();
                SSOwindow.close();

            }
        }
        else
        {
            BackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture BackTexture;
        BackTexture.loadFromFile(BackImage);
        Back.setTexture(&BackTexture);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        Texture FloorTexture;
        FloorImage = "resources/floor-" + to_string(FloorLevel) + ".png";
        FloorTexture.loadFromFile(FloorImage);
        Floor.setTexture(&FloorTexture);

        Texture PlanTexture;
        PLAN_IMAGE = "resources/SSC-" + to_string(FloorLevel) + ".png";
        PlanTexture.loadFromFile(PLAN_IMAGE);
        FLOOR_PLAN.setTexture(&PlanTexture);

        //RENDER DISPLAY
        SSOwindow.clear();

        SSOwindow.draw(skies1);
        SSOwindow.draw(skies2);
        SSOwindow.draw(cloud3);
        SSOwindow.draw(SSO);
        SSOwindow.draw(Right);
        SSOwindow.draw(Left);
        SSOwindow.draw(Floor);
        SSOwindow.draw(Back);
        SSOwindow.draw(FLOOR_PLAN);
        SSOwindow.display();

    }

}

void LOGO_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow LOGOwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    LOGOwindow.setFramerateLimit(30);


    float xPos = w / 2;
    float yPos = h / 2;


    // FRONT GATE
    RectangleShape gate(Vector2f(w, h));
    gate.setPosition(xPos, yPos*1.1);
    Texture gateTexture;
    gateTexture.loadFromFile("resources/frontgate.png");
    gate.setTexture(&gateTexture);
    gate.setOrigin(xPos, yPos);

    // INFO
    RectangleShape Credits(Vector2f(w * 0.7 , h * 0.7));
    Credits.setPosition(w * 0.001, h * 0.01);
    Texture CreditsTexture;
    CreditsTexture.loadFromFile("resources/info.png");
    Credits.setTexture(&CreditsTexture);

    // INFO2
    RectangleShape INFO(Vector2f(w * 0.50, h * 0.25));
    INFO.setPosition(w * 0.105, h * 0.32);
    Texture INFOTexture;
    INFOTexture.loadFromFile("resources/info2.png");
    INFO.setTexture(&INFOTexture);

    // BACK BUTTON
    RectangleShape Back(Vector2f(w * 0.17, h * 0.09));
    Back.setPosition(w * 0.03, h * 0.83);
    string BackImage = "resources/back.png";

    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.3, h * 0.9));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/cloudS-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos, yPos);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, yPos * 0.7);
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(LOGOwindow).x;
    mp.y = Mouse::getPosition(LOGOwindow).y;


    // GAME LOOP
    while (LOGOwindow.isOpen())
    {
        Event ev2;
        Vector2i mp = Mouse::getPosition(LOGOwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));


        //EVENTS
        while (LOGOwindow.pollEvent(ev2))
        {

            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                LOGOwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    LOGOwindow.close();
            Fullscreen:
                break;
            }
            cout << mp.y << "  " << mp.x << endl;
        }
        //BACK
        if (Back.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            BackImage = "resources/back2.png";
            if (Back.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                BackImage = "resources/back3.png";
                MAIN_WINDOW();
                LOGOwindow.close();

            }
        }
        else
        {
            BackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture BackTexture;
        BackTexture.loadFromFile(BackImage);
        Back.setTexture(&BackTexture);

        //RENDER DISPLAY
        LOGOwindow.clear();
        LOGOwindow.draw(skies1);
        LOGOwindow.draw(skies2);
        LOGOwindow.draw(cloud3);
        LOGOwindow.draw(gate);
        LOGOwindow.draw(Back);
        LOGOwindow.draw(Credits);
        LOGOwindow.draw(INFO);
        LOGOwindow.display();

    }


}
void BSU_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow BSUwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    BSUwindow.setFramerateLimit(30);


    float xPos = w / 2;
    float yPos = h / 2;

    // FRONT GATE
    RectangleShape gate(Vector2f(w, h));
    gate.setPosition(xPos, yPos);
    Texture gateTexture;
    gateTexture.loadFromFile("resources/frontgateqrcode.png");
    gate.setTexture(&gateTexture);
    gate.setOrigin(xPos, yPos);

    // BACK BUTTON
    RectangleShape Back(Vector2f(w * 0.17, h * 0.09));
    Back.setPosition(w * 0.03, h * 0.83);
    string BackImage = "resources/back.png";

    // QR
    RectangleShape QR(Vector2f(w * 0.253, h* 0.45));
    QR.setPosition(w * 0.06, h * 0.10);
    Texture QRTexture;
    QRTexture.loadFromFile("resources/QR.png");
    QR.setTexture(&QRTexture);
    
    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.3, h * 0.9));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/cloudS-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos, yPos);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, yPos * 0.7);
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    // MOUSE POSITION
    Vector2f mp;
    mp.x = Mouse::getPosition(BSUwindow).x;
    mp.y = Mouse::getPosition(BSUwindow).y;


    // GAME LOOP
    while (BSUwindow.isOpen())
    {
        Event ev2;
        Vector2i mp = Mouse::getPosition(BSUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));


        //EVENTS
        while (BSUwindow.pollEvent(ev2))
        {

            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                BSUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    BSUwindow.close();
            Fullscreen:
                break;
            }
            cout << mp.y << "  " << mp.x << endl;
        }
        //BACK
        if (Back.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            BackImage = "resources/back2.png";
            if (Back.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                BackImage = "resources/back3.png";
                MAIN_WINDOW();
                BSUwindow.close();

            }
        }
        else
        {
            BackImage = "resources/back.png";
        }

        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture BackTexture;
        BackTexture.loadFromFile(BackImage);
        Back.setTexture(&BackTexture);

        //RENDER DISPLAY
        BSUwindow.clear();

        BSUwindow.draw(skies1);
        BSUwindow.draw(skies2);
        BSUwindow.draw(cloud3);
        BSUwindow.draw(gate);
        BSUwindow.draw(Back);
        BSUwindow.draw(QR);

        BSUwindow.display();

    }


}
void EVENTS_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = VideoMode::getDesktopMode().width;
    int h = VideoMode::getDesktopMode().height;

    RenderWindow EVENTSwindow(VideoMode(w, h), "Spotmap", Style::Fullscreen);
    EVENTSwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    // EVENTS BOARDER
    RectangleShape EventsBoarder(Vector2f(w, h));
    EventsBoarder.setPosition(xPos, yPos);
    EventsBoarder.setOrigin(xPos, yPos);
    string EventsBoarderImage = "resources/Boarder.png";

    // EVENT PAGE
    RectangleShape EventsPage(Vector2f(w * 0.75, h * 0.75));
    EventsPage.setPosition(xPos * 1.39, yPos * 1.19);
    EventsPage.setOrigin(xPos, yPos);
    string EventsPageImage;

        
    // BACK BUTTON
    RectangleShape EventsBack(Vector2f(w * 0.15, h * 0.08));
    EventsBack.setPosition(w * 0.01, h * 0.02);
    EventsBoarder.setOrigin(xPos, yPos);
    string EventsBackImage = "resources/back.png";

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.85, h * 0.45);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.22, h * 0.45);
    std::string LeftImage = "resources/left.png";

    int max_event = 7;
    int chosen_event = 2;
    // GAME LOOP
    while (EVENTSwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(EVENTSwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        int maxFloor = 5;

        //EVENTS
        while (EVENTSwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                EVENTSwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    EVENTSwindow.close();

                // BUTTONS
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";

            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    cout << "Eventswindow; the left button was pressed" << endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;

                //BUTTON SENSOR: RIGHT
                if (Right.getGlobalBounds().contains(mo))
                {
                    if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                    {

                        chosen_event++;
                        if (chosen_event > max_event)
                        {
                            chosen_event = 2;
                        }


                    }
                }
           

                //BUTTON SENSOR: LEFT
                if (Left.getGlobalBounds().contains(mo))
                {
                    
                    if (Left.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                    {
                        chosen_event--;
                        if (chosen_event == 1)
                        {
                            chosen_event = max_event;
                        }
                    }
                }
             
                break;
           
               
            Fullscreen:
                break;
            }
            
        }
        //BUTTON SENSOR: RIGHT
        if (Right.getGlobalBounds().contains(mo) )
        {
          
            RightImage = "resources/right2.png";

            
        }
        else
        {
            RightImage = "resources/right.png";
        }
        //BUTTON SENSOR: LEFT
        if (Left.getGlobalBounds().contains(mo) )
        
        {     LeftImage = "resources/left2.png";

           
        }
        else
        {
            LeftImage = "resources/left.png";
        }

        //BUTTONS HOVERED
        if (EventsBack.getGlobalBounds().contains(mo))
        {
            cout << "you clicked the BACK Button" << endl;
            EventsBackImage = "resources/back2.png";
            if (EventsBack.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                EventsBackImage = "resources/back3.png";
                MAIN_WINDOW();
                EVENTSwindow.close();
            }
        }
        else
        {
            EventsBackImage = "resources/back.png";
        }

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture EventsBoarderTexture;
        EventsBoarderTexture.loadFromFile(EventsBoarderImage);
        EventsBoarder.setTexture(&EventsBoarderTexture);

        Texture EventsBackTexture;
        EventsBackTexture.loadFromFile(EventsBackImage);
        EventsBack.setTexture(&EventsBackTexture);

        Texture EventsPageTexture;
        EventsPageImage = "resources/"+ to_string(chosen_event) + ".jpg";
        EventsPageTexture.loadFromFile(EventsPageImage);
        EventsPage.setTexture(&EventsPageTexture);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        //RENDER DISPLAY
        EVENTSwindow.clear();
        EVENTSwindow.draw(EventsPage);
        EVENTSwindow.draw(EventsBoarder);
        EVENTSwindow.draw(EventsBack);
        EVENTSwindow.draw(Right);
        EVENTSwindow.draw(Left);
        EVENTSwindow.display();

    }
}


void MENU_PAGE_1_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(60);

    float xPos = w / 2;
    float yPos = h / 2;

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.87, h * 0.04);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.16, h * 0.1));
    Left.setPosition(w * 0.02, h * 0.04);
    std::string LeftImage = "resources/back.png";

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");


    //MENU PAGE 1 DECLARATIONS

    //Accounting 
    RectangleShape Accounting(Vector2f(w * 0.4, h * 0.1));
    Accounting.setPosition(w * 0.05, h * 0.21);
    string ACCOUNTING_IMAGE = "resources/-accounting.png";

    //ACCREDITATION
    RectangleShape Acreditation(Vector2f(w * 0.4, h * 0.1));
    Acreditation.setPosition(w * 0.05, h * 0.34);
    string ACREDITATION_IMAGE = "resources/-accreditationroom.png";

    //ACCESS STORAGE
    RectangleShape Access_Storage(Vector2f(w * 0.4, h * 0.1));
    Access_Storage.setPosition(w * 0.05, h * 0.47);
    string ACCESS_STORAGE_IMAGE = "resources/-acesstorageroom.png";

    //AMPHI THEATER
    RectangleShape Amphi_Theater(Vector2f(w * 0.4, h * 0.1));
    Amphi_Theater.setPosition(w * 0.05, h * 0.60);
    string AMPHI_THEATER_IMAGE = "resources/-amphitheater.png";

    //AMPHI THEATER STORAGE
    RectangleShape Amphi_Theater_Storage(Vector2f(w * 0.4, h * 0.1));
    Amphi_Theater_Storage.setPosition(w * 0.05, h * 0.73);
    string AMPHI_THEATER_STORAGE_IMAGE = "resources/-amphitheaterstorageroom.png";

    //AUDIO VISUAL
    RectangleShape Audio_Visual(Vector2f(w * 0.4, h * 0.1));
    Audio_Visual.setPosition(w * 0.05, h * 0.87);
    string AUDIO_VISUAL_IMAGE = "resources/-audiovisualroom.png";

    //CAFAD FACULTY ROOM
    RectangleShape Cafad_Faculty_Room(Vector2f(w * 0.4, h * 0.1));
    Cafad_Faculty_Room.setPosition(w * 0.55, h * 0.21);
    string CAFAD_FACULTY_ROOM_IMAGE = "resources/-cafadfacultyroom.png";

    //CAFETERIA
    RectangleShape Cafeteria(Vector2f(w * 0.4, h * 0.1));
    Cafeteria.setPosition(w * 0.55, h * 0.34);
    string CAFETERIA_IMAGE = "resources/-cafeteria.png";

    //CAFETERIA STORAGE ROOM
    RectangleShape Cafeteria_Storage(Vector2f(w * 0.4, h * 0.1));
    Cafeteria_Storage.setPosition(w * 0.55, h * 0.47);
    string CAFETERIA_STORAGE_IMAGE = "resources/-cafeteriastorageroom.png";

    //CASHIER
    RectangleShape Cashier(Vector2f(w * 0.4, h * 0.1));
    Cashier.setPosition(w * 0.55, h * 0.60);
    string CASHIER_IMAGE = "resources/-cashier.png";

    //CEAFA FACULTY LAUNGE
    RectangleShape Ceafa_Faculty_Launge(Vector2f(w * 0.4, h * 0.1));
    Ceafa_Faculty_Launge.setPosition(w * 0.55, h * 0.73);
    string CEAFA_FACULTY_LAUNGE_IMAGE = "resources/-ceafasfacultylounge.png";

    //CEAFA FACULTY ROOM
    RectangleShape Ceafa_Faculty(Vector2f(w * 0.4, h * 0.1));
    Ceafa_Faculty.setPosition(w * 0.55, h * 0.87);
    string CEAFA_FACULTY_IMAGE = "resources/-cefacultyroom.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
                break;
            Fullscreen:
                break;
            }
            //BUTTON SENSOR: RIGHT
            if (Right.getGlobalBounds().contains(mo))
            {
                RightImage = "resources/right2.png";
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_2_WINDOW();


                }
            }
            else
            {
                RightImage = "resources/right.png";
            }
            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/back2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MAIN_WINDOW();

                }
            }
            else
            {
                LeftImage = "resources/back.png";
            }

        }
        //button 1 ACCOUNTING
        if (Accounting.getGlobalBounds().contains(mo))
        {
            ACCOUNTING_IMAGE = "resources/ssc2.png";
            if (Accounting.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(1);

            }
        }
        else
        {
            ACCOUNTING_IMAGE = "resources/-accounting.png";
        }
        //button 2 ACREDITATION
        if (Acreditation.getGlobalBounds().contains(mo))
        {
            ACREDITATION_IMAGE = "resources/ceafa2.png";
            if (Acreditation.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(2);

            }
        }
        else
        {
            ACREDITATION_IMAGE = "resources/-accreditationroom.png";
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //button 3 ACES STORAGE ROOM
        if (Access_Storage.getGlobalBounds().contains(mo))
        {
            ACCESS_STORAGE_IMAGE = "resources/ceafa2.png";
            if (Access_Storage.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(3);

            }
        }
        else
        {
            ACCESS_STORAGE_IMAGE = "resources/-acesstorageroom.png";
        }

        //button 4 AMPHI THEATER
        if (Amphi_Theater.getGlobalBounds().contains(mo))
        {
            AMPHI_THEATER_IMAGE = "resources/ceafa4.png";
            if (Amphi_Theater.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(4);

            }
        }
        else
        {
            AMPHI_THEATER_IMAGE = "resources/-amphitheater.png";
        }

        //button 5 THEATER STORAGE
        if (Amphi_Theater_Storage.getGlobalBounds().contains(mo))
        {
            AMPHI_THEATER_STORAGE_IMAGE = "resources/ceafa3.png";
            if (Amphi_Theater_Storage.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(5);

            }
        }
        else
        {
            AMPHI_THEATER_STORAGE_IMAGE = "resources/-amphitheaterstorageroom.png";
        }
        //button 6 AUDIO VISUAL ROOM
        if (Audio_Visual.getGlobalBounds().contains(mo))
        {
            AUDIO_VISUAL_IMAGE = "resources/ceafa1.png";
            if (Audio_Visual.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(6);

            }
        }
        else
        {
            AUDIO_VISUAL_IMAGE = "resources/-audiovisualroom.png";
        }
        //button 7  CAFAD FACULTY ROOM

        if (Cafad_Faculty_Room.getGlobalBounds().contains(mo))
        {
            CAFAD_FACULTY_ROOM_IMAGE = "resources/ceafa3.png";
            if (Cafad_Faculty_Room.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(7);

            }
        }
        else
        {
            CAFAD_FACULTY_ROOM_IMAGE = "resources/-cafadfacultyroom.png";
        }

        //button 8  CAFETERIA

        if (Cafeteria.getGlobalBounds().contains(mo))
        {
            CAFETERIA_IMAGE = "resources/ceafa1.png";
            if (Cafeteria.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(8);

            }
        }
        else
        {
            CAFETERIA_IMAGE = "resources/-cafeteria.png";
        }

        //button 9    CAFE STORAGE

        if (Cafeteria_Storage.getGlobalBounds().contains(mo))
        {
            CAFETERIA_STORAGE_IMAGE = "resources/ceafa1.png";
            if (Cafeteria_Storage.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(9);

            }
        }
        else
        {
            CAFETERIA_STORAGE_IMAGE = "resources/-cafeteriastorageroom.png";
        }

        //button 10   CASHIER

        if (Cashier.getGlobalBounds().contains(mo))
        {
            CASHIER_IMAGE = "resources/ssc1.png";
            if (Cashier.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(10);

            }
        }
        else
        {
            CASHIER_IMAGE = "resources/-cashier.png";
        }

        //button 11    CE FACULTY LAUNGE

        if (Ceafa_Faculty_Launge.getGlobalBounds().contains(mo))
        {
            CEAFA_FACULTY_LAUNGE_IMAGE = "resources/ceafa1.png";
            if (Ceafa_Faculty_Launge.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(11);

            }
        }
        else
        {
            CEAFA_FACULTY_LAUNGE_IMAGE = "resources/-ceafasfacultylounge.png";
        }

        //button 12     CAFAD FACULTY

        if (Ceafa_Faculty.getGlobalBounds().contains(mo))
        {
            CEAFA_FACULTY_IMAGE = "resources/ceafa1.png";
            if (Ceafa_Faculty.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(12);

            }
        }
        else
        {
            CEAFA_FACULTY_IMAGE = "resources/-cefacultyroom.png";
        }
        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture ACCOUNTING_TEXTURE;
        ACCOUNTING_TEXTURE.loadFromFile(ACCOUNTING_IMAGE);
        Accounting.setTexture(&ACCOUNTING_TEXTURE);

        Texture ACREDITATION_TEXTURE;
        ACREDITATION_TEXTURE.loadFromFile(ACREDITATION_IMAGE);
        Acreditation.setTexture(&ACREDITATION_TEXTURE);

        Texture ACCESS_STORAGE_TEXTURE;
        ACCESS_STORAGE_TEXTURE.loadFromFile(ACCESS_STORAGE_IMAGE);
        Access_Storage.setTexture(&ACCESS_STORAGE_TEXTURE);

        Texture AMPHI_THEATER_TEXTURE;
        AMPHI_THEATER_TEXTURE.loadFromFile(AMPHI_THEATER_IMAGE);
        Amphi_Theater.setTexture(&AMPHI_THEATER_TEXTURE);

        Texture AMPHI_THEATER_STORAGE_TEXTURE;
        AMPHI_THEATER_STORAGE_TEXTURE.loadFromFile(AMPHI_THEATER_STORAGE_IMAGE);
        Amphi_Theater_Storage.setTexture(&AMPHI_THEATER_STORAGE_TEXTURE);

        Texture AUDIO_VISUAL_TEXTURE;
        AUDIO_VISUAL_TEXTURE.loadFromFile(AUDIO_VISUAL_IMAGE);
        Audio_Visual.setTexture(&AUDIO_VISUAL_TEXTURE);

        Texture CAFAD_FACULTY_TEXTURE;
        CAFAD_FACULTY_TEXTURE.loadFromFile(CAFAD_FACULTY_ROOM_IMAGE);
        Cafad_Faculty_Room.setTexture(&CAFAD_FACULTY_TEXTURE);

        Texture CAFETERIA_TEXTURE;
        CAFETERIA_TEXTURE.loadFromFile(CAFETERIA_IMAGE);
        Cafeteria.setTexture(&CAFETERIA_TEXTURE);

        Texture CAFETERIA_STORAGE_TEXTURE;
        CAFETERIA_STORAGE_TEXTURE.loadFromFile(CAFETERIA_STORAGE_IMAGE);
        Cafeteria_Storage.setTexture(&CAFETERIA_STORAGE_TEXTURE);

        Texture CASHIER_TEXTURE;
        CASHIER_TEXTURE.loadFromFile(CASHIER_IMAGE);
        Cashier.setTexture(&CASHIER_TEXTURE);

        Texture CEAFA_FACULTY_LAUNGE_TEXTURE;
        CEAFA_FACULTY_LAUNGE_TEXTURE.loadFromFile(CEAFA_FACULTY_LAUNGE_IMAGE);
        Ceafa_Faculty_Launge.setTexture(&CEAFA_FACULTY_LAUNGE_TEXTURE);

        Texture CEAFA_FACULTY_TEXTURE;
        CEAFA_FACULTY_TEXTURE.loadFromFile(CEAFA_FACULTY_IMAGE);
        Ceafa_Faculty.setTexture(&CEAFA_FACULTY_TEXTURE);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Right);
        MENUwindow.draw(Accounting);
        MENUwindow.draw(Acreditation);
        MENUwindow.draw(Access_Storage);
        MENUwindow.draw(Amphi_Theater);
        MENUwindow.draw(Amphi_Theater_Storage);
        MENUwindow.draw(Audio_Visual);
        MENUwindow.draw(Cafad_Faculty_Room);
        MENUwindow.draw(Cafeteria_Storage);
        MENUwindow.draw(Cafeteria);
        MENUwindow.draw(Cashier);
        MENUwindow.draw(Ceafa_Faculty_Launge);
        MENUwindow.draw(Ceafa_Faculty);
        MENUwindow.draw(text);
        MENUwindow.display();
    }


}

void MENU_PAGE_2_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(60);

    float xPos = w / 2;
    float yPos = h / 2;

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.87, h * 0.04);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    //MENU PAGE 2 DECLARATIONS

    //CE PARK
    RectangleShape Button1(Vector2f(w * 0.4, h * 0.1));
    Button1.setPosition(w * 0.05, h * 0.21);
    string Button1_IMAGE = "resources/-cepark.png";

    //Chem Engr Lab
    RectangleShape Button2(Vector2f(w * 0.4, h * 0.1));
    Button2.setPosition(w * 0.05, h * 0.34);
    string Button2_IMAGE = "resources/-chemicalengineeringlab.png";

    //Chem Lab
    RectangleShape Button3(Vector2f(w * 0.4, h * 0.1));
    Button3.setPosition(w * 0.05, h * 0.47);
    string Button3_IMAGE = "resources/-chemistrylab.png";

    //Cisco
    RectangleShape Button4(Vector2f(w * 0.4, h * 0.1));
    Button4.setPosition(w * 0.05, h * 0.60);
    string Button4_IMAGE = "resources/-cisco.png";

    //Com Lab
    RectangleShape Button5(Vector2f(w * 0.4, h * 0.1));
    Button5.setPosition(w * 0.05, h * 0.73);
    string Button5_IMAGE = "resources/-computerlab.png";

    //Com Room
    RectangleShape Button6(Vector2f(w * 0.4, h * 0.1));
    Button6.setPosition(w * 0.05, h * 0.87);
    string Button6_IMAGE = "resources/-computerroom.png";

    //Counseling Office
    RectangleShape Button7(Vector2f(w * 0.4, h * 0.1));
    Button7.setPosition(w * 0.55, h * 0.21);
    string Button7_IMAGE = "resources/-counselingoffice.png";

    //COunter
    RectangleShape Button8(Vector2f(w * 0.4, h * 0.1));
    Button8.setPosition(w * 0.55, h * 0.34);
    string Button8_IMAGE = "resources/-counter.png";

    //Deabs Office
    RectangleShape Button9(Vector2f(w * 0.4, h * 0.1));
    Button9.setPosition(w * 0.55, h * 0.47);
    string Button9_IMAGE = "resources/-deansoffice.png";

    //Deans Office
    RectangleShape Button10(Vector2f(w * 0.4, h * 0.1));
    Button10.setPosition(w * 0.55, h * 0.60);
    string Button10_IMAGE = "resources/-deansofficereceivingroom.png";

    //Dental Clinic
    RectangleShape Button11(Vector2f(w * 0.4, h * 0.1));
    Button11.setPosition(w * 0.55, h * 0.73);
    string Button11_IMAGE = "resources/-dentalclinic.png";

    //Doctors Rooom
    RectangleShape Button12(Vector2f(w * 0.4, h * 0.1));
    Button12.setPosition(w * 0.55, h * 0.87);
    string Button12_IMAGE = "resources/-doctorsroom.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }
            //BUTTON SENSOR: RIGHT
            if (Right.getGlobalBounds().contains(mo))
            {
                RightImage = "resources/right2.png";
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_3_WINDOW();


                }
            }
            else
            {
                RightImage = "resources/right.png";
            }
            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/left2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_1_WINDOW();

                }
            }
            else
            {
                LeftImage = "resources/left.png";
            }

            //HOVER DECLARATION

              //button 1  CE PARK
            if (Button1.getGlobalBounds().contains(mo))
            {
                Button1_IMAGE = "resources/ceafa1.png";
                if (Button1.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(13);

                }
            }
            else
            {
                Button1_IMAGE = "resources/-cepark.png";
            }
            //button 2  CHEM eng LAB
            if (Button2.getGlobalBounds().contains(mo))
            {
                Button2_IMAGE = "resources/ceafa1.png";
                if (Button2.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(14);

                }
            }
            else
            {
                Button2_IMAGE = "resources/-chemicalengineeringlab.png";
            }
            //button 3  CHEM LAB
            if (Button3.getGlobalBounds().contains(mo))
            {
                Button3_IMAGE = "resources/ceafa1.png";
                if (Button3.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(15);

                }
            }
            else
            {
                Button3_IMAGE = "resources/chemistrylab.png";
            }

            //button 4   CISCO LAB
            if (Button4.getGlobalBounds().contains(mo))
            {
                Button4_IMAGE = "resources/cit3.png";
                if (Button4.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(16);

                }
            }
            else
            {
                Button4_IMAGE = "resources/-ciscolaboratory.png";
            }

            //button 5      COM LAB
            if (Button5.getGlobalBounds().contains(mo))
            {
                Button5_IMAGE = "resources/ceafa3.png";
                if (Button5.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(17);

                }
            }
            else
            {
                Button5_IMAGE = "resources/-computerlab.png";
            }
            //button 6      COM ROOM
            if (Button6.getGlobalBounds().contains(mo))
            {
                Button6_IMAGE = "resources/ceafa3.png";
                if (Button6.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(18);

                }
            }
            else
            {
                Button6_IMAGE = "resources/-computerroom.png";
            }
            //button 7      COUNSELING OFFICE

            if (Button7.getGlobalBounds().contains(mo))
            {
                Button7_IMAGE = "resources/ssc3.png";
                if (Button7.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(19);

                }
            }
            else
            {
                Button7_IMAGE = "resources/-counselingoffice.png";
            }

            //button 8      COUNTER

            if (Button8.getGlobalBounds().contains(mo))
            {
                Button8_IMAGE = "resources/ceafa1.png";
                if (Button8.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(20);

                }
            }
            else
            {
                Button8_IMAGE = "resources/-counter.png";
            }

            //button 9          DEANS OFFICE

            if (Button9.getGlobalBounds().contains(mo))
            {
                Button9_IMAGE = "resources/ceafa2.png";
                if (Button9.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(21);

                }
            }
            else
            {
                Button9_IMAGE = "resources/-deansoffice.png";
            }

            //button 10 DEANS OFFICE RECEIVING ROOM

            if (Button10.getGlobalBounds().contains(mo))
            {
                Button10_IMAGE = "resources/ceafa2.png";
                if (Button10.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(22);

                }
            }
            else
            {
                Button10_IMAGE = "resources/-deansofficereceivingroom.png";
            }

            //button 11     DENTAL CLINIC

            if (Button11.getGlobalBounds().contains(mo))
            {
                Button11_IMAGE = "resources/ssc1.png";
                if (Button11.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(23);

                }
            }
            else
            {
                Button11_IMAGE = "resources/-dentalclinic.png";
            }

            //button 12   DOCTORS ROOM

            if (Button12.getGlobalBounds().contains(mo))
            {
                Button12_IMAGE = "resources/ssc1.png";
                if (Button12.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(24);

                }
            }
            else
            {
                Button12_IMAGE = "resources/-doctorsroom.png";
            }

        }
        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture Button1_TEXTURE;
        Button1_TEXTURE.loadFromFile(Button1_IMAGE);
        Button1.setTexture(&Button1_TEXTURE);

        Texture Button2_TEXTURE;
        Button2_TEXTURE.loadFromFile(Button2_IMAGE);
        Button2.setTexture(&Button2_TEXTURE);

        Texture Button3_TEXTURE;
        Button3_TEXTURE.loadFromFile(Button3_IMAGE);
        Button3.setTexture(&Button3_TEXTURE);

        Texture Button4_TEXTURE;
        Button4_TEXTURE.loadFromFile(Button4_IMAGE);
        Button4.setTexture(&Button4_TEXTURE);

        Texture Button5_TEXTURE;
        Button5_TEXTURE.loadFromFile(Button5_IMAGE);
        Button5.setTexture(&Button5_TEXTURE);

        Texture Button6_TEXTURE;
        Button6_TEXTURE.loadFromFile(Button6_IMAGE);
        Button6.setTexture(&Button6_TEXTURE);

        Texture Button7_TEXTURE;
        Button7_TEXTURE.loadFromFile(Button7_IMAGE);
        Button7.setTexture(&Button7_TEXTURE);

        Texture Button8_TEXTURE;
        Button8_TEXTURE.loadFromFile(Button8_IMAGE);
        Button8.setTexture(&Button8_TEXTURE);

        Texture Button9_TEXTURE;
        Button9_TEXTURE.loadFromFile(Button9_IMAGE);
        Button9.setTexture(&Button9_TEXTURE);

        Texture Button10_TEXTURE;
        Button10_TEXTURE.loadFromFile(Button10_IMAGE);
        Button10.setTexture(&Button10_TEXTURE);

        Texture Button11_TEXTURE;
        Button11_TEXTURE.loadFromFile(Button11_IMAGE);
        Button11.setTexture(&Button11_TEXTURE);

        Texture Button12_TEXTURE;
        Button12_TEXTURE.loadFromFile(Button12_IMAGE);
        Button12.setTexture(&Button12_TEXTURE);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Right);
        MENUwindow.draw(Button1);
        MENUwindow.draw(Button2);
        MENUwindow.draw(Button3);
        MENUwindow.draw(Button4);
        MENUwindow.draw(Button5);
        MENUwindow.draw(Button6);
        MENUwindow.draw(Button7);
        MENUwindow.draw(Button8);
        MENUwindow.draw(Button9);
        MENUwindow.draw(Button10);
        MENUwindow.draw(Button11);
        MENUwindow.draw(Button12);
        MENUwindow.draw(text);
        MENUwindow.display();
    }

}


void MENU_PAGE_3_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(60);

    float xPos = w / 2;
    float yPos = h / 2;

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.87, h * 0.04);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    //MENU PAGE 2 DECLARATIONS

    //Dormitory
    RectangleShape Button1(Vector2f(w * 0.4, h * 0.1));
    Button1.setPosition(w * 0.05, h * 0.21);
    string Button1_IMAGE = "resources/-dormitory.png";

    //Drafting ROom
    RectangleShape Button2(Vector2f(w * 0.4, h * 0.1));
    Button2.setPosition(w * 0.05, h * 0.34);
    string Button2_IMAGE = "resources/-draftingroom.png";

    //E-Library
    RectangleShape Button3(Vector2f(w * 0.4, h * 0.1));
    Button3.setPosition(w * 0.05, h * 0.47);
    string Button3_IMAGE = "resources/-e-library.png";

    //ENgineering Faculty Room
    RectangleShape Button4(Vector2f(w * 0.4, h * 0.1));
    Button4.setPosition(w * 0.05, h * 0.60);
    string Button4_IMAGE = "resources/-egnnineeringfacultyroom.png";

    //Electrical Engineering Lab
    RectangleShape Button5(Vector2f(w * 0.4, h * 0.1));
    Button5.setPosition(w * 0.05, h * 0.73);
    string Button5_IMAGE = "resources/-electricalengineeringlab.png";
    ////////////////////////////////////////////////////////////////////////////
    //Electronical Technology Shop
    //wala pang button
    RectangleShape Button6(Vector2f(w * 0.4, h * 0.1));
    Button6.setPosition(w * 0.05, h * 0.87);
    string Button6_IMAGE = "resources/-electronicaltechnologyshop.png";
    ////////////////////////////////////////////////////////////////////////////
    //Electronics Shop
    //wala pang button
    RectangleShape Button7(Vector2f(w * 0.4, h * 0.1));
    Button7.setPosition(w * 0.55, h * 0.21);
    string Button7_IMAGE = "resources/-electronicshop.png";

    //Electronic System Lab
    RectangleShape Button8(Vector2f(w * 0.4, h * 0.1));
    Button8.setPosition(w * 0.55, h * 0.34);
    string Button8_IMAGE = "resources/-electronicssystemslab.png";

    //Emergency Treatment Area
    RectangleShape Button9(Vector2f(w * 0.4, h * 0.1));
    Button9.setPosition(w * 0.55, h * 0.47);
    string Button9_IMAGE = "resources/-emergency_treatmentarea.png";

    //Encoding
    RectangleShape Button10(Vector2f(w * 0.4, h * 0.1));
    Button10.setPosition(w * 0.55, h * 0.60);
    string Button10_IMAGE = "resources/-encoding.png";
    /////////////////////////////////////////////////////////////////////////////
    //Engineering Faculty Room
    //wala pang button
    RectangleShape Button11(Vector2f(w * 0.4, h * 0.1));
    Button11.setPosition(w * 0.55, h * 0.73);
    string Button11_IMAGE = "resources/-engineeringfacultyroom.png";

    //Environmental Lab
    RectangleShape Button12(Vector2f(w * 0.4, h * 0.1));
    Button12.setPosition(w * 0.55, h * 0.87);
    string Button12_IMAGE = "resources/-environmentallab.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }
            //BUTTON SENSOR: RIGHT
            if (Right.getGlobalBounds().contains(mo))
            {
                RightImage = "resources/right2.png";
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_4_WINDOW();


                }
            }
            else
            {
                RightImage = "resources/right.png";
            }
            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/left2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_2_WINDOW();

                }
            }
            else
            {
                LeftImage = "resources/left.png";
            }
            //HOVER DECLARATION

               //button 1   DORMITORY
            if (Button1.getGlobalBounds().contains(mo))
            {
                Button1_IMAGE = "resources/ceafa5.png";
                if (Button1.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(13);

                }
            }
            else
            {
                Button1_IMAGE = "resources/-dormitory.png";
            }
            //button 2   DRAFTING ROOM
            if (Button2.getGlobalBounds().contains(mo))
            {
                Button2_IMAGE = "resources/ceafa3.png";
                if (Button2.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(14);

                }
            }
            else
            {
                Button2_IMAGE = "resources/-draftingroom.png";
            }
            //button 3   E-LIBRARY
            if (Button3.getGlobalBounds().contains(mo))
            {
                Button3_IMAGE = "resources/ceafa2.png";
                if (Button3.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(15);

                }
            }
            else
            {
                Button3_IMAGE = "resources/-e-library.png";
            }

            //button 4   ELEC ENGINEERING LAB
            if (Button4.getGlobalBounds().contains(mo))
            {
                Button4_IMAGE = "resources/ceafa3.png";
                if (Button4.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(16);

                }
            }
            else
            {
                Button4_IMAGE = "resources/-electricalengineeringlab.png";
            }

            //button 5          ELECTRONICAL TECHNOLOGY SHOP
            if (Button5.getGlobalBounds().contains(mo))
            {
                Button5_IMAGE = "resources/cit1.png";
                if (Button5.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(17);

                }
            }
            else
            {
                Button5_IMAGE = "resources/-electronicaltechnologyshop.png";
            }
            //button 6          ELECTRICS SHOP
            if (Button6.getGlobalBounds().contains(mo))
            {
                Button6_IMAGE = "resources/cit1.png";
                if (Button6.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(18);

                }
            }
            else
            {
                Button6_IMAGE = "resources/-electronicshop.png";
            }
            //button 7      ELECTRONICS SYSTEM LAB

            if (Button7.getGlobalBounds().contains(mo))
            {
                Button7_IMAGE = "resources/ceafa1.png";
                if (Button7.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(19);

                }
            }
            else
            {
                Button7_IMAGE = "resources/-electronicssystemslab.png";
            }

            //button 8      EMERGENCY TREATMENT AREA

            if (Button8.getGlobalBounds().contains(mo))
            {
                Button8_IMAGE = "resources/ssc1.png";
                if (Button8.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(20);

                }
            }
            else
            {
                Button8_IMAGE = "resources/-emergency_treatmentarea.png";
            }

            //button 9      ENCODING

            if (Button9.getGlobalBounds().contains(mo))
            {
                Button9_IMAGE = "resources/ssc.png";
                if (Button9.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(21);

                }
            }
            else
            {
                Button9_IMAGE = "resources/-encoding.png";
            }

            //button 10         ENGINEERING FACULTY ROOM

            if (Button10.getGlobalBounds().contains(mo))
            {
                Button10_IMAGE = "resources/ceafa2.png";
                if (Button10.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(22);

                }
            }
            else
            {
                Button10_IMAGE = "resources/-engineeringfacultyroom.png";
            }

            //button 11     ENVIRONMENTAL LAB

            if (Button11.getGlobalBounds().contains(mo))
            {
                Button11_IMAGE = "resources/ceafa4.png";
                if (Button11.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(23);

                }
            }
            else
            {
                Button11_IMAGE = "resources/-environmentallab.png";
            }

            //button 12         EXECUTIVE

            if (Button12.getGlobalBounds().contains(mo))
            {
                Button12_IMAGE = "resources/ssc3.png";
                if (Button12.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(24);

                }
            }
            else
            {
                Button12_IMAGE = "resources/-executive.png";
            }

        }
        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture Button1_TEXTURE;
        Button1_TEXTURE.loadFromFile(Button1_IMAGE);
        Button1.setTexture(&Button1_TEXTURE);

        Texture Button2_TEXTURE;
        Button2_TEXTURE.loadFromFile(Button2_IMAGE);
        Button2.setTexture(&Button2_TEXTURE);

        Texture Button3_TEXTURE;
        Button3_TEXTURE.loadFromFile(Button3_IMAGE);
        Button3.setTexture(&Button3_TEXTURE);

        Texture Button4_TEXTURE;
        Button4_TEXTURE.loadFromFile(Button4_IMAGE);
        Button4.setTexture(&Button4_TEXTURE);

        Texture Button5_TEXTURE;
        Button5_TEXTURE.loadFromFile(Button5_IMAGE);
        Button5.setTexture(&Button5_TEXTURE);

        Texture Button6_TEXTURE;
        Button6_TEXTURE.loadFromFile(Button6_IMAGE);
        Button6.setTexture(&Button6_TEXTURE);

        Texture Button7_TEXTURE;
        Button7_TEXTURE.loadFromFile(Button7_IMAGE);
        Button7.setTexture(&Button7_TEXTURE);

        Texture Button8_TEXTURE;
        Button8_TEXTURE.loadFromFile(Button8_IMAGE);
        Button8.setTexture(&Button8_TEXTURE);

        Texture Button9_TEXTURE;
        Button9_TEXTURE.loadFromFile(Button9_IMAGE);
        Button9.setTexture(&Button9_TEXTURE);

        Texture Button10_TEXTURE;
        Button10_TEXTURE.loadFromFile(Button10_IMAGE);
        Button10.setTexture(&Button10_TEXTURE);

        Texture Button11_TEXTURE;
        Button11_TEXTURE.loadFromFile(Button11_IMAGE);
        Button11.setTexture(&Button11_TEXTURE);

        Texture Button12_TEXTURE;
        Button12_TEXTURE.loadFromFile(Button12_IMAGE);
        Button12.setTexture(&Button12_TEXTURE);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Right);
        MENUwindow.draw(Button1);
        MENUwindow.draw(Button2);
        MENUwindow.draw(Button3);
        MENUwindow.draw(Button4);
        MENUwindow.draw(Button5);
        MENUwindow.draw(Button6);
        MENUwindow.draw(Button7);
        MENUwindow.draw(Button8);
        MENUwindow.draw(Button9);
        MENUwindow.draw(Button10);
        MENUwindow.draw(Button11);
        MENUwindow.draw(Button12);
        MENUwindow.draw(text);
        MENUwindow.display();
    }

}


void MENU_PAGE_4_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(60);

    float xPos = w / 2;
    float yPos = h / 2;

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");
    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.87, h * 0.04);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    //MENU PAGE 2 DECLARATIONS
    
    //EXECUTIVE
    RectangleShape Button1(Vector2f(w * 0.4, h * 0.1));
    Button1.setPosition(w * 0.05, h * 0.21);
    string Button1_IMAGE = "resources/-executive.png";

    //Extension Office
    RectangleShape Button2(Vector2f(w * 0.4, h * 0.1));
    Button2.setPosition(w * 0.05, h * 0.34);
    string Button2_IMAGE = "resources/-extensionoffice.png";

    //Faculty Room
    RectangleShape Button3(Vector2f(w * 0.4, h * 0.1));
    Button3.setPosition(w * 0.05, h * 0.47);
    string Button3_IMAGE = "resources/-facultyroom.png";

    //Female Ward
    RectangleShape Button4(Vector2f(w * 0.4, h * 0.1));
    Button4.setPosition(w * 0.05, h * 0.60);
    string Button4_IMAGE = "resources/-femaleward.png";

    //Function Hall
    RectangleShape Button5(Vector2f(w * 0.4, h * 0.1));
    Button5.setPosition(w * 0.05, h * 0.73);
    string Button5_IMAGE = "resources/-functionhall.png";

    //Gallery
    RectangleShape Button6(Vector2f(w * 0.4, h * 0.1));
    Button6.setPosition(w * 0.05, h * 0.87);
    string Button6_IMAGE = "resources/-gallery.png";

    //Guidance
    RectangleShape Button7(Vector2f(w * 0.4, h * 0.1));
    Button7.setPosition(w * 0.55, h * 0.21);
    string Button7_IMAGE = "resources/-guidance.png";

    //Hardware Lab
    //Walang BUtton
    /////////////////////////////////
    RectangleShape Button8(Vector2f(w * 0.4, h * 0.1));
    Button8.setPosition(w * 0.55, h * 0.34);
    string Button8_IMAGE = "resources/-hardwarelab.png";

    //Hydraulics Lab
    RectangleShape Button9(Vector2f(w * 0.4, h * 0.1));
    Button9.setPosition(w * 0.55, h * 0.47);
    string Button9_IMAGE = "resources/-hydraulicslab.png";

    //iacepo
    RectangleShape Button10(Vector2f(w * 0.4, h * 0.1));
    Button10.setPosition(w * 0.55, h * 0.60);
    string Button10_IMAGE = "resources/-iacepo.png";

    //IGP STALL
    RectangleShape Button11(Vector2f(w * 0.4, h * 0.1));
    Button11.setPosition(w * 0.55, h * 0.73);
    string Button11_IMAGE = "resources/-igpstall.png";

    //Industrial Engineering lab
    RectangleShape Button12(Vector2f(w * 0.4, h * 0.1));
    Button12.setPosition(w * 0.55, h * 0.87);
    string Button12_IMAGE = "resources/-industrialengineeringlab.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }
            //BUTTON SENSOR: RIGHT
          //BUTTON SENSOR: RIGHT
            if (Right.getGlobalBounds().contains(mo))
            {
                RightImage = "resources/right2.png";
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_5_WINDOW();


                }
            }
            else
            {
                RightImage = "resources/right.png";
            }
            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/left2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_3_WINDOW();

                }
            }
            else
            {
                LeftImage = "resources/left.png";
            }

        }
        //HOVER DECLARATION

              //button 1
        if (Button1.getGlobalBounds().contains(mo))
        {
            Button1_IMAGE = "resources/ssc1.png";
            if (Button1.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(13);

            }
        }
        else
        {
            Button1_IMAGE = "resources/-executive.png";
        }
        //button 2
        if (Button2.getGlobalBounds().contains(mo))
        {
            Button2_IMAGE = "resources/ceafa1.png";
            if (Button2.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(14);

            }
        }
        else
        {
            Button2_IMAGE = "resources/-extensionoffice.png";
        }
        //button 3
        if (Button3.getGlobalBounds().contains(mo))
        {
            Button3_IMAGE = "resources/cit2.png";
            if (Button3.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(15);

            }
        }
        else
        {
            Button3_IMAGE = "resources/-facultyroom.png";
        }

        //button 4
        if (Button4.getGlobalBounds().contains(mo))
        {
            Button4_IMAGE = "resources/ssc1.png";
            if (Button4.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(16);

            }
        }
        else
        {
            Button4_IMAGE = "resources/-femaleward.png";
        }

        //button 5
        if (Button5.getGlobalBounds().contains(mo))
        {
            Button5_IMAGE = "resources/ssc3.png";
            if (Button5.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(17);

            }
        }
        else
        {
            Button5_IMAGE = "resources/-functionhall.png";
        }
        //button 6
        if (Button6.getGlobalBounds().contains(mo))
        {
            Button6_IMAGE = "resources/ceafa3.png";
            if (Button6.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(18);

            }
        }
        else
        {
            Button6_IMAGE = "resources/-gallery.png";
        }
        //button 7

        if (Button7.getGlobalBounds().contains(mo))
        {
            Button7_IMAGE = "resources/ssc3.png";
            if (Button7.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(19);

            }
        }
        else
        {
            Button7_IMAGE = "resources/-guidance.png";
        }

        //button 8

        if (Button8.getGlobalBounds().contains(mo))
        {
            Button8_IMAGE = "resources/cit3.png";
            if (Button8.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(20);

            }
        }
        else
        {
            Button8_IMAGE = "resources/-hardwarelab.png";
        }

        //button 9

        if (Button9.getGlobalBounds().contains(mo))
        {
            Button9_IMAGE = "resources/aces1.png";
            if (Button9.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(21);

            }
        }
        else
        {
            Button9_IMAGE = "resources/-hydraulicslab.png";
        }

        //button 10

        if (Button10.getGlobalBounds().contains(mo))
        {
            Button10_IMAGE = "resources/ssc2.png";
            if (Button10.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(22);

            }
        }
        else
        {
            Button10_IMAGE = "resources/-iacepo.png";
        }

        //button 11

        if (Button11.getGlobalBounds().contains(mo))
        {
            Button11_IMAGE = "resources/ceafa1.png";
            if (Button11.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(23);

            }
        }
        else
        {
            Button11_IMAGE = "resources/-igpstall.png";
        }

        //button 12

        if (Button12.getGlobalBounds().contains(mo))
        {
            Button12_IMAGE = "resources/ceafa3.png";
            if (Button12.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
            {
                MENUwindow.close();
                BUTTON_WINDOW(24);

            }
        }
        else
        {
            Button12_IMAGE = "resources/-industrialengineeringlab.png";
        }


        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture Button1_TEXTURE;
        Button1_TEXTURE.loadFromFile(Button1_IMAGE);
        Button1.setTexture(&Button1_TEXTURE);

        Texture Button2_TEXTURE;
        Button2_TEXTURE.loadFromFile(Button2_IMAGE);
        Button2.setTexture(&Button2_TEXTURE);

        Texture Button3_TEXTURE;
        Button3_TEXTURE.loadFromFile(Button3_IMAGE);
        Button3.setTexture(&Button3_TEXTURE);

        Texture Button4_TEXTURE;
        Button4_TEXTURE.loadFromFile(Button4_IMAGE);
        Button4.setTexture(&Button4_TEXTURE);

        Texture Button5_TEXTURE;
        Button5_TEXTURE.loadFromFile(Button5_IMAGE);
        Button5.setTexture(&Button5_TEXTURE);

        Texture Button6_TEXTURE;
        Button6_TEXTURE.loadFromFile(Button6_IMAGE);
        Button6.setTexture(&Button6_TEXTURE);

        Texture Button7_TEXTURE;
        Button7_TEXTURE.loadFromFile(Button7_IMAGE);
        Button7.setTexture(&Button7_TEXTURE);

        Texture Button8_TEXTURE;
        Button8_TEXTURE.loadFromFile(Button8_IMAGE);
        Button8.setTexture(&Button8_TEXTURE);

        Texture Button9_TEXTURE;
        Button9_TEXTURE.loadFromFile(Button9_IMAGE);
        Button9.setTexture(&Button9_TEXTURE);

        Texture Button10_TEXTURE;
        Button10_TEXTURE.loadFromFile(Button10_IMAGE);
        Button10.setTexture(&Button10_TEXTURE);

        Texture Button11_TEXTURE;
        Button11_TEXTURE.loadFromFile(Button11_IMAGE);
        Button11.setTexture(&Button11_TEXTURE);

        Texture Button12_TEXTURE;
        Button12_TEXTURE.loadFromFile(Button12_IMAGE);
        Button12.setTexture(&Button12_TEXTURE);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Right);
        MENUwindow.draw(Button1);
        MENUwindow.draw(Button2);
        MENUwindow.draw(Button3);
        MENUwindow.draw(Button4);
        MENUwindow.draw(Button5);
        MENUwindow.draw(Button6);
        MENUwindow.draw(Button7);
        MENUwindow.draw(Button8);
        MENUwindow.draw(Button9);
        MENUwindow.draw(Button10);
        MENUwindow.draw(Button11);
        MENUwindow.draw(Button12);
        MENUwindow.draw(text);
        MENUwindow.display();
    }

}


void MENU_PAGE_5_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");

    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.87, h * 0.04);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    //MENU PAGE 2 DECLARATIONS

    //instrumental lab
    RectangleShape Button1(Vector2f(w * 0.4, h * 0.1));
    Button1.setPosition(w * 0.05, h * 0.21);
    string Button1_IMAGE = "resources/-instrumentallab.png";

    //instrumental control===== NO BUTTON
    RectangleShape Button2(Vector2f(w * 0.4, h * 0.1));
    Button2.setPosition(w * 0.05, h * 0.34);
    string Button2_IMAGE = "resources/-instrumentation&control.png";

    //instrumentation control lab
    RectangleShape Button3(Vector2f(w * 0.4, h * 0.1));
    Button3.setPosition(w * 0.05, h * 0.47);
    string Button3_IMAGE = "resources/-instrumentation_controllab.png";

    //Internet Lab
    RectangleShape Button4(Vector2f(w * 0.4, h * 0.1));
    Button4.setPosition(w * 0.05, h * 0.60);
    string Button4_IMAGE = "resources/-internetlab.png";

    //KITCHEN
    RectangleShape Button5(Vector2f(w * 0.4, h * 0.1));
    Button5.setPosition(w * 0.05, h * 0.73);
    string Button5_IMAGE = "resources/-kitchen.png";

    //Library
    RectangleShape Button6(Vector2f(w * 0.4, h * 0.1));
    Button6.setPosition(w * 0.05, h * 0.87);
    string Button6_IMAGE = "resources/-library.png";

    //maleward
    RectangleShape Button7(Vector2f(w * 0.4, h * 0.1));
    Button7.setPosition(w * 0.55, h * 0.21);
    string Button7_IMAGE = "resources/-maleward.png";

    //Mechanical Engineering lAB
    RectangleShape Button8(Vector2f(w * 0.4, h * 0.1));
    Button8.setPosition(w * 0.55, h * 0.34);
    string Button8_IMAGE = "resources/-mechanicalengineeringlab.png";

    //MECHATRONICS
    RectangleShape Button9(Vector2f(w * 0.4, h * 0.1));
    Button9.setPosition(w * 0.55, h * 0.47);
    string Button9_IMAGE = "resources/-mechatronics_roboticslab.png";

    //-multimedialab2 NO BUTTTTOOOONNN
    RectangleShape Button10(Vector2f(w * 0.4, h * 0.1));
    Button10.setPosition(w * 0.55, h * 0.60);
    string Button10_IMAGE = "resources/-multimedialab.png";

    //-officesstudentaffairs
    RectangleShape Button11(Vector2f(w * 0.4, h * 0.1));
    Button11.setPosition(w * 0.55, h * 0.73);
    string Button11_IMAGE = "resources/-officesstudentaffairs.png";

    //-officestudentsdicipline
    RectangleShape Button12(Vector2f(w * 0.4, h * 0.1));
    Button12.setPosition(w * 0.55, h * 0.87);
    string Button12_IMAGE = "resources/-officestudentsdicipline.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }
            //BUTTON SENSOR: RIGHT
            if (Right.getGlobalBounds().contains(mo))
            {
                RightImage = "resources/right2.png";
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {

                    MENU_PAGE_6_WINDOW();
                    MENUwindow.close();

                }
            }
            else
            {
                RightImage = "resources/right.png";
            }
            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/left2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {

                    MENU_PAGE_4_WINDOW();
                    MENUwindow.close();
                }
            }
            else
            {
                LeftImage = "resources/left.png";
            }
            //HOVER DECLARATION

              //button 1
            if (Button1.getGlobalBounds().contains(mo))
            {
                Button1_IMAGE = "resources/ceafa4.png";
                if (Button1.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(13);

                }
            }
            else
            {
                Button1_IMAGE = "resources/-instrumentallab.png";
            }
            //button 2
            if (Button2.getGlobalBounds().contains(mo))
            {
                Button2_IMAGE = "resources/cit1.png";
                if (Button2.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(14);

                }
            }
            else
            {
                Button2_IMAGE = "resources/-instrumentation_controllab.png";
            }
            //button 3
            if (Button3.getGlobalBounds().contains(mo))
            {
                Button3_IMAGE = "resources/ceafa1.png";
                if (Button3.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(15);

                }
            }
            else
            {
                Button3_IMAGE = "resources/-instrumentationandcontrol.png";
            }

            //button 4
            if (Button4.getGlobalBounds().contains(mo))
            {
                Button4_IMAGE = "resources/ceafa3.png";
                if (Button4.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(16);

                }
            }
            else
            {
                Button4_IMAGE = "resources/-internetlab.png";
            }

            //button 5
            if (Button5.getGlobalBounds().contains(mo))
            {
                Button5_IMAGE = "resources/ceafa1.png";
                if (Button5.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(17);

                }
            }
            else
            {
                Button5_IMAGE = "resources/-kitchen.png";
            }
            //button 6
            if (Button6.getGlobalBounds().contains(mo))
            {
                Button6_IMAGE = "resources/ceafa2.png";
                if (Button6.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(18);

                }
            }
            else
            {
                Button6_IMAGE = "resources/-library.png";
            }
            //button 7

            if (Button7.getGlobalBounds().contains(mo))
            {
                Button7_IMAGE = "resources/ssc1.png";
                if (Button7.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(19);

                }
            }
            else
            {
                Button7_IMAGE = "resources/-maleward.png";
            }

            //button 8

            if (Button8.getGlobalBounds().contains(mo))
            {
                Button8_IMAGE = "resources/ceafa1.png";
                if (Button8.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(20);

                }
            }
            else
            {
                Button8_IMAGE = "resources/-mechanicalengineeringlab.png";
            }

            //button 9

            if (Button9.getGlobalBounds().contains(mo))
            {
                Button9_IMAGE = "resources/ceafa1.png";
                if (Button9.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(21);

                }
            }
            else
            {
                Button9_IMAGE = "resources/-mechatronics_roboticslab.png";
            }

            //button 10

            if (Button10.getGlobalBounds().contains(mo))
            {
                Button10_IMAGE = "resources/cit3.png";
                if (Button10.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(22);

                }
            }
            else
            {
                Button10_IMAGE = "resources/-multimedialaboratory.png";
            }

            //button 11

            if (Button11.getGlobalBounds().contains(mo))
            {
                Button11_IMAGE = "resources/ssc3.png";
                if (Button11.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(23);

                }
            }
            else
            {
                Button11_IMAGE = "resources/-officesstudentaffairs.png";
            }

            //button 12

            if (Button12.getGlobalBounds().contains(mo))
            {
                Button12_IMAGE = "resources/ssc3.png";
                if (Button12.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(24);

                }
            }
            else
            {
                Button12_IMAGE = "resources/-officestudentsdicipline.png";
            }


        }
        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture Button1_TEXTURE;
        Button1_TEXTURE.loadFromFile(Button1_IMAGE);
        Button1.setTexture(&Button1_TEXTURE);

        Texture Button2_TEXTURE;
        Button2_TEXTURE.loadFromFile(Button2_IMAGE);
        Button2.setTexture(&Button2_TEXTURE);

        Texture Button3_TEXTURE;
        Button3_TEXTURE.loadFromFile(Button3_IMAGE);
        Button3.setTexture(&Button3_TEXTURE);

        Texture Button4_TEXTURE;
        Button4_TEXTURE.loadFromFile(Button4_IMAGE);
        Button4.setTexture(&Button4_TEXTURE);

        Texture Button5_TEXTURE;
        Button5_TEXTURE.loadFromFile(Button5_IMAGE);
        Button5.setTexture(&Button5_TEXTURE);

        Texture Button6_TEXTURE;
        Button6_TEXTURE.loadFromFile(Button6_IMAGE);
        Button6.setTexture(&Button6_TEXTURE);

        Texture Button7_TEXTURE;
        Button7_TEXTURE.loadFromFile(Button7_IMAGE);
        Button7.setTexture(&Button7_TEXTURE);

        Texture Button8_TEXTURE;
        Button8_TEXTURE.loadFromFile(Button8_IMAGE);
        Button8.setTexture(&Button8_TEXTURE);

        Texture Button9_TEXTURE;
        Button9_TEXTURE.loadFromFile(Button9_IMAGE);
        Button9.setTexture(&Button9_TEXTURE);

        Texture Button10_TEXTURE;
        Button10_TEXTURE.loadFromFile(Button10_IMAGE);
        Button10.setTexture(&Button10_TEXTURE);

        Texture Button11_TEXTURE;
        Button11_TEXTURE.loadFromFile(Button11_IMAGE);
        Button11.setTexture(&Button11_TEXTURE);

        Texture Button12_TEXTURE;
        Button12_TEXTURE.loadFromFile(Button12_IMAGE);
        Button12.setTexture(&Button12_TEXTURE);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Right);
        MENUwindow.draw(Button1);
        MENUwindow.draw(Button2);
        MENUwindow.draw(Button3);
        MENUwindow.draw(Button4);
        MENUwindow.draw(Button5);
        MENUwindow.draw(Button6);
        MENUwindow.draw(Button7);
        MENUwindow.draw(Button8);
        MENUwindow.draw(Button9);
        MENUwindow.draw(Button10);
        MENUwindow.draw(Button11);
        MENUwindow.draw(Button12);
        MENUwindow.draw(text);
        MENUwindow.display();
    }

}


/*===================================================================================================================================================================================*/
void MENU_PAGE_6_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(60);

    float xPos = w / 2;
    float yPos = h / 2;

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");
    // RIGHT BUTTON
    RectangleShape Right(Vector2f(w * 0.08, h * 0.1));
    Right.setPosition(w * 0.87, h * 0.04);
    std::string RightImage = "resources/right.png";

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    //MENU PAGE 2 DECLARATIONS

    //-physicslab
    RectangleShape Button1(Vector2f(w * 0.4, h * 0.1));
    Button1.setPosition(w * 0.05, h * 0.21);
    string Button1_IMAGE = "resources/-physicslab.png";

    //-planning&developmentcenter
    RectangleShape Button2(Vector2f(w * 0.4, h * 0.1));
    Button2.setPosition(w * 0.05, h * 0.34);
    string Button2_IMAGE = "resources/-planning_developmentcenter.png";

    //-publichelpdesk
    RectangleShape Button3(Vector2f(w * 0.4, h * 0.1));
    Button3.setPosition(w * 0.05, h * 0.47);
    string Button3_IMAGE = "resources/-publichelpdesk.png";

    //-receptionarea
    RectangleShape Button4(Vector2f(w * 0.4, h * 0.1));
    Button4.setPosition(w * 0.05, h * 0.60);
    string Button4_IMAGE = "resources/-receptionarea.png";

    //-registrar
    RectangleShape Button5(Vector2f(w * 0.4, h * 0.1));
    Button5.setPosition(w * 0.05, h * 0.73);
    string Button5_IMAGE = "resources/-registrar.png";

    //-registrarcashier
    RectangleShape Button6(Vector2f(w * 0.4, h * 0.1));
    Button6.setPosition(w * 0.05, h * 0.87);
    string Button6_IMAGE = "resources/-registrarcashier.png";

    //-registraroffice
    RectangleShape Button7(Vector2f(w * 0.4, h * 0.1));
    Button7.setPosition(w * 0.55, h * 0.21);
    string Button7_IMAGE = "resources/-registraroffice.png";

    //-registrarsoffice
    RectangleShape Button8(Vector2f(w * 0.4, h * 0.1));
    Button8.setPosition(w * 0.55, h * 0.34);
    string Button8_IMAGE = "resources/-registrarsoffice.png";

    //--researchoffice
    RectangleShape Button9(Vector2f(w * 0.4, h * 0.1));
    Button9.setPosition(w * 0.55, h * 0.47);
    string Button9_IMAGE = "resources/-researchoffice.png";

    //---reviewcenteroffice
    RectangleShape Button10(Vector2f(w * 0.4, h * 0.1));
    Button10.setPosition(w * 0.55, h * 0.60);
    string Button10_IMAGE = "resources/-reviewcenteroffice.png";

    //--scholarship
    RectangleShape Button11(Vector2f(w * 0.4, h * 0.1));
    Button11.setPosition(w * 0.55, h * 0.73);
    string Button11_IMAGE = "resources/-scholarship.png";

    //--signal&systemslab
    RectangleShape Button12(Vector2f(w * 0.4, h * 0.1));
    Button12.setPosition(w * 0.55, h * 0.87);
    string Button12_IMAGE = "resources/-signal_systemslab.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                RightImage = "resources/right.png";
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }
            //BUTTON SENSOR: RIGHT
            if (Right.getGlobalBounds().contains(mo))
            {
                RightImage = "resources/right2.png";
                if (Right.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_7_WINDOW();


                }
            }
            else
            {
                RightImage = "resources/right.png";
            }
            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/left2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_5_WINDOW();

                }
            }
            else
            {
                LeftImage = "resources/left.png";
            }
            //HOVER DECLARATION

              //button 1
            if (Button1.getGlobalBounds().contains(mo))
            {
                Button1_IMAGE = "resources/cit.png";
                if (Button1.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(13);

                }
            }
            else
            {
                Button1_IMAGE = "resources/-physicslaboratory.png";
            }
            //button 2
            if (Button2.getGlobalBounds().contains(mo))
            {
                Button2_IMAGE = "resources/ceafa1.png";
                if (Button2.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(14);

                }
            }
            else
            {
                Button2_IMAGE = "resources/-planning_developmentcenter.png";
            }
            //button 3
            if (Button3.getGlobalBounds().contains(mo))
            {
                Button3_IMAGE = "resources/ssc1.png";
                if (Button3.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(15);

                }
            }
            else
            {
                Button3_IMAGE = "resources/-publichelpdesk.png";
            }

            //button 4
            if (Button4.getGlobalBounds().contains(mo))
            {
                Button4_IMAGE = "resources/ssc1.png";
                if (Button4.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(16);

                }
            }
            else
            {
                Button4_IMAGE = "resources/-receptionarea.png";
            }

            //button 5
            if (Button5.getGlobalBounds().contains(mo))
            {
                Button5_IMAGE = "resources/ssc1.png";
                if (Button5.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(17);

                }
            }
            else
            {
                Button5_IMAGE = "resources/-registrar.png";
            }
            //button 6
            if (Button6.getGlobalBounds().contains(mo))
            {
                Button6_IMAGE = "resources/ssc2.png";
                if (Button6.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(18);

                }
            }
            else
            {
                Button6_IMAGE = "resources/-registrarcashier.png";
            }
            //button 7

            if (Button7.getGlobalBounds().contains(mo))
            {
                Button7_IMAGE = "resources/ceafa3.png";
                if (Button7.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(19);

                }
            }
            else
            {
                Button7_IMAGE = "resources/-registraroffice.png";
            }

            //button 8

            if (Button8.getGlobalBounds().contains(mo))
            {
                Button8_IMAGE = "resources/ceafa3.png";
                if (Button8.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(20);

                }
            }
            else
            {
                Button8_IMAGE = "resources/-registrarsoffice.png";
            }

            //button 9

            if (Button9.getGlobalBounds().contains(mo))
            {
                Button9_IMAGE = "resources/ceafa1.png";
                if (Button9.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(21);

                }
            }
            else
            {
                Button9_IMAGE = "resources/-researchoffice.png";
            }

            //button 10

            if (Button10.getGlobalBounds().contains(mo))
            {
                Button10_IMAGE = "resources/ceafa1.png";
                if (Button10.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(22);

                }
            }
            else
            {
                Button10_IMAGE = "resources/-reviewcenteroffice.png";
            }

            //button 11

            if (Button11.getGlobalBounds().contains(mo))
            {
                Button11_IMAGE = "resources/ssc2.png";
                if (Button11.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(23);

                }
            }
            else
            {
                Button11_IMAGE = "resources/-scholarship.png";
            }

            //button 12

            if (Button12.getGlobalBounds().contains(mo))
            {
                Button12_IMAGE = "resources/ceafa1.png";
                if (Button12.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(24);

                }
            }
            else
            {
                Button12_IMAGE = "resources/-signal_systemslab.png";
            }


        }
        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture Button1_TEXTURE;
        Button1_TEXTURE.loadFromFile(Button1_IMAGE);
        Button1.setTexture(&Button1_TEXTURE);

        Texture Button2_TEXTURE;
        Button2_TEXTURE.loadFromFile(Button2_IMAGE);
        Button2.setTexture(&Button2_TEXTURE);

        Texture Button3_TEXTURE;
        Button3_TEXTURE.loadFromFile(Button3_IMAGE);
        Button3.setTexture(&Button3_TEXTURE);

        Texture Button4_TEXTURE;
        Button4_TEXTURE.loadFromFile(Button4_IMAGE);
        Button4.setTexture(&Button4_TEXTURE);

        Texture Button5_TEXTURE;
        Button5_TEXTURE.loadFromFile(Button5_IMAGE);
        Button5.setTexture(&Button5_TEXTURE);

        Texture Button6_TEXTURE;
        Button6_TEXTURE.loadFromFile(Button6_IMAGE);
        Button6.setTexture(&Button6_TEXTURE);

        Texture Button7_TEXTURE;
        Button7_TEXTURE.loadFromFile(Button7_IMAGE);
        Button7.setTexture(&Button7_TEXTURE);

        Texture Button8_TEXTURE;
        Button8_TEXTURE.loadFromFile(Button8_IMAGE);
        Button8.setTexture(&Button8_TEXTURE);

        Texture Button9_TEXTURE;
        Button9_TEXTURE.loadFromFile(Button9_IMAGE);
        Button9.setTexture(&Button9_TEXTURE);

        Texture Button10_TEXTURE;
        Button10_TEXTURE.loadFromFile(Button10_IMAGE);
        Button10.setTexture(&Button10_TEXTURE);

        Texture Button11_TEXTURE;
        Button11_TEXTURE.loadFromFile(Button11_IMAGE);
        Button11.setTexture(&Button11_TEXTURE);

        Texture Button12_TEXTURE;
        Button12_TEXTURE.loadFromFile(Button12_IMAGE);
        Button12.setTexture(&Button12_TEXTURE);

        Texture RightTexture;
        RightTexture.loadFromFile(RightImage);
        Right.setTexture(&RightTexture);

        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Right);
        MENUwindow.draw(Button1);
        MENUwindow.draw(Button2);
        MENUwindow.draw(Button3);
        MENUwindow.draw(Button4);
        MENUwindow.draw(Button5);
        MENUwindow.draw(Button6);
        MENUwindow.draw(Button7);
        MENUwindow.draw(Button8);
        MENUwindow.draw(Button9);
        MENUwindow.draw(Button10);
        MENUwindow.draw(Button11);
        MENUwindow.draw(Button12);
        MENUwindow.draw(text);
        MENUwindow.display();
    }

}

/*===================================================================================================================================================================================*/

void MENU_PAGE_7_WINDOW()
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow MENUwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    MENUwindow.setFramerateLimit(60);

    float xPos = w / 2;
    float yPos = h / 2;

    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    Font font;
    if (!font.loadFromFile("resources/LLPIXEL3.ttf"))
    {
        cout << "no font is here!";
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(w * 0.37f, h * 0.08f);
    text.setString("DISCOVER");

    //MENU PAGE 7 DECLARATIONS

    //Smart Wireless Lab
    RectangleShape Button1(Vector2f(w * 0.4, h * 0.1));
    Button1.setPosition(w * 0.30, h * 0.21);
    string Button1_IMAGE = "resources/-smartwirelesslab.png";

    //software Labl===== NO BUTTON  #############################################################################################################################################################
    RectangleShape Button2(Vector2f(w * 0.4, h * 0.1));
    Button2.setPosition(w * 0.30, h * 0.34);
    string Button2_IMAGE = "resources/-softwarelab.png";

    //SOIL/CMT LABRATORY
    RectangleShape Button3(Vector2f(w * 0.4, h * 0.1));
    Button3.setPosition(w * 0.30, h * 0.47);
    string Button3_IMAGE = "resources/-soilcmtlab.png";

    //ssc and other
    RectangleShape Button4(Vector2f(w * 0.4, h * 0.1));
    Button4.setPosition(w * 0.30, h * 0.60);
    string Button4_IMAGE = "resources/-ssc_other.png";

    //Student's Recreation
    RectangleShape Button5(Vector2f(w * 0.4, h * 0.1));
    Button5.setPosition(w * 0.30, h * 0.73);
    string Button5_IMAGE = "resources/-studentsrecreation.png";

    //Water Filling Station
    RectangleShape Button6(Vector2f(w * 0.4, h * 0.1));
    Button6.setPosition(w * 0.30, h * 0.87);
    string Button6_IMAGE = "resources/-waterrefillingstation.png";


    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;


    //GAME LOOP
    while (MENUwindow.isOpen())
    {
        Event ev2;

        Vector2i mp = Mouse::getPosition(MENUwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));



        //EVENTS
        while (MENUwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                MENUwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    MENUwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }


            //BUTTON SENSOR: LEFT
            if (Left.getGlobalBounds().contains(mo))
            {
                LeftImage = "resources/left2.png";
                if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    MENU_PAGE_6_WINDOW();

                }
            }
            else
            {
                LeftImage = "resources/left.png";
            }
            //HOVER DECLARATION

              //button 1
            if (Button1.getGlobalBounds().contains(mo))
            {
                Button1_IMAGE = "resources/ceafa1.png";
                if (Button1.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(13);

                }
            }
            else
            {
                Button1_IMAGE = "resources/-smartwirelesslab.png";
            }
            //button 2
            if (Button2.getGlobalBounds().contains(mo))
            {
                Button2_IMAGE = "resources/cics3.png";
                if (Button2.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(14);

                }
            }
            else
            {
                Button2_IMAGE = "resources/-softwarelaboratory.png";
            }
            //button 3
            if (Button3.getGlobalBounds().contains(mo))
            {
                Button3_IMAGE = "resources/aces1.png";
                if (Button3.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(15);

                }
            }
            else
            {
                Button3_IMAGE = "resources/-soilcmtlab.png";
            }

            //button 4
            if (Button4.getGlobalBounds().contains(mo))
            {
                Button4_IMAGE = "resources/ssc2.png";
                if (Button4.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(16);

                }
            }
            else
            {
                Button4_IMAGE = "resources/-ssc_other.png";
            }

            //button 5
            if (Button5.getGlobalBounds().contains(mo))
            {
                Button5_IMAGE = "resources/ssc2.png";
                if (Button5.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(17);

                }
            }
            else
            {
                Button5_IMAGE = "resources/-studentsrecreation.png";
            }
            //button 6
            if (Button6.getGlobalBounds().contains(mo))
            {
                Button6_IMAGE = "resources/ceafa1.png";
                if (Button6.getGlobalBounds().contains(mo) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MENUwindow.close();
                    BUTTON_WINDOW(18);

                }
            }
            else
            {
                Button6_IMAGE = "resources/-waterrefillingstation.png";
            }

        }
        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD FROM FILE UPDATES
        Texture Button1_TEXTURE;
        Button1_TEXTURE.loadFromFile(Button1_IMAGE);
        Button1.setTexture(&Button1_TEXTURE);

        Texture Button2_TEXTURE;
        Button2_TEXTURE.loadFromFile(Button2_IMAGE);
        Button2.setTexture(&Button2_TEXTURE);

        Texture Button3_TEXTURE;
        Button3_TEXTURE.loadFromFile(Button3_IMAGE);
        Button3.setTexture(&Button3_TEXTURE);

        Texture Button4_TEXTURE;
        Button4_TEXTURE.loadFromFile(Button4_IMAGE);
        Button4.setTexture(&Button4_TEXTURE);

        Texture Button5_TEXTURE;
        Button5_TEXTURE.loadFromFile(Button5_IMAGE);
        Button5.setTexture(&Button5_TEXTURE);

        Texture Button6_TEXTURE;
        Button6_TEXTURE.loadFromFile(Button6_IMAGE);
        Button6.setTexture(&Button6_TEXTURE);



        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);

        MENUwindow.clear();
        MENUwindow.draw(skies1);
        MENUwindow.draw(skies2);
        MENUwindow.draw(Left);
        MENUwindow.draw(Button1);
        MENUwindow.draw(Button2);
        MENUwindow.draw(Button3);
        MENUwindow.draw(Button4);
        MENUwindow.draw(Button5);
        MENUwindow.draw(Button6);
        MENUwindow.draw(text);
        MENUwindow.display();
    }

}




void BUTTON_WINDOW(int x)
{
    // BSU BUTTON WINDOW
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow BUTTONwindow(sf::VideoMode(w, h), "Spotmap", sf::Style::Fullscreen);
    //std::cout << sf::VideoMode::getDesktopMode().width << "," << sf::VideoMode::getDesktopMode().height;
    BUTTONwindow.setFramerateLimit(30);

    float xPos = w / 2;
    float yPos = h / 2;


    // LEFT BUTTON
    RectangleShape Left(Vector2f(w * 0.08, h * 0.1));
    Left.setPosition(w * 0.06, h * 0.04);
    std::string LeftImage = "resources/left.png";

    //MENU PAGE 7 DECLARATIONS

    //Smart Wireless Lab
    RectangleShape Button(Vector2f(w, h));
    Button.setPosition(0, 0);

    RectangleShape Route(Vector2f(w, h));
    Route.setPosition(0, 0);
    

    // SKIES 1
    RectangleShape skies1(Vector2f(w * 1.26, h));
    Texture skies1Texture;
    skies1Texture.loadFromFile("resources/skies-1.png");
    skies1.setTexture(&skies1Texture);
    skies1.setOrigin(xPos * 1.26, yPos);

    // SKIES 2
    RectangleShape skies2(Vector2f(w * 1.26, h));
    Texture skies2Texture;
    skies2Texture.loadFromFile("resources/skies-2.png");
    skies2.setTexture(&skies2Texture);
    skies2.setOrigin(xPos * 1.26, yPos);

    // CLOUD 3
    RectangleShape cloud3(Vector2f(w * 1.5, h * 1.2));
    Texture cloud3Texture;
    cloud3Texture.loadFromFile("resources/clouds-3.png");
    cloud3.setTexture(&cloud3Texture);
    cloud3.setOrigin(xPos * 0.5, yPos * 0.5);

    // MOVING SKIES
    Vector2f skies1Position(xPos, yPos);
    skies1.setPosition(skies1Position);

    Vector2f skies2Position(xPos, yPos);
    skies2.setPosition(skies2Position);

    // MOVING CLOUDS
    Vector2f cloud3Position(0, w * (-0.1));
    cloud3.setPosition(cloud3Position);

    bool skies1direction = false;
    bool skies2direction = true;
    bool cloud3direction = true;

    float skiesmove = 1;
    float cloudmove = 1;
    float skiesmaxMove = 250;
    float c3maxMove = 200;
    float skies1maxPos = xPos + skiesmaxMove;
    float skies1minPos = xPos - skiesmaxMove;
    float skies2maxPos = xPos + skiesmaxMove;
    float skies2minPos = xPos - skiesmaxMove;
    float c3maxPos = xPos + c3maxMove;
    float c3minPos = xPos * 0.5 - c3maxMove;

    //GAME LOOP
    while (BUTTONwindow.isOpen())
    {
        Event ev2;
        Vector2i mp = Mouse::getPosition(BUTTONwindow);
        Vector2f mo(static_cast<float>(mp.x), static_cast<float>(mp.y));

        //EVENTS
        while (BUTTONwindow.pollEvent(ev2))
        {
            switch (ev2.type)
            {
                //CLOSE WINDOW
            case Event::Closed:
                BUTTONwindow.close();
                break;
            case Event::KeyPressed:
                if (ev2.key.code == Keyboard::Escape)
                    BUTTONwindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (Left.getGlobalBounds().contains(mo))
                {
                    LeftImage = "resources/left2.png";
                    if (Left.getGlobalBounds().contains(mo) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {

                        BUTTONwindow.close();
                        MENU_PAGE_1_WINDOW();
                    }
                }
                else
                {
                    LeftImage = "resources/left.png";
                }
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "the left button was pressed" << std::endl;
                }
                cout << "mouse x: " << ev2.mouseButton.x << endl;
                cout << "mouse y: " << ev2.mouseButton.y << endl;
                break;
            case Event::MouseButtonReleased:
                LeftImage = "resources/left.png";
            Fullscreen:
                break;

            }

        }
       


        // MOVING SKIES
        if (skies1Position.x == skies1maxPos) {
            skies1direction = false;
        }

        if (skies1Position.x == skies1minPos) {
            skies1direction = true;
        }

        if (skies1direction == true) {
            skies1Position.x += skiesmove;
        }
        else if (skies1direction == false) {
            skies1Position.x -= skiesmove;

        }
        skies1.setPosition(skies1Position);

        if (skies2Position.x == skies2maxPos) {
            skies2direction = false;
        }

        if (skies2Position.x == skies2minPos) {
            skies2direction = true;
        }

        if (skies2direction == true) {
            skies2Position.x += skiesmove;
        }
        else if (skies2direction == false) {
            skies2Position.x -= skiesmove;

        }
        skies2.setPosition(skies2Position);

        //MOVING CLOUDS
        if (cloud3Position.x == c3maxPos) {
            cloud3direction = false;
        }

        if (cloud3Position.x == c3minPos) {
            cloud3direction = true;
        }

        if (cloud3direction == true) {
            cloud3Position.x += cloudmove;
        }
        else if (cloud3direction == false) {
            cloud3Position.x -= cloudmove;
        }
        cloud3.setPosition(cloud3Position);

        //BUTTON TEXTURES: LOAD From FILE UPDATES
        Texture Button_TEXTURE1, Button_TEXTURE2, Button_TEXTURE3, Button_TEXTURE4, Button_TEXTURE5, Button_TEXTURE6, Button_TEXTURE7, Button_TEXTURE8, Button_TEXTURE9, Button_TEXTURE10, Button_TEXTURE11,
            Button_TEXTURE12, Button_TEXTURE13, Button_TEXTURE14, Button_TEXTURE15, Button_TEXTURE16, Button_TEXTURE17, Button_TEXTURE18, Button_TEXTURE19, Button_TEXTURE20, Button_TEXTURE21, Button_TEXTURE22,
            Button_TEXTURE23, Button_TEXTURE24, Button_TEXTURE25, Button_TEXTURE26, Button_TEXTURE27, Button_TEXTURE28, Button_TEXTURE29, Button_TEXTURE30, Button_TEXTURE31, Button_TEXTURE32, Button_TEXTURE33, Button_TEXTURE34,
            Button_TEXTURE35, Button_TEXTURE36, Button_TEXTURE37, Button_TEXTURE38, Button_TEXTURE39, Button_TEXTURE40, Button_TEXTURE41, Button_TEXTURE42, Button_TEXTURE43, Button_TEXTURE44, Button_TEXTURE45, Button_TEXTURE46,
            Button_TEXTURE47, Button_TEXTURE48, Button_TEXTURE49, Button_TEXTURE50, Button_TEXTURE51, Button_TEXTURE52, Button_TEXTURE53, Button_TEXTURE54, Button_TEXTURE55, Button_TEXTURE56, Button_TEXTURE57, Button_TEXTURE58,
            Button_TEXTURE59, Button_TEXTURE60, Button_TEXTURE61, Button_TEXTURE62, Button_TEXTURE63, Button_TEXTURE64, Button_TEXTURE65, Button_TEXTURE66, Button_TEXTURE67, Button_TEXTURE68, Button_TEXTURE69, Button_TEXTURE70,
            Button_TEXTURE71, Button_TEXTURE72, Button_TEXTURE73, Button_TEXTURE74, Button_TEXTURE75, Button_TEXTURE76, Button_TEXTURE77, Button_TEXTURE78;

        Texture image1, image2, image3, image4, image5, image6, image7, image8, image9, image10,
            image11, image12, image13, image14, image15, image16, image17, image18, image19, image20,
            image21, image22, image23, image24, image25, image26, image27, image28, image29, image30,
            image31, image32, image33, image34, image35, image36, image37, image38, image39, image40,
            image41, image42, image43, image44, image45, image46, image47, image48, image49, image50,
            image51, image52, image53, image54, image55, image56, image57, image58, image59, image60,
            image61, image62, image63, image64, image65, image66, image67, image68, image69, image70,
            image71, image72, image73, image74, image75, image76, image77, image78;



        Button_TEXTURE1.loadFromFile("resources/-accounting2.png"); Button_TEXTURE2.loadFromFile("resources/-accreditationroom2.png"); Button_TEXTURE3.loadFromFile("resources/-acesstorageroom2.png"); Button_TEXTURE4.loadFromFile("resources/-amphitheater2.png"); Button_TEXTURE5.loadFromFile("resources/-amphitheaterstorageroom2.png");
        Button_TEXTURE6.loadFromFile("resources/-audiovisualroom2.png"); Button_TEXTURE7.loadFromFile("resources/-cafadfacultyroom2.png"); Button_TEXTURE8.loadFromFile("resources/-cafeteria2.png"); Button_TEXTURE9.loadFromFile("resources/-cafeteriastorageroom2.png"); Button_TEXTURE10.loadFromFile("resources/-cashier2.png");
        Button_TEXTURE11.loadFromFile("resources/-ceafasfacultylounge2.png"); Button_TEXTURE12.loadFromFile("resources/-cefacultyroom2.png"); Button_TEXTURE13.loadFromFile("resources/-cepark2.png"); Button_TEXTURE14.loadFromFile("resources/-chemicalengineeringlab2.png"); Button_TEXTURE15.loadFromFile("resources/-chemistrylab2.png");
        Button_TEXTURE16.loadFromFile("resources/-cisco2.png"); Button_TEXTURE17.loadFromFile("resources/-computerlab2.png"); Button_TEXTURE18.loadFromFile("resources/-computerroom2.png"); Button_TEXTURE19.loadFromFile("resources/-counselingroom2.png"); Button_TEXTURE20.loadFromFile("resources/-counter2.png");
        Button_TEXTURE21.loadFromFile("resources/-deansoffice2.png"); Button_TEXTURE22.loadFromFile("resources/-deansofficereceivingroom2.png"); Button_TEXTURE23.loadFromFile("resources/-dentalclinic2.png"); Button_TEXTURE24.loadFromFile("resources/-doctorsroom2.png"); Button_TEXTURE25.loadFromFile("resourcess/-dormitory2.png");
        Button_TEXTURE26.loadFromFile("resources/-draftingroom2.png"); Button_TEXTURE27.loadFromFile("resources/-e-library2.png"); Button_TEXTURE28.loadFromFile("resources/-electricalengineeringlab2.png"); Button_TEXTURE29.loadFromFile("resources/-electronicaltechnologyshop2.png"); Button_TEXTURE30.loadFromFile("resources/-electronicshop2.png");
        Button_TEXTURE31.loadFromFile("resources/-electronicssystemslab2.png"); Button_TEXTURE32.loadFromFile("resources/-emergency_treatmentarea2.png"); Button_TEXTURE33.loadFromFile("resources/-encoding2.png"); Button_TEXTURE34.loadFromFile("resources/-engineeringfacultyroom2.png"); Button_TEXTURE35.loadFromFile("resources/-environmentallab2.png");
        Button_TEXTURE36.loadFromFile("resources/-executivedirectorsoffice2.png"); Button_TEXTURE37.loadFromFile("resources/-extensionoffice2.png"); Button_TEXTURE38.loadFromFile("resources/-facultyroom2.png"); Button_TEXTURE39.loadFromFile("resources/-femaleward2.png"); Button_TEXTURE40.loadFromFile("resources/-functionhall2.png");
        Button_TEXTURE41.loadFromFile("resources/-gallery2.png"); Button_TEXTURE42.loadFromFile("resources/-guidanceoffice2.png"); Button_TEXTURE43.loadFromFile("resources/-hardwarelab2.png"); Button_TEXTURE44.loadFromFile("resources/-hydraulicslab2.png"); Button_TEXTURE45.loadFromFile("resources/-iacepo2.png");
        Button_TEXTURE46.loadFromFile("resources/-igpstall2.png"); Button_TEXTURE47.loadFromFile("resources/-industrialengineeringlab2.png"); Button_TEXTURE48.loadFromFile("resources/-instrumentallab2.png"); Button_TEXTURE49.loadFromFile("resources/-instrumentation_control2.png"); Button_TEXTURE50.loadFromFile("resources/-instrumentation&controllab2.png");
        Button_TEXTURE51.loadFromFile("resources/-internetlab2.png"); Button_TEXTURE52.loadFromFile("resources/-kitchen2.png"); Button_TEXTURE53.loadFromFile("resources/-library2.png"); Button_TEXTURE54.loadFromFile("resources/-maleware2.png"); Button_TEXTURE55.loadFromFile("resources/-mechanicalengineeringlab2.png");
        Button_TEXTURE56.loadFromFile("resources/-mechatronics_roboticslab2.png"); Button_TEXTURE57.loadFromFile("resources/-multimedialab2.png"); Button_TEXTURE58.loadFromFile("resources/-officesstudentaffairs2.png"); Button_TEXTURE59.loadFromFile("resources/-officestudentsdiscipline2.png"); Button_TEXTURE60.loadFromFile("resources/-physicslaboratory.png");
        Button_TEXTURE61.loadFromFile("resources/-planning&developmentcenter2.png"); Button_TEXTURE62.loadFromFile("resources/-publichelpdesk2.png"); Button_TEXTURE63.loadFromFile("resources/-receptionarea2.png"); Button_TEXTURE64.loadFromFile("resources/-registrar2.png"); Button_TEXTURE65.loadFromFile("resources/-registrarcashier2.png");
        Button_TEXTURE66.loadFromFile("resources/-registraroffice2.png"); Button_TEXTURE67.loadFromFile("resources/-registrarsoffice2.png"); Button_TEXTURE68.loadFromFile("resources/-researchoffice2.png"); Button_TEXTURE69.loadFromFile("resources/-reviewcenteroffice2.png"); Button_TEXTURE70.loadFromFile("resources/-scholarship2.png");
        Button_TEXTURE71.loadFromFile("resources/-signal&systemslab2.png"); Button_TEXTURE72.loadFromFile("resources/-smartwirelesslab2.png"); Button_TEXTURE73.loadFromFile("resources/softwarelab2.png"); Button_TEXTURE74.loadFromFile("resources/-soil_cmtlab2.png"); Button_TEXTURE75.loadFromFile("resources/-ssc_otherorganizationsoffice2.png");
        Button_TEXTURE76.loadFromFile("resources/-studentsrecreationcenter2.png"); Button_TEXTURE77.loadFromFile("resources/-waterrefillingstation2.png");

        image1.loadFromFile("resources/-accounting22.png");image2.loadFromFile("resources/.png");image3.loadFromFile("resources/.png");image4.loadFromFile("resources/-amphitheater22.png");image5.loadFromFile("resources/.png");image6.loadFromFile("resources/.png");image7.loadFromFile("resources/.png");image8.loadFromFile("resources/.png");image9.loadFromFile("resources/.png");image10.loadFromFile("resources/.png");
      
        image71.loadFromFile("resources/.png");image72.loadFromFile("resources/.png");image73.loadFromFile("resources/-softwarelab22.png");image74.loadFromFile("resources/.png");image75.loadFromFile("resources/.png");image76.loadFromFile("resources/.png");image77.loadFromFile("resources/.png");image78.loadFromFile("resources/.png");
        if (x == 1)
        {
            Button.setTexture(&Button_TEXTURE1);
            Route.setTexture(&image1);
        }
        else if (x == 2)
        {
            Button.setTexture(&Button_TEXTURE2);
            Route.setTexture(&image1);
        }
        else if (x == 3)
        {
            Button.setTexture(&Button_TEXTURE3);
            Route.setTexture(&image1);
        }
        else if (x == 4)
        {
            Button.setTexture(&Button_TEXTURE4);
            Route.setTexture(&image1);
        }
        else if (x == 5)
        {
            Button.setTexture(&Button_TEXTURE5);
            Route.setTexture(&image1);
        }
        else if (x == 6)
        {
            Button.setTexture(&Button_TEXTURE6);
            Route.setTexture(&image1);
        }
        else if (x == 7)
        {
            Button.setTexture(&Button_TEXTURE7);
            Route.setTexture(&image1);
        }
        else if (x == 8)
        {
            Button.setTexture(&Button_TEXTURE8);
            Route.setTexture(&image1);
        }
        else if (x == 9)
        {
            Button.setTexture(&Button_TEXTURE9);
            Route.setTexture(&image1);
        }
        else if (x == 10)
        {
            Button.setTexture(&Button_TEXTURE10);
            Route.setTexture(&image1);
        }
        else if (x == 11)
        {
            Button.setTexture(&Button_TEXTURE11);
            Route.setTexture(&image1);
        }
        else if (x == 12)
        {
            Button.setTexture(&Button_TEXTURE12);
            Route.setTexture(&image1);
        }
        else if (x == 13)
        {
            Button.setTexture(&Button_TEXTURE13);
            Route.setTexture(&image1);
        }
        else if (x == 14)
        {
            Button.setTexture(&Button_TEXTURE14);
            Route.setTexture(&image1);
        }
        else if (x == 15)
        {
            Button.setTexture(&Button_TEXTURE15);
            Route.setTexture(&image1);
        }
        else if (x == 16)
        {
            Button.setTexture(&Button_TEXTURE16);
            Route.setTexture(&image1);
        }
        else if (x == 17)
        {
            Button.setTexture(&Button_TEXTURE17);
            Route.setTexture(&image1);
        }
        else if (x == 18)
        {
            Button.setTexture(&Button_TEXTURE18);
            Route.setTexture(&image1);
        }
        else if (x == 19)
        {
            Button.setTexture(&Button_TEXTURE19);
            Route.setTexture(&image1);
        }
        else if (x == 20)
        {
            Button.setTexture(&Button_TEXTURE20);
            Route.setTexture(&image1);
        }
        else if (x == 21)
        {
            Button.setTexture(&Button_TEXTURE21);
            Route.setTexture(&image1);
        }
        else if (x == 22)
        {
            Button.setTexture(&Button_TEXTURE22);
            Route.setTexture(&image22);
        }
        else if (x == 23)
        {
            Button.setTexture(&Button_TEXTURE23);
            Route.setTexture(&image1);
        }
        else if (x == 24)
        {
            Button.setTexture(&Button_TEXTURE24);
            Route.setTexture(&image1);
        }
        else if (x == 25)
        {
            Button.setTexture(&Button_TEXTURE25);
            Route.setTexture(&image1);
        }
        else if (x == 26)
        {
            Button.setTexture(&Button_TEXTURE26);
            Route.setTexture(&image1);
        }
        else if (x == 27)
        {
            Button.setTexture(&Button_TEXTURE27);
            Route.setTexture(&image1);
        }
        else if (x == 28)
        {
            Button.setTexture(&Button_TEXTURE28);
            Route.setTexture(&image1);
        }
        else if (x == 29)
        {
            Button.setTexture(&Button_TEXTURE29);
            Route.setTexture(&image1);
        }
        else if (x == 30)
        {
            Button.setTexture(&Button_TEXTURE30);
            Route.setTexture(&image1);
        }
        else if (x == 31)
        {
            Button.setTexture(&Button_TEXTURE31);
            Route.setTexture(&image1);
        }
        else if (x == 32)
        {
            Button.setTexture(&Button_TEXTURE32);
            Route.setTexture(&image32);
        }
        else if (x == 33)
        {
            Button.setTexture(&Button_TEXTURE33);
            Route.setTexture(&image33);
        }
        else if (x == 34)
        {
            Button.setTexture(&Button_TEXTURE34);
            Route.setTexture(&image34);
        }
        else if (x == 35)
        {
            Button.setTexture(&Button_TEXTURE35);
            Route.setTexture(&image35);
        }
        else if (x == 36)
        {
            Button.setTexture(&Button_TEXTURE36);
            Route.setTexture(&image36);
        }
        else if (x == 37)
        {
            Button.setTexture(&Button_TEXTURE37);
            Route.setTexture(&image37);
        }
        else if (x == 38)
        {
            Button.setTexture(&Button_TEXTURE38);
            Route.setTexture(&image38);
        }
        else if (x == 39)
        {
            Button.setTexture(&Button_TEXTURE39);
            Route.setTexture(&image39);
        }
        else if (x == 40)
        {
            Button.setTexture(&Button_TEXTURE40);
            Route.setTexture(&image40);
        }
        else if (x == 41)
        {
            Button.setTexture(&Button_TEXTURE41);
            Route.setTexture(&image41);
        }
        else if (x == 42)
        {
            Button.setTexture(&Button_TEXTURE42);
            Route.setTexture(&image42);
        }
        else if (x == 43)
        {
            Button.setTexture(&Button_TEXTURE43);
            Route.setTexture(&image43);
        }
        else if (x == 44)
        {
            Button.setTexture(&Button_TEXTURE44);
            Route.setTexture(&image44);
        }
        else if (x == 45)
        {
            Button.setTexture(&Button_TEXTURE45);
            Route.setTexture(&image45);
        }
        else if (x == 46)
        {
            Button.setTexture(&Button_TEXTURE46);
            Route.setTexture(&image46);
        }
        else if (x == 47)
        {
            Button.setTexture(&Button_TEXTURE47);
            Route.setTexture(&image47);
        }
        else if (x == 48)
        {
            Button.setTexture(&Button_TEXTURE48);
            Route.setTexture(&image48);
        }
        else if (x == 49)
        {
            Button.setTexture(&Button_TEXTURE49);
            Route.setTexture(&image49);
        }
        else if (x == 50)
        {
            Button.setTexture(&Button_TEXTURE50);
            Route.setTexture(&image50);
        }
        else if (x == 51)
        {
            Button.setTexture(&Button_TEXTURE51);
            Route.setTexture(&image51);
        }
        else if (x == 52)
        {
            Button.setTexture(&Button_TEXTURE52);
            Route.setTexture(&image52);
        }
        else if (x == 53)
        {
            Button.setTexture(&Button_TEXTURE53);
            Route.setTexture(&image53);
        }
        else if (x == 54)
        {
            Button.setTexture(&Button_TEXTURE54);
            Route.setTexture(&image54);
        }
        else if (x == 55)
        {
            Button.setTexture(&Button_TEXTURE55);
            Route.setTexture(&image55);
        }
        else if (x == 56)
        {
            Button.setTexture(&Button_TEXTURE56);
            Route.setTexture(&image56);
        }
        else if (x == 57)
        {
            Button.setTexture(&Button_TEXTURE57);
            Route.setTexture(&image57);
        }
        else if (x == 58)
        {
            Button.setTexture(&Button_TEXTURE58);
            Route.setTexture(&image58);
        }
        else if (x == 59)
        {
            Button.setTexture(&Button_TEXTURE59);
            Route.setTexture(&image59);
        }
        else if (x == 60)
        {
            Button.setTexture(&Button_TEXTURE60);
            Route.setTexture(&image60);
        }
        else if (x == 61)
        {
            Button.setTexture(&Button_TEXTURE61);
            Route.setTexture(&image61);
        }
        else if (x == 62)
        {
            Button.setTexture(&Button_TEXTURE62);
            Route.setTexture(&image62);
        }
        else if (x == 63)
        {
            Button.setTexture(&Button_TEXTURE63);
            Route.setTexture(&image63);
        }
        else if (x == 64)
        {
            Button.setTexture(&Button_TEXTURE64);
            Route.setTexture(&image64);
        }
        else if (x == 65)
        {
            Button.setTexture(&Button_TEXTURE65);
            Route.setTexture(&image65);
        }
        else if (x == 66)
        {
            Button.setTexture(&Button_TEXTURE66);
            Route.setTexture(&image66);
        }
        else if (x == 67)
        {
            Button.setTexture(&Button_TEXTURE67);
            Route.setTexture(&image67);
        }
        else if (x == 68)
        {
            Button.setTexture(&Button_TEXTURE68);
            Route.setTexture(&image68);
        }
        else if (x == 69)
        {
            Button.setTexture(&Button_TEXTURE69);
            Route.setTexture(&image69);
        }
        else if (x == 70)
        {
            Button.setTexture(&Button_TEXTURE70);
            Route.setTexture(&image70);
        }
        else if (x == 71)
        {
            Button.setTexture(&Button_TEXTURE71);
            Route.setTexture(&image71);
        }
        else if (x == 72)
        {
            Button.setTexture(&Button_TEXTURE72);
            Route.setTexture(&image72);
        }
        else if (x == 73)
        {
            Button.setTexture(&Button_TEXTURE73);
            Route.setTexture(&image73);
        }
        else if (x == 74)
        {
            Button.setTexture(&Button_TEXTURE74);
            Route.setTexture(&image74);
        }
        else if (x == 75)
        {
            Button.setTexture(&Button_TEXTURE75);
            Route.setTexture(&image75);
        }
        else if (x == 76)
        {
            Button.setTexture(&Button_TEXTURE76);
            Route.setTexture(&image76);
        }
        else if (x == 77)
        {
            Button.setTexture(&Button_TEXTURE77);
            Route.setTexture(&image77);
        }
        else if (x == 78)
        {
            Button.setTexture(&Button_TEXTURE78);
            Route.setTexture(&image78);
        }
        Texture LeftTexture;
        LeftTexture.loadFromFile(LeftImage);
        Left.setTexture(&LeftTexture);


        BUTTONwindow.clear();
        BUTTONwindow.draw(skies1);
        BUTTONwindow.draw(skies2);
        BUTTONwindow.draw(cloud3);
        BUTTONwindow.draw(Button);
        BUTTONwindow.draw(Route);
        BUTTONwindow.draw(Left);
        BUTTONwindow.display();


    }
}



