#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1280, 720), "My window", Style::Titlebar | Style::Close); // ȭ��ũ�⸦ �������� ���ϵ��� ��(�ʿ������ ���� ��!)

    // �ؽ�ó ���� �� �̹��� ���� �ε�
    // ����ȭ�� ���
    Texture ima1;
    if (!ima1.loadFromFile("C:/C++����/Project1/Project1/iMac - 2.png")) // �̹��� ��� �Է�
        return EXIT_FAILURE;

    // start ��ư �̹���
    Texture ima2;
    if (!ima2.loadFromFile("C:/C++����/Project1/Project1/Group 13.png"))
        return EXIT_FAILURE;

    // ���� ���� ���
    Texture ima3;
    if (!ima3.loadFromFile("C:/C++����/Project1/Project1/iMac - 20.png"))
        return EXIT_FAILURE;

    // ���� ���� ���� ��ư
    Texture ima4;
    if (!ima4.loadFromFile("C:/C++����/Project1/Project1/Group 132.png"))
        return EXIT_FAILURE;

    // �ڱ�Ұ�
    Texture ima5;
    if (!ima5.loadFromFile("C:/C++����/Project1/Project1/iMac - 74.png"))
        return EXIT_FAILURE;

    // �ڱ�Ұ� ������ư
    Texture ima6;
    if (!ima6.loadFromFile("C:/C++����/Project1/Project1/button1.png"))
        return EXIT_FAILURE;

    // ����
    Texture ima7;
    if (!ima7.loadFromFile("C:/C++����/Project1/Project1/iMac - 4 (2).png"))
        return EXIT_FAILURE;

    // ��������Ʈ ���� �� �ؽ�ó ����
    Sprite sprite1;
    sprite1.setTexture(ima1);

    Sprite sprite2(ima2); // ���� �� �ؽ�ó ���� ���ÿ�
    Sprite sprite3(ima3);
    Sprite sprite4(ima4);
    Sprite sprite5(ima5);
    Sprite sprite6(ima6);
    Sprite sprite7(ima7);

    // ������ �ʴ� ��������Ʈ ���� ����
    bool sp1 = false;
    bool sp2 = false;
    bool sp3 = false;


    // ��������Ʈ2�� ��������Ʈ1 ���� ��ġ
    sprite2.setPosition(sprite1.getPosition());
    sprite4.setPosition(sprite3.getPosition());
    sprite6.setPosition(sprite5.getPosition());

    // ��������Ʈ ��ġ ����
    sprite2.setPosition(500, 520);
    sprite4.setPosition(950, 560);
    sprite6.setPosition(1050, 600);
    
    // ��������Ʈ ũ�� ���̱�
    sprite1.setScale(0.25f, 0.25f);
    sprite2.setScale(0.25f, 0.25f);
    sprite3.setScale(0.25f, 0.25f);
    sprite4.setScale(0.25f, 0.25f);
    sprite5.setScale(0.25f, 0.25f);
    sprite6.setScale(0.25f, 0.25f);

    // ��������Ʈ�� ũ�⸦ �������� ũ�⿡ �°� ����
    Vector2u windowSize = window.getSize();
    sprite1.setScale((float)windowSize.x / ima1.getSize().x, (float)windowSize.y / ima1.getSize().y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)    // ����
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
        window.draw(sprite1); // ��������Ʈ �׸���
        window.draw(sprite2);
        if (sp1 == true)
        {
            window.draw(sprite3); // sprite3�� sprite1,2 ���� �׷���
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
