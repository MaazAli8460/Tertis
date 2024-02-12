
For windows user follow the steps below


To install and link SFML (Simple and Fast Multimedia Library) in Visual Studio, follow these steps:

    Download SFML: Go to the SFML website and download the appropriate version of SFML for your operating system and compiler. Make sure to choose the version that matches your Visual Studio version and compiler (usually VS 2017 or VS 2019).

    Extract SFML: Once downloaded, extract the contents of the SFML zip file to a location on your computer. Remember this location as you'll need it later.

    Create a new Visual Studio project: Open Visual Studio and create a new C++ project.

    Configure Visual Studio project settings:
        Right-click on your project in the Solution Explorer and select "Properties".
        Go to "Configuration Properties" > "C/C++" > "General".
        Add the path to SFML's include directory to "Additional Include Directories". This directory should contain the SFML header files.
        Go to "Configuration Properties" > "Linker" > "General".
        Add the path to SFML's lib directory to "Additional Library Directories". This directory should contain the SFML library files.
        Go to "Configuration Properties" > "Linker" > "Input".
        Add the names of the SFML libraries you want to link to in "Additional Dependencies". For example, if you're using SFML's graphics and window modules, you would add sfml-graphics.lib, sfml-window.lib, etc.

    Copy DLL files: SFML requires DLL files to run. Copy the necessary DLL files from the SFML bin directory to your project's output directory (where your .exe file will be generated). These DLL files should include sfml-graphics-2.dll, sfml-window-2.dll, etc.

    Write your code: Now you can start writing your code using SFML.

    Build and Run: Build your project in Visual Studio and run it. It should compile and link with SFML successfully.

    Test: Write a simple SFML program to test whether everything is set up correctly. For example, create a window using SFML's sf::RenderWindow class and display it.

Remember to adjust the paths and settings based on your specific setup and version of Visual Studio and SFML. If you encounter any issues, double-check your configurations and ensure that you've correctly copied the necessary DLL files.


For Ubuntu users Type the commands below for sfml instalation
sudo apt-get install libsfml-dev

Commands for compiling and running the sfml code
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./sfml-app


