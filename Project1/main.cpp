#include <SFML/Graphics.hpp>
using namespace sf;

void mouseHover(sf::RenderWindow& window, sf::Sprite& sprite1, sf::Sprite& sprite2, sf::Texture& texture1, sf::Texture& texture2)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (sprite1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
    {
        // ���콺�� sprite1 ���� ���� �� sprite1�� sprite2�� ����
        sprite1.setTexture(texture2);
    }
    else
    {
        // ���콺�� sprite1 ���� ���� ���� �� sprite1�� ���� �̹����� ����
        sprite1.setTexture(texture1);
    }
}

int main()
{
    RenderWindow window(VideoMode(1280, 720), "My window"); // ȭ��ũ�⸦ �������� ���ϵ��� ��(�ʿ������ ���� ��!)

    // �ؽ�ó ���� �� �̹��� ���� �ε�
    // ����ȭ�� ���
    Texture ima1;
    if (!ima1.loadFromFile("C:/C++����/Project1/Project1/iMac - 2.png")) // �̹��� ��� �Է�
        return EXIT_FAILURE;

    // start ��ư �̹���
    Texture ima2;
    if (!ima2.loadFromFile("C:/C++����/Project1/Project1/start1.png"))
        return EXIT_FAILURE;

    Texture ima3;
    if (!ima3.loadFromFile("C:/C++����/Project1/Project1/start2.png"))
        return EXIT_FAILURE;

    // ���� ���� ���
    Texture ima4;
    if (!ima4.loadFromFile("C:/C++����/Project1/Project1/iMac - 20.png"))
        return EXIT_FAILURE;

    // ���� ���� ���� ��ư
    Texture ima5;
    if (!ima5.loadFromFile("C:/C++����/Project1/Project1/button1.png"))
        return EXIT_FAILURE;

    // ���� ���� ȣ�� ��ư
    Texture ima6;
    if (!ima6.loadFromFile("C:/C++����/Project1/Project1/button2.png"))
        return EXIT_FAILURE;

    // �ڱ�Ұ�
    Texture ima7;
    if (!ima7.loadFromFile("C:/C++����/Project1/Project1/iMac - 74.png"))
        return EXIT_FAILURE;

    // �ڱ�Ұ� ������ư
    Texture ima8;
    if (!ima8.loadFromFile("C:/C++����/Project1/Project1/next1.png"))
        return EXIT_FAILURE;

    // �ڱ�Ұ� ������ư ȣ��
    Texture ima9;
    if (!ima9.loadFromFile("C:/C++����/Project1/Project1/next2.png"))
        return EXIT_FAILURE;

    // ����
    Texture ima10;
    if (!ima10.loadFromFile("C:/C++����/Project1/Project1/iMac - 4 (2).png"))
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
    Sprite sprite8(ima8);
    Sprite sprite9(ima9);
    Sprite sprite10(ima10);

    // ������ �ʴ� ��������Ʈ ���� ����
    bool sp1 = false;
    bool sp2 = false;
    bool sp3 = false;


    // ��������Ʈ2�� ��������Ʈ1 ���� ��ġ
    sprite2.setPosition(sprite1.getPosition());
    sprite5.setPosition(sprite4.getPosition());
    sprite8.setPosition(sprite7.getPosition());

    // ��������Ʈ ��ġ ����
    sprite2.setPosition(535, 500);
    sprite5.setPosition(950, 560);
    sprite8.setPosition(1050, 600);
    
    // ��������Ʈ ũ�� ���̱�
    sprite1.setScale(0.25f, 0.25f);
    sprite2.setScale(0.25f, 0.25f);
    sprite3.setScale(0.25f, 0.25f);
    sprite4.setScale(0.25f, 0.25f);
    sprite5.setScale(0.25f, 0.25f);
    sprite6.setScale(0.25f, 0.25f);
    sprite7.setScale(0.25f, 0.25f);
    sprite8.setScale(0.25f, 0.25f);
    sprite9.setScale(0.25f, 0.25f);

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
                        if (sprite5.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                        {
                            sp2 = true;
                        }
                    }
                    if (sp2 == true) {
                        if (sprite8.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                        {
                            sp3 = true;
                        }
                    }
                }
            }
        }

        mouseHover(window, sprite2, sprite3, ima2, ima3);
        mouseHover(window, sprite5, sprite6, ima5, ima6);
        mouseHover(window, sprite8, sprite9, ima8, ima9);

        window.clear();
        window.draw(sprite1); // ��������Ʈ �׸���
        window.draw(sprite2);
        if (sp1 == true)
        {
            window.draw(sprite4); // sprite3�� sprite1,2 ���� �׷���
            window.draw(sprite5);
        }
        if (sp2 == true)
        {
            window.draw(sprite7);
            window.draw(sprite8);
        }
        if (sp3 == true)
        {
            window.draw(sprite10);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}