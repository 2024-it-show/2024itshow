#include <SFML/Graphics.hpp> 
#include <iostream>

using namespace std;
using namespace sf;

int Number = 10; // 주사위 누적값 변수입니다. 24가 넘어가면 24를 빼줘야 해용
int Jheart = 0;
int Hheart = 0;
int Mheart = 0;
int Xheart = 0;


int main()
{

    Font font;
    auto a = font.loadFromFile("설레임.ttf");

    const unsigned int originalWidth = 1280;
    const unsigned int originalHeight = 720;

    RenderWindow app(VideoMode(originalWidth, originalHeight), "game");

    // 여기서부터
    Texture s_back[3]; // 시작배경
    s_back[0].loadFromFile("startB1.png");
    s_back[1].loadFromFile("startB2.png");
    s_back[2].loadFromFile("startB3.png");

    Sprite s_background[3];
    for (int i = 0; i < 3; i++) {
        s_background[i].setTexture(s_back[i]);
        s_background[i].setScale(0.25f, 0.25f);
    }

    bool sB1 = true; bool sB2 = false; bool sB3 = false;

    Texture s_button[3]; // 시작버튼
    s_button[0].loadFromFile("start1.png");
    s_button[1].loadFromFile("button1.png");
    s_button[2].loadFromFile("next1.png");

    Sprite s_nextbutton[3];
    for (int i = 0; i < 3; i++) {
        s_nextbutton[i].setTexture(s_button[i]);
        s_nextbutton[i].setScale(0.25f, 0.25f);
    }
    s_nextbutton[0].setPosition(535, 500);
    s_nextbutton[1].setPosition(950, 560);
    s_nextbutton[2].setPosition(1050, 600);

    Texture s_buttonH[3]; // 시작버튼 호버
    s_buttonH[0].loadFromFile("start2.png");
    s_buttonH[1].loadFromFile("button2.png");
    s_buttonH[2].loadFromFile("next2.png");
    //여까지

    Texture back[20];
    back[0].loadFromFile("game-back.png");
    back[1].loadFromFile("Hch1.png");
    back[2].loadFromFile("Hch1-2.png");
    back[3].loadFromFile("HchB.png");
    back[4].loadFromFile("HchG.png");
    back[5].loadFromFile("Hch2.png");
    back[6].loadFromFile("Mch1.png");
    back[7].loadFromFile("Mch1-2.png");
    back[8].loadFromFile("Mch1B.png");
    back[9].loadFromFile("Mch1G.png");
    back[10].loadFromFile("Mch2.png");
    back[11].loadFromFile("Mch2B.png");
    back[12].loadFromFile("Mch2G.png");
    back[13].loadFromFile("Jch1.png");
    back[14].loadFromFile("JchB.png");
    back[15].loadFromFile("JchG.png");
    back[16].loadFromFile("Jch2.png");
    back[17].loadFromFile("ch(13).png");
    Sprite background[20];
    for (int i = 0; i < 20; i++) {
        background[i].setTexture(back[i]);
        background[i].setScale(0.25f, 0.25f);
    }
    bool Screen1 = false;
    bool Hch1 = false, Hch1_2 = false, HchB = false, HchG = false, Hch2 = false;
    bool Mch1 = false, Mch1_2 = false, Mch1B = false, Mch1G = false, Mch2 = false, Mch2B = false, Mch2G = false;
    bool Jch1 = false, JchG = false, JchB = false, Jch2 = false, Jch = false;
    bool Ch13 = false;
    Texture* block = new Texture[24];
    block[0].loadFromFile("1.png");
    block[1].loadFromFile("2.png");
    block[2].loadFromFile("3.png");
    block[3].loadFromFile("4.png");
    block[4].loadFromFile("5.png");
    block[5].loadFromFile("6.png");
    block[6].loadFromFile("7.png");
    block[7].loadFromFile("8.png");
    block[8].loadFromFile("9.png");
    block[9].loadFromFile("10.png");
    block[10].loadFromFile("11.png");
    block[11].loadFromFile("12.png");
    block[12].loadFromFile("13.png");
    block[13].loadFromFile("14.png");
    block[14].loadFromFile("15.png");
    block[15].loadFromFile("16.png");
    block[16].loadFromFile("17.png");
    block[17].loadFromFile("18.png");
    block[18].loadFromFile("19.png");
    block[19].loadFromFile("20.png");
    block[20].loadFromFile("21.png");
    block[21].loadFromFile("22.png");
    block[22].loadFromFile("23.png");
    block[23].loadFromFile("24.png");

    Sprite* button = new Sprite[24];

    for (int i = 0; i < 24; i++) {
        button[i].setTexture(block[i]);
        button[i].setScale(0.25f, 0.25f);
    }


    button[0].setPosition(958, 571);
    button[7].setPosition(210, 571);
    button[12].setPosition(210, 36);
    button[19].setPosition(958, 36);
    button[13].setPosition(321, 36);
    button[6].setPosition(321, 538);

    for (int i = 0; i < 5; i++) {
        button[1 + i].setPosition(852 - (i * 106), 538);
        button[14 + i].setPosition(428 + (i * 106), 36);
        if (i < 4) {
            button[11 - i].setPosition(210, 147 + (i * 106));
            button[20 + i].setPosition(924, 147 + (i * 106));
        }
    }



    Texture* blockhover = new Texture[24];
    blockhover[0].loadFromFile("1h.png");
    blockhover[1].loadFromFile("2h.png");
    blockhover[2].loadFromFile("3h.png");
    blockhover[3].loadFromFile("4h.png");
    blockhover[4].loadFromFile("5h.png");
    blockhover[5].loadFromFile("6h.png");
    blockhover[6].loadFromFile("7h.png");
    blockhover[7].loadFromFile("8h.png");
    blockhover[8].loadFromFile("9h.png");
    blockhover[9].loadFromFile("10h.png");
    blockhover[10].loadFromFile("11h.png");
    blockhover[11].loadFromFile("12h.png");
    blockhover[12].loadFromFile("13h.png");
    blockhover[13].loadFromFile("14h.png");
    blockhover[14].loadFromFile("15h.png");
    blockhover[15].loadFromFile("16h.png");
    blockhover[16].loadFromFile("17h.png");
    blockhover[17].loadFromFile("18h.png");
    blockhover[18].loadFromFile("19h.png");
    blockhover[19].loadFromFile("20h.png");
    blockhover[20].loadFromFile("21h.png");
    blockhover[21].loadFromFile("22h.png");
    blockhover[22].loadFromFile("23h.png");
    blockhover[23].loadFromFile("24h.png");

    // nextbutton
    Texture next[4];
    next[0].loadFromFile("popupNB.png");
    next[1].loadFromFile("chNB1.png");
    next[2].loadFromFile("chNB2.png");
    Sprite nextbutton[4];
    for (int i = 0; i < 4; i++) {
        nextbutton[i].setTexture(next[i]);
        nextbutton[i].setScale(0.25f, 0.25f);
    }
    nextbutton[0].setPosition(715, 431);
    nextbutton[1].setPosition(1155, 595);
    nextbutton[2].setPosition(1038, 580);
    Texture nextBhover[4];
    nextBhover[0].loadFromFile("popupNBH.png");
    nextBhover[1].loadFromFile("chNBH1.png");
    nextBhover[2].loadFromFile("chNBH2.png");

    // choice button
    Texture choice;
    choice.loadFromFile("chB.png");
    Sprite chbutton[2];
    for (int i = 0; i < 2; i++) {
        chbutton[i].setTexture(choice);
        chbutton[i].setScale(0.25f, 0.25f);
    }
    chbutton[0].setPosition(801, 153);
    chbutton[1].setPosition(801, 382);
    Texture chBhover;
    chBhover.loadFromFile("chBH.png");


    bool isButtonHovered = false;

    Texture speech;
    speech.loadFromFile("chSB.png");
    Sprite chSB;
    chSB.setTexture(speech);
    chSB.setScale(0.25f, 0.25f);
    chSB.setPosition(327, 120);

    // popup
    Texture pop[4];
    pop[0].loadFromFile("pop1.png");
    pop[1].loadFromFile("pop2.png");
    pop[2].loadFromFile("pop3.png");
    pop[3].loadFromFile("pop4.png");
    Sprite PopUp[4];
    for (int i = 0; i < 4; i++) {
        PopUp[i].setTexture(pop[i]);
        PopUp[i].setScale(0.25f, 0.25f);
        PopUp[i].setPosition(396, 206);
    }

    bool popup1 = false, popup2 = false, popup3 = false, popup4 = false;

    Texture popBack;
    popBack.loadFromFile("pop-back.png");
    Sprite PopUpBack;
    PopUpBack.setTexture(popBack);
    PopUpBack.setScale(0.25f, 0.25f);


    //text
    Text text1, text2;
    text1.setFont(font);
    text2.setFont(font);
    text1.setString(L"안녕하세요");
    text2.setString(L"안녕하세요");
    text1.setCharacterSize(120);
    text2.setCharacterSize(120);
    text1.setScale(0.25f, 0.25f);
    text2.setScale(0.25f, 0.25f);
    text1.setFillColor(sf::Color(67, 64, 64));
    text2.setFillColor(sf::Color(67, 64, 64));
    bool chText = false;

    Text chSBText;
    chSBText.setFont(font);
    chSBText.setString(L"안녕하세요");
    chSBText.setCharacterSize(144);
    chSBText.setScale(0.25f, 0.25f);
    chSBText.setFillColor(sf::Color(67, 64, 64));
    bool chSBTEXT = false;

    // Ch13
    Texture choice13[3];
    choice13[0].loadFromFile("ch13H.png");
    choice13[1].loadFromFile("ch13M.png");
    choice13[2].loadFromFile("ch13J.png");
    Sprite chB13[3];
    for (int i = 0; i < 3; i++) {
        chB13[i].setTexture(choice13[i]);
        chB13[i].setScale(0.25f, 0.25f);
    }
    chB13[0].setPosition(516.57, 218);
    chB13[1].setPosition(832.14, 218);
    chB13[2].setPosition(201, 218);
    Texture chB13hover[3];
    chB13hover[0].loadFromFile("ch13HBh.png");
    chB13hover[1].loadFromFile("ch13MBh.png");
    chB13hover[2].loadFromFile("ch13JBh.png");
    bool Ch13B = false, Ch13HMJ[3] = { false };

    // Click // 지수민소리 여기서 setPosition만 해주면 되는데 칸마다 다르게 해줘야 해
    // 그니까 Number 두고 switch나 if로 2부터 24까지(for문X) 조건 줘서 피그마 보고 x,y 따와서 세팅하면 돼용 
    Texture click[4];
    click[0].loadFromFile("click2~7.png");
    click[1].loadFromFile("click8~13.png");
    click[2].loadFromFile("click14~19.png");
    click[3].loadFromFile("click20~24.png");
    Sprite Click[4];
    for (int i = 0; i < 4; i++) {
        Click[i].setTexture(click[i]);
        Click[i].setScale(0.25f, 0.25f);
    }

    // 재현 호감도
    Text JheartS;
    JheartS.setFont(font);
    JheartS.setCharacterSize(112);
    JheartS.setScale(0.25f, 0.25f);
    JheartS.setFillColor(sf::Color(255, 120, 135));
    JheartS.setPosition(130, 253);
    char buffer1[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함
    // 한솔 호감도
    Text HheartS;
    HheartS.setFont(font);
    HheartS.setCharacterSize(112);
    HheartS.setScale(0.25f, 0.25f);
    HheartS.setFillColor(sf::Color(103, 156, 68));
    HheartS.setPosition(1162, 253);
    char buffer2[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함
    // 민재 호감도
    Text MheartS;
    MheartS.setFont(font);
    MheartS.setCharacterSize(112);
    MheartS.setScale(0.25f, 0.25f);
    MheartS.setFillColor(sf::Color(13, 85, 109));
    MheartS.setPosition(130, 550);
    char buffer3[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함
    // X 호감도
    Text XheartS;
    XheartS.setFont(font);
    XheartS.setCharacterSize(112);
    XheartS.setScale(0.25f, 0.25f);
    XheartS.setFillColor(sf::Color(65, 58, 57));
    XheartS.setPosition(1162, 550);
    char buffer4[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함

    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            else if (event.type == sf::Event::Resized)
            {
                float aspectRatio = static_cast<float>(originalWidth) / originalHeight;
                unsigned int newHeight = event.size.height;
                unsigned int newWidth = static_cast<unsigned int>(newHeight * aspectRatio);
                app.setSize(sf::Vector2u(newWidth, newHeight));
                sf::Vector2u windowSize = app.getSize();
                sf::Vector2i newPosition((static_cast<int>(sf::VideoMode::getDesktopMode().width) - static_cast<int>(windowSize.x)) / 2, 0); // 화면의 상단 좌표를 사용하여 Y 좌표를 0으로 설정
                app.setPosition(newPosition);
            }

            Vector2f mousePos = app.mapPixelToCoords(Mouse::getPosition(app));

            for (int i = 0; i < 3; i++) {
                if (s_nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    s_nextbutton[i].setTexture(s_buttonH[i]);
                }
                else {
                    s_nextbutton[i].setTexture(s_button[i]);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (s_nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 0 && sB1) {
                            sB1 = false;
                            sB2 = true;
                        }
                        else if (i == 1 && sB2) {
                            sB2 = false;
                            sB3 = true;
                        }
                        else if (i == 2 && sB3) {
                            sB3 = false;
                            Screen1 = true;
                        }
                    }
                }
            }

            for (int i = 0; i < 24; i++) {
                if (button[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    button[i].setTexture(blockhover[i]);
                }
                else {
                    button[i].setTexture(block[i]);
                }



                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (button[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 3 && Screen1) {
                            Screen1 = false;
                            Hch1 = true;
                        }
                        else if (i == 8 && Screen1) {
                            Screen1 = false;
                            Mch1 = true;
                        }
                        else if (i == 11 && Screen1) {
                            Screen1 = false;
                            Hch2 = true;
                            text1.setString(L"전 카라멜 팝콘 좋아해요");
                            text1.setPosition(862, 225);
                            text2.setString(L"전 민트초코 팝콘 좋아해요");
                            text2.setPosition(848, 452);
                        }
                        else if (i == 14 && Screen1) {
                            Screen1 = false;
                            Jch1 = true;
                            text1.setString(L"가는데 10분 정도 걸리니까\n지금 나가야겠네요");
                            text1.setPosition(845, 206);
                            text2.setString(L"에이 천천히 가도 괜찮아요");
                            text2.setPosition(848, 452);
                        }
                        else if (i == 18 && Screen1) {
                            Screen1 = false;
                            Mch2 = true;
                            text1.setString(L"(장난스럽게) 하하\n이래서 그만두셨구나");
                            text1.setPosition(882, 206);
                            text2.setString(L"그래도 잘하시네요\n역시 선수 출신!");
                            text2.setPosition(896, 433);
                        }
                        else if (i == 20 && Screen1) {
                            Jch2 = true;
                            Screen1 = false;
                            text1.setString(L"아뇨, 이제 씻어야죠");
                            text1.setPosition(888, 226);
                            text2.setString(L"에이 괜찮아요~\n어차피 장갑 낄 건데요");
                            text2.setPosition(875, 432);
                        }
                        else if (i == 12 && Screen1) {
                            Ch13 = true;
                        }
                        else if (i == 7 && Screen1) {
                            popup1 = true;
                            Hheart -= 10;
                            Jheart -= 10;
                            Mheart -= 10;
                        }
                        else if (i == 15 && Screen1) {
                            popup2 = true;
                            Hheart += 15;
                            Jheart += 15;
                            Mheart += 15;
                        }
                        else if (i == 19 && Screen1) {
                            popup3 = true;
                            Xheart += 20;
                        }
                        else if (i == 23 && Screen1) {
                            popup4 = true;
                            Hheart -= 15;
                            Jheart -= 15;
                            Mheart -= 15;
                        }
                    }
                }

            }

            for (int i = 0; i < 4; i++) {
                if (nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    nextbutton[i].setTexture(nextBhover[i]);
                }
                else {
                    nextbutton[i].setTexture(next[i]);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 1 && Hch1) {
                            Hch1 = false;
                            Hch1_2 = true;
                            text1.setString(L"이거 재미없나봐요\n저희 다른 거 볼까요? ");
                            text1.setPosition(880, 206);
                            text2.setString(L"그래도 이미 예매했는데\n그냥 볼까요? ");
                            text2.setPosition(865, 433);
                        }
                        else if (i == 1 && Mch1) {
                            Mch1 = false;
                            Mch1_2 = true;
                            text1.setString(L"김치가 다 떨어졌나요?\n하하 농담~");
                            text1.setPosition(870, 206);
                            text2.setString(L"혹시 주문이\n잘못 들어갔나요?");
                            text2.setPosition(901, 433);
                        }
                        else if (i == 2 && (HchB || HchG || Mch1G || Mch1B || Mch2G || Mch2B || JchB || JchG || Ch13)) {
                            HchB = false, HchG = false;
                            Mch1G = false, Mch1B = false, Mch2G = false, Mch2B = false;
                            JchB = false, JchG = false;
                            Ch13 = false; chSBTEXT = false;
                            Screen1 = true;
                        }
                        else if (i == 0 && Screen1) {
                            popup1 = false;
                            popup2 = false;
                            popup3 = false;
                            popup4 = false;
                        }
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                if (chbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    chbutton[i].setTexture(chBhover);
                }
                else {
                    chbutton[i].setTexture(choice);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (chbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 0 && (Hch1_2 || Hch2)) {
                            if (Hch2) {
                                chSBText.setString(L"전 카라멜은\n     별로...");
                                chSBText.setPosition(397, 192);
                            }
                            if (Hch1_2) {
                                chSBText.setString(L"( 아.. 줏대가 없네 )");
                                chSBText.setPosition(343, 213.99);
                            }
                            Hheart -= 20;
                            chText = false;
                            Hch1_2 = false;
                            Hch2 = false;
                            HchB = true;
                        }
                        else if (i == 1 && (Hch1_2 || Hch2)) {
                            if (Hch2) {
                                chSBText.setString(L"저도 민초\n좋아해요!");
                                chSBText.setPosition(412, 192);
                            }
                            if (Hch1_2) {
                                chSBText.setString(L"\t\t좋아요!\n(줏대있다!멋져)");
                                chSBText.setPosition(370, 193);
                            }
                            Hheart += 20;
                            chText = false;
                            Hch1_2 = false;
                            Hch2 = false;
                            HchG = true;
                        }
                        if (i == 0 && (Mch1_2 || Mch2)) {
                            if (Mch1_2) {
                                chSBText.setString(L"  ( 저게 무슨\n말버릇이람..)");
                                chSBText.setPosition(379, 187.99);
                                Mch1B = true;
                            }
                            else if (Mch2) {
                                chSBText.setString(L"\t부상 때문에\n잘 안되네요 ㅎㅎ;");
                                chSBText.setPosition(360, 187.99);
                                Mch2B = true;
                            }
                            Mheart -= 20;
                            chText = false;
                            Mch1_2 = false;
                            Mch2 = false;
                        }
                        else if (i == 1 && (Mch1_2 || Mch2)) {
                            if (Mch1_2) {
                                chSBText.setString(L"( 아주 예의가\n   바르구만 )");
                                chSBText.setPosition(386, 187.99);
                                Mch1G = true;
                            }
                            else if (Mch2) {
                                chSBText.setString(L"하하 아녜요\n  고마워요");
                                chSBText.setPosition(397, 187.99);
                                Mch2G = true;
                            }
                            Mheart += 20;
                            chText = false;
                            Mch1_2 = false;
                            Mch2 = false;
                        }
                        if (i == 0 && (Jch1 || Jch)) {
                            if (Jch1) {
                                chSBText.setString(L"   아... 되게\n칼같으시네요");
                                chSBText.setPosition(385, 187.99);
                            }
                            else if (Jch) {
                                chSBText.setString(L"( 왜 저렇게\n깔끔떨지 ? )");
                                chSBText.setPosition(395, 191);
                            }
                            Jheart -= 20;
                            chText = false;
                            Jch1 = false;
                            Jch2 = false;
                            JchB = true;
                            Jch = false;
                        }
                        else if (i == 1 && (Jch1 || Jch)) {
                            if (Jch1) {
                                chSBText.setString(L"( 여유롭네\n  멋있어!)");
                                chSBText.setPosition(406, 193);
                            }
                            else if (Jch) {
                                chSBText.setString(L"( 털털한 성격\n\t  좋다!)");
                                chSBText.setPosition(386, 198);
                            }
                            Jheart += 20;
                            chText = false;
                            Jch1 = false;
                            Jch2 = false;
                            JchG = true;
                            Jch = false;
                        }
                    }
                }
            }
            for (int i = 0; i < 3; i++) {

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (chB13[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        Ch13B = true;
                        for (int j = 0; j < 3; j++) {
                            if (i == j) {
                                chB13[j].setTexture(chB13hover[j]);
                                Ch13HMJ[j] = true;
                            }
                            else {
                                chB13[j].setTexture(choice13[j]);
                                Ch13HMJ[j] = false;
                            }
                        }
                    }
                    if (!Ch13B) chB13[i].setTexture(choice13[i]);
                }
            }
        }

        std::snprintf(buffer1, sizeof(buffer1), "%3d", Jheart);
        JheartS.setString(buffer1);
        std::snprintf(buffer2, sizeof(buffer2), "%3d", Hheart);
        HheartS.setString(buffer2);
        std::snprintf(buffer3, sizeof(buffer3), "%3d", Mheart);
        MheartS.setString(buffer3);
        std::snprintf(buffer4, sizeof(buffer4), "%3d", Xheart);
        XheartS.setString(buffer4);

        if (sB1) {
            app.draw(s_background[0]);
            app.draw(s_nextbutton[0]);
        }

        if (Screen1) {
            app.draw(background[0]);
            for (int i = 23; i >= 0; i--) {
                if (i == 20) continue;
                app.draw(button[i]);
            }
            app.draw(button[20]);
            for (int i = 0; i < 3; i++) Ch13HMJ[i] = false;
            Ch13B = false;
            app.draw(JheartS);
            app.draw(HheartS);
            app.draw(MheartS);
            app.draw(XheartS);
        }

        // 주사위 Click 이미지
        if (Screen1) {
            switch (Number) {
                // click2~7
            case 2:
                Click[0].setPosition(867, 457);
                app.draw(Click[0]);
                break;
            case 3:
                Click[0].setPosition(761, 457);
                app.draw(Click[0]);
                break;
            case 4:
                Click[0].setPosition(655, 457);
                app.draw(Click[0]);
                break;
            case 5:
                Click[0].setPosition(549, 457);
                app.draw(Click[0]);
                break;
            case 6:
                Click[0].setPosition(443, 457);
                app.draw(Click[0]);
                break;
            case 7:
                Click[0].setPosition(337, 457);
                app.draw(Click[0]);
                break;
                // click8~13
            case 8:
                Click[1].setPosition(395, 582);
                app.draw(Click[1]);
                break;
            case 9:
                Click[1].setPosition(344, 474);
                app.draw(Click[1]);
                break;
            case 10:
                Click[1].setPosition(344, 368);
                app.draw(Click[1]);
                break;
            case 11:
                Click[1].setPosition(344, 262);
                app.draw(Click[1]);
                break;
            case 12:
                Click[1].setPosition(344, 156);
                app.draw(Click[1]);
                break;
            case 13:
                Click[1].setPosition(395, 54);
                app.draw(Click[1]);
                break;
                // click14~19
            case 14:
                Click[2].setPosition(867, 160);
                app.draw(Click[2]);
                break;
            case 15:
                Click[2].setPosition(761, 160);
                app.draw(Click[2]);
                break;
            case 16:
                Click[2].setPosition(655, 160);
                app.draw(Click[2]);
                break;
            case 17:
                Click[2].setPosition(549, 160);
                app.draw(Click[2]);
                break;
            case 18:
                Click[2].setPosition(443, 160);
                app.draw(Click[2]);
                break;
            case 19:
                Click[2].setPosition(337, 160);
                app.draw(Click[2]);
                break;
                // click20~24
            case 20:
                Click[3].setPosition(886, 54);
                app.draw(Click[3]);
                break;
            case 21:
                Click[3].setPosition(834, 156);
                app.draw(Click[3]);
                break;
            case 22:
                Click[3].setPosition(834, 262);
                app.draw(Click[3]);
                break;
            case 23:
                Click[3].setPosition(834, 368);
                app.draw(Click[3]);
                break;
            case 24:
                Click[3].setPosition(834, 474);
                app.draw(Click[3]);
                break;
            }
        }

        //sB
        if (sB2) {

            app.draw(s_background[1]);
            app.draw(s_nextbutton[1]);
        }
        if (sB3) {
            app.draw(s_background[2]);
            app.draw(s_nextbutton[2]);
        }

        //Hch
        if (Hch1) {
            app.draw(background[1]);
        }
        else if (Hch2) {
            chText = true;
            app.draw(background[5]);
        }
        else if (Hch1_2) {
            chText = true;
            app.draw(background[2]);
        }
        else if (HchB) {
            app.draw(background[3]);
        }
        else if (HchG) {
            app.draw(background[4]);
        }

        //Mch
        if (Mch1) {
            app.draw(background[6]);
        }
        else if (Mch2) {
            chText = true;
            app.draw(background[10]);
        }
        else if (Mch1_2) {
            chText = true;
            app.draw(background[7]);
        }
        else if (Mch1B) {
            app.draw(background[8]);
        }
        else if (Mch1G) {
            app.draw(background[9]);
        }
        else if (Mch2G) {
            app.draw(background[12]);
        }
        else if (Mch2B) {
            app.draw(background[11]);
        }

        //Jch
        if (Jch1) {
            app.draw(background[13]);
            chText = true;
        }
        else if (Jch2) {
            app.draw(background[16]);
            chText = true;
            Jch = true;
        }
        else if (JchB) {
            app.draw(background[14]);
        }
        else if (JchG) {
            app.draw(background[15]);

        }

        // Ch13
        if (Ch13) {
            Screen1 = false;
            app.draw(background[17]);
            for (int i = 0; i < 3; i++)   app.draw(chB13[i]);
        }
        if (Screen1) {
            if (Ch13HMJ[0]) {
                // 한솔 호감도 상승
            }
            else if (Ch13HMJ[1]) {
                // 민재 호감도 상승
            }
            else if (Ch13HMJ[2]) {
                // 재현 호감도 상승
            }
        }


        if (Hch1 || Mch1) {
            app.draw(nextbutton[1]);
        }
        if (Hch1_2 || Hch2 || Mch1_2 || Mch2 || Jch1 || Jch2) {
            app.draw(chbutton[0]);
            app.draw(chbutton[1]);
        }
        if (HchB || HchG || Mch1B || Mch1G || Mch2B || Mch2G || JchB || JchG) {
            app.draw(nextbutton[2]);
            app.draw(chSB);
            chSBTEXT = true;
        }
        if (Ch13 && Ch13B) {
            app.draw(nextbutton[2]);
        }

        if (popup1 || popup2 || popup3 || popup4) {
            app.draw(PopUpBack);
            if (popup1) {
                app.draw(PopUp[0]);
            }
            else if (popup2) {
                app.draw(PopUp[1]);
            }
            else if (popup3) {
                app.draw(PopUp[2]);
            }
            else if (popup4) {
                app.draw(PopUp[3]);
            }
            app.draw(nextbutton[0]);
        }

        if (chText) {
            app.draw(text1);
            app.draw(text2);
        }
        if (chSBTEXT) {
            app.draw(chSBText);
        }
        app.display();
    }

    delete[] block;
    delete[] blockhover;
    delete[] button;

    return 0;

}