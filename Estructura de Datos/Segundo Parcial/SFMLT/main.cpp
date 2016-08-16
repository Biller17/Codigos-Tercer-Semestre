//Modified for Estructura de datos homework
//Adrián Biller A01018940
//Written in Xcode
//HW 6  October 13


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
#include <DoubleLinkedList.h>
#include <string.h>
#include <cstring>
#include <fstream>

int play_music(std::string file_name);
//int pause_music();
void user_menu();
//int play_sound(std::string file_name);


int main()
{
    user_menu();
    return 0;
}

void readTxt()
{

    return 0;
}

void user_menu()
{
    DoubleLinkedList<std::string> list;
    int i = 0;
    std::string line;
    std::ifstream file ("songs.txt");
    
    if (file.is_open())
    {
        while(getline(file, line) && i<6)
        {
            list.insertOrdered(line);
        }
        file.close();
    }
    std::cout<<"List of songs:"<<std::endl;
    std::cout<<"1. Across the Universe - The Beatles"<<std::endl;
    std::cout<<"2. Collide             - Breathe Carolina"<<std::endl;
    std::cout<<"3. East Harlem         - Beirut"<<std::endl;
    std::cout<<"4. Lucy In The Sky With Diamonds- The Beatles"<<std::endl;
    std::cout<<"5. Pay No Mind         - Madeon"<<std::endl;
    std::cout<<"6. Whoa Whoa Whoa      - Watsky"<<std::endl;
    std::string temp;
    char ans = 'a';
    int num;
    while (ans != 'q')
    {
        std::cout<<"Menu options:" << std::endl;
        std::cout<<"    a. Play" << std::endl;
        std::cout<<"    b. Next"<<std::endl;
        std::cout<<"    c. Previous song"<<std::endl;
        std::cout<<"    d. Choose a song"<<std::endl;
        std::cout<<"    q. Exit program" << std::endl;
        std::cout<<"Choose an option: ";
        std::cin>> ans;
        
        if (ans == 'a')
        {
            ans = play_music(list.getItemAt(i)->getData());
        }
        if(ans == 'b')
        {
            play_music(list.getItemAt(i)->getNext()->getData());
            i++;
        }
        if(ans == 'c')
        {
            play_music(list.getItemAt(i)->getPrevious()->getData());
            i--;
        }
        if(ans == 'd')
        {
            std::cout<<"Type the number of the song you wish to hear"<<std::endl;
            std::cin>>num;
            play_music(list.getItemAt(num-1)->getData());
        }
        if (ans == 'q')
        {
            std::cout << "Good bye!" << std::endl;
        }
        else
        {
            std::cout << "Invalid option. Try again ..." << std::endl;
        }
        
    }
}



int play_music(std::string file_name)
{
    char ans;
    static sf::Music music;
    static sf::Clock clock;
    static sf::Time duration;
    double adv = 5;
    
    if (!music.openFromFile(file_name))
        return -1; // error
    
    duration = music.getDuration();
    std::cout << "Music Duration: " << duration.asSeconds() << std::endl;
    sf::Time elapsed = sf::milliseconds(0);
    std::cout << "Playing music: " << file_name << std::endl;
    music.play();
    
     clock.restart();
    std::cout<<"    a. Play/Replay"<<std::endl;
    std::cout<<"    b. Next" << std::endl;
    std::cout<<"    c. Pause"<<std::endl;
    std::cout<<"    d. Stop song" << std::endl;
    std::cout<<"    e. Forward 5 seconds"<<std::endl;
     while (true)
     {
         std::cin>>ans;
         if(ans == 'a')
             music.play();
         if(ans  == 'b')
         {
             music.stop();
             return ans;
         }
         if(ans == 'c')
             music.pause();
         if(ans == 'd')
         {
             music.stop();
             return 1;
         }
         if(ans == 'e')
             music.setPlayingOffset(music.getPlayingOffset()+sf::seconds(5));
         if (clock.getElapsedTime() >= duration)
             break;
     }
     std::cout << "Finished!" << std::endl;
     
    
    return 0;
}

