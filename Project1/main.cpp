#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1280, 720), "My window", Style::Titlebar | Style::Close); // 화면크기를 변경하지 못하도록 함(필요없으면 지울 것!)

    // 텍스처 생성 및 이미지 파일 로드
    // 시작화면 배경
    Texture ima1;
    if (!ima1.loadFromFile("C:/C++연습/Project1/Project1/iMac - 2.png")) // 이미지 경로 입력
        return EXIT_FAILURE;

    // start 버튼 이미지
    Texture ima2;
    if (!ima2.loadFromFile("C:/C++연습/Project1/Project1/Group 13.png"))
        return EXIT_FAILURE;

    // 게임 설명 배경
    Texture ima3;
    if (!ima3.loadFromFile("C:/C++연습/Project1/Project1/iMac - 20.png"))
        return EXIT_FAILURE;

    // 게임 설명 다음 버튼
    Texture ima4;
    if (!ima4.loadFromFile("C:/C++연습/Project1/Project1/Group 132.png"))
        return EXIT_FAILURE;

    // 자기소개
    Texture ima5;
    if (!ima5.loadFromFile("C:/C++연습/Project1/Project1/iMac - 74.png"))
        return EXIT_FAILURE;

    // 자기소개 다음버튼
    Texture ima6;
    if (!ima6.loadFromFile("C:/C++연습/Project1/Project1/button1.png"))
        return EXIT_FAILURE;

    // 보드
    Texture ima7;
    if (!ima7.loadFromFile("C:/C++연습/Project1/Project1/iMac - 4 (2).png"))
        return EXIT_FAILURE;

    // 스프라이트 생성 및 텍스처 설정
    Sprite sprite1;
    sprite1.setTexture(ima1);

    Sprite sprite2(ima2); // 생성 및 텍스처 설정 동시에
    Sprite sprite3(ima3);
    Sprite sprite4(ima4);
    Sprite sprite5(ima5);
    Sprite sprite6(ima6);
    Sprite sprite7(ima7);

    // 보이지 않는 스프라이트 눌림 방지
    bool sp1 = false;
    bool sp2 = false;
    bool sp3 = false;


    // 스프라이트2를 스프라이트1 위에 배치
    sprite2.setPosition(sprite1.getPosition());
    sprite4.setPosition(sprite3.getPosition());
    sprite6.setPosition(sprite5.getPosition());

    // 스프라이트 위치 설정
    sprite2.setPosition(500, 520);
    sprite4.setPosition(950, 560);
    sprite6.setPosition(1050, 600);
    
    // 스프라이트 크기 줄이기
    sprite1.setScale(0.25f, 0.25f);
    sprite2.setScale(0.25f, 0.25f);
    sprite3.setScale(0.25f, 0.25f);
    sprite4.setScale(0.25f, 0.25f);
    sprite5.setScale(0.25f, 0.25f);
    sprite6.setScale(0.25f, 0.25f);

    // 스프라이트의 크기를 윈도우의 크기에 맞게 조정
    Vector2u windowSize = window.getSize();
    sprite1.setScale((float)windowSize.x / ima1.getSize().x, (float)windowSize.y / ima1.getSize().y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)    // 종료
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (sprite2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                    {
                        sp1 = true;
                    }
                    if (sp1 == true) {
                        if (sprite4.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                        {
                            sp2 = true;
                        }
                    }
                    if (sp2 == true) {
                        if (sprite6.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                        {
                            sp3 = true;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(sprite1); // 스프라이트 그리기
        window.draw(sprite2);
        if (sp1 == true)
        {
            window.draw(sprite3); // sprite3는 sprite1,2 위에 그려짐
            window.draw(sprite4);
        }
        if (sp2 == true)
        {
            window.draw(sprite5);
            window.draw(sprite6);
        }
        if (sp3 == true)
        {
            window.draw(sprite7);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}
