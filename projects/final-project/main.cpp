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
        std::cout << "\t\t" << mountain.getName() << "    \t\t\t " << mountain.getCountry() << "\t\t\t\t   "
                  << mountain.getElevation() << "\t\t\t\t" << mountain.toMeters() << std::endl;
        
        
    }

    // Find the shortest mountain
    double minElev = minElevation(mountains);
    std::cout << "\nShortest Mountain: " << minElev << " ft" << std::endl;

    return 0;
}
