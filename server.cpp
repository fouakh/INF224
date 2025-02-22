#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <functional>

#include "tcpserver.h"
#include "MediaManager.h"

const int PORT = 3331; // Define the port number for the server

int main(int argc, char* argv[]) {
    MediaManager manager; // Create an instance of MediaManager to handle media operations

    // Creating multimedia objects
    auto photo1 = manager.createPhoto("Beach Vacation", "beach_vacation.jpg", 200.00, 500.00);
    auto video1 = manager.createVideo("Nature Documentary", "nature_doc.mp4", 25);
    int chapters[] = {120, 55, 105, 40};
    auto film1 = manager.createFilm("The Lord of the Rings", "lotr.mkv", 320, chapters, 4);

    // Creating groups
    auto photoGroup = manager.createGroup("Photos");
    auto vacationGroup = manager.createGroup("Vacations");

    // Adding objects to groups
    photoGroup->push_back(photo1);
    vacationGroup->push_back(photo1);
    vacationGroup->push_back(video1);
    vacationGroup->push_back(film1);

    // Define a map to associate commands with their corresponding lambdas
    std::map<std::string, std::function<std::string(const std::string&)>> commands;

    // Add commands to the map
    commands["search"] = [&manager](const std::string& name) -> std::string {
        std::string response = manager.displayMultimedia(name);
        if (response.find("Error") != std::string::npos) {
            response = manager.displayGroup(name);
        }
        return response;
    };

    commands["play"] = [&manager](const std::string& name) -> std::string {
        return manager.playMultimedia(name);
    };

    commands["delete"] = [&manager](const std::string& name) -> std::string {
        manager.deleteMultimedia(name);
        return "Deleted: " + name;
    };

    commands["displaygroup"] = [&manager](const std::string& groupName) -> std::string {
        return manager.displayGroup(groupName); // Call the existing displayGroup function
    };

    // Create the TCPServer with a lambda function to handle client requests
    auto server = std::make_unique<TCPServer>([&](std::string const& request, std::string& response) {
        // Print the request received from the client
        std::cout << "Request: " << request << std::endl;

        std::stringstream ss(request); // Use a stringstream to parse the request
        std::string command, name;
        ss >> command; // Extract the command from the request

        // Handle the command using the map
        if (commands.find(command) != commands.end()) {
            ss >> std::ws; // Skip whitespace
            std::getline(ss, name); // Get the rest of the line as the name
            response = commands[command](name); // Execute the corresponding lambda
        } else {
            response = "Error: Unknown command"; // Handle unknown commands
        }

        // Remove any newline characters from the response to avoid communication errors
        response.erase(std::remove(response.begin(), response.end(), '\n'), response.end());

        return true;
    });

    // Start the server and print a message indicating the server is running
    std::cout << "Starting Server on port " << PORT << std::endl;

    // Run the server on the specified port
    int status = server->run(PORT);

    // Handle errors if the server fails to start
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1; // Return an error code
    }

    return 0; // Return 0 to indicate successful execution
}