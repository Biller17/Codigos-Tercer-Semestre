/*
 Example from:
 http://stackoverflow.com/questions/22253074/how-to-play-or-open-mp3-or-wav-sound-file-in-c-program
 http://www.sfml-dev.org/
 Install with: sudo apt-get install libsfml-dev
 
 Compile program with:
 g++ sound_test.cpp -o sound_test -std=c++11 -lsfml-audio -lsfml-system -g
 
 
 Alternatively in Windows
 http://www.cplusplus.com/forum/windows/114060/
 */
#include <SFML/Audio.hpp>
#include <iostream>

int play_music(std::string file_name);
int play_sound(std::string file_name);
void user_menu();

int main()
{
    user_menu();
    
    return 0;
}

void user_menu()
{
    char ans = 'a';
    std::string sound_file = "75347__neotone__gun.wav";
    std::string music_file = "264781__dodgy-c__disco-loop-by-dodgy-c.ogg";
    //std::string music_file = "12922_newgrounds_jermai.ogg";
    
    while (ans != 'q')
    {
        std::cout << "\nMenu uptions:" << std::endl;
        std::cout << "\ta. Play sound" << std::endl;
        std::cout << "\tb. Play music" << std::endl;
        std::cout << "\tq. Exit program" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> ans;
        
        if (ans == 'a')
        {
            play_sound(sound_file);
        }
        else if (ans == 'b')
        {
            play_music(music_file);
        }
        else if (ans == 'q')
        {
            std::cout << "Good bye!" << std::endl;
        }
        else
        {
            std::cout << "Invalid option. Try again ..." << std::endl;
        }
        
    }
}

int play_sound(std::string file_name)
{
    static sf::SoundBuffer buffer;
    static sf::Sound sound;
    
    if (!buffer.loadFromFile(file_name))
    {
        std::cout << "Could not open file: " << file_name << std::endl;
        return -1;
    }
    std::cout << "Preparing to play: " << file_name << std::endl;
    sound.setBuffer(buffer);
    std::cout << "Playing sound" << std::endl;
    sound.play();
    
    return 0;
}

int play_music(std::string file_name)
{
    static sf::Music music;
    static sf::Clock clock;
    static sf::Time duration;
    
    if (!music.openFromFile(file_name))
        return -1; // error
    
    duration = music.getDuration();
    std::cout << "Music Duration: " << duration.asSeconds() << std::endl;
    sf::Time elapsed = sf::milliseconds(0);
    std::cout << "Playing music: " << file_name << std::endl;
    music.play();
    /*
     clock.restart();
     while (true)
     {
     if (clock.getElapsedTime() >= duration)
     break;
     }
     std::cout << "Finished!" << std::endl;
     */
    
    return 0;
}
