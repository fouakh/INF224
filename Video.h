// Video.h

#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia {
private:
    int duration;  // Duration of the video in seconds

public:
    Video(const std::string& name = "", const std::string& fileName = "",
          int duration = 0)
        : Multimedia(name, fileName), duration(duration) {}

    // Getter
    int getDuration() const { return duration; }

    // Setter
    void setDuration(int dur) { duration = dur; }

    // Overridden display method
    void display(std::ostream& os) const override {
        Multimedia::display(os); 
        os << "Duration: " << duration << " seconds\n"; 
        std::cout << std::endl; 
    }

    // Method to play the video (using a video player like mpv)
    void play() const override {
        std::string command = "mpv " + getFileName() + " &"; 
        system(command.data());
    }
};

#endif // VIDEO_H
