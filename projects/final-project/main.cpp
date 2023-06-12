/*
main.cpp
Author: Jessica Sandoval
Date: June 4, 2023
Email: sandovalj51506@student.vvc.edu
Description: 

Mountain                                                         Country                                                           Elevation 
Chimborazo                                                       Ecuador                                                           20,549 ft
Matterhorn                                                     Switzerland                                                         14,692 ft
Olympus                                                      Greece (Macedonia)                                                     9,573 ft
Everest                                                           Nepal                                                            29,029 ft
Mount Marcy - Adirondacks                                      United States                                                        5,344 ft
Mount Mitchell - Blue Ridge                                    United States                                                        6,684 ft
Zugspitze                                                       Switzerland                                                         9,719 ft


Write a program that will include the following:
1.A class that will store mountain details which will included the following:

           Member for the name, (make it private for java or c++)
           Member for the country, (make it private for java or c++)
           Member for the elevation, (make it private for java or c++)
           Setters and getters for all the data members. (Make them public for java or c++)

           A member function call toMeters that will take the elevation and convert the value from feet 
           to meters and return the converted value.  The relationship for feet to meters is 1 meter per 
           3.2808 feet

2. In the main function of the Main class(for java, main function for c++ and  a main function for python with the __name__=="__main__" structure) ,
   create 7 instances of Mountain objects and put the mountain data from the table above.
3. Put the mountain objects in an appropriate data structure for the language that you are writing this for.
4. Write a method called minElevation in the (Main class for java, main module for python, or the file that has main for c++) that will return the minimum elevation.
5. Iterate over the data structure that contains the Mountain objects and print out the Mountain details similar to the table above, with the addition of the elevation
   in feet and in meters.
6. Programmatically print out the elevation and name of the shortest mountain (do not hard code this)
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Mountain {
private:
    std::string name;
    std::string country;
    double elevation;

public:
    Mountain(const std::string& name, const std::string& country, double elevation)
        : name(name), country(country), elevation(elevation) {}

    // Getters
    std::string getName() const { return name; }
    std::string getCountry() const { return country; }
    double getElevation() const { return elevation; }

    // Convert elevation from feet to meters
    double toMeters() const { return elevation / 3.2808; }
};

// Find the minimum elevation among the mountains
double minElevation(const std::vector<Mountain>& mountains) {
    if (mountains.empty()) {
        return 0.0; // Return 0 if the vector is empty
    }

    double minElev = mountains[0].getElevation();
    for (const Mountain& mountain : mountains) {
        if (mountain.getElevation() < minElev) {
            minElev = mountain.getElevation();
        }
    }
    return minElev;
}

int main() {
    // Create Mountain objects
    std::vector<Mountain> mountains = {
        Mountain("Chimborazo", "Ecuador", 20549),
        Mountain("Matterhorn", "Switzerland", 14692),
        Mountain("Olympus", "Greece (Macedonia)", 9573),
        Mountain("Everest", "Nepal", 29029),
        Mountain("Mount Marcy - Adirondacks", "United States", 5344),
        Mountain("Mount Mitchell - Blue Ridge", "United States", 6684),
        Mountain("Zugspitze", "Switzerland", 9719)
    };

    // Print mountain details
    std::cout << "\t\tMountain\t\t\t Country\t\t\t\tElevation (ft)\t\t\t\t Elevation (m)" << std::endl;
    for (const Mountain& mountain : mountains) {
        std::cout << "\t\t" << mountain.getName() << " \t\t\t " << mountain.getCountry() << "   \t\t\t\t"
                  << mountain.getElevation() << " ft\t\t\t\t         " << mountain.toMeters() << " m" << std::endl;
        
        
    }

    // Find the shortest mountain
    double minElev = minElevation(mountains);
    std::cout << "\nShortest Mountain: " << minElev << " ft" << std::endl;

    return 0;
}
