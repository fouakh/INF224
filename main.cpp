// main.cpp

#include "Photo.h"
#include "Video.h"
#include "Film.h"

#include <iostream>

int main() {
    // Create an array of Multimedia pointers
    Multimedia** multimedia = new Multimedia*[3];

    // Create instances of Photo, Video, and Film
    multimedia[0] = new Photo("Vacation Photo", "vacation.jpg", 48.8566, 20.22);
    multimedia[1] = new Video("Nature Documentary", "nature.mp4", 120);

    // Dynamic chapter durations for the Film object
    int chapters[] = {15, 25, 30, 20};
    multimedia[2] = new Film("Adventure Film", "adventure.mp4", 90, chapters, 4);

    // Loop through the array and display attributes or play the media
    for (int i = 0; i < 3; ++i) {
        multimedia[i]->display(std::cout); 
        std::cout << std::endl;
    }

    // Modify and reuse the Film object to test dynamic memory management
    Film* film = dynamic_cast<Film*>(multimedia[2]); 
    if (film) {
        int newChapters[] = {35, 55};
        film->setChapters(newChapters, 2); // Modify the chapters
        std::cout << "After modifying chapters:\n";
        film->display(std::cout);
   
        // Get a copy of the chapter durations
        int* chapterDurationsCopy = film->getChapterDurationsCopy();
        size_t numChapters = film->getNumChapters();

        // Modify the copied array
        chapterDurationsCopy[0] = 99; // Change the first chapter duration

        // Display the modified copy
        std::cout << "Modified Chapter Durations (copy only): ";
        for (size_t i = 0; i < numChapters; ++i) {
            std::cout << chapterDurationsCopy[i] << " ";
        }
        std::cout << std::endl;

        // Get another copy and verify the Film instance's internal array is unchanged
        int* chapterDurationsCopyAgain = film->getChapterDurationsCopy();

        std::cout << "Original Chapter Durations (after modification): ";
        for (size_t i = 0; i < numChapters; ++i) {
            std::cout << chapterDurationsCopyAgain[i] << " ";
        }
        std::cout << std::endl;

        // Clean up the copied arrays
        delete[] chapterDurationsCopy;
        delete[] chapterDurationsCopyAgain;
    }

    for (int i = 0; i < 3; ++i) {
        delete multimedia[i];
    }

    delete[] multimedia;

    return 0;
}



