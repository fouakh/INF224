// Film.h

#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <iostream>

class Film : public Video {
private:
    int* chapterDurations;  // Pointer to dynamically allocated array for chapter durations
    size_t numChapters;     // Number of chapters

public:
    // Constructor
    Film(const std::string& name = "", const std::string& fileName = "", int duration = 0, 
         int* chapters = nullptr, size_t numChapters = 0)
        : Video(name, fileName, duration), chapterDurations(nullptr), numChapters(0) {     
        setChapters(chapters, numChapters); // Use the modifier to handle initialization
    }

    // Destructor
    ~Film() {
        delete[] chapterDurations; 
    }

    // Modifier to set chapter durations
    void setChapters(int* chapters, size_t numChapters) {
        delete[] chapterDurations; 

        this->numChapters = numChapters;
        if (numChapters > 0 && chapters != nullptr) {
            chapterDurations = new int[numChapters];  
            for (size_t i = 0; i < numChapters; ++i) {
                chapterDurations[i] = chapters[i];  
            }
        } else {
            chapterDurations = nullptr;  
        }
    }

    // Accessor to get chapter durations (returns a pointer to a copy)
    int* getChapterDurationsCopy() const {
        if (!chapterDurations) return nullptr; 

        int* copy = new int[numChapters]; 
        for (size_t i = 0; i < numChapters; ++i) {
            copy[i] = chapterDurations[i]; 
        }
        return copy;
    }

    // Accessor to get the number of chapters
    size_t getNumChapters() const {
        return numChapters;
    }

    // Display method to show chapter durations
    void display(std::ostream& os) const override {
        Video::display(os); 
        os << "Chapter Durations: ";
        for (size_t i = 0; i < numChapters; ++i) {
            os << chapterDurations[i] << " "; 
        }
        os << std::endl;
    }
};

#endif // FILM_H
