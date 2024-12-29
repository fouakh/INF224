// main.cpp

#include "Photo.h"
#include "Video.h"

#include <iostream>

int main() {
    // Create an array of Multimedia pointers
    Multimedia** multimedia = new Multimedia*[4]; 

    // Create instances of Photo and Video and store them in the array
    multimedia[0] = new Photo("Vacation Photo", "vacation.jpg", 48.8566, 20.22); 
    multimedia[1] = new Video("Nature Documentary", "nature.mp4", 120); 
    multimedia[2] = new Photo("Beach Sunset", "sunset.jpg", 34.0522, 118.2437); 
    multimedia[3] = new Video("Wildlife Documentary", "wildlife.mp4", 150); 

    // Loop through the array and display attributes or play the media
    for (int i = 0; i < 4; ++i) {
        multimedia[i]->display(std::cout);  // Display the attributes of the multimedia item
        // multimedia[i]->play();  // Play the multimedia item
    }

    // Clean up the memory by deleting the dynamically allocated objects
    for (int i = 0; i < 4; ++i) {
        delete multimedia[i];
    }

    // Delete the array of pointers itself
    delete[] multimedia;

    return 0;
}


