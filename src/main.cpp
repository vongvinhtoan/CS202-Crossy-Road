#include <iostream>
#include <Application.hpp>

int main() 
{
    try
    {
        Application &application = Application::getInstance();
        application.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}